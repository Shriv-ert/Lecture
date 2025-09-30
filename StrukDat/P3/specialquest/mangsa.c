/* Program   : mmatriks.c */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : Shofwan Fikrul Huda*/
/* Tanggal   : 18 09 2025*/
/***********************************/

#include <stdio.h>
#include "matriks.h"
int main() {
	/*kamus*/
    Matriks M1, M2;
    int N, M, X, temp;
    int point[2] = {0, 0};
	/*algoritma*/
    initMatriks(&M1);
    initMatriks(&M2);
    
    scanf("%d %d %d", &N, &M, &X);
    populateMatriks(&M1, N, M);
    for(int i = 0; i < X; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(M1.cell[a][b] == 1) {
            point[(i+2)%2] += 1;
            M1.cell[a][b] = 0;
        }else if(M1.cell[a][b] >= 2) {
            point[(i+2)%2] += M1.cell[a][b] + flr_sqrt(M1.cell[a][b]);
            M1.cell[a][b] = 0;
        }
        createMatriksZero(&M2, N, M);
        for(int k = 1; k <= N; k++) {
            for(int l = 1; l <= M; l++) {
                if(M1.cell[k][l] >= 1) {
                    if(k%2 == 0 && l%2 == 1){
                        M2.cell[k][(l-1+3+M)%M+1] += M1.cell[k][l];
                    }else if(k%2 == 1 && l%2 == 0){
                        M2.cell[(k+N-2-1)%N+1][(l+M-1-1)%M+1] += M1.cell[k][l];
                    }else if(k%2 == 1 && l%2 == 1){
                        M2.cell[(k+N+3-1)%N+1][(l-3+M-1)%M+1] += M1.cell[k][l];
                    }else if(k%2 == 0 && l%2 == 0){
                        M2.cell[(k+N-1-1)%N+1][(l+2+M-1)%M+1] += M1.cell[k][l];
                    }
                }
            }
        }
        M1 = M2;
    }
    printf("%d\n%d", point[0], point[1]);
    return 0;
}