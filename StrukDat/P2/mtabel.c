#include <stdio.h>
#include "tabel.h"

/* Deskripsi : driver modul Tabel */
/* NIM/Nama : Shofwan Fikrul Huda*/
/* Tanggal : 11/09/2025*/

int main() {
	
	/* KAMUS */
	Tabel T1,T2,T3;
	Tabel Ta;
	int pos, count;
	
	/* ALGORITMA */
	createTable(&T1);
	createTable(&T2);
	createTable(&T3);

	printf("Ukuran tabel T1: %d\n", getSize(T1));
	printf("Ukuran tabel T2: %d\n", getSize(T2));

	printf("\nApakah tabel T1 kosong? ");
	if(isEmptyTable(T1)) {
		printf("Ya\n");
	}else{
		printf("Tidak\n");
	}
	
	printf("\nMasukkan char B A C A A D W E B A ke tabel T1\n");

	addXTable(&T1, 'B');
	addXTable(&T1, 'A');
	addXTable(&T1, 'C');
	addXTable(&T1, 'A');
	addXTable(&T1, 'A');
	addXTable(&T1, 'D');
	addXTable(&T1, 'W');
	addXTable(&T1, 'E');
	addXTable(&T1, 'B');
	addXTable(&T1, 'A');

	printf("Tabel T1: ");
	printTable(T1);

	printf("\nApakah tabel T1 kosong? ");
	if(isEmptyTable(T1)) {
		printf("Ya\n");
	}else{
		printf("Tidak\n");
	}
	printf("\nApakah tabel T1 penuh? ");
	if(isFullTable(T1)) {
		printf("Ya\n");
	}else{
		printf("Tidak\n");
	}
	printf("\nApakah karakter C ada di tabel T1? ");
	searchX(T1, 'C', &pos);
	if(pos != -999) {
		printf("Ya karaketer C ada di tabel T1 indeks ke %d\n", pos);
	}else{
		printf("Karakter C tidak ada di tabel T1\n");
	}
	printf("\nApakah karakter Z ada di tabel T1? ");
	searchX(T1, 'Z', &pos);
	if(pos != -999) {
		printf("Ya karaketer Z ada di tabel T1 indeks ke %d\n", pos);
	}else{
		printf("Karakter Z tidak ada di tabel T1\n");
	}
	printf("\nJumlah karakter A ada di tabel T1: %d\n", countX(T1, 'A'));
	printf(" Jumlah huruf vokal ada di tabel T1: %d\n", countVocal(T1));

	printf("\nHapus karakter A di tabel T1\n");
	printf("Tabel T1 sebelum A dihapus: ");
	printTable(T1);
	delXTable(&T1, 'A');
	printf("Tabel T1 sesudah A dihapus: ");
	printTable(T1);

	printf("\nHapus seluruh karakter B dalam tabel T1\n");
	printf("Tabel T1 sebelum seluruh B dihapus: ");
	printTable(T1);
	delAllXTable(&T1, 'B');
	printf("Tabel T1 sesudah seluruh B dihapus: ");
	printTable(T1);

	printf("\nHapus indeks ke 3 di tabel T1\n");
	printf("Tabel T1 sebelum indeks 3 dihapus: ");
	printTable(T1);
	delTable(&T1, 3);
	printf("Tabel T1 sesudah indeks 3 dihapus: ");
	printTable(T1);

	printf("Hasil view T1: ");
	viewTable(T1);

	printf("\nTambah karakter unik(berbeda) ke tabel T1. menambah karakter A C Z\n");
	printf("Tabel T1 sebelum ditambah karakter unik: ");
	printTable(T1);
	addUniqueXTable(&T1, 'A');
	addUniqueXTable(&T1, 'C');
	addUniqueXTable(&T1, 'Z');
	printf("Tabel T1 sesudah ditambah karakter unik: ");
	printTable(T1);

	printf("\nMembuat tabel T2 dengan karakter A B C D E F \n");

	createTable(&T2);
	addXTable(&T2, 'A');
	addXTable(&T2, 'B');
	addXTable(&T2, 'C');
	addXTable(&T2, 'D');
	addXTable(&T2, 'E');
	addXTable(&T2, 'F');

	printf("Tabel T2: ");
	printTable(T2);

	printf("Apakah tabel T1 sama dengan T2? ");
	if(isEqualTable(T1, T2)) {
		printf("Ya\n");
	}else{
		printf("Tidak\n");
	}

	printf("\nBuat tabel T3 dengan input keyboard(tanpa spasi) dengan ukuran 5\n");
	populateTable(&T3, 5);

	printf("Tabel T3: ");
	printTable(T3);

	printf("\nModus tabel T1 adalah karakter: ");
	printf("%c\n", Modus(T1));

	printf("\nHasil inverse dari Tabel T1\n");
	printf("Tabel T1 sebelum di inverse: ");
	printTable(T1);
	getInverseTable(T1);
	printf("Tabel T1 sesudah di inverse: ");
	printTable(T1);

	printf("\nHasil inverse langsung dari Tabel T1\n");
	printf("Tabel T1 sebelum di inverse langsung: ");
	printTable(T1);
	inverseTable(&T1);
	printf("Tabel T1 sesudah di inverse langsung: ");
	printTable(T1);

	printf("\nHasil sort menaik dari T1\n");
	printf("Tabel T1 sebelum di sort: ");
	printTable(T1);
	sortAsc(&T1);
	printf("Tabel T1 sesudah di sort: ");
	printTable(T1);

	printf("\nHasil sort menurun dari T1\n");
	printf("Tabel T1 sebelum di sort: ");
	printTable(T1);
	sortDesc(&T1);
	printf("Tabel T1 sesudah di sort: ");
	printTable(T1);

	return 0;
}