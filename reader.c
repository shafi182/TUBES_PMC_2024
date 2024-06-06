#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "variable.h"

int getBiaya(char biayaIn[255]){
    char titik = '.';
    char *titikCheck = strchr(biayaIn, titik);

    int biayaOut;

    if(titikCheck){
        token = strtok(biayaIn, ".");
        biayaOut = atoi(token)*1000;
        token = strtok(NULL, ".");
        biayaOut += atoi(token);
    }
    else{
        biayaOut = atoi(biayaIn);
    }

    return biayaOut;
}

int getMonth(char month[255]){
    if(strstr("Januari", month) || strstr("januari", month)){
        return 1;
    }
    else if(strstr("Februari", month) || strstr("februari", month)){
        return 2;
    }
    else if(strstr("Maret", month) || strstr("maret", month)){
        return 3;
    }
    else if(strstr("April", month) || strstr("april", month)){
        return 4;
    }
    else if(strstr("Mei", month) || strstr("mei", month)){
        return 5;
    }
    else if(strstr("Juni", month) || strstr("juni", month)){
        return 6;
    }
    else if(strstr("Juli", month) || strstr("juli", month)){
        return 7;
    }
    else if(strstr("Agustus", month) || strstr("agustus", month)){
        return 8;
    }
    else if(strstr("September", month) || strstr("september", month)){
        return 9;
    }
    else if(strstr("Oktober", month) || strstr("oktober", month)){
        return 10;
    }
    else if(strstr("November", month) || strstr("november", month)){
        return 11;
    }
    else if(strstr("Desember", month) || strstr("desember", month)){
        return 12;
    }
}

void getTanggal(char date[255], int dateArr[3]){
    char strip = '-';
    char *stripCheck = strchr(date, strip);

    if(stripCheck){
        token = strtok(date, "-");
        dateArr[0] = atoi(token);
        token = strtok(NULL, "-");
        dateArr[1] = getMonth(token);
        token = strtok(NULL, "-");
        int tahun = atoi(token);

        if(tahun > 24){ 
            tahun += 1900;
        }
        else{ 
            tahun += 2000;
        }

        dateArr[2] = tahun;
    }
    else{
        token = strtok(date, " ");
        dateArr[0] = atoi(token);
        token = strtok(NULL, " ");
        dateArr[1] = getMonth(token);
        token = strtok(NULL, " ");
        dateArr[2] = atoi(token);
    }
}

void addLinkedList1(char temp[8][255], int baris){

    if(baris == 0){
        strcpy(dataPasienHead->nama, temp[0]);
        strcpy(dataPasienHead->alamat, temp[1]);
        strcpy(dataPasienHead->kota, temp[2]);
        strcpy(dataPasienHead->tempatLahir, temp[3]);
        getTanggal(temp[4], dataPasienHead->tanggalLahir);
        dataPasienHead->umur = atoi(temp[5]);
        strcpy(dataPasienHead->noBpjs, temp[6]);
        strcpy(dataPasienHead->idPasien, temp[7]);
        dataPasienHead->next = NULL;
    }
    else{
        // mencari data terakhir pada linked list
        dataPasien *current = dataPasienHead;
        while(current->next != NULL){
            current = current->next;
        }
        dataPasien *n = (dataPasien*) malloc(sizeof(dataPasien));
        strcpy(n->nama, temp[0]);
        strcpy(n->alamat, temp[1]);
        strcpy(n->kota, temp[2]);
        strcpy(n->tempatLahir, temp[3]);
        getTanggal(temp[4], n->tanggalLahir);
        n->umur = atoi(temp[5]);
        strcpy(n->noBpjs, temp[6]);
        strcpy(n->idPasien, temp[7]);
        n->next = NULL;
        current->next = n;
    }
}

