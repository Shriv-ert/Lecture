#include <stdio.h>

int main() {
    int n = 30;
    int tinggiAndi = 170;

    int ListTinggi[31] = {0, 162, 170, 155, 168, 155, 172, 160, 155, 168, 158,
        166, 160, 172, 164, 159, 170, 155, 168, 153, 169,
        161, 160, 168, 152, 165, 170, 155, 168, 163, 170
    };

    int indeksSama[30];
    int kiri = 0, kanan = 0;
    int tengah, i, j = 0;

    // Hitung kiri dan kanan
    for (i = 1; i <= n; i++) {
        if (tinggiAndi < ListTinggi[i]) {
            kanan++;
        } else if (tinggiAndi > ListTinggi[i]) {
            kiri++;
        }
    }
    printf("Kiri: %d, Kanan: %d, Tengah: %d\n", kiri, kanan, tengah);
    tengah = kiri + 1;
    kanan = n - kanan;
    // Isi indeksSama
    while (tengah <= kanan) {
        indeksSama[j] = tengah;
        tengah++;
        j++;
    }
    // debug nilai kiri, kanan, dan tengah
    printf("Kiri: %d, Kanan: %d, Tengah: %d\n", kiri, kanan, tengah);
    // Output hasil
    printf("Indeks Sama:\n");
    for (i = 0; i < j; i++) {
        printf("%d ", indeksSama[i]);
    }
    return 0;
}