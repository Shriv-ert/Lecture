/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : Shofwan Fikrul Huda/24060124130106*/
/* Tanggal   : 09/25/2025*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
/* include tstack+boolean */

int main() 
{	/* kamus main */
	Tstack A, B, C; // variabel A bertipe tStack
	char e;
	int n;
	char kata[30] = {'B', 'S', 'A', 'Q', 'D', 'Q', 'A', 'A', 'Q', 'D', 'Q', 'A', 'S', 'B'};
	/* algoritma */
	createStack(&A);
	createStack(&B);
	createStack(&C);
	printf("Masukkan karakter B S A Q D Q A ke stack A\n");
	push(&A,'B');
	push(&A,'S');
	push(&A,'A');
	push(&A,'Q');
	push(&A,'D');
	push(&A,'Q');
	push(&A,'A');
	printf("Stack A : ");
	printStack(A);
	printf("Top A   : %c\n", infotop(A));
	printf("Pop A   : "); 
	pop(&A,&e);
	printf("%c\n",e);
	printf("View A  : ");
	viewStack(A);
	printf("\n");
	printf("Apakah stack B kosong? ");
	if(isEmptyStack(B)){
		printf("Iya\n");
	}else{
		printf("Tidak\n");
	}
	printf("Masukkan karakter S T R U K D A T G G G ke stack C\n");
	push(&C,'S');
	push(&C,'T');
	push(&C,'R');
	push(&C,'U');
	push(&C,'K');
	push(&C,'D');
	push(&C,'A');
	push(&C,'T');
	push(&C,'G');
	push(&C,'G');
	push(&C,'G');
	printf("Stack C : ");
	printStack(C);
	printf("Top C   : %c\n", infotop(C));
	printf("Apakah stack C penuh? ");
	if(isFullStack(C)){
		printf("Iya\n");
	}else{
		printf("Tidak\n");
	}printf("Input Stack B menggunakan Keyboard\n");
	printf("Masukkan jumlah elemen : ");
	scanf("%d",&n);
	pushN(&B,n);
	printf("Stack B : ");
	printStack(B);
	printf("kata: %s\n", kata);
	printf("Apakah kata palindrom? ");
	if (isPalindrom(kata)){
		printf("Iya\n");
	}else{
		printf("Tidak\n");
	}
	
	
	return 0;
}
