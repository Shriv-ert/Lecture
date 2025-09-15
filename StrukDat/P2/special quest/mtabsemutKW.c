#include <stdio.h>
#include <stdlib.h>
#include "tabel.h"

/* Deskripsi : mtabsemut salah paham. saya kira ketika semut sudah ke ujung akan putar balik */
/* NIM/Nama : Shofwan Fikrul Huda*/
/* Tanggal : 15/09/2025*/

int main() {
    Tabel T, res;
    createTable(&T);
    createTable(&res);
    int n, t,MOD;
    scanf("%d %d", &n, &t);
    MOD = 2*(n-1);
    t = (t+MOD)%MOD;
    for(int i = 1; i <= n; i++) {
        scanf(" %c", &T.wadah[i]);
    }for (int i = 1; i <= n; i++){
        res.wadah[i]='N';
    }
    for(int i = 1; i <= n; i++){
        int idx = i, geser;
        geser=(T.wadah[i]=='L')? t*-1 : t;
        while(idx+geser<1 || idx+geser>n){
            if(idx+geser<1){
                geser=-1*(geser+idx+(geser/abs(geser)));
                idx=1;
            }if(idx+geser>n){
                geser=-1*(n-geser-(geser/abs(geser)));
                idx=n;
            }
        }
        printf("%d\n", idx+geser);
        res.wadah[idx+geser]='Y';
    }
    printf("\n");
    for(int i = 1; i <= n; i++){
        printf("%c ", res.wadah[i]);
    }

    return 0;
}