/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060124130106/Shofwan Fikrul Huda*/
/* Tanggal   : 4/9/2025*/
/***********************************/
#include <stdio.h>
#include "titik.h"

int main() {
	//kamus main
	//Titik T1;
	
	//algoritma
	printf("Halo, ini driver modul Titik \n");
	Titik T1, T2, T3;
	makeTitik(&T1,4, 5);
	makeTitik(&T2, 4, 5);
	makeTitik(&T3, 7, 0);
	printf("\nNilai titik T1 adalah: (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
	printf("Nilai titik T2 adalah: (%d, %d)\n", getAbsis(T2), getOrdinat(T2));
	printf("Nilai titik T3 adalah: (%d, %d)\n", getAbsis(T3), getOrdinat(T3));
	makeTitik0(&T1);
	printf("\nNilai titik T1 setelah di originkan adalah: (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
	setAbsis(&T1, 9);
	setOrdinat(&T1, 4);
	printf("Nilai titik T1 setelah di set absis = 9 dan ordinat = 4: (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
	if (isOrigin(T1)){
		printf("\nT1 merupakan bentuk origin");
	}else{
		printf("\nT1 bukan merupakan bentuk origin");
	}if (isOnSumbuX(T1)){
		printf("\nT1 berada di sumbu X");
	}else{
		printf("\nT1 tidak berada di sumbu X");
	}if (isOnSumbuX(T3)){
		printf("\nT3 berada di sumbu X");
	}else{
		printf("\nT3 tidak berada di sumbu X");
	}if (isOnSumbuY(T1)){
		printf("\nT1 berada dalam sumbu Y");
	}else{
		printf("\nT1 tidak berada dalam sumbu Y");
	}if(isEqual(T1, T2)){
		printf("\nT1 dan T2 sama\n");
	}else{
		printf("T1 dan T2 tidak sama\n");
	}if(isEqual(T1, T3)){
		printf("T1 dan T3 sama\n");
	}else{
		printf("T1 dan T3 tidak sama\n");
	}printf("\nT1 sebelum di geser sebesar (1, 2): (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
	geser(&T1, 1, 2);
	printf("T1 sesudah di geser sebesar (1, 2): (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
	geser(&T1, -1, -2); // kembalikan ke titik awal
	printf("\nT2 sebelum di refleksi terhadap sumbu x: (%d, %d)\n", getAbsis(T2), getOrdinat(T2));
	refleksiX(&T2);
	printf("T2 sesudah di refleksi terhadap sumbu x: (%d, %d)\n", getAbsis(T2), getOrdinat(T2));
	refleksiX(&T2); // kembalikan ke titik awal
	printf("T3 sebelum di refleksi terhadap sumbu y: (%d, %d)\n", getAbsis(T3), getOrdinat(T3));
	refleksiY(&T3);
	printf("T3 sesudah di refleksi terhadap sumbu y: (%d, %d)\n", getAbsis(T3), getOrdinat(T3));
	refleksiY(&T3); // kembalikan ke titik awal
	printf("\nT1 sebelum dilatasi sebesar 2: (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
	dilatasi(&T1, 2);
	printf("T1 sesudah dilatasi sebesar 2: (%d, %d)\n", getAbsis(T1), getOrdinat(T1));
	dilatasi(&T1, 0.5); // kembalikan ke titik awal
	Titik X;
	makeTitik(&X, 2, 3);
	printf("\nT2 sebelum dilatasi sebesar 2 terhadap titik (2,3): (%d, %d)\n", getAbsis(T2), getOrdinat(T2));
	dilatasiX(&T2, X, 2);
	printf("T2 sesudah dilatasi sebesar 2 terhadap titik (2,3): (%d, %d)\n", getAbsis(T2), getOrdinat(T2));
	dilatasiX(&T2, X, 0.5); // kembalikan ke titik awal
	


	
	return 0;
}
