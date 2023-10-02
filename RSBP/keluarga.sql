CREATE DATABASE penduduk;
USE penduduk;

-- Membuat Tabel Warga
CREATE TABLE Warga (
    nomor_ktp INT AUTO_INCREMENT PRIMARY KEY,
    nama VARCHAR(255) NOT NULL,
    status_nikah ENUM('Menikah', 'Belum Menikah', 'Cerai') NOT NULL,
    jenis_kelamin ENUM('Laki-laki', 'Perempuan') NOT NULL
);

-- Membuat Tabel Keluarga
CREATE TABLE Keluarga (
    nomor_kk INT AUTO_INCREMENT PRIMARY KEY,
    nomor_ktp INT NOT NULL,
    ayah INT,
    ibu INT,
    FOREIGN KEY (nomor_ktp) REFERENCES Warga(nomor_ktp),
    FOREIGN KEY (ayah) REFERENCES Warga(nomor_ktp),
    FOREIGN KEY (ibu) REFERENCES Warga(nomor_ktp)
);

-- Insert data warga
INSERT INTO Warga (nama, status_nikah, jenis_kelamin) VALUES
    ('Joko', 'Menikah', 'Laki-laki'),
    ('Ucup', 'Belum Menikah', 'Laki-laki'),
    ('Susanti', 'Menikah', 'Perempuan'),
    ('Dewi', 'Belum Menikah', 'Perempuan'),
    ('Rudi', 'Menikah', 'Laki-laki'),
    ('Lia', 'Belum Menikah', 'Perempuan'),
    ('Budi', 'Menikah', 'Laki-laki'),
    ('Siti', 'Belum Menikah', 'Perempuan'),
    ('Adi', 'Menikah', 'Laki-laki'),
    ('Rina', 'Menikah', 'Perempuan'),
    ('Agus', 'Menikah', 'Laki-laki'),
    ('Sari', 'Belum Menikah', 'Perempuan'),
    ('Ahmad', 'Menikah', 'Laki-laki'),
    ('Dina', 'Belum Menikah', 'Perempuan'),
    ('Eko', 'Menikah', 'Laki-laki'),
    ('Sinta', 'Belum Menikah', 'Perempuan'),
    ('Rico', 'Menikah', 'Laki-laki'),
    ('Lina', 'Belum Menikah', 'Perempuan'),
    ('Fahmi', 'Menikah', 'Laki-laki'),
    ('Rita', 'Belum Menikah', 'Perempuan'),
    ('Farid', 'Menikah', 'Laki-laki'),
    ('Nina', 'Menikah', 'Perempuan'),
    ('Jaya', 'Belum Menikah', 'Laki-laki'),
    ('Ani', 'Menikah', 'Perempuan'),
    ('Hadi', 'Belum Menikah', 'Laki-laki');

-- Insert data keluarga dengan tambahan anak tiri
INSERT INTO Keluarga (nomor_ktp, ayah, ibu) VALUES
    (1, 13, 3),    
    (2, 5, 7), 
    (4, 9, 10),
    (6, 2, 4), 
    (8, 12, 10), 
    (9, NULL, NULL),
    (10, NULL, NULL), 
    (11, 13, 14),
    (16, 13, 14),
    (12, 6, 8),  
    (13, NULL, NULL),
    (14, NULL, NULL),
    (15, 5, 3),
    (16, 13, 14),
    (18, 15, 16),
    (20, 19, 21),
    (21, 11, 2),
    (22, 16, 17),
    (23, 18, 20),
    (24, 22, 23);

-- Mencari keluarga Dewi dan menampilkan perannya dalam row yang ditemukan
SELECT 
    K.nomor_kk AS 'Nomor KK', 
    W1.nama AS 'Nama Ayah', 
    W2.nama AS 'Nama Ibu',
    (SELECT nama FROM Warga WHERE nomor_ktp IN (
        SELECT nomor_ktp FROM Keluarga WHERE nomor_kk = K.nomor_kk
    )) AS 'Anak',
    CASE
        WHEN K.nomor_ktp = (SELECT nomor_ktp FROM Warga WHERE nama = 'Dewi') THEN 'Anak'
        WHEN K.ayah = (SELECT nomor_ktp FROM Warga WHERE nama = 'Dewi') THEN 'Ayah'
        WHEN K.ibu = (SELECT nomor_ktp FROM Warga WHERE nama = 'Dewi') THEN 'Ibu'
    END AS 'Peran'
