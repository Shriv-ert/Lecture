/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124130106 /Shofwan Fikrul Huda */
/* Tanggal   : 21/9/2025*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"

int main(){
    printf("Mengecek apakah kurung {[(A+B) * (C+D)] - (7*D)} valid\n");
    if(isValidKurung("{[(A+B) * (C+D)] - (7*D)}")){
        printf("Kurung {[(A+B) * (C+D)] - (7*D)} valid\n");
    }else{
        printf("Kurung {[(A+B) * (C+D)] - (7*D)} tidak valid\n");
    }
}