void addLinkedList2(char temp[6][255], int baris){

    if(baris == 0){
        getTanggal(temp[0], riwayatDiagnosisHead->tanggalPeriksa);
        strcpy(riwayatDiagnosisHead->idPasien, temp[1]);
        strcpy(riwayatDiagnosisHead->diagnosis, temp[2]);
        strcpy(riwayatDiagnosisHead->tindakan, temp[3]);
        getTanggal(temp[4], riwayatDiagnosisHead->tanggalKontrol);
        riwayatDiagnosisHead->biaya = getBiaya(temp[5]);
        riwayatDiagnosisHead->next = NULL;
    }
    else{
        // mencari data terakhir pada linked list
        riwayatDiagnosis *current = riwayatDiagnosisHead;
        while(current->next != NULL){
            current = current->next;
        }
        riwayatDiagnosis *n = (riwayatDiagnosis*) malloc(sizeof(riwayatDiagnosis));
        getTanggal(temp[0], n->tanggalPeriksa);
        strcpy(n->idPasien, temp[1]);
        strcpy(n->diagnosis, temp[2]);
        strcpy(n->tindakan, temp[3]);
        getTanggal(temp[4], n->tanggalKontrol);
        // strcpy(n->biaya, temp[5]);
        n->biaya = getBiaya(temp[5]);
        n->next = NULL;
        current->next = n;
    }
}

void readFile1(char fileName[255]){

    FILE* stream = fopen(fileName, "r");
    if (stream == NULL){
        printf("File %s tidak ditemukan", fileName);
        return;
    }

    //Parsing
    char temp[8][255];
    i = 0;
    fgets(line, 255, stream);   
    strcpy(header1, line);      // menyimpan data header
    while(fgets(line, 255, stream)){
        strcpy(tempLine, line);
        token = strtok(tempLine, ";");  // skip  data nomor
        token = strtok(NULL, ";");
        strcpy(temp[0], token);     // data nama
        token = strtok(NULL, ";");
        strcpy(temp[1], token);     // data alamat
        token = strtok(NULL, ";");
        strcpy(temp[2], token);     // data kota
        token = strtok(NULL, ";");
        strcpy(temp[3], token);     // data tempat lahir
        token = strtok(NULL, ";");
        strcpy(temp[4], token);     // data tanggal lahir
        token = strtok(NULL, ";");
        strcpy(temp[5], token);     // data umur
        token = strtok(NULL, ";");
        strcpy(temp[6], token);     // data no bpjs
        token = strtok(NULL, "\n");
        strcpy(temp[7], token);     // data id pasien
        addLinkedList1(temp, i);
        
        i++;
    }
    fclose(stream);
}

void readFile2(char fileName[255]){

    FILE* stream = fopen(fileName, "r");
    if (stream == NULL){
        printf("File %s tidak ditemukan", fileName);
        return;
    }

    //Parsing
    char temp[6][255];
    i = 0;
    fgets(line, 255, stream); 
    strcpy(header2, line);      // menyimpan data header
    while(fgets(line, 255, stream)){
        strcpy(tempLine, line);
        token = strtok(tempLine, ";");  // skip  data nomor
        token = strtok(NULL, ";");
        strcpy(temp[0], token);     // data tanggal periksa
        token = strtok(NULL, ";");
        strcpy(temp[1], token);     // data id pasien
        token = strtok(NULL, ";");
        strcpy(temp[2], token);     // data diagnosis
        token = strtok(NULL, ";");
        strcpy(temp[3], token);     // data tindakan
        token = strtok(NULL, ";");
        strcpy(temp[4], token);     // data tanggal kontrol
        token = strtok(NULL, "\n");
        strcpy(temp[5], token);     // data biaya
        addLinkedList2(temp, i);
        
        i++;
    }
    fclose(stream);
}

void readFile3(char fileName[255]){

    FILE* stream = fopen(fileName, "r");
    if (stream == NULL){
        printf("File %s tidak ditemukan", fileName);
        return;
    }

    //Parsing
    char temp[6][255];
    i = 0;
    fgets(line, 255, stream);   //  skip header
    while(fgets(line, 255, stream)){
        strcpy(tempLine, line);
        token = strtok(tempLine, ";");  // skip  data nomor
        token = strtok(NULL, ";");  // skip data aktivitas
        token = strtok(NULL, ";");
        biayaTindakan[i] = getBiaya(token);    // data biaya tindakan
        
        i++;
    }
    fclose(stream);
}

void readFile(){
    readFile1("DataPasien.csv");
    readFile2("RiwayatDiagnosis.csv");
    readFile3("BiayaTindakan.csv");
}