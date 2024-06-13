#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


#include "variable.h"
#include "reader.c"
#include "writer.c"
#include "DataRiwayat.c"


int main(){    
    
    dataPasienHead = (dataPasien*) malloc(sizeof(dataPasien));
    riwayatDiagnosisHead = (riwayatDiagnosis*) malloc(sizeof(riwayatDiagnosis));

    readFile();

    tambahData(&dataPasienHead, "Daffa Juanda", "Jl. Kediri", "Kediri", "Jepang", "01-02-2000", "1234567890", "KX 1230129");

    writeFile();
    return 0;
}