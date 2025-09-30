#include <stdio.h>
#include "tabel.h"

/* Deskripsi : real mtabsemut. semut akan berjalan sebanyak t langkah ketika bertemu semut lain akan putar balik, ketika ke penghujung akan teleport ke ujung lain dalam 1 langkah*/
/* NIM/Nama : Shofwan Fikrul Huda*/
/* Tanggal : 15/09/2025*/

int main() {
    Tabel T, res;
    createTable(&T);
    createTable(&res);
    int n, t;
    scanf("%d %d", &n, &t);
    t=(t+n)%n;
    for(int i = 1; i <= n; i++) {
        scanf(" %c", &T.wadah[i]);
    }for (int i = 1; i <= n; i++){
        res.wadah[i]='N';
    }
    for(int i = 1; i <= n; i++){
        int idx = i, geser;
        geser=(T.wadah[i]=='L')? t*-1 : t;
        if(idx+geser<1){
            geser=idx+geser;
            idx=n;
        }else if(idx+geser>n){
            geser=idx+geser-n-1;
            idx=1;
        }
        res.wadah[idx+geser]='Y';
        printf("%d\n", idx+geser);

    }
    for(int i = 1; i <= n; i++){
        printf("%c", res.wadah[i]);
    }

    return 0;
}