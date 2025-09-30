#ifndef tstack_H
#define tstack_H 

#include "boolean.h"

#define MAX 10
#define STRLEN 100

/* type Tstack = < wadah: array[1..MAX] of string, 
                   top: integer > */
typedef struct { 
    char wadah[MAX+1][STRLEN];
    int top;
} Tstack;

/* procedure createStack( output S: Tstack)
    I.S.: S sembarang
    F.S.: S terdefinisi dengan top = 0 dan semua elemen wadah berupa string kosong */
void createStack(Tstack *S);

/* function isEmptyStack(S: Tstack) -> boolean
    Mengembalikan true jika stack S kosong (top = 0) */
boolean isEmptyStack(Tstack S);

/* function isFullStack(S: Tstack) -> boolean
    Mengembalikan true jika stack S penuh (top = MAX) */
boolean isFullStack(Tstack S);

/* procedure push( input/output S: Tstack, input e: string )
    I.S.: S terdefinisi, e terdefinisi
    F.S.: Elemen e ditambahkan ke top stack jika stack belum penuh */
void push(Tstack *S, char e[]);

/* procedure pop( input/output S: Tstack, output e: string )
    I.S.: S terdefinisi
    F.S.: Elemen top stack diambil dan disimpan di e, top berkurang 1 */
void pop(Tstack *S, char e[]);

/* procedure clearStack( input/output S: Tstack )
    I.S.: S terdefinisi
    F.S.: S dikosongkan (top = 0 dan semua elemen wadah berupa string kosong) */
void clearStack(Tstack *S);

/* procedure printStack( input S: Tstack )
    I.S.: S terdefinisi
    F.S.: Isi stack S ditampilkan ke layar */
void printStack(Tstack S);

#define infotop(S) (S).wadah[(S).top]

#endif