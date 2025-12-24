
/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : */
/* Tanggal   : */
/***********************************/
#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* include matriks.h & boolean.h */

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M){
    //kamus
    int i, j;
    //algoritma
    (*M).nbaris = 0;
    (*M).nkolom = 0;
    for (i = 1; i <= 10; i++){
        for (j = 1; j <= 10; j++){
            (*M).cell[i][j] = -999;
        }
    }
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M){
    //kamus
    //algoritma
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M){
    //kamus
    //algoritma
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M){
    //kamus
    //algoritma
    return M.nbaris == 0 && M.nkolom == 0;
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    //kamus
    //algoritma
    return M.nbaris == 10 && M.nkolom == 10;
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col){
    if(!isFullMatriks(*M)){
        (*M).cell[row][col] = X;
    }else{
        printf("Matriks sudah penuh\n");
    }
    
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X){
    //kamus
    boolean found = false;
    int i, j;
    //algoritma
    for (i = 1; i <= (*M).nbaris && !found; i++){
        for (j = 1; j <= (*M).nkolom && !found; j++){
            if((*M).cell[i][j] == X){
                (*M).cell[i][j] = -999;
                found = true;
            }
        }
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y){
    //kamus
    int i, j;
    //algoritma
    (*M).nbaris = x;
    (*M).nkolom = y;
    for (i = 1; i <= x; i++){
        for (j = 1; j <= y; j++){
            (*M).cell[i][j] = rand()%100;
        }
    }
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n){
    //kamus
    int i, j;
    //algoritma
    (*M).nbaris = n;
    (*M).nkolom = n;
    for (i = 1; i <= (*M).nbaris; i++){
        for (j = 1; j <= (*M).nkolom; j++){
            if(i == j){
                (*M).cell[i][j] = 1;
            }else{
                (*M).cell[i][j] = 0;
            }
        }
    }
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y){
    //kamus
    int i, j;
    //algoritma
    (*M).nbaris = x;
    (*M).nkolom = y;
    for (i = 1; i <= (*M).nbaris; i++){
        for (j = 1; j <= (*M).nkolom; j++){
            scanf(" %d", &(*M).cell[i][j]);
        }
    }
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M){
    //kamus
    int i, j;
    //algoritma
    for (i = 1; i <= 10; i++){
        for (j = 1; j <= 10; j++){
            printf("%d ", M.cell[i][j]);
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M){
    //kamus
    int i, j;
    //algoritma
    for (i = 1; i <= M.nbaris; i++){
        for (j = 1; j <= M.nkolom; j++){
            if(M.cell[i][j] != -999){
                printf("%d ", M.cell[i][j]);
            }else{
                printf("- ");
            }
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2){
    //kamus
    int i, j;
    Matriks M3;
    //algoritma
    if(M1.nbaris == M2.nbaris && M1.nkolom == M2.nkolom){
        M3.nbaris = M1.nbaris;
        M3.nkolom = M1.nkolom;
        for (i = 1; i <= M1.nbaris; i++){
            for (j = 1; j <= M1.nkolom; j++){
                if(M1.cell[i][j] == -999){
                    
                }
                M3.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
            }
        }
        return M3;
    }
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2){
    //kamus
    int i, j;
    Matriks M3;
    //algoritma
    if(M1.nbaris == M2.nbaris && M1.nkolom == M2.nkolom){
        M3.nbaris = M1.nbaris;
        M3.nkolom = M1.nkolom;
        for (i = 1; i <= M1.nbaris; i++){
            for (j = 1; j <= M1.nkolom; j++){
                M3.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
            }
        }
        return M3;
    }
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2){
    //kamus
    int i, j, k;
    Matriks M3;
    //algoritma
    M3.nbaris = M1.nbaris;
    M3.nkolom = M2.nkolom;
    for (i = 1; i <= M3.nbaris; i++){
        for (j = 1; j <= M3.nkolom; j++){
            M3.cell[i][j] = 0;
            for (k = 1; k <= M1.nkolom; k++){
                M3.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
            }
        }
    }
    return M3;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x){
    //kamus
    int i, j;
    Matriks M3;
    //algoritma
    M3.nbaris = M1.nbaris;
    M3.nkolom = M1.nkolom;
    for (i = 1; i <= M3.nbaris; i++){
        for (j = 1; j <= M3.nkolom; j++){
            M3.cell[i][j] = M1.cell[i][j] * x;
        }
    }
    return M3;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
    //kamus
    int i, j;
    Matriks Mtemp;
    //algoritma
    Mtemp.nbaris = (*M).nkolom;
    Mtemp.nkolom = (*M).nbaris;

    for (i = 1; i <= Mtemp.nbaris; i++) {
        for (j = 1; j <= Mtemp.nkolom; j++) {
            Mtemp.cell[i][j] = (*M).cell[j][i];
        }
    }

    *M = Mtemp;
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M){
    //kamus
    Matriks M2;
    //algoritma
    M2 = M;
    transposeMatriks(&M2);
    return M2;
}

/* function addPadding(M: Matriks, input n:integer)
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n){
    //kamus
    int i, j;
    Matriks M2;
    //algoritma
    if(M.nbaris + 2 * n >10 || M.nkolom + 2 * n > 10) return M;
    M2.nbaris = M.nbaris + 2 * n;
    M2.nkolom = M.nkolom + 2 * n;
    for (i = 1; i <= M2.nbaris; i++){
        for (j = 1; j <= M2.nkolom; j++){
            if (i <= n || i > M2.nbaris - n || j <= n || j > M2.nkolom - n){
                M2.cell[i][j] = 0;
            }else{
                M2.cell[i][j] = M.cell[i - n][j - n];
            }
        }
    }
    return M2;
}

/* function maxPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size){
    //kamus
    Matriks res;
    int sum, curr;
    int i,j,k,l;

    //algoritma
    initMatriks(&res);
    if (M.nbaris % size == 0){res.nbaris = M.nbaris/size;}else{res.nbaris = (M.nbaris/size) + 1;}
    if (M.nkolom % size == 0){res.nkolom = M.nkolom/size;}else{res.nkolom = (M.nkolom/size) + 1;}
    for(i = 1; i <= getNBaris(res); i++){
        for(j = 1; j <= getNKolom(res); j++){
            
            sum = -999;
            for(k = (i-1)*size + 1; k <= i*size && k <= getNBaris(M); k++){
                for(l = (j-1)*size + 1; l <= j*size && l <= getNKolom(M); l++){
                    curr = M.cell[k][l];
                    if(curr > sum){
                        sum = curr;
                    }
                }
            }
            addX(&res,sum, i, j);
        }
    }
    return res;
}

/* function avgPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size){
    //kamus
    Matriks res;
    int sum, count;
    int avg;
    int i,j,k,l;

    //algoritma
    initMatriks(&res);
    if (M.nbaris % size == 0){res.nbaris = M.nbaris/size;}else{res.nbaris = (M.nbaris/size) + 1;}
    if (M.nkolom % size == 0){res.nkolom = M.nkolom/size;}else{res.nkolom = (M.nkolom/size) + 1;}

    for(i = 1; i <= getNBaris(res); i++){
        for(j = 1; j <= getNKolom(res); j++){
            sum = 0;
            avg = 0;
            count = 0;
            for(k = (i-1)*size + 1; k <= i*size && k <= getNBaris(M); k++){
                for(l = (j-1)*size + 1; l <= j*size && l <= getNKolom(M); l++){
                    sum = sum + M.cell[k][l];
                    count ++;
                }
            }
            avg = sum / count;
            addX(&res,avg, i, j);
        }
    }
    return res;
}

/* function conv(M: Matriks, K:Matriks)
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K){
    //kamus
    Matriks res;
    int sum,mul;
    int i,j,k,l;
    int r,c;

    //algoritma
    initMatriks(&res);
    res.nbaris = (getNBaris(M) - getNBaris(K)) + 1;
    res.nkolom = (getNKolom(M) - getNBaris(K)) + 1;
    for(i = 1; i <= getNBaris(res); i++){
        for(j = 1; j <= getNKolom(res); j++){
            sum = 0;
            mul = 0;
            r = 1;
            for(k = i; k <= i+getNBaris(K)-1 && k <= getNBaris(M); k++){
                c = 1;
                for(l = j; l <= j+getNKolom(K)-1 && l <= getNKolom(M); l++){
                    mul = M.cell[k][l] * K.cell[r][c];
                    sum = sum + mul;
                    c++;
                }
                r++;
            }
            addX(&res, sum, i, j);
        }
    }
    return res;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col){
    //kamus
    int i, j;
    boolean found = false;
    //algoritma
    for (i = 1; i <= M.nbaris && !found; i++){
        for (j = 1; j <= M.nkolom && !found; j++){
            if(M.cell[i][j] == X){
                *row = i;
                *col = j;
                found = true;
            }
        }
    }if(!found){
        *row = -999;
        *col = -999;
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X){
    //kamus
    int i, j, count = 0;
    //algoritma
    for (i = 1; i <= M.nbaris; i++){
        for (j = 1; j <= M.nkolom; j++){
            if(M.cell[i][j] == X){
                count++;
            }
        }
    }
    return count;
}