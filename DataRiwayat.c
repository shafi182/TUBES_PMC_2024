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

void tambahRiwayat(riwayatDiagnosis** riwayatHead, const char* idPasien, const char* tanggalPeriksaStr, const char* diagnosis, const char* tindakan)
{
    riwayatDiagnosis* newRiwayat = (riwayatDiagnosis*)malloc(sizeof(riwayatDiagnosis));

    strcpy(newRiwayat->idPasien, idPasien);
    strcpy(newRiwayat->diagnosis, diagnosis);
    strcpy(newRiwayat->tindakan, tindakan);

    //passing tanggal Pengecekan

    char tanggalPeriksaCopy[255];
    strcpy(tanggalPeriksaCopy, tanggalPeriksaStr);
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

    int biayapasien = 140000; // Base biaya pasien
    if (strcmp(newRiwayat->tindakan, "Vaksinasi") == 0) {
        biayapasien += 100000;
    } else if (strcmp(newRiwayat->tindakan, "Cek gula darah") == 0) {
        biayapasien += 25000;
    } else if (strcmp(newRiwayat->tindakan, "Pemasangan infus") == 0) {
        biayapasien += 125000;
    } else if (strcmp(newRiwayat->tindakan, "Pengobatan") == 0) {
        biayapasien += 150000;
    }
    char message[255];
    strcpy(message, "Riwayat berhasil ditambahkan");

    newRiwayat->biaya = biayapasien;

    newRiwayat->next = *riwayatHead;
    *riwayatHead = newRiwayat;
}

void hapusDataPasien(dataPasien** pasienHead, riwayatDiagnosis** riwayatHead, const char* idPasien)
{
    dataPasien* currentPasien = *pasienHead;
    dataPasien* prevPasien = NULL;
    riwayatDiagnosis* currentRiwayat = *riwayatHead;
    riwayatDiagnosis* prevRiwayat = NULL;

    // Cari pasien berdasarkan ID
    while (currentPasien != NULL && strcmp(currentPasien->idPasien, idPasien) != 0) {
        prevPasien = currentPasien;
        currentPasien = currentPasien->next;
    }

    // Jika pasien tidak ditemukan
    if (currentPasien == NULL) {
        return;
    }

    // Hapus riwayat diagnosis yang terkait dengan pasien yang akan dihapus
    while (currentRiwayat != NULL) {
        if (strcmp(currentRiwayat->idPasien, idPasien) == 0) {
            if (prevRiwayat == NULL) {
                *riwayatHead = currentRiwayat->next;
            } else {
                prevRiwayat->next = currentRiwayat->next;
            }
            free(currentRiwayat);
            currentRiwayat = prevRiwayat->next;
        } else {
            prevRiwayat = currentRiwayat;
            currentRiwayat = currentRiwayat->next;
        }
    }

    // Hapus data pasien dari linked list
    if (prevPasien == NULL) {
        *pasienHead = currentPasien->next;
    } else {
        prevPasien->next = currentPasien->next;
    }
    free(currentPasien);

    char message[255];
    strcpy(message, "Data berhasil dihapus");

}

void hapusRiwayatDiagnosis(riwayatDiagnosis** riwayatHead, const char* idPasien, const char* tanggalPeriksa)
{
    riwayatDiagnosis* currentRiwayat = *riwayatHead;
    riwayatDiagnosis* prevRiwayat = NULL;

    // Parsing tanggalPeriksa menjadi tanggal, bulan, dan tahun
    int tanggal, tahun;
    char bulan[10]; // Untuk menyimpan bulan dalam format lengkap (misalnya "September")
    sscanf(tanggalPeriksa, "%d-%9s-%d", &tanggal, bulan, &tahun);

    // Cari riwayat diagnosis berdasarkan ID pasien dan tanggal periksa
    while (currentRiwayat != NULL) {
        if (strcmp(currentRiwayat->idPasien, idPasien) == 0 &&
            currentRiwayat->tanggalPeriksa[0] == tanggal &&
            currentRiwayat->tanggalPeriksa[1] == getMonth_(bulan) &&
            currentRiwayat->tanggalPeriksa[2] == tahun) {
            // Hapus riwayat diagnosis yang sesuai
            if (prevRiwayat == NULL) {
                *riwayatHead = currentRiwayat->next;
            } else {
                prevRiwayat->next = currentRiwayat->next;
            }
            free(currentRiwayat);

            ;
            return;
        }
        prevRiwayat = currentRiwayat;
        currentRiwayat = currentRiwayat->next;
    }
    char message[255];
    strcpy(message, "Riwayat berhasil dihapus");

}

// void ubahDataPasien(dataPasien* pasienHead, const char* idPasien, const char* nama, const char* alamat, const char* kota, const char* tempatLahir, const char* tanggalLengkap, const char* noBpjs)* bulan, const char* tahun, const char* noBpjs)
// {
//     dataPasien* current = pasienHead;

//     // Cari pasien berdasarkan ID
//     while (current != NULL && strcmp(current->idPasien, idPasien) != 0 && ) {
//         current = current->next;
//     }

//     // Jika pasien tidak ditemukan
//     if (current == NULL) {
//         return;
//     }

