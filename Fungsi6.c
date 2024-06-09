#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variable.h"

// struktur inputtanggalbulan
typedef struct inputtanggalbulan
{
    char Bulan[255];
    int tahun;
} inputtanggalbulan;


// fungsi untuk mendapatkan bulan dalam bentuk integer dari string
int getMonthFromString(char *bulan) {
    if (strcmp(bulan, "Januari") == 0) return 1;
    if (strcmp(bulan, "Februari") == 0) return 2;
    if (strcmp(bulan, "Maret") == 0) return 3;
    if (strcmp(bulan, "April") == 0) return 4;
    if (strcmp(bulan, "Mei") == 0) return 5;
    if (strcmp(bulan, "Juni") == 0) return 6;
    if (strcmp(bulan, "Juli") == 0) return 7;
    if (strcmp(bulan, "Agustus") == 0) return 8;
    if (strcmp(bulan, "September") == 0) return 9;
    if (strcmp(bulan, "Oktober") == 0) return 10;
    if (strcmp(bulan, "November") == 0) return 11;
    if (strcmp(bulan, "Desember") == 0) return 12;
    return -1;  // Jika bulan tidak valid
}

// fungsi untuk menampilkan nama dan ID pasien yang harus kontrol pada bulan dan tahun tertentu
void tampilkanKontrolPasien(inputtanggalbulan input) {
    int bulanInput = getMonthFromString(input.Bulan);
    int tahunInput = input.tahun;
    
    if (bulanInput == -1) {
        printf("Bulan yang dimasukkan tidak valid.\n");
        return;
    }

    riwayatDiagnosis *currentDiagnosis = riwayatDiagnosisHead;
    while (currentDiagnosis != NULL) {
        if (currentDiagnosis->tanggalKontrol[1] == bulanInput && currentDiagnosis->tanggalKontrol[2] == tahunInput) {
            dataPasien *currentPasien = dataPasienHead;
            while (currentPasien != NULL) {
                if (strcmp(currentPasien->idPasien, currentDiagnosis->idPasien) == 0) {
                    printf("Nama: %s, ID: %s\n", currentPasien->nama, currentPasien->idPasien);
                    break;
                }
                currentPasien = currentPasien->next;
            }
        }
        currentDiagnosis = currentDiagnosis->next;
    }
}

