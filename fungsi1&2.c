#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

#include "variable.h"


int getMonth_(const char* month) {
    if (strcasecmp(month, "januari") == 0 || strcasecmp(month, "Januari") == 0) return 1;
    if (strcasecmp(month, "februari") == 0 || strcasecmp(month, "Februari") == 0) return 2;
    if (strcasecmp(month, "maret") == 0 || strcasecmp(month, "Maret") == 0) return 3;
    if (strcasecmp(month, "Apr") == 0 || strcasecmp(month, "April") == 0) return 4;
    if (strcasecmp(month, "Mei") == 0) return 5;
    if (strcasecmp(month, "Jun") == 0 || strcasecmp(month, "Juni") == 0) return 6;
    if (strcasecmp(month, "Jul") == 0 || strcasecmp(month, "Juli") == 0) return 7;
    if (strcasecmp(month, "Agu") == 0 || strcasecmp(month, "Agustus") == 0) return 8;
    if (strcasecmp(month, "Sep") == 0 || strcasecmp(month, "September") == 0) return 9;
    if (strcasecmp(month, "Okt") == 0 || strcasecmp(month, "Oktober") == 0) return 10;
    if (strcasecmp(month, "Nov") == 0 || strcasecmp(month, "November") == 0) return 11;
    if (strcasecmp(month, "Des") == 0 || strcasecmp(month, "Desember") == 0) return 12;
    return -1; // Invalid month
}

const char* getMonthStr(int month) {
    switch (month) {
        case 1: return "Januari";
        case 2: return "Februari";
        case 3: return "Maret";
        case 4: return "April";
        case 5: return "Mei";
        case 6: return "Juni";
        case 7: return "Juli";
        case 8: return "Agustus";
        case 9: return "September";
        case 10: return "Oktober";
        case 11: return "November";
        case 12: return "Desember";
        default: return "Invalid"; // Handle invalid month
    }
}

int getAge(int birthDate[3])
{
    int currentYear = 2024; // Asumsi current year 2024
    int currentMonth = 5;   // Asumsi current month May
    int currentDay = 31;    // Asumsi current day 31

    int age = currentYear - birthDate[2];
    if (currentMonth < birthDate[1] || (currentMonth == birthDate[1] && currentDay < birthDate[0])) {
        age -= 1;
    }
    return age;
}

