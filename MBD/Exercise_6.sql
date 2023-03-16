CREATE DATABASE exercise_6
    WITH
    OWNER = postgres
    ENCODING = 'UTF8'
    CONNECTION LIMIT = -1
    IS_TEMPLATE = False;

CREATE TABLE DataPasien (
    IDPasien varchar(50) NOT NULL,
    NoKtp character varying(50),
    NamaPasien character varying(50),
    CONSTRAINT DataPasien_pkey PRIMARY KEY (IDPasien)
);

CREATE TABLE Dokter (
    NID varchar(50) NOT NULL,
    KodePoli varchar(50),
    Nama varchar(50),
    CONSTRAINT Dokter_pkey PRIMARY KEY (NID)
);

CREATE TABLE Poli (
    KodePoli varchar(50) NOT NULL,
    NamaPoli varchar(50),
    CONSTRAINT Poli_pkey PRIMARY KEY (KodePoli)
);

CREATE TABLE Pemeriksaan (
    IDPeriksa varchar(50) NOT NULL,
    NID varchar(50),
    IDPasien varchar(50),
    TglPeriksa date,
    Diagnosa varchar(50),
    CONSTRAINT Pemeriksaan_pkey PRIMARY KEY (IDPeriksa),
    CONSTRAINT Pemeriksaan_NID_fkey FOREIGN KEY (NID) REFERENCES Dokter (NID),
    CONSTRAINT Pemeriksaan_IDPasien_fkey FOREIGN KEY (IDPasien) REFERENCES DataPasien (IDPasien)
);

INSERT INTO DataPasien VALUES ('PS00006', '3507254111940001', 'Lidra Trifidya');
INSERT INTO DataPasien VALUES ('PS00007', '3606125204940003', 'Yutika Amelia Effendi');

INSERT INTO Dokter VALUES ('D009', 'P01', 'Dr. Budikusnaedi');
INSERT INTO Dokter VALUES ('D010', 'P02', 'Dr. Hariyanto Kusuma');
INSERT INTO Dokter VALUES ('D011', 'P02', 'Dr. Sri Herianti');
INSERT INTO Dokter VALUES ('D012', 'P03', 'Dr. Elvin Purwantari');

INSERT INTO Poli VALUES ('P01', 'Bedah Umum');
INSERT INTO Poli VALUES ('P02', 'Mulut');
INSERT INTO Poli VALUES ('P03', 'THT');

INSERT INTO Pemeriksaan VALUES ('C001', 'D009', 'PS00006', '01-Jan-15', 'Radang Usus Buntu');
INSERT INTO Pemeriksaan VALUES ('C002', 'D010', 'PS00007', '02-Jan-15', 'Gigi Berlubang');
INSERT INTO Pemeriksaan VALUES ('C003', 'D011', 'PS00007', '10-Feb-15', 'Flu');
INSERT INTO Pemeriksaan VALUES ('C004', 'D009', 'PS00007', '02-May-15', 'Radang Usus Buntu');

-- Select id of patient and check date of patient who got “Gigi Berlubang” or “Flu
SELECT IDPasien, TglPeriksa FROM Pemeriksaan WHERE Diagnosa = 'Gigi Berlubang' OR Diagnosa = 'Flu';

-- Select KTP number and name of patients who checked on May
SELECT NoKtp, NamaPasien FROM DataPasien WHERE IDPasien IN (SELECT IDPasien FROM Pemeriksaan WHERE EXTRACT(MONTH FROM TglPeriksa) = 5);

-- Select name of patients, name of doctors, the doctor’s poly, and check date of patients who handled by doctor Dr. Budikusnaedi
SELECT NamaPasien, Nama, NamaPoli, TglPeriksa
FROM DataPasien, Dokter, Poli, Pemeriksaan
WHERE
    Nama LIKE 'Dr. Budikusnaedi' AND
    Dokter.NID = Pemeriksaan.NID AND
    Poli.KodePoli = Dokter.KodePoli AND
    DataPasien.IDPasien = Pemeriksaan.IDPasien;