FROM Keluarga K
JOIN Warga W1 ON K.ayah = W1.nomor_ktp
JOIN Warga W2 ON K.ibu = W2.nomor_ktp
WHERE K.nomor_ktp = (SELECT nomor_ktp FROM Warga WHERE nama = 'Dewi')
   OR K.ayah = (SELECT nomor_ktp FROM Warga WHERE nama = 'Dewi')
   OR K.ibu = (SELECT nomor_ktp FROM Warga WHERE nama = 'Dewi');

-- Mencari semua saudara Sinta
SELECT Warga.nama, Keluarga.ayah, Keluarga.ibu
FROM Keluarga JOIN Warga ON Keluarga.nomor_ktp = Warga.nomor_ktp
WHERE Keluarga.ayah IN (
    SELECT Keluarga.ayah FROM Keluarga JOIN Warga ON Keluarga.nomor_ktp = Warga.nomor_ktp WHERE Warga.nama = 'Sinta'
) OR Keluarga.ibu IN (
    SELECT Keluarga.ibu FROM Keluarga JOIN Warga ON Keluarga.nomor_ktp = Warga.nomor_ktp WHERE Warga.nama = 'Sinta'
);

-- Mencari saudara kandung Agus
SELECT Warga.nama
FROM Keluarga JOIN Warga ON Keluarga.nomor_ktp = Warga.nomor_ktp
WHERE Keluarga.ayah IN (
    SELECT Keluarga.ayah FROM Keluarga JOIN Warga ON Keluarga.nomor_ktp = Warga.nomor_ktp WHERE Warga.nama = 'Agus'
) AND Keluarga.ibu IN (
    SELECT Keluarga.ibu FROM Keluarga JOIN Warga ON Keluarga.nomor_ktp = Warga.nomor_ktp WHERE Warga.nama = 'Agus'
);

-- Mencari saudara tiri Dewi
SELECT Warga.nama
FROM Keluarga JOIN Warga ON Keluarga.nomor_ktp = Warga.nomor_ktp
WHERE (
    Keluarga.ayah IN (
    	SELECT Keluarga.ayah FROM Keluarga JOIN Warga ON Keluarga.nomor_ktp = Warga.nomor_ktp WHERE Warga.nama = 'Dewi'
	) AND Keluarga.ibu NOT IN (
  		SELECT Keluarga.ibu FROM Keluarga JOIN Warga ON Keluarga.nomor_ktp = Warga.nomor_ktp WHERE Warga.nama = 'Dewi'
	)
) OR (
    Keluarga.ayah NOT IN (
    	SELECT Keluarga.ayah FROM Keluarga JOIN Warga ON Keluarga.nomor_ktp = Warga.nomor_ktp WHERE Warga.nama = 'Dewi'
	) AND Keluarga.ibu IN (
  		SELECT Keluarga.ibu FROM Keluarga JOIN Warga ON Keluarga.nomor_ktp = Warga.nomor_ktp WHERE Warga.nama = 'Dewi'
	)
)

-- Mencari kakek Farid
SELECT Warga.nama FROM Warga
JOIN Keluarga ON Warga.nomor_ktp = (
    SELECT Keluarga.ayah
    FROM Keluarga
    WHERE Keluarga.nomor_ktp = (
        SELECT Keluarga.ayah
        FROM Warga JOIN Keluarga ON Warga.nomor_ktp = Keluarga.nomor_ktp
        WHERE Warga.nama = 'Farid'
    )
) GROUP BY Warga.nama

-- Mencari cucu dari Ahmad
SELECT * FROM Warga, Keluarga WHERE Keluarga.ayah IN (
    SELECT Keluarga.nomor_ktp
    FROM Warga JOIN Keluarga ON Warga.nomor_ktp = Keluarga.ayah
    WHERE Warga.nama = 'Ahmad'
) AND Warga.nomor_ktp = Keluarga.nomor_ktp
