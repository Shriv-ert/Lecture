Seorang mahasiswa bernama Andi ingin mengetahui posisinya di antara teman-teman sekelasnya berdasarkan tinggi badan. Ia mencatat tinggi badan n mahasiswa di kelasnya dalam sebuah daftar. Namun, karena data tersebut dikumpulkan secara acak, urutan tinggi badan dalam daftar tersebut tidak teratur.
Andi ingin mengetahui pada urutan ke berapa saja terdapat mahasiswa yang memiliki tinggi badan yang sama dengan dirinya jika daftar tersebut disusun dari yang paling pendek hingga paling tinggi. Bantulah Andi untuk menentukan semua indeks (1-based) dimana tinggi badan sama dengan tinggi badan Andi. Dipastikan ada data tinggi tersebut minimal 1(Andi sendiri).

Algoritma Fungsional
```
function cariSemuaIndeks(n : integer, ListTinggi : array of integer, tinggiAndi : integer) -> array of integer
    {Kamus Lokal}
    indeksSama : array of integer
    kiri : integer
    kanan : integer
    jumlah : integer
    {Algoritma}
    kiri <- 0
    kanan <- 0
    i Traversal [1..n]
        depend on tinggiAndi:
            if tinggiAndi < ListTinggi[i] then
                kanan <- kanan + 1
            else if tinggiAndi > ListTinggi[i] then
                kiri <- kiri + 1
    tengah <- kiri + 1
    i <- 1
    while tengah < kanan do
        indeksSama[i] <- tengah
        tengah <- tengah + 1
        i <- i + 1 
    return indeksSama

```

prob2
Di sebuah perpustakaan agung, terdapat sebuah pilar besar berbentuk lingkaran yang dikelilingi oleh rak buku. Setiap buku memiliki ID unik berupa bilangan bulat, dan awalnya buku-buku tersebut disusun secara menaik berdasarkan ID. Untuk menandai awal dan akhir susunan, terdapat pembatas khusus di antara buku dengan ID terkecil dan terbesar.
Suatu hari, pembatas tersebut hilang, sehingga susunan buku tetap terurut secara relatif, tetapi tidak lagi diketahui titik awalnya. Akibatnya, urutan buku yang terlihat saat ini merupakan hasil pergeseran dari susunan semula.
Budi ingin mencari sebuah buku dengan ID X, namun kesulitan karena tidak mengetahui titik awal susunan tersebut. Bantulah Budi untuk menemukan indeks (1-based) dari buku dengan ID X dalam susunan saat ini secara efisien. Jika buku tersebut tidak ditemukan, kembalikan -1.

input
```
n = 30
Target = 160
List Buku = [148, 150, 152, 155, 158, 160, 162, 165, 168, 170, 172, 175, 178, 180, 140, 142, 144, 146, 147, 149, 151, 153, 156, 159, 161, 163, 166, 169, 171, 174]


```
expected output

```
6

```

Algoritma Fungsional
```
function cariBuku(n : integer, ListBuku : array of integer, Target : integer) -> integer
    {Kamus Lokal}
    kiri : integer
    kanan : integer
    tengah : integer
    {Algoritma}
    kiri <- 1
    kanan <- n
    while kiri <= kanan do
        tengah <- (kiri + kanan) / 2
        depend on ListBuku[tengah]:
            ListBuku[tengah] == Target:
                -> tengah
            ListBuku[tengah] < ListBuku[kanan]:
                if Target > ListBuku[tengah] and Target <= ListBuku[kanan] then
                    kiri <- tengah + 1
                else
                    kanan <- tengah - 1
            else:
                if Target >= ListBuku[kiri] and Target < ListBuku[tengah] then
                    kanan <- tengah - 1
                else
                    kiri <- tengah + 1
    -> -1
```

prob3
Di sebuah pusat analisis data, seorang analis bernama Lani sedang mempelajari pola unik dari sebuah deret angka. Deret tersebut memiliki sifat khusus: nilainya selalu meningkat secara ketat hingga mencapai satu titik tertinggi, kemudian menurun secara ketat setelahnya. Dengan kata lain, deret tersebut hanya memiliki satu puncak (peak) dan tidak ada nilai yang sama di sekitarnya.
Lani ingin mengetahui posisi puncak tersebut, namun ukuran data yang besar membuatnya tidak ingin memeriksa satu per satu. Diberikan sebuah array Ketinggian berisi n bilangan bulat dengan sifat tersebut, bantulah Lani untuk menentukan indeks (1-based) dari elemen puncak dalam array.
input
```
n = 30
Ketinggian = [5, 9, 14, 18, 23, 27, 31, 36, 40, 45, 50, 55, 60, 90, 83, 80, 77, 73, 68, 64, 59, 53, 47, 42, 37, 30, 25, 20, 15, 10]
```
expected output
```
14
```
Algoritma Fungsional
```
function cariPuncak(n : integer, Ketinggian : array of integer) -> integer
    {Kamus Lokal}
    kiri : integer
    kanan : integer
    tengah : integer
    {Algoritma}
    kiri <- 1
    kanan <- n
    while kiri <= kanan do
        tengah <- random(kiri, kanan)tengah <- (kiri + kanan) / 2
        depend on Ketinggian[tengah]:
            Ketinggian[tengah] > Ketinggian[tengah - 1] and Ketinggian[tengah] > Ketinggian[tengah + 1]:
                -> tengah
            Ketinggian[tengah] < Ketinggian[tengah - 1]:
                kanan <- tengah - 1
            else:
                kiri <- tengah + 1
    -> -1
```