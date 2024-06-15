#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <string.h>
#define maxs 255
#include "variable.h"

//Linked list untuk menyimpan list penyakit dan jumlah masing-masing penyakitnya per bulan
typedef struct dataPenyakit{
    char penyakit[maxs];
    int jumlah;
    struct dataPenyakit* next;
} dataPenyakit;


//Fungsi untuk mengurutkan linked list berdasarkan tahun menggunakan bubble sort
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

//Fungsi untuk menghitung jumlah variasi tahun dalam linked list
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

//Fungsi untuk menambahkan penyakit (diagnosa) ke list
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

//Fungsi untuk mencari penyakit (diagnosa) dalam list per bulan
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

//Fungsi untuk mengurutkan linked list berdasarkan tahun menggunakan bubble sort
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

//Fungsi untuk menampilkan data penyakit per bulan
void printLL(dataPenyakit* node, char massage[4096], char buffer[256]) 
{
    while (node != NULL) 
    {
        sprintf(buffer,"%s:%d\n", node->penyakit, node->jumlah);
        strcat(massage,buffer);
        //printf("%s:%d\n", node->penyakit, node->jumlah);
        node = node->next;
    }
}

/*
Fitur 4
Mendapatkan informasi laporan pendapatan bulanan dan tahunan dan informasi rata-rata pendapatan per tahun yang didapatkan klinik X
*/
void infoPendapatan(GtkWidget* widget, gpointer userData) 
{
    strCallbackData* tempUI = userData;
    
    riwayatDiagnosis* current = riwayatDiagnosisHead;
    riwayatDiagnosis* temp = current;
    sortYear(&temp); //Mengurutkan linked list berdasarkan tahun

    int tahun = countYear(&temp); //Menghitung jumlah variasi tahun

    int perTahun[tahun]; //Menyimpan pendapatan per tahun
    int daftarTahun[tahun]; //Menyimpan variasi tahun
    int avgTahun[tahun]; //Menyimpan rata-rata pendapatan per tahun
    int perBulan[tahun][12]; //Menyimpan pendapatan per bulan
    char daftarBulan [12][20] = {"Januari  ", "Februari", "Maret   ", 
                                "April   ", "Mei     ", "Juni    ", 
                                "Juli    ", "Agustus ", "September", 
                                "Oktober ", "November", "Desember"};
    
    int i = 0, a, b, n = 0; 
    //Variabel n menyimpan jumlah kedatangan pasien per tahun
    
    //Inisialisasi variabel
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

    //Menghitung pendapatan per tahun dan per bulan
    while (temp != NULL)
    {
        //Looping untuk menghitung pendapatan per tahun
        do
        {
            //Menghitung pendapatan per bulan
            if (temp->tanggalPeriksa[1] == 1) //Bulan Januari
            {
                perBulan[i][0]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 2) //Bulan Februari
            {
                perBulan[i][1]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 3) //Bulan Maret
            {
                perBulan[i][2]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 4) //Bulan April
            {
                perBulan[i][3]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 5) //Bulan Mei
            {
                perBulan[i][4]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 6) //Bulan Juni
            {
                perBulan[i][5]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 7) //Bulan Juli
            {
                perBulan[i][6]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 8) //Bulan Agustus
            {
                perBulan[i][7]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 9) //Bulan September
            {
                perBulan[i][8]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 10) //Bulan Oktober
            {
                perBulan[i][9]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 11) //Bulan November
            {
                perBulan[i][10]+=temp->biaya;
            }
            else if (temp->tanggalPeriksa[1] == 12) //Bulan Desember
            {
                perBulan[i][11]+=temp->biaya;
            }
            perTahun[i]+=temp->biaya; //Menghitung pendapatan per tahun
            //a & b untuk memeriksa apakah sudah ganti tahun 
            a = temp->tanggalPeriksa[2];
            if (temp->next != NULL)
            {
                b = temp->next->tanggalPeriksa[2];
            }
            else
            {
                b = 99;
            }
            n++; //Menyimpan jumlah kedatangan pasien
            temp = temp->next; //Lanjut ke data berikutnya
        } 
        while (a == b && temp!=NULL);
        //Ganti tahun
        daftarTahun[i] += a; //Menyimpan tahun
        avgTahun[i] = perTahun[i]/n; //Menghitung rata-rata pendapatan per tahun
        i++; //Indeks ke tahun berikutnya
        n = 0; //Reset n
    }

    char message[1024] = ""; // Buffer untuk pesan
    char buffer[256];

    //Mencetak pendapatan per tahun dan per bulan
    for (int j = 0; j < tahun; j++)
    {
        sprintf(buffer, "Tahun %d :\nPasien bulanan:\n", daftarTahun[j]);
        strcat(message, buffer);
        //printf("Tahun %d :\nPasien bulanan:\n", daftarTahun[j]);
        for (int k = 0; k < 12; k++)
        {
            if (perBulan[j][k] != 0)
            {
                sprintf(buffer,"%s\t:\tRp%d\n", daftarBulan[k], perBulan[j][k]);
                strcat(message, buffer);
                //printf("%s\t:\tRp%d\n", daftarBulan[k], perBulan[j][k]);
            }
            else //Tidak ada pendapatan (bulanan)
            {
                sprintf(buffer,"%s\t:\tRp0\n", daftarBulan[k], perBulan[j][k]);
                strcat(message, buffer);
                //printf("%s\t:\tRp0\n", daftarBulan[k], perBulan[j][k]);
            }
        }
        sprintf(buffer,"Total pendapatan:\tRp%d\nRata-rata pendapatan:   Rp%d\n\n", perTahun[j], avgTahun[j]);
        strcat(message, buffer);
        //printf("Total pendapatan:\tRp%d\nRata-rata pendapatan:   Rp%d\n\n", perTahun[j], avgTahun[j]);
    }
    strcpy(tempUI->strOutput, message);
}

