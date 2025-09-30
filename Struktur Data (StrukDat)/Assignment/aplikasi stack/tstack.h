#ifndef tstack_H
#define tstack_H 

/* Program   : tstack.h */
/* Deskripsi : file HEADER modul stack karakter */
/* NIM/Nama  : 24060124130106 /Shofwan Fikrul Huda */
/* Tanggal   : */
/***********************************/

#include "boolean.h"

/* type Tstack = < wadah : array[1..10] of character,
                   top   : integer > */
typedef	struct { char wadah[100];
                 int  top; 
			   } Tstack;
/*karakter kosong dilambangkan dengan '#'  */
typedef char* string;
/*procedure createStack( output S: Tstack)
	{I.S.: -}
	{F.S.: _ terdefinisi, semua nilai elemen S.wadah = '_' }
	{Proses: menginisialisasi S} */
void createStack (Tstack *S);

/*function top( S: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
//int top (Tstack S);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(S) (S).top

/*function infotop( S: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
//char infotop (Tstack S);
#define infotop(S) (S).wadah[(S).top]

/*function isEmptyStack( S: Tstack) -> boolean
	{mengembalikan True jika S kosong } */
boolean isEmptyStack (Tstack S);

/*function isFullStack( S: Tstack) -> boolean
	{mengembalikan True jika S penuh } */
boolean isFullStack (Tstack S);

/*procedure push ( input/output S:Tstack, input e: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai e }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *S, char e);

/*procedure pop ( input/output S:Tstack, output e: character )
	{I.S.: T terdefinisi}
	{F.S.: e= infotop stack lama, atau '_' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *S, char *e);

/*procedure printStack ( input S:Tstack )
	{I.S.: S terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah S ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack S);

/*function isValidKurung( kata: string) -> boolean
    {mengembalikan True jika kata merupakan kurung valid } */
boolean isValidKurung(string kata);

#endif