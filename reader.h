#ifndef READER_H
#define READER_H

// #include "variable.h"

int getMonth(char month[255]);

void addLinkedList1(dataPasien **headp, char temp[8][255], int baris);

void addLinkedList2(riwayatDiagnosis **headp, char temp[6][255], int baris);

void readFile1(dataPasien **head, char fileName[255]);

void readFile2(riwayatDiagnosis **head, char fileName[255]);

void readFile(dataPasien **head1, riwayatDiagnosis **head2);

#endif