//     // Ubah data pasien jika input bukan "-"
//     if (strcmp(nama, "-") != 0) {
//         strcpy(current->nama, nama);
//     }
//     if (strcmp(alamat, "-") != 0) {
//         strcpy(current->alamat, alamat);
//     }
//     if (strcmp(kota, "-") != 0) {
//         strcpy(current->kota, kota);
//     }
//     if (strcmp(tempatLahir, "-") != 0) {
//         strcpy(current->tempatLahir, tempatLahir);
//     }
//     if (strcmp(tanggalLengkap, "-") != 0) {
//         // Memisahkan tanggal, bulan, dan tahun dari string lengkap
//         int tanggal, tahun;
//         char bulan[10]; // Untuk menyimpan bulan dalam format lengkap (misalnya "September")

//         sscanf(tanggalLengkap, "%d-%9s-%d", &tanggal, bulan, &tahun);

//         current->tanggalLahir[0] = tanggal;
//         current->tanggalLahir[1] = getMonth_(bulan);
//         current->tanggalLahir[2] = tahun;

//         int tanggalLahir[3] = {current->tanggalLahir[0], current->tanggalLahir[1], current->tanggalLahir[2]};
//         current->umur = getAge(tanggalLahir);
//     }
//     if (strcmp(noBpjs, "-") != 0) {
//         strcpy(current->noBpjs, noBpjs);
//     }
//     char message[255];
//     strcpy(message, "Data berhasil diubah");
// }

void ubahRiwayatDiagnosis(riwayatDiagnosis* riwayatHead, const char* idPasien, const char* tanggalLengkap, const char* diagnosis, const char* tindakan, const char* tanggalBaru, const char* IDBaru) {
    riwayatDiagnosis* current = riwayatHead;

    // Memisahkan tanggal, bulan, dan tahun dari string lengkap
    int tanggal, tahun;
    char bulan[20]; // Untuk menyimpan bulan dalam format lengkap (misalnya "September")

    sscanf(tanggalLengkap, "%d-%9s-%d", &tanggal, bulan, &tahun);

    // Cari riwayat diagnosis berdasarkan ID pasien dan tanggal Pemeriksaan
    while (current != NULL && strcmp(current->idPasien, idPasien) != 0 && current->tanggalPeriksa[0] != tanggal && current->tanggalPeriksa[1] != getMonth_(bulan) && current->tanggalPeriksa[2] != tahun) {
        current = current->next;
    }
    // Jika riwayat diagnosis tidak ditemukan
    if (current == NULL) {
        return;
    }

    // Ubah data riwayat diagnosis jika input bukan "-"
    if (strcmp(tanggalBaru, "-") != 0) {
    int newTanggal, newTahun;
    char newBulan[20]; // Untuk menyimpan bulan dalam format lengkap (misalnya "September")
    sscanf(tanggalBaru, "%d-%9s-%d", &newTanggal, newBulan, &newTahun);

    current->tanggalPeriksa[0] = newTanggal;
    current->tanggalPeriksa[1] = getMonth_(newBulan);
    current->tanggalPeriksa[2] = newTahun;
}

    if (strcmp(IDBaru, "-") != 0) {
        strcpy(current->idPasien, IDBaru);
    }


    if (strcmp(diagnosis, "-") != 0) {
        strcpy(current->diagnosis, diagnosis);
    }
    if (strcmp(tindakan, "-") != 0) {
        strcpy(current->tindakan, tindakan);

        // Perbarui biaya berdasarkan tindakan
        int biayapasien = 140000; // Base biaya pasien
        if (strcmp(current->tindakan, "Vaksinasi") == 0) {
            biayapasien += 100000;
        } else if (strcmp(current->tindakan, "Cek gula darah") == 0) {
            biayapasien += 25000;
        } else if (strcmp(current->tindakan, "Pemasangan infus") == 0) {
            biayapasien += 125000;
        } else if (strcmp(current->tindakan, "Pengobatan") == 0) {
            biayapasien += 150000;
        }
        current->biaya = biayapasien;
    }
    char message[255];
    strcpy(message, "Riwayat berhasil diubah");
}

void searchData(GtkWidget* widget, gpointer userData)
{
    dataPasien* current = pasienHead;

    // Search for the patient by ID
    while (current != NULL && strcmp(current->idPasien, idPasien) != 0) {
        current = current->next;
    }

    // If the patient is not found
    if (current == NULL) {
        printf("Pasien dengan ID %s tidak ditemukan.\n", idPasien);
        return;
    }

    // Print patient data in one line
    char message[1024] = ""; // Buffer untuk pesan
    char buffer[256];

    strcat(message, "Data Pasien:\nNama: ");
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
}

void searchRiwayat(riwayatDiagnosis* riwayatHead, const char* idPasien, const char* tanggalPeriksa) {
    riwayatDiagnosis* current = riwayatHead;

    printf("Riwayat Diagnosis untuk Pasien dengan ID %s pada Tanggal Periksa %s:\n", idPasien, tanggalPeriksa);

    // Pisahkan tanggal, bulan, dan tahun dari string tanggalPeriksa
    int tanggal, tahun;
    char bulan[20]; // Untuk menyimpan bulan dalam format lengkap (misalnya "September")
    sscanf(tanggalPeriksa, "%d-%9s-%d", &tanggal, bulan, &tahun);

    // Cari riwayat diagnosis berdasarkan ID pasien dan tanggal periksa
    while (current != NULL) {
        if (strcmp(current->idPasien, idPasien) == 0 &&
            current->tanggalPeriksa[0] == tanggal &&
            current->tanggalPeriksa[1] == getMonth_(bulan) &&
            current->tanggalPeriksa[2] == tahun) {

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

            strcat(message, "\n");
        }
        current = current->next;
    }
}
