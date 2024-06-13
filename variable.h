#ifndef VARIABLE_H
#define VARIABLE_H

#include <gtk/gtk.h>

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
    int biaya;
    struct riwayatDiagnosis* next;
} riwayatDiagnosis;


// head untuk linked list
dataPasien *dataPasienHead;
riwayatDiagnosis *riwayatDiagnosisHead;


int biayaTindakan[6];   // [0] = Pendaftaran, [1] = Pemeriksaan, [2] = Vaksinasi, [3] = Cek gula darah, [4] = pemasangan infus, [5] = pengobatan

// variabel string untuk menyimpan header dari file
char header1[255];
char header2[255];

// variabel untuk parsing
char line[255];
char tempLine[255];
char* token;
int i;


typedef struct{
    dataPasien *dataPasienHead;
    riwayatDiagnosis *riwayatDiagnosisHead;
    const char *str1;
    const char *str2;
    const char *str3;
    const char *str4;
    const char *str5;
    const char *str6;
    const char *str7;
    char strOutput[3600];
    GtkWidget *labelOutput;
}strCallbackData;

#endif