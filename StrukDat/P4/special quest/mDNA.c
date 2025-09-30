/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : Shofwan Fikrul Huda/24060124130106*/
/* Tanggal   : 09/25/2025*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
#include "boolean.h"
/* include tstack+boolean */

int main() {
    /* kamus main */
    Tstack DNA;
    int N, M, i;
    char x;
    // Algoritma
    createStack(&DNA);
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++){
        scanf(" %c", &x);
        push(&DNA, x);
    }while(M--){
        Tstack copyDNA = DNA;
        int A;
        scanf("%d", &A);
        char B[1001];
        scanf("%s", &B);
        for(i = 0; i < A; i++){
            if(B[i] == infotop(copyDNA)){
                while (B[i] == infotop(copyDNA)){
                    char e ;
                    pop(&copyDNA, &e);
                }
            }else{
                push(&copyDNA, B[i]);
            }
            
        }
        if(!isEmptyStack(copyDNA)){
            printf("NORMAL\n");
        }else{
            printf("OVEREXPRESSION\n");
        }
    }
	
	
	return 0;
}
