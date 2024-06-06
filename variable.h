#ifndef VARIABLE_H
#define VARIABLE_H

typedef struct dataPasien
{
    char nama[255];
    char alamat[255];
    char kota[255];
    char tempatLahir[255];
    int tanggalLahir[3];    // [0] = tanggal, [1] = bulan, [2] = tahun
    int umur;
    char noBpjs[255];
    char idPasien[255];
    struct dataPasien* next;
} dataPasien;

typedef struct riwayatDiagnosis
{
    int tanggalPeriksa[3];    // [0] = tanggal, [1] = bulan, [2] = tahun
    char idPasien[255];
    char diagnosis[255];
    char tindakan[255];
    int tanggalKontrol[3];    // [0] = tanggal, [1] = bulan, [2] = tahun
    char biaya[255];
    // int biaya;
    struct riwayatDiagnosis* next;
} riwayatDiagnosis;


dataPasien *dataPasienHead;
riwayatDiagnosis *riwayatDiagnosisHead;

// variabel untuk parsing
char line[255];
char tempLine[255];
char* token;
int i;

#endif