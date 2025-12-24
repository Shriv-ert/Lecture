/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060124130106 /Shofwan Fikrul Huda */
/* Tanggal   : */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
/* include tstack+boolean */

/*procedure createStack( output S: Tstack)
	{I.S.: -}
	{F.S.: S terdefinisi, semua nilai elemen S.wadah = '_' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *S){
    // Kamus Lokal
    int i;
    // Algoritma
    top(*S) = 0;
    for (int i = 1; i <= 10; i++)
    {
        (*S).wadah[i] = '_';
    }
}

/*function isEmptyStack( S: Tstack) -> boolean
	{mengembalikan True jika S kosong } */
boolean isEmptyStack (Tstack S){
    // Kamus Lokal
    // Algoritma
    return top(S) == 0;
}

/*function isFullStack( S: Tstack) -> boolean
	{mengembalikan True jika S penuh } */
boolean isFullStack (Tstack S){
    // Kamus Lokal
    // Algoritma
    return top(S) == 10;
}

/*procedure push ( input/output S:Tstack, input e: character )
	{I.S.: T,e terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai e }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *S, char e){
    // Kamus Lokal
    // Algoritma
    if (isFullStack(*S) == false){
        top(*S) = top(*S) + 1;
        (*S).wadah[top(*S)] = e;
    }
}

/*procedure pop ( input/output S:Tstack, output e: character )
	{I.S.: _ terdefinisi}
	{F.S.: e= infotop stack lama, atau '_' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *S, char *e){
    // Kamus Lokal
    // Algoritma
    *e = '_';
    if (isEmptyStack(*S) == false)
    {
        *e = infotop(*S);
        (*S).wadah[(*S).top] = '_';
        (*S).top = (*S).top - 1;
    }
    
}

/*procedure printStack ( input S:Tstack )
	{I.S.: S terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack S){
    // Kamus Lokal
    int i;
    char X;
    // Algoritma
    for (i = 1; i <= 10; i++)
    {
        printf("%c", S.wadah[i]);
        if (i < 10){
            printf(", ");
        }

    }
    printf("\n");
}
/*function isValidKurung( kata: string) -> boolean
    {mengembalikan True jika kata merupakan kurung valid } 
*/
boolean isValidKurung (string kata){
    // Kamus Lokal
    Tstack S;
    int i, len = strlen(kata);
    char e;
    // Algoritma
    createStack(&S);
    if(len>0){
        for (i = 0; i < len; i++){
            e = kata[i];
            if (e == '{' || e == '(' || e == '['){
                push(&S, e);
            }else if(e == '}' || e == ')' || e == ']'){
                if(!isEmptyStack(S)){
                    if(e == '}' && infotop(S) == '{'){
                        pop(&S, &e);
                    }else if(e == ')' && infotop(S) == '('){
                        pop(&S, &e);
                    }else if(e == ']' && infotop(S) == '['){
                        pop(&S, &e);
                    }
                }else{
                    return false;
                }
            }
        }
    }else{
        return false;
    }
    if(isEmptyStack(S)){
        return true;
    }else{
        return false;
    }
}
