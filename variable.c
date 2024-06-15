#include "variable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

dataPasien *dataPasienHead;
riwayatDiagnosis *riwayatDiagnosisHead;

dataPasienHead = (dataPasien*) malloc(sizeof(dataPasien));
riwayatDiagnosisHead = (riwayatDiagnosis*) malloc(sizeof(riwayatDiagnosis));