/*
Fitur 5
Mendapatkan informasi jumlah pasien dan penyakit yang di derita pasien 
(diurutkan mulai dari yang terbesar sampai yang terkecil) per bulan dan per tahun
*/
void jumlahPasiendanPenyakit(GtkWidget* widget, gpointer userData) 
{
    strCallbackData* tempUI = userData;

    riwayatDiagnosis* current = riwayatDiagnosisHead;
    riwayatDiagnosis* temp = current;
    sortYear(&temp); //Mengurutkan linked list berdasarkan tahun

    int tahun = countYear(&temp); //Menghitung jumlah variasi tahun

    int perTahun[tahun]; //Menyimpan jumlah per tahun
    int daftarTahun[tahun]; //Menyimpan variasi tahun
    int perBulan[tahun][12]; //Menyimpan jumlah pasien per bulan
    char daftarBulan [12][25] = {"Januari  ", "Februari", "Maret   ", 
                                "April   ", "Mei     ", "Juni    ", 
                                "Juli    ", "Agustus ", "September", 
                                "Oktober ", "November", "Desember"};
    
    int i = 0, a, b, n = 0;
    dataPenyakit* diagnosis[tahun][12]; //List diagnosis & jumlahnya per bulan
    dataPenyakit* diagnosisPerTahun[tahun]; //List diagnosis & jumlahnya per tahun

    //Inisialisasi variabel
    for (int o=0; o<tahun; o++)
    {
        for (int p = 0; p<12; p++)
        {
            perBulan[o][p]=0;
            diagnosis[o][p]=NULL;
        }
        diagnosisPerTahun[o]= NULL;
        perTahun[o]=0;
        daftarTahun[o]=0;
    }

    //Menghitung jumlah pasien dan diagnosis per tahun dan per bulan
    while (temp != NULL)
    {
        //Looping untuk menghitung per tahun
        do
        {
            //Menghitung jumlah pasien dan daftar diagnosis per bulan
            if (temp->tanggalPeriksa[1] == 1) //Bulan Januari
            {
                perBulan[i][0]++; //Menambahkan jumlah pasien per bulan
                int x = searchPenyakit(&diagnosis[i][0],temp->diagnosis); //Mencari diagnosis dalam list
                if (x==0)
                {
                    //Jika diagnosis belum ada, diagnosis dimasukkan ke dalam list
                    insertPenyakit(&diagnosis[i][0],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][0]); //Mengurutkan list diagnosis dari yang jumlahnya paling banyak
            } //Pada bulan-bulan selanjutnya cara kerjanya sama
            else if (temp->tanggalPeriksa[1] == 2) //Bulan Februari
            {
                perBulan[i][1]++;
                int x = searchPenyakit(&diagnosis[i][1],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][1],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][1]);
            }
            else if (temp->tanggalPeriksa[1] == 3) //Bulan Maret
            {
                perBulan[i][2]++;
                int x = searchPenyakit(&diagnosis[i][2],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][2],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][2]);
            }
            else if (temp->tanggalPeriksa[1] == 4) //Bulan April
            {
                perBulan[i][3]++;
                int x = searchPenyakit(&diagnosis[i][3],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][3],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][3]);
            }
            else if (temp->tanggalPeriksa[1] == 5) //Bulan Mei
            {
                perBulan[i][4]++;
                int x = searchPenyakit(&diagnosis[i][4],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][4],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][4]);
            }
            else if (temp->tanggalPeriksa[1] == 6) //Bulan Juni
            {
                perBulan[i][5]++;
                int x = searchPenyakit(&diagnosis[i][5],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][5],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][5]);
            }
            else if (temp->tanggalPeriksa[1] == 7) //Bulan Juli
            {
                perBulan[i][6]++;
                int x = searchPenyakit(&diagnosis[i][6],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][6],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][6]);
            }
            else if (temp->tanggalPeriksa[1] == 8) //Bulan Agustus
            {
                perBulan[i][7]++;
                int x = searchPenyakit(&diagnosis[i][7],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][7],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][7]);
            }
            else if (temp->tanggalPeriksa[1] == 9) //Bulan September
            {
                perBulan[i][8]++;
                int x = searchPenyakit(&diagnosis[i][8],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][8],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][8]);
            }
            else if (temp->tanggalPeriksa[1] == 10) //Bulan Oktober
            {
                perBulan[i][9]++;
                int x = searchPenyakit(&diagnosis[i][9],temp->diagnosis); 
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][9],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][9]);
            }
            else if (temp->tanggalPeriksa[1] == 11) //Bulan November
            {
                perBulan[i][10]++;
                int x = searchPenyakit(&diagnosis[i][10],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][10],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][10]);
            }
            else if (temp->tanggalPeriksa[1] == 12) //Bulan Desember
            {
                perBulan[i][11]++;
                int x = searchPenyakit(&diagnosis[i][11],temp->diagnosis);
                if (x==0)
                {
                    insertPenyakit(&diagnosis[i][11],temp->diagnosis);
                }
                sortPenyakit(&diagnosis[i][11]);
            }
            perTahun[i]++; //Menghitung jumlah kedatangan pasien per tahun
            //a & b untuk memeriksa apakah sudah ganti tahun
            int y = searchPenyakit(&diagnosisPerTahun[i],temp->diagnosis);
            if (y==0)
            {
                insertPenyakit(&diagnosisPerTahun[i],temp->diagnosis);
            }
            sortPenyakit(&diagnosisPerTahun[i]);
            a = temp->tanggalPeriksa[2];
            if (temp->next != NULL)
            {
                b = temp->next->tanggalPeriksa[2];
            }
            else
            {
                b = -99;
            }
            temp = temp->next; //Lanjut ke data berikutnya
        } 
        while (a == b && temp!=NULL);
        //Ganti tahun
        daftarTahun[i] += a; //Menyimpan tahun
        i++; //Indeks ke tahun berikutnya
    }

    char message[4096] = ""; //Buffer untuk pesan
    char buffer[256];

    //Mencetak jumlah pasien dan penyakit per tahun dan per bulan
    for (int j = 0; j < tahun; j++)
    {
        sprintf(buffer,"Tahun %d :\nPasien bulanan:\n", daftarTahun[j]);
        strcat(message, buffer);
        printf("Tahun %d :\nPasien bulanan:\n", daftarTahun[j]);
        strcat(message,"--------------------------\n");
        printf("--------------------------\n");
        for (int k = 0; k < 12; k++)
        {
            if (perBulan[j][k] != 0)
            {
                sprintf(buffer,"%s\t:\t%d\n", daftarBulan[k], perBulan[j][k]);
                strcat(message, buffer);
                printf("%s\t:\t%d\n", daftarBulan[k], perBulan[j][k]);
                strcat(message,"Daftar diagnosis:\n");
                printf("Daftar diagnosis:\n");
                printLL(diagnosis[j][k],message,buffer);
            }
            else //Tidak ada pasien (bulanan)
            {
                sprintf(buffer,"%s\t:\t0\n", daftarBulan[k], perBulan[j][k]);
                strcat(message, buffer);
                printf("%s\t:\t0\n", daftarBulan[k]);
            }
            printf("--------------------------\n", k);
        }
        sprintf(buffer,"Total Pasien\t:\t%d\n\n", perTahun[j]);
        strcat(message, buffer);
        printf("Total Pasien\t:\t%d\n", perTahun[j]);
        strcat(message,"Daftar diagnosis:\n");
        printf("Daftar diagnosis tahun %d:\n", daftarTahun[j]);
        printLL(diagnosisPerTahun[j],message,buffer);
        strcat(message,"\n");
        printf("\n");
    }

    strcpy(tempUI->strOutput, message);
}