void tanggalKontrol(int tanggal[3], int hariTambah)
{
    int hariPerBulan[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int tglTemp[3] = {tanggal[0], tanggal[1], tanggal[2]}; // Create a copy of the date
    tglTemp[0] += hariTambah;

    // Adjust for leap year
    if ((tglTemp[2] % 4 == 0 && tglTemp[2] % 100 != 0) || (tglTemp[2] % 400 == 0)) {
        hariPerBulan[1] = 29;
    }

    while (tglTemp[0] > hariPerBulan[tglTemp[1] - 1]) {
        tglTemp[0] -= hariPerBulan[tglTemp[1] - 1];
        tglTemp[1]++;
        if (tglTemp[1] > 12) {
            tglTemp[1] = 1;
            tglTemp[2]++;
        }
    }

    tanggal[0] = tglTemp[0];
    tanggal[1] = tglTemp[1];
    tanggal[2] = tglTemp[2];
}

void tambahData(GtkWidget* widget, gpointer userData)
{
    strCallbackData* temp = userData;

    // dataPasien** pasienHead, const char* nama, const char* alamat, const char* kota, const char* tempatLahir, const char* tanggalLahirStr, const char* noBpjs, const char* idPasien
    dataPasien* newPasien = (dataPasien*)malloc(sizeof(dataPasien));
    
    if (newPasien == NULL) {
        return;
    }
    g_print("masuk\n");

    strcpy((newPasien->nama), (temp->str1));
    g_print("masuk2\n");
    strcpy(newPasien->alamat, temp->str2);
    strcpy(newPasien->kota, temp->str3);
    strcpy(newPasien->tempatLahir, temp->str4);
    strcpy(newPasien->noBpjs, temp->str6);
    strcpy(newPasien->idPasien, temp->str7);

    //passing tanggal lahir

    char tanggalLahirCopy[255];
    strcpy(tanggalLahirCopy, temp->str5);
    char* token = strtok(tanggalLahirCopy, "-");
    newPasien->tanggalLahir[0] = atoi(token);
    token = strtok(NULL, "-");
    char bulanStr[20];
    strcpy(bulanStr, token);
    token = strtok(NULL, "-");
    newPasien->tanggalLahir[2] = atoi(token);
    newPasien->tanggalLahir[1] = getMonth_(bulanStr);

    //Hitung umur

    int tanggalLahir[3] = { newPasien->tanggalLahir[0], newPasien->tanggalLahir[1], newPasien->tanggalLahir[2] };
    newPasien->umur = getAge(tanggalLahir);

    char message[255];
    strcpy(temp->strOutput, "Data berhasil ditambahkan");


    newPasien->next = dataPasienHead;
    dataPasienHead = newPasien;
}

void tambahRiwayat(GtkWidget* widget, gpointer userData)
{
    strCallbackData* temp = userData;
    
    riwayatDiagnosis* newRiwayat = (riwayatDiagnosis*)malloc(sizeof(riwayatDiagnosis));

    strcpy(newRiwayat->idPasien, temp->str1);
    strcpy(newRiwayat->diagnosis, temp->str3);
    strcpy(newRiwayat->tindakan, temp->str4);

    //passing tanggal Pengecekan

    char tanggalPeriksaCopy[255];
    strcpy(tanggalPeriksaCopy, temp->str2);
    char* token = strtok(tanggalPeriksaCopy, "-");
    newRiwayat->tanggalPeriksa[0] = atoi(token);
    token = strtok(NULL, "-");
    char bulanStr[20];
    strcpy(bulanStr, token);
    token = strtok(NULL, "-");
    newRiwayat->tanggalPeriksa[2] = atoi(token);
    newRiwayat->tanggalPeriksa[1] = getMonth_(bulanStr);

    //kalkulasi tanggal kontrol

    int tempTanggalKontrol[3] = { newRiwayat->tanggalPeriksa[0], newRiwayat->tanggalPeriksa[1], newRiwayat->tanggalPeriksa[2] };
    tanggalKontrol(tempTanggalKontrol, 3);
    newRiwayat->tanggalKontrol[0] = tempTanggalKontrol[0];
    newRiwayat->tanggalKontrol[1] = tempTanggalKontrol[1];
    newRiwayat->tanggalKontrol[2] = tempTanggalKontrol[2];

    //Hitung biaya

    int biayapasien = biayaTindakan[0] + biayaTindakan[1]; // Base biaya pasien
    if (strcmp(newRiwayat->tindakan, "Vaksinasi") == 0) {
        biayapasien += biayaTindakan[2];
    } else if (strcmp(newRiwayat->tindakan, "Cek gula darah") == 0) {
        biayapasien += biayaTindakan[3];
    } else if (strcmp(newRiwayat->tindakan, "Pemasangan infus") == 0) {
        biayapasien += biayaTindakan[4];
    } else if (strcmp(newRiwayat->tindakan, "Pengobatan") == 0) {
        biayapasien += biayaTindakan[5];
    }
    newRiwayat->biaya = biayapasien;

    newRiwayat->next = riwayatDiagnosisHead;
    riwayatDiagnosisHead = newRiwayat;

    strcpy((temp->strOutput), "Riwayat berhasil ditambahkan");
}

void hapusDataPasien(GtkWidget* widget, gpointer userData)
{
    strCallbackData* temp = userData;

    dataPasien* currentPasien = dataPasienHead;
    dataPasien* prevPasien = NULL;
    riwayatDiagnosis* currentRiwayat = riwayatDiagnosisHead;
    riwayatDiagnosis* prevRiwayat = NULL;

    // Cari pasien berdasarkan ID
    while (currentPasien != NULL && strcmp(currentPasien->idPasien, temp->str1) != 0) {
        prevPasien = currentPasien;
        currentPasien = currentPasien->next;
    }

    // Jika pasien tidak ditemukan
    if (currentPasien == NULL) {
        strcpy(temp->strOutput, "ID pasien tidak ditemukan");
        return;
    }
    // Hapus riwayat diagnosis yang terkait dengan pasien yang akan dihapus
    while (currentRiwayat != NULL) {
        if (strcmp(currentRiwayat->idPasien, temp->str1) == 0) {
            if (prevRiwayat == NULL) {
                riwayatDiagnosisHead = currentRiwayat->next;
                free(currentRiwayat);
                currentRiwayat = riwayatDiagnosisHead;
            } else {
                prevRiwayat->next = currentRiwayat->next;
                free(currentRiwayat);
                currentRiwayat = prevRiwayat->next;
            }
        } 
        else{
            prevRiwayat = currentRiwayat;
            currentRiwayat = currentRiwayat->next;
        }
    }
            
    // Hapus data pasien dari linked list
    if (prevPasien == NULL) {
        dataPasienHead = currentPasien->next;
    } else {
        prevPasien->next = currentPasien->next;
    }
    free(currentPasien);

    char message[255];
    strcpy(message, "Data berhasil dihapus");

    strcpy(temp->strOutput, message);
}

void hapusRiwayatDiagnosis(GtkWidget* widget, gpointer userData)
{
    strCallbackData* temp = userData;

    riwayatDiagnosis* currentRiwayat = riwayatDiagnosisHead;
    riwayatDiagnosis* prevRiwayat = NULL;

    // Parsing tanggalPeriksa menjadi tanggal, bulan, dan tahun
    int tanggal, tahun;
    char bulan[10]; // Untuk menyimpan bulan dalam format lengkap (misalnya "September")
    char tempTanggal[255];
    strcpy(tempTanggal, temp->str2);
    token = strtok(tempTanggal, "-");
    tanggal = atoi(token);
    token = strtok(NULL, "-");
    strcpy(bulan, token);
    token = strtok(NULL, "-");
    tahun = atoi(token);

    printf("%d %s %d\n", tanggal, (bulan), tahun);

    // Cari riwayat diagnosis berdasarkan ID pasien dan tanggal periksa
    int found = 0;
    while (currentRiwayat != NULL) {
        if (strcmp(currentRiwayat->idPasien, temp->str1) == 0 &&
            currentRiwayat->tanggalPeriksa[0] == tanggal &&
            currentRiwayat->tanggalPeriksa[1] == getMonth_(bulan) &&
            currentRiwayat->tanggalPeriksa[2] == tahun) {
            // Hapus riwayat diagnosis yang sesuai
            if (prevRiwayat == NULL) {
                riwayatDiagnosisHead = currentRiwayat->next;
            } else {
                prevRiwayat->next = currentRiwayat->next;
            }
            free(currentRiwayat);

            found = 1;
            break;
        }
        prevRiwayat = currentRiwayat;
        currentRiwayat = currentRiwayat->next;
    }

    if (!found) {
        strcpy(temp->strOutput, "Riwayat tidak ditemukan");
        return;
    }
    char message[255];
    strcpy(message, "Riwayat berhasil dihapus");

    strcpy(temp->strOutput, message);
}

void ubahDataPasien(GtkWidget* widget, gpointer userData)
{
    strCallbackData* temp = userData;

    dataPasien* current = dataPasienHead;

    // Cari pasien berdasarkan ID
    while (current != NULL && strcmp(current->idPasien, temp->str7) != 0) {
        current = current->next;
    }

    // Jika pasien tidak ditemukan
    if (current == NULL) {
        strcpy(temp->strOutput, "\nID pasien tidak ditemukan");
        return;
    }
    // Ubah data pasien jika input bukan "-" atau " "
    printf("nemu\n");
    if (strcmp(temp->str1, "-") != 0) {
        strcpy(current->nama, temp->str1);
    }
    if (strcmp(temp->str2, "-") != 0) {
        strcpy(current->alamat, temp->str2);
    }
    if (strcmp(temp->str3, "-") != 0) {
        printf("masuk\n");
        strcpy(current->kota, temp->str3);
    }
    if (strcmp(temp->str4, "-") != 0) {
        strcpy(current->tempatLahir, temp->str4);
    }
    if (strcmp(temp->str5, "-") != 0) {
        // Memisahkan tanggal, bulan, dan tahun dari string lengkap
        int tanggal, tahun;
        char bulan[10]; // Untuk menyimpan bulan dalam format lengkap (misalnya "September")
        char tempTanggal[255];
        strcpy(tempTanggal, temp->str5);
        token = strtok(tempTanggal, "-");
        tanggal = atoi(token);
        token = strtok(NULL, "-");
        strcpy(bulan, token);
        token = strtok(NULL, "-");
        tahun = atoi(token);

        printf("%d %s %d\n", tanggal, (bulan), tahun);
        current->tanggalLahir[0] = tanggal;
        current->tanggalLahir[1] = getMonth_(bulan);
        current->tanggalLahir[2] = tahun;

        int tanggalLahir[3] = {current->tanggalLahir[0], current->tanggalLahir[1], current->tanggalLahir[2]};
        current->umur = getAge(tanggalLahir);
    }
    if (strcmp(temp->str6, "-") != 0) {
        strcpy(current->noBpjs, temp->str6);
    }
    char message[255];
    strcpy(message, "Data berhasil diubah");

    strcpy(temp->strOutput, message);
}

void ubahRiwayatDiagnosis(GtkWidget* widget, gpointer userData) {

    strCallbackData* temp = userData;

    riwayatDiagnosis* current = riwayatDiagnosisHead;

    // Memisahkan tanggal, bulan, dan tahun dari string lengkap
    int tanggal, bulan, tahun;
    char tempBulan[10]; // Untuk menyimpan bulan dalam format lengkap (misalnya "September")
    char tempTanggal[255];
    strcpy(tempTanggal, temp->str3);
    token = strtok(tempTanggal, "-");
    tanggal = atoi(token);
    token = strtok(NULL, "-");
    strcpy(tempBulan, token);
    token = strtok(NULL, "-");
    tahun = atoi(token);
    bulan = getMonth_(tempBulan);

    // Cari riwayat diagnosis berdasarkan ID pasien dan tanggal Pemeriksaan
    int idFound = 0;
    int dateFound = 0;
    while (current != NULL){
        if(strcmp(current->idPasien, temp->str1) == 0){
            idFound = 1;
            if (current->tanggalPeriksa[0] == tanggal && current->tanggalPeriksa[1] == bulan && current->tanggalPeriksa[2] == tahun) {
                dateFound = 1;
                break;                
            }
        }
        current = current->next;
    }

    // Jika riwayat diagnosis tidak ditemukan
    if (idFound == 0) {
        strcpy(temp->strOutput, "\nID pasien tidak ditemukan");
        return;
    }
    // printf("%s %s\n", current->idPasien, temp->str1);

    if(dateFound == 0){
        strcpy(temp->strOutput, "\nTanggal pemeriksaan tidak ditemukan");
        return;
    }

    // Ubah data riwayat diagnosis jika input bukan "-"
    if (strcmp(temp->str4, "-") != 0) {
        int newTanggal, newTahun;
        char newBulan[20]; // Untuk menyimpan bulan dalam format lengkap (misalnya "September")
        strcpy(tempTanggal, temp->str4);
        token = strtok(tempTanggal, "-");
        newTanggal = atoi(token);
        token = strtok(NULL, "-");
        strcpy(newBulan, token);
        token = strtok(NULL, "-");
        newTahun = atoi(token);

        current->tanggalPeriksa[0] = newTanggal;
        current->tanggalPeriksa[1] = getMonth_(newBulan);
        current->tanggalPeriksa[2] = newTahun;
    }

    if (strcmp(temp->str2, "-") != 0) {
        strcpy(current->idPasien, temp->str2);
    }


    if (strcmp(temp->str5, "-") != 0) {
        strcpy(current->diagnosis, temp->str5);
    }
    if (strcmp(temp->str6, "-") != 0) {
        strcpy(current->tindakan, temp->str6);

        // Perbarui biaya berdasarkan tindakan
        int biayapasien = biayaTindakan[0]+biayaTindakan[1]; // Base biaya pasien
        if (strcmp(current->tindakan, "Vaksinasi") == 0) {
            biayapasien += biayaTindakan[2];
        } else if (strcmp(current->tindakan, "Cek gula darah") == 0) {
            biayapasien += biayaTindakan[3];
        } else if (strcmp(current->tindakan, "Pemasangan infus") == 0) {
            biayapasien += biayaTindakan[4];
        } else if (strcmp(current->tindakan, "Pengobatan") == 0) {
            biayapasien += biayaTindakan[5];
        }
        current->biaya = biayapasien;
    }
    char message[255];
    strcpy(message, "Riwayat berhasil diubah");

    strcpy(temp->strOutput, message);
}

void searchData(GtkWidget* widget, gpointer userData)
{
    strCallbackData* temp = userData;

    dataPasien* current = dataPasienHead;

    // Search for the patient by ID
    while (current != NULL && strcmp(current->idPasien, (temp->str1)) != 0) {
        current = current->next;
    }

    // If the patient is not found
    if (current == NULL) {
        printf("Pasien dengan ID %s tidak ditemukan.\n", (temp->str1));
        strcpy(temp->strOutput, "\nData Pasien tidak ditemukan");
        return;
    }

    // Print patient data in one line
    char message[1024] = ""; // Buffer untuk pesan
    char buffer[256];

    strcat(message, "Data Pasien:\n\nNama: ");
    strcat(message, current->nama);

    strcat(message, "\nAlamat: ");
    strcat(message, current->alamat);

    strcat(message, "\nKota: ");
    strcat(message, current->kota);

    strcat(message, "\nTempat Lahir: ");
    strcat(message, current->tempatLahir);

    strcat(message, "\nTanggal Lahir: ");
    sprintf(buffer, "%02d-%s-%04d", current->tanggalLahir[0], getMonthStr(current->tanggalLahir[1]), current->tanggalLahir[2]);
    strcat(message, buffer);

    strcat(message, "\nUmur: ");
    sprintf(buffer, "%d", current->umur);
    strcat(message, buffer);

    strcat(message, "\nNo BPJS: ");
    strcat(message, current->noBpjs);

    strcat(message, "\nID Pasien: ");
    strcat(message, current->idPasien);

    strcpy(temp->strOutput, message);
}

void searchRiwayat(GtkWidget* widget, gpointer userData) {

    strCallbackData* temp = userData;

    riwayatDiagnosis* current = riwayatDiagnosisHead;

    printf("Riwayat Diagnosis untuk Pasien dengan ID %s pada Tanggal Periksa %s:\n", temp->str1, temp->str2);

    // Pisahkan tanggal, bulan, dan tahun dari string tanggalPeriksa
    int tanggal, tahun;
    char bulan[20]; // Untuk menyimpan bulan dalam format lengkap (misalnya "September")
    sscanf(temp->str2, "%d-%9s-%d", &tanggal, bulan, &tahun);

    // Cari riwayat diagnosis berdasarkan ID pasien dan tanggal periksa
    char totalMessage[2048] = ""; // Buffer untuk pesan
    strcat(totalMessage, "Riwayat medis\t: \n\n");
    int found = 0;
    while (current != NULL) {
        if (strcmp(current->idPasien, temp->str1) == 0){ 
            found = 1;
            char message[1024] = ""; // Buffer untuk pesan
            char buffer[256];
            strcat(message, "ID Pasien: ");
            strcat(message, current->idPasien);
            strcat(message, "\nTanggal Periksa: ");
            sprintf(buffer, "%02d-%s-%04d", current->tanggalPeriksa[0], getMonthStr(current->tanggalPeriksa[1]), current->tanggalPeriksa[2]);
            strcat(message, buffer);

            strcat(message, "\nDiagnosis: ");
            strcat(message, current->diagnosis);

            strcat(message, "\nTindakan: ");
            strcat(message, current->tindakan);

            strcat(message, "\nTanggal Kontrol: ");
            sprintf(buffer, "%02d-%s-%04d", current->tanggalKontrol[0], getMonthStr(current->tanggalKontrol[1]), current->tanggalKontrol[2]);
            strcat(message, buffer);

            strcat(message, "\nBiaya: ");
            sprintf(buffer, "%d", current->biaya);
            strcat(message, buffer);

            strcat(message, "\n\n");

            strcat(totalMessage, message);
        }
        current = current->next;
    }

    if (!found) {
        strcpy(totalMessage, "Riwayat Pasien tidak ditemukan.\n");
    }
    printf("%s\n", totalMessage);
    strcpy(temp->strOutput, totalMessage);
}