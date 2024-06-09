#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <string.h>
#define maxs 255
#include "variable.h"

typedef struct dataPenyakit{
    char penyakit[maxs];
    int jumlah;
    struct dataPenyakit* next;
} dataPenyakit;

void sortYear(riwayatDiagnosis** head_ref) 
{
    riwayatDiagnosis *current = *head_ref, *index = NULL;
    int tempPeriksa[3],tempBiaya,tempKontrol[3];
    char tempId[255],tempDiagnosa[255],tempTindakan[255];

    if (head_ref == NULL) 
    {
    return;
    } 
    else 
    {
        while (current != NULL) 
        {
            index = current->next;
            while (index != NULL) 
            {
                if (current->tanggalPeriksa[2] >= index->tanggalPeriksa[2]) 
                {
                    tempPeriksa[0] = current->tanggalPeriksa[0];
                    current->tanggalPeriksa[0] = index->tanggalPeriksa[0];
                    index->tanggalPeriksa[0] = tempPeriksa[0];
                    tempPeriksa[1] = current->tanggalPeriksa[1];
                    current->tanggalPeriksa[1] = index->tanggalPeriksa[1];
                    index->tanggalPeriksa[1] = tempPeriksa[1];
                    tempPeriksa[2] = current->tanggalPeriksa[2];
                    current->tanggalPeriksa[2] = index->tanggalPeriksa[2];
                    index->tanggalPeriksa[2] = tempPeriksa[2];
                    strcpy(tempId,current->idPasien);
                    strcpy(current->idPasien,index->idPasien);
                    strcpy(index->idPasien,tempId);
                    strcpy(tempDiagnosa,current->diagnosis);
                    strcpy(current->diagnosis,index->diagnosis);
                    strcpy(index->diagnosis,tempDiagnosa);
                    strcpy(tempTindakan,current->tindakan);
                    strcpy(current->tindakan,index->tindakan);
                    strcpy(index->tindakan,tempTindakan);
                    tempBiaya = current->biaya;
                    current->biaya = index->biaya;
                    index->biaya = tempBiaya;
                    tempKontrol[0] = current->tanggalKontrol[0];
                    current->tanggalKontrol[0] = index->tanggalKontrol[0];
                    index->tanggalKontrol[0] = tempKontrol[0];
                    tempKontrol[1] = current->tanggalKontrol[1];
                    current->tanggalKontrol[1] = index->tanggalKontrol[1];
                    index->tanggalKontrol[1] = tempKontrol[1];
                    tempKontrol[2] = current->tanggalKontrol[2];
                    current->tanggalKontrol[2] = index->tanggalKontrol[2];
                    index->tanggalKontrol[2] = tempKontrol[2];
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

int countYear(riwayatDiagnosis** head_ref)
{
    riwayatDiagnosis* current = *head_ref;
    int tahun=1;
    while (current->next != NULL) 
    {
        if (current->tanggalPeriksa[2] != current->next->tanggalPeriksa[2])
        {
            tahun++;
        }

        current = current->next;
    }
    return tahun;
}

void insertPenyakit(dataPenyakit** head_ref, char penyakit[maxs]) {
    dataPenyakit* new_node = (dataPenyakit*)malloc(sizeof(dataPenyakit));
    dataPenyakit* last = *head_ref;

    strcpy(new_node->penyakit, penyakit);
    new_node->jumlah = 1;
    new_node->next = NULL;

    if (*head_ref == NULL) 
    {
    *head_ref = new_node;
    return;
    }

    while (last->next != NULL) last = last->next;

    last->next = new_node;
    return;
}

int searchPenyakit(dataPenyakit** head_ref, char penyakit[maxs]) 
{
    dataPenyakit* current = *head_ref;

    while (current != NULL) 
    {
        if (strcmp(current->penyakit, penyakit) == 0) 
        {
            current->jumlah++;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void sortPenyakit(dataPenyakit** head_ref) 
{
    dataPenyakit *current = *head_ref, *index = NULL;
    int temp;

    if (head_ref == NULL) 
    {
    return;
    } 
    else 
    {
        while (current != NULL) 
        {
            index = current->next;
            while (index != NULL) 
            {
                if (current->jumlah < index->jumlah) 
                {
                    temp = current->jumlah;
                    current->jumlah = index->jumlah;
                    index->jumlah = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void printLL(riwayatDiagnosis* node) {
    int i = 0;
    while (node != NULL) 
    {
        i++;
        printf("%d/%d/%d\t:\t%s\n", node->tanggalPeriksa[0],node->tanggalPeriksa[1],node->tanggalPeriksa[2], node->idPasien);
        node = node->next;
    }
    printf("total: %d\n",i);
}

void printLL2(dataPenyakit* node, char massage[1024], char buffer[256]) 
{

    while (node != NULL) 
    {
        sprintf(buffer,"%s:%d\n", node->penyakit, node->jumlah);
        strcat(massage,buffer);
        node = node->next;
    }
}

/*
Fitur 4
Mendapatkan informasi laporan pendapatan bulanan dan tahunan dan informasi rata-rata pendapatan per tahun yang didapatkan klinik X
*/
void infoPendapatan(riwayatDiagnosis** head_ref) 
{
    riwayatDiagnosis* current = *head_ref;
    riwayatDiagnosis* temp = current;
    sortYear(&temp);

    int tahun = countYear(&temp); 

    int perTahun[tahun];
    int daftarTahun[tahun];
    int avgTahun[tahun];
    int perBulan[tahun][12];
    char daftarBulan [12][20] = {"Januari  ", "Februari", "Maret   ", "April   ", "Mei     ", "Juni    ", "Juli    ", "Agustus ", "September", "Oktober ", "November", "Desember"};
    
    int i = 0, a, b, n = 0;
    
    for (int o=0; o<tahun; o++)
    {
        for (int p = 0; p<12; p++)
        {
            perBulan[o][p]=0;
        }
        perTahun[o]=0;
        avgTahun[o]=0;
        daftarTahun[o]=0;
    }

    while (temp != NULL)
    {
        do
        {
            if (temp->tanggalPeriksa[1] == 1)
            {
                perBulan[i][0]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 2)
            {
                perBulan[i][1]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 3)
            {
                perBulan[i][2]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 4)
            {
                perBulan[i][3]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 5)
            {
                perBulan[i][4]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 6)
            {
                perBulan[i][5]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 7)
            {
                perBulan[i][6]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 8)
            {
                perBulan[i][7]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 9)
            {
                perBulan[i][8]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 10)
            {
                perBulan[i][9]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 11)
            {
                perBulan[i][10]+=temp->biaya;
            }
            else
            {
                perBulan[i][11]+=temp->biaya;
            }
            perTahun[i]+=temp->biaya;
            a = temp->tanggalPeriksa[2];
            if (temp->next != NULL)
            {
                b = temp->next->tanggalPeriksa[2];
            }
            else
            {
                b = 99;
            }
            n++;
            temp = temp->next;
        } 
        while (a == b && temp!=NULL);
        daftarTahun[i] += a;
        avgTahun[i] = perTahun[i]/n;
        i++;
        n = 0;
    }

    char message[1024] = ""; // Buffer untuk pesan
    char buffer[256];

    for (int j = 0; j < tahun; j++)
    {
        sprintf("Tahun %d :\nPasien bulanan:\n", daftarTahun[j]);
        strcat(message, buffer);
        for (int k = 0; k < 12; k++)
        {
            if (perBulan[j][k] != 0)
            {
                sprintf(buffer,"%s\t:\tRp%d\n", daftarBulan[k], perBulan[j][k]);
                strcat(message, buffer);
            }
            else
            {
                sprintf(buffer,"%s\t:\tRp0\n", daftarBulan[k], perBulan[j][k]);
                strcat(message, buffer);
            }
        }
        sprintf(buffer,"Total pendapatan:\tRp%d\nRata-rata pendapatan:   Rp%d\n\n", perTahun[j], avgTahun[j]);
        strcat(message, buffer);
    }
}

/*
Fitur 5
Mendapatkan informasi laporan pendapatan bulanan dan tahunan dan informasi rata-rata pendapatan per tahun yang didapatkan klinik X
*/
void jumlahPasiendanPenyakit(riwayatDiagnosis** head_ref)
{
    riwayatDiagnosis* current = *head_ref;
    riwayatDiagnosis* temp = current;
    sortYear(&temp);

    int tahun = countYear(&temp);

    int perTahun[tahun];
    int daftarTahun[tahun];
    int avgTahun[tahun];
    int perBulan[tahun][12];
    char daftarBulan [12][25] = {"Januari  ", "Februari", "Maret   ", "April   ", "Mei     ", "Juni    ", "Juli    ", "Agustus ", "September", "Oktober ", "November", "Desember"};
    
    int i = 0, a, b, n = 0;
    dataPenyakit* diagnosis[tahun][12];

    for (int o=0; o<tahun; o++)
    {
        for (int p = 0; p<12; p++)
        {
            perBulan[o][p]=0;
            diagnosis[o][p]=NULL;
        }
        perTahun[o]=0;
        avgTahun[o]=0;
        daftarTahun[o]=0;
    }

    while (temp != NULL)
    {
        do
        {
            if (temp->tanggalPeriksa[1] == 1)
            {
                perBulan[i][0]++;
                int x = searchPenyakit(&diagnosis[i][0],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][0],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][0]);
            }
            else if (temp->tanggalPeriksa[1] == 2)
            {
                perBulan[i][1]++;
                int x = searchPenyakit(&diagnosis[i][1],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][1],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][1]);
            }
            else if (temp->tanggalPeriksa[1] == 3)
            {
                perBulan[i][2]++;
                int x = searchPenyakit(&diagnosis[i][2],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][2],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][2]);
            }
            else if (temp->tanggalPeriksa[1] == 4)
            {
                perBulan[i][3]++;
                int x = searchPenyakit(&diagnosis[i][3],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][3],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][3]);
            }
            else if (temp->tanggalPeriksa[1] == 5)
            {
                perBulan[i][4]++;
                int x = searchPenyakit(&diagnosis[i][4],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][4],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][4]);
            }
            else if (temp->tanggalPeriksa[1] == 6)
            {
                perBulan[i][5]++;
                int x = searchPenyakit(&diagnosis[i][5],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][5],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][5]);
            }
            else if (temp->tanggalPeriksa[1] == 7)
            {
                perBulan[i][6]++;
                int x = searchPenyakit(&diagnosis[i][6],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][6],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][6]);
            }
            else if (temp->tanggalPeriksa[1] == 8)
            {
                perBulan[i][7]++;
                int x = searchPenyakit(&diagnosis[i][7],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][7],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][7]);
            }
            else if (temp->tanggalPeriksa[1] == 9)
            {
                perBulan[i][8]++;
                int x = searchPenyakit(&diagnosis[i][8],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][8],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][8]);
            }
            else if (temp->tanggalPeriksa[1] == 10)
            {
                perBulan[i][9]++;
                int x = searchPenyakit(&diagnosis[i][9],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][9],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][9]);
            }
            else if (temp->tanggalPeriksa[1] == 11)
            {
                perBulan[i][10]++;
                int x = searchPenyakit(&diagnosis[i][10],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][10],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][10]);
            }
            else
            {
                perBulan[i][11]++;
                int x = searchPenyakit(&diagnosis[i][11],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][11],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][11]);
            }
            perTahun[i]++;
            a = temp->tanggalPeriksa[2];
            if (temp->next != NULL)
            {
                b = temp->next->tanggalPeriksa[2];
            }
            else
            {
                b = 99;
            }
            n++;
            temp = temp->next;
        } 
        while (a == b && temp!=NULL);
        daftarTahun[i] += a;
        i++;
        n = 0;
    }

    char message[1024] = "";
    char buffer[256];

    for (int j = 0; j < tahun; j++)
    {
        sprintf(buffer,"Tahun %d :\nPasien bulanan:\n", daftarTahun[j]);
        strcat(message, buffer);
        strcat(message,"--------------------------\n");
        for (int k = 0; k < 12; k++)
        {
            if (perBulan[j][k] != 0)
            {
                sprintf(buffer,"%s\t:\t%d\n", daftarBulan[k], perBulan[j][k]);
                strcat(message, buffer);
                strcat(message,"Daftar diagnosis:\n");
                printLL2(diagnosis[j][k],message,buffer);
            }
            else
            {
                sprintf(buffer,"%s\t:\t0\n", daftarBulan[k], perBulan[j][k]);
                strcat(message, buffer);
            }
            printf("--------------------------\n");
        }
        sprintf(buffer,"Total Pasien\t:\t%d\n\n", perTahun[j]);
        strcat(message, buffer);
    }
}