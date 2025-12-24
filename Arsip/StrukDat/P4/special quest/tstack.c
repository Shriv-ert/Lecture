/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : Shofwan Fikrul Huda/24060124130106*/
/* Tanggal   : 09/25/2025*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include <string.h>
/* include tstack+boolean */
/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T){
    //kamus lokal
    //algoritma
    (*T).top = 0;
    for (int i = 1; i <= 1000; i++){
        (*T).wadah[i] = '#';
    }
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T){
    //kamus lokal
    //algoritma
    return Top(T) == 0;
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T){
    //kamus lokal
    //algoritma
    return Top(T) == 10;
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E){
    //kamus lokal
    //algoritma
    if (!isFullStack(*T)){
        Top(*T)++;
        (*T).wadah[Top(*T)] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X){
    //kamus lokal
    //algoritma
    if (!isEmptyStack(*T)){
        *X = (*T).wadah[Top(*T)];
        (*T).wadah[Top(*T)] = '#';
        Top(*T)--;
    }else{
        *X = '#';
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T){
    //kamus lokal
    //algoritma
    for (int i = 1; i <= 10; i++){
        printf("%c, ", T.wadah[i]);
    }
    printf("\n");
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T){
    //kamus lokal
    //algoritma
    for (int i = 1; i <= Top(T); i++){
        printf("%c, ", T.wadah[i]);
    }
    printf("\n");
}

/* boolean isPalindrom(kata:String) 
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
boolean isPalindrom(char kata[30]){
    //kamus lokal
    Tstack A, B;
    int i, n = strlen(kata);
    char j;
    //algoritma
    if(n > 20){
        for(i = 1; i <= 10; i++){
            push(&A, kata[i]);
        }for(i = 11; i <= n/2; i++){
            push(&B, kata[i]);
        }
        for(i = i; i <= Top(B)+10; i++){
            if(kata[i] == B.wadah[B.top]){
                pop(&B, &j);
            }else{
                return false;
            }
        }for(i = i; i <= Top(A)+Top(B)+10; i++){
            if(kata[i] == A.wadah[A.top]){
                pop(&A, &j);
            }else{
                return false;
            }
        }
    }else{
        for(i = 0; i < n/2; i++){
            push(&A, kata[i]);
        }
        if(n%2 == 1){
            i++;
        }
        for(i = i; i < n; i++){
            if(kata[i] == A.wadah[A.top]){
                pop(&A, &j);
            }else{
                return false;
            }
        }
    }
    return true;
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N){
    //kamus lokal
    int i;
    char E;
    //algoritma
    for (i = 1; i <= N && !isFullStack(*T); i++){
        scanf(" %c", &E);
        push(T, E);
    }
}
