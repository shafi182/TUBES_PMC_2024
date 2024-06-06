#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


#include "variable.h"
#include "reader.c"


int main(){    
    dataPasienHead = (dataPasien*) malloc(sizeof(dataPasien));
    riwayatDiagnosisHead = (riwayatDiagnosis*) malloc(sizeof(riwayatDiagnosis));

    readFile(&dataPasienHead, &riwayatDiagnosisHead);

    riwayatDiagnosis *cur = riwayatDiagnosisHead;
    for(i=0; i<3; i++){
        cur = cur->next;
    }
    printf("%d %d %d\n", cur->tanggalKontrol[0], cur->tanggalKontrol[1], cur->tanggalKontrol[2]);
    return 0;
}