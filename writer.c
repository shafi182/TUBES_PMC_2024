#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "variable.h"

void intToStringMonth(int month, char monthOut[255]){
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

void writeFile1(char filename[255]){
    FILE* stream = fopen(filename, "w");

    int jumlahData = 1;
    dataPasien *current = dataPasienHead;
    fprintf(stream, "%s", header1);   // write header1
    while(current->next != NULL){
        char month[255];
        intToStringMonth(current->tanggalLahir[1], month);

        fprintf(stream, "%d;%s;%s;%s;%s;%d %s %d;%d;%s;%s\n", jumlahData, current->nama, current->alamat, 
                                                            current->kota, current->tempatLahir, current->tanggalLahir[0], 
                                                            month, current->tanggalLahir[2], current->umur, 
                                                            current->noBpjs, current->idPasien);
        current = current->next;
        jumlahData++;
    }
    fclose(stream);
}

void writeFile2(char filename[255]){
    FILE* stream = fopen(filename, "w");

    int jumlahData = 1;
    riwayatDiagnosis *current = riwayatDiagnosisHead;
    fprintf(stream, "%s", header2);   // write header2
    while(current->next != NULL){
        char monthPeriksa[255];
        char monthKontrol[255];
        intToStringMonth(current->tanggalPeriksa[1], monthPeriksa);
        intToStringMonth(current->tanggalKontrol[1], monthKontrol);

        fprintf(stream, "%d;%d %s %d;%s;%s;%s;%d %s %d;%d\n", jumlahData, current->tanggalPeriksa[0], monthPeriksa, 
                                                            current->tanggalPeriksa[2], current->idPasien, current->diagnosis, 
                                                            current->tindakan, current->tanggalKontrol[0], monthKontrol, 
                                                            current->tanggalKontrol[2], current->biaya);
        current = current->next;
        jumlahData++;
    }
    fclose(stream);
}

void writeFile(){
    char filename[255];
    strcpy(filename, "tes1.csv");
    writeFile1(filename);
    strcpy(filename, "tes2.csv");
    writeFile2(filename);
}