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

    printf("%d %d %d\n", biayaTindakan[0], biayaTindakan[1], biayaTindakan[2]);

    riwayatDiagnosis *cur = riwayatDiagnosisHead;
    for(i=0; i<5; i++){
        cur = cur->next;
    }
    printf("%d %s %s\n", cur->biaya, cur->idPasien, cur->diagnosis);
    return 0;
}