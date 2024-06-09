#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


#include "variable.h"
#include "reader.c"
#include "writer.c"


int main(){    
    
    dataPasienHead = (dataPasien*) malloc(sizeof(dataPasien));
    riwayatDiagnosisHead = (riwayatDiagnosis*) malloc(sizeof(riwayatDiagnosis));

    readFile();
    infoPendapatan(&riwayatDiagnosisHead);
    jumlahPasiendanPenyakit(&riwayatDiagnosisHead);
    writeFile();
    return 0;
}
