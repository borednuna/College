CREATE TABLE alat_olahraga (
    id_alat_olahraga INT NOT NULL PRIMARY KEY,
    nama_alat_olahraga VARCHAR(50) NOT NULL,
    harga_sewa_alat_olahraga NUMERIC(10,2) NOT NULL,
);

CREATE TABLE mengurus(
    pengelola_id_pengelola INT NOT NULL FOREIGN KEY REFERENCES pengelola(id_pengelola),
    alat_olahraga_id_alat_olahraga INT NOT NULL FOREIGN KEY REFERENCES alat_olahraga(id_alat_olahraga)
);

CREATE TABLE feedback (
    id_feedback INT NOT NULL PRIMARY KEY,
    tanggal_feedback DATE NOT NULL,
    keterangan_komplain VARCHAR(300) NOT NULL,
    id_tipe_feedback INT NOT NULL FOREIGN KEY REFERENCES tipe_feedback(id_tipe_feedback),
    id_peminjam INT NOT NULL FOREIGN KEY REFERENCES peminjam(id_peminjam),
);
