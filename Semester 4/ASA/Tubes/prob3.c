#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int counter = 0;

void cariPuncakRandom(int n, int Ketinggian[]) {
    int kiri = 0;
    int kanan = n - 1;
    int tengah;

    while (kiri <= kanan) {
        tengah = kiri + rand() % (kanan - kiri + 1);
        counter++;

        // Hindari out of bounds + cegah infinite loop
        if (tengah == 0) {
            kiri = tengah + 1;
            continue;
        }
        if (tengah == n - 1) {
            kanan = tengah - 1;
            continue;
        }

        if (Ketinggian[tengah] > Ketinggian[tengah - 1] &&
            Ketinggian[tengah] > Ketinggian[tengah + 1]) {
            return;
        }
        else if (Ketinggian[tengah] < Ketinggian[tengah - 1]) {
            kanan = tengah - 1;
        }
        else {
            kiri = tengah + 1;
        }
    }
}

void cariPuncakBinSer(int n, int Ketinggian[]) {
    int kiri = 0;
    int kanan = n - 1;
    int tengah;

    while (kiri <= kanan) {
        tengah = (kanan + kiri) / 2;
        counter++;
        // Amankan akses array
        if (tengah > 0 && tengah < n - 1 &&
            Ketinggian[tengah] > Ketinggian[tengah - 1] &&
            Ketinggian[tengah] > Ketinggian[tengah + 1]) {
            return;
        }
        else if (tengah > 0 && Ketinggian[tengah] < Ketinggian[tengah - 1]) {
            kanan = tengah - 1;
        }
        else {
            kiri = tengah + 1;
        }
    }
}

int main() {
    srand(time(NULL)); // pindah ke sini

    int n = 30;

    int Ketinggian[30] = {
        5, 9, 14, 18, 23, 27, 31, 36, 40, 45,
        50, 55, 60, 90, 83, 80, 77, 73, 68, 64,
        59, 53, 47, 42, 37, 30, 25, 20, 15, 10
    };
    // int Ketinggian2[30] = {
    //     // buat data dengan puncak di posisi agak samping
    //     5, 9, 14, 18, 23, 27, 31, 36, 40, 45,
    //     50, 55, 60, 65, 70, 75, 80, 85, 90, 95,
    //     97, 98, 99, 100, 104, 110, 120, 130, 140, 100
    // };
    // int Ketinggian[100]={
    //     1, 6, 11, 16, 21, 26, 31, 36, 41, 46,
    //     51, 56, 61, 66, 71, 76, 81, 86, 91, 96,
    //     101, 106, 111, 116, 121, 126, 131, 136, 141, 146,
    //     151, 156, 161, 166, 171, 176, 181, 186, 191, 196,
    //     201, 206, 211, 216, 221, 226, 231, 236, 241, 246,
    //     251, 256, 261, 266, 271, 276, 281, 286, 291, 296,
    //     301, 306, 311, 316, 321, 326, 331, 336, 341, 346,
    //     351, 356, 361, 366, 371, 376, 381, 386, 391, 396,
    //     401, 406, 411, 416, 421, 426, 431, 436, 441, 446,
    //     500, 502, 545, 600, 700, 800, 900, 1000, 9999, 999
    // };
    // int Ketinggian2[100]={
    //     1, 20, 40, 60, 80, 100, 120, 140, 160, 180,
    //     200, 220, 240, 260, 280, 300, 320, 340, 360, 380,
    //     400, 420, 440, 460, 480, 500, 520, 540, 560, 580, 
    //     600, 620, 640, 660, 680, 700, 720, 740, 760, 780,
    //     800, 820, 840, 860, 880, 900, 920, 940, 960, 980,
    //     1000, 980, 960, 940, 920, 900, 880, 860, 840, 820, 
    //     800, 780,
    //     760, 740, 720, 700, 680, 660, 640, 620, 600, 580,
    //     560, 540, 520, 500, 480, 460, 440, 420, 400, 380,
    //     360, 340, 320, 300, 280, 260, 240, 220, 200, 180,
    //     160, 140, 120, 100, 80, 60, 40, 20
    // };

    int totalCounter = 0;
    for(int i = 0; i < 1000000; i++) {
        counter = 0;
        cariPuncakRandom(n, Ketinggian);
        totalCounter += counter;
    }

    printf("Rata-rata counter untuk cariPuncakRandom posisi berada di aga tengah: %f\n", (float)totalCounter / 1000000);

    // totalCounter = 0;
    // for(int i = 0; i < 1000000; i++) {
    //     counter = 0;
    //     cariPuncakRandom(n, Ketinggian2);
    //     totalCounter += counter;
    // }

    // printf("Rata-rata counter untuk cariPuncak posisi berada di aga samping: %f\n", (float)totalCounter / 1000000);

    counter = 0;
    cariPuncakBinSer(n, Ketinggian);
    printf("Counter untuk cariPuncakBinSer posisi aga tengah: %d\n", counter);

    // counter = 0;
    // cariPuncakBinSer(n, Ketinggian2);
    // printf("Counter untuk cariPuncakBinSer posisi aga samping: %d\n", counter);


    return 0;
}