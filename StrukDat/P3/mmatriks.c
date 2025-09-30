/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060124130106/Shofwan Fikrul Huda*/
/* Tanggal   : 18-09-2025*/



#include <stdio.h>
#include "matriks.h"

int main() {
	/* KAMUS */
	Matriks M1, M2, M3, M4, M5;
	int row, col, count, x, row1, col1;
	
	/* ALGORITMA */
	printf("Inisiasi M1 dengan matriks kosong\n");
	initMatriks(&M1);
	printf("print M1\n");
	printMatriks(M1);
	printf("Inisiasi M2 dengan matriks kosong\n");
	initMatriks(&M2);
	printf("print M2\n");
	printMatriks(M2);
	printf("Inisiasi M3 dengan matriks kosong\n");
	initMatriks(&M3);
	printf("print M3\n");
	printMatriks(M3);
	printf("Inisiasi M4 dengan matriks kosong\n");
	initMatriks(&M4);
	printf("print M4\n");
	printMatriks(M4);
	printf("Inisiasi M5 dengan matriks kosong\n");
	initMatriks(&M5);
	printf("print M5\n");
	printMatriks(M5);

	printf("\nMasukkan nilai matriks M1 dengan ukuran 3x3 dengan nilai:\n1 2 3\n4 5 6\n7 8 9\n");
	M1.nbaris = 3;
	M1.nkolom = 3;
	addX(&M1, 1, 1, 1);
	addX(&M1, 2, 1, 2);
	addX(&M1, 3, 1, 3);
	addX(&M1, 4, 2, 1);
	addX(&M1, 5, 2, 2);
	addX(&M1, 6, 2, 3);
	addX(&M1, 7, 3, 1);
	addX(&M1, 8, 3, 2);
	addX(&M1, 9, 3, 3);
	printf("Hasil view matriks M1\n");
	viewMatriks(M1);
	printf("Apakah matriks M2 kosong?");
	if(isEmptyMatriks(M2)){
		printf("Ya\n");
	}
	else{
		printf("Tidak\n");
	}
	printf("\nIsi matriks B dengan matriks random 10x10\n");
	isiMatriksRandom(&M2, 10, 10);
	printf("Hasil view matriks M2\n");
	viewMatriks(M2);
	printf("Apakah matriks M2 penuh?");
	if(isFullMatriks(M2)){
		printf("Ya\n");
	}
	else{
		printf("Tidak\n");
	}printf("\nHapus 1 elemen dengan nilai 4 pada matriks M1\n");
	delX(&M1, 4);
	printf("Hasil view matriks M1\n");
	viewMatriks(M1);
	printf("\nIsi matriks M1 dengan nilai 11 pada baris 2 dan kolom 1\n");
	addX(&M1, 11, 2, 1);
	printf("Hasil view matriks M1\n");
	viewMatriks(M1);
	printf("\nIsi matriks M3 dengan matriks identitas 3x3\n");
	isiMatriksIdentitas(&M3, 3);
	printf("Hasil view matriks M3\n");
	viewMatriks(M3);
	printf("\nIsi matriks M4 dengan pertambahan antara matriks M1 dan M3\n");
	M4 = addMatriks(M1, M3);
	printf("Hasil view matriks M4\n");
	viewMatriks(M4);
	printf("Kosongkan matriks M4\n");
	initMatriks(&M4);
	printf("\nIsi matriks M4 dengan pengurangan antara matriks M1 dan M3\n");
	M4 = subMatriks(M1, M3);
	printf("Hasil view matriks M4\n");
	viewMatriks(M4);
	printf("Kosongkan matriks M4\n");
	initMatriks(&M4);
	printf("\nIsi matriks M4 dengan perkalian antara matriks M1 dan M3\n");
	M4 = kaliMatriks(M1, M3);
	printf("Hasil view matriks M4\n");
	viewMatriks(M4);
	printf("Kosongkan matriks M4\n");
	initMatriks(&M4);
	printf("\nIsi matriks M4 dengan perkalian antara matriks M1 dengan skalar 2\n");
	M4 = kaliSkalarMatriks(M1, 2);
	printf("Hasil view matriks M4\n");
	viewMatriks(M4);
	printf("Kosongkan matriks M4\n");
	initMatriks(&M4);
	printf("isi matriks M4 populate dengan bantuan keyboard\n");
	printf("Masukkan jumlah baris matriks: ");
	scanf(" %d", &row);
	printf("Masukkan jumlah kolom matriks: ");
	scanf(" %d", &col);
	printf("\n");
	populateMatriks(&M4, row, col);
	printf("Hasil view matriks M4\n");
	viewMatriks(M4);
	printf("Hasil matriks transpose M4\n");
	transposeMatriks(&M4);
	viewMatriks(M4);
	printf("\nMenambahkan padding 0 pada matrik M4 dengan n sebesar 2\n");
	M4 = addPadding(M4, 2);
	printf("Hasil view matriks M4\n");
	viewMatriks(M4);
	printf("\n Mengisi matriks M5 dengan maxpooling 2x2 pada matriks M2\n");
	M5 = maxPooling(M2, 2);
	printf("Hasil view matriks M5\n");
	viewMatriks(M5);
	printf("\nMengosongkan matriks M5\n");
	initMatriks(&M5);
	printf("\nMengisi matriks M5 dengan average pooling 2x2 pada matriks M2\n");
	M5 = avgPooling(M2, 2);
	printf("Hasil view matriks M5\n");
	viewMatriks(M5);
	printf("\nMengosongkan matriks M5\n");
	initMatriks(&M5);
	printf("\nMengisi matriks M5 dengan konvolusi pada matriks M2 dengan kernel M1\n");
	M5 = conv(M2, M1);
	printf("Hasil view matriks M5\n");
	viewMatriks(M5);
	printf("\nMencari elemen 13 pada matriks random M2 dengan mengembalikan indeks baris dan kolom\n");
	searchX(M2, 13, &row1, &col1);
	printf("Elemen 13 terdapat pada baris %d dan kolom %d\n", row1, col1);
	printf("\nMenghitung berapa banyak elemen 11 pada matriks random M2\n");
	printf("Elemen 11 terdapat sebanyak %d kali\n", countX(M2, 11));
}