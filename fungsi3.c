#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "variable.h"

void stringMonth(int month, char monthOut[20]){
    if(month == 1){
        strcpy(monthOut, "Januari");
    }
    else if(month == 2){
        strcpy(monthOut, "Februari");
    }
    else if(month == 3){
        strcpy(monthOut, "Maret");
    }
    else if(month == 4){
        strcpy(monthOut, "April");
    }
    else if(month == 5){
        strcpy(monthOut, "Mei");
    }
    else if(month == 6){
        strcpy(monthOut, "Juni");
    }
    else if(month == 7){
        strcpy(monthOut, "Juli");
    }
    else if(month == 8){
        strcpy(monthOut, "Agustus");
    }
    else if(month == 9){
        strcpy(monthOut, "September");
    }
    else if(month == 10){
        strcpy(monthOut, "Oktober");
    }
    else if(month == 11){
        strcpy(monthOut, "November");
    }
    else if(month == 12){
        strcpy(monthOut, "Desember");
    }
}

// fungsi untuk mencari data pasien berdasarkan idPasien
dataPasien* cariDataPasien(const char* idPasien) {
    dataPasien* current = dataPasienHead;
    while (current != NULL) {
        if (strcmp(current->idPasien, idPasien) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// fungsi untuk cari riwayat diagnosis berdasarkan idPasien
void cariRiwayatDiagnosis(const char* idPasien, char messageOut[1024]) {
    riwayatDiagnosis* current = riwayatDiagnosisHead;
    while (current != NULL) {
        if (strcmp(current->idPasien, idPasien) == 0) {
            printf("Tanggal Periksa: %02d-%02d-%04d\n", current->tanggalPeriksa[0], current->tanggalPeriksa[1], current->tanggalPeriksa[2]);
            strcat(messageOut, "Tanggal Periksa: ");
            char str[10];
            sprintf(str, "%d", current->tanggalPeriksa[0]);
            strcat(messageOut, str);
            strcat(messageOut, "-");
            char bulan[20];
            stringMonth(current->tanggalPeriksa[1], bulan);
            strcat(messageOut, bulan);
            strcat(messageOut, "-");
            sprintf(str, "%d", current->tanggalPeriksa[2]);
            strcat(messageOut, str);
            
            printf("Diagnosis: %s\n", current->diagnosis);
            strcat(messageOut, "\nDiagnosis: ");
            strcat(messageOut, current->diagnosis);
            
            printf("Tindakan: %s\n", current->tindakan);
            strcat(messageOut, "\nTindakan: ");
            strcat(messageOut, current->tindakan);

            printf("Tanggal Kontrol: %02d-%02d-%04d\n", current->tanggalKontrol[0], current->tanggalKontrol[1], current->tanggalKontrol[2]);
            strcat(messageOut, "\nTanggal Kontrol: ");
            sprintf(str, "%d", current->tanggalKontrol[0]);
            strcat(messageOut, str);
            strcat(messageOut, "-");
            stringMonth(current->tanggalKontrol[1], bulan);
            strcat(messageOut, bulan);
            strcat(messageOut, "-");
            sprintf(str, "%d", current->tanggalKontrol[2]);
            strcat(messageOut, str);

            printf("Biaya: %d\n", current->biaya);
            strcat(messageOut, "\nBiaya: ");
            sprintf(str, "%d", current->biaya);
            strcat(messageOut, str);
            
            printf("----------------------------\n");
            strcat(messageOut, "\n\n");
        }
        current = current->next;
    }
}

// fungsi gabungan untuk mencari informasi pasien dan riwayat medisnya
void cariInformasiPasien(GtkWidget* widget, gpointer userData) {

    strCallbackData* temp = userData;

    dataPasien* pasien = cariDataPasien(temp->str1);
    if (pasien == NULL) {
        printf("Data pasien dengan ID %s tidak ditemukan.\n", temp->str1);
        strcpy(temp->strOutput, "Data pasien tidak ditemukan.");
        return;
    }
    
    // output informasi pasien
    char message[3072] = "";
    printf("Informasi Pasien:\n");
    printf("Nama: %s\n", pasien->nama);
    strcat(message, "Informasi Pasien:\n\nNama: ");
    strcat(message, pasien->nama);

    printf("Alamat: %s\n", pasien->alamat);
    strcat(message, "\nAlamat: ");
    strcat(message, pasien->alamat);

    printf("Kota: %s\n", pasien->kota);
    strcat(message, "\nKota: ");
    strcat(message, pasien->kota);

    printf("Tempat Lahir: %s\n", pasien->tempatLahir);
    strcat(message, "\nTempat Lahir: ");
    strcat(message, pasien->tempatLahir);

    printf("Tanggal Lahir: %02d-%02d-%04d\n", pasien->tanggalLahir[0], pasien->tanggalLahir[1], pasien->tanggalLahir[2]);
    strcat(message, "\nTanggal Lahir: ");
    char str[10];
    sprintf(str, "%d", pasien->tanggalLahir[0]);
    strcat(message, str);
    strcat(message, "-");
    char bulan[20];
    stringMonth(pasien->tanggalLahir[1], bulan);
    strcat(message, bulan);
    strcat(message, "-");
    sprintf(str, "%d", pasien->tanggalLahir[2]);
    strcat(message, str);
    
    printf("Umur: %d\n", pasien->umur);
    strcat(message, "\nUmur: ");
    sprintf(str, "%d", pasien->umur);
    strcat(message, str);

    printf("No BPJS: %s\n", pasien->noBpjs);
    strcat(message, "\nNo BPJS: ");
    strcat(message, pasien->noBpjs);
    
    // output riwayat diagnosis
    printf("\nRiwayat Diagnosis:\n");
    strcat(message, "\n\nRiwayat Diagnosis:\n\n");
    char message2[1024] = "";
    cariRiwayatDiagnosis(temp->str1, message2);

    strcat(message, message2);
    strcpy(temp->strOutput, message);
}

