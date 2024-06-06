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
    printf("%d %s %s\n", riwayatDiagnosisHead->biaya, riwayatDiagnosisHead->idPasien, riwayatDiagnosisHead->diagnosis);
    return 0;
}