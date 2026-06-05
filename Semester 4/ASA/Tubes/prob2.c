#include <stdio.h>

int cariBuku(int n, int ListBuku[], int Target) {
    int kiri = 0;
    int kanan = n - 1;
    int tengah;

    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        // debug nilai kiri, kanan, dan tengah
        printf("Kiri: %d, Kanan: %d, Tengah: %d\n", kiri, kanan, tengah);
        // debug nilai ListBuku di kiri, tengah, dan kanan
        printf("ListBuku[Kiri]: %d, ListBuku[Tengah]: %d, ListBuku[Kanan]: %d\n", ListBuku[kiri], ListBuku[tengah], ListBuku[kanan]);
        if (ListBuku[tengah] == Target) {
            return tengah;
        }

        // Bagian kanan terurut
        if (ListBuku[tengah] < ListBuku[kanan]) {
            if (Target > ListBuku[tengah] && Target <= ListBuku[kanan]) {
                kiri = tengah + 1;
            } else {
                kanan = tengah - 1;
            }
        }
        // Bagian kiri terurut
        else {
            if (Target >= ListBuku[kiri] && Target < ListBuku[tengah]) {
                kanan = tengah - 1;
            } else {
                kiri = tengah + 1;
            }
        }
    }

    return -1;
}

int main() {
    int n = 30;
    int Target = 55; // masih sama

    int ListBuku[30] = {
        34, 37, 41, 45, 52, 55, 58, 63, 67, 71,
        73, 76, 79, 82, 85, 88, 91, 94, 97,
        3, 7, 11, 15, 18, 21, 24, 27, 29, 31, 33
    };

    int hasil = cariBuku(n, ListBuku, Target);

    if (hasil != -1) {
        printf("Target ditemukan di indeks: %d\n", hasil);
    } else {
        printf("Target tidak ditemukan\n");
    }

    return 0;
}