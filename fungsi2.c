#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variable.h"

// fungsi untuk mencari data pasien berdasarkan idPasien
dataPasien* cariDataPasien(char* idPasien) {
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
void cariRiwayatDiagnosis(char* idPasien) {
    riwayatDiagnosis* current = riwayatDiagnosisHead;
    while (current != NULL) {
        if (strcmp(current->idPasien, idPasien) == 0) {
            printf("Tanggal Periksa: %02d-%02d-%04d\n", current->tanggalPeriksa[0], current->tanggalPeriksa[1], current->tanggalPeriksa[2]);
            printf("Diagnosis: %s\n", current->diagnosis);
            printf("Tindakan: %s\n", current->tindakan);
            printf("Tanggal Kontrol: %02d-%02d-%04d\n", current->tanggalKontrol[0], current->tanggalKontrol[1], current->tanggalKontrol[2]);
            printf("Biaya: %d\n", current->biaya);
            printf("----------------------------\n");
        }
        current = current->next;
    }
}

// fungsi gabungan untuk mencari informasi pasien dan riwayat medisnya
void cariInformasiPasien(char* idPasien) {
    dataPasien* pasien = cariDataPasien(idPasien);
    if (pasien == NULL) {
        printf("Data pasien dengan ID %s tidak ditemukan.\n", idPasien);
        return;
    }
    
    // output informasi pasien
    printf("Informasi Pasien:\n");
    printf("Nama: %s\n", pasien->nama);
    printf("Alamat: %s\n", pasien->alamat);
    printf("Kota: %s\n", pasien->kota);
    printf("Tempat Lahir: %s\n", pasien->tempatLahir);
    printf("Tanggal Lahir: %02d-%02d-%04d\n", pasien->tanggalLahir[0], pasien->tanggalLahir[1], pasien->tanggalLahir[2]);
    printf("Umur: %d\n", pasien->umur);
    printf("No BPJS: %s\n", pasien->noBpjs);
    
    // output riwayat diagnosis
    printf("\nRiwayat Diagnosis:\n");
    cariRiwayatDiagnosis(idPasien);
}

