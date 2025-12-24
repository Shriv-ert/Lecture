#include <stdio.h>
#include <string.h>
#include "tstack.h"

/* procedure createStack( output S: Tstack)
    I.S.: S sembarang
    F.S.: S terdefinisi dengan top = 0 dan semua elemen wadah berupa string kosong */
void createStack(Tstack *S) {
    S->top = 0;
    for (int i = 1; i <= MAX; i++) {
        S->wadah[i][0] = '\0';
    }
}

/* function isEmptyStack(S: Tstack) -> boolean
    Mengembalikan true jika stack S kosong (top = 0) */
boolean isEmptyStack(Tstack S) {
    return (S.top == 0);
}

/* function isFullStack(S: Tstack) -> boolean
    Mengembalikan true jika stack S penuh (top = MAX) */
boolean isFullStack(Tstack S) {
    return (S.top == MAX);
}

/* procedure push( input/output S: Tstack, input e: string )
    I.S.: S terdefinisi, e terdefinisi
    F.S.: Elemen e ditambahkan ke top stack jika stack belum penuh */
void push(Tstack *S, char e[]) {
    if (!isFullStack(*S)) {
        S->top++;
        strcpy(S->wadah[S->top], e);
    } else {
        printf("Stack penuh! Tidak bisa menambahkan perintah.\n");
    }
}

/* procedure pop( input/output S: Tstack, output e: string )
    I.S.: S terdefinisi
    F.S.: Elemen top stack diambil dan disimpan di e, top berkurang 1 */
void pop(Tstack *S, char e[]) {
    if (!isEmptyStack(*S)) {
        strcpy(e, S->wadah[S->top]);
        S->wadah[S->top][0] = '\0';
        S->top--;
    } else {
        printf("Stack kosong! Tidak ada yang bisa di-pop.\n");
        e[0] = '\0';
    }
}

/* procedure clearStack( input/output S: Tstack )
    I.S.: S terdefinisi
    F.S.: S dikosongkan (top = 0 dan semua elemen wadah berupa string kosong) */
void clearStack(Tstack *S) {
    S->top = 0;
    for (int i = 1; i <= MAX; i++) {
        S->wadah[i][0] = '\0';
    }
}

/* procedure printStack( input S: Tstack )
    I.S.: S terdefinisi
    F.S.: Isi stack S ditampilkan ke layar */
void printStack(Tstack S) {
    if (isEmptyStack(S)) {
        printf("Stack kosong\n");
    } else {
        printf("Isi stack (dari atas ke bawah):\n");
        for (int i = S.top; i >= 1; i--) {
            printf("%d. %s\n", S.top - i + 1, S.wadah[i]);
        }
    }
}