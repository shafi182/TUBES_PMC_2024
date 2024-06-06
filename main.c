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

    readFile();

    riwayatDiagnosis *cur = riwayatDiagnosisHead;
    for(i=0; i<5; i++){
        cur = cur->next;
    }
    printf("%d %s %s\n", cur->biaya, cur->idPasien, cur->diagnosis);
    return 0;
}