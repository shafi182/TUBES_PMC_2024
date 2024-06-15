#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variable.h"


// fungsi untuk mendapatkan bulan dalam bentuk integer dari string
int getMonthFromString(const char *bulan) {
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
void tampilkanKontrolPasien(GtkWidget* widget, gpointer userData) {
    strCallbackData* temp = userData;

    int bulanInput = getMonthFromString(temp->str1);
    int tahunInput = atoi(temp->str2);
    
    if (bulanInput == -1) {
        printf("Bulan yang dimasukkan tidak valid.\n");
        strcpy(temp->strOutput, "Bulan yang dimasukkan tidak valid.\n");
        return;
    }

    riwayatDiagnosis *currentDiagnosis = riwayatDiagnosisHead;
    char str[10];
    char message[1024] = "";
    strcat(message, "Jadwal kontrol\t: \n");
    while (currentDiagnosis != NULL) {
        if (currentDiagnosis->tanggalKontrol[1] == bulanInput && currentDiagnosis->tanggalKontrol[2] == tahunInput) {
            dataPasien *currentPasien = dataPasienHead;
            while (currentPasien != NULL) {
                if (strcmp(currentPasien->idPasien, currentDiagnosis->idPasien) == 0) {
                    printf("Nama: %s, ID: %s\n", currentPasien->nama, currentPasien->idPasien);
                    strcat(message, "\nNama: ");
                    strcat(message, currentPasien->nama);
                    strcat(message, "\nID: ");
                    strcat(message, currentPasien->idPasien);
                    strcat(message, "\nJadwal Kontrol: ");
                    sprintf(str, "%d", currentDiagnosis->tanggalKontrol[0]);
                    strcat(message, str);
                    strcat(message, "-");
                    strcat(message, temp->str1);
                    strcat(message, "-");
                    sprintf(str, "%d", currentDiagnosis->tanggalKontrol[2]);
                    strcat(message, str);
                    strcat(message, "\n");
                    break;
                }
                currentPasien = currentPasien->next;
            }
        }
        currentDiagnosis = currentDiagnosis->next;
    }

    strcpy(temp->strOutput, message);
}

