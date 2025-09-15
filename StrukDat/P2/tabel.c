#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
/* Deskripsi : Realisasi modul Tabel */
/* NIM/Nama : Shofwan Fikrul Huda*/
/* Tanggal : 11/09/2025*/

/************************KONSTRUKTOR*************************/				 
/* procedure createTable( output T: Tabel)
	{I.S.: -}
	{F.S.: size=0, setiap elemen wadah dengan 1 karakter spasi, spasi dianggap karakter kosong}
	{Proses: menginisialisasi T} */
void createTable(Tabel *T){
    // kamus lokal
    // algoritma
    for (int i = 1; i <= 10; i++){
        (*T).wadah[i] = ' ';   
    }
    (*T).size = 0;
}

/************************SELEKTOR*************************/
/* function getSize( T: Tabel) -> integer
	{mengembalikan banyak elemen pengisi T } */
int getSize(Tabel T){
    // kamus lokal
    int count = 0;
    int i;
    // algoritma
    for (i = 1; i <= 10; i++){
        if (T.wadah[i] != ' '){
            count++;
        }
    }
    return count; 
}

/*************************PREDIKAT*************************/
/* function isEmptyTable( T: Tabel) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyTable(Tabel T){
    // kamus lokal
    // algoritma
    return getSize(T) == 0;
}

/* function isFullTable( T: Tabel) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullTable(Tabel T){
    // kamus lokal
    // algoritma
    return getSize(T) == 10;
}

/*************************OPERASI PENCARIAN*************************/
/*  procedure searchX (input T:Tabel, input X:character, output pos:integer )
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: pos berisi posisi ketemu di T.wadah, atau -999 jika tidak ketemu }
	{Proses: mencari elemen bernilai x dalam T.wadah} */
void searchX(Tabel T, char x, int *pos){
    // kamus lokal
    boolean found = false;
    // algoritma
    for (int i = 1; i <= getSize(T) && !found; i++){
        if (T.wadah[i] == x){
            *pos = i;
            found = true;
        }
    }
    if(!found){
        *pos = -999;
    }
}

/* function countX (T:Tabel, x:character) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam T.wadah} */
int countX(Tabel T, char x){
    // kamus lokal
    int count = 0;
    int i;
    // algoritma
    for (i = 1; i <= getSize(T); i++){
        if (T.wadah[i] == x){
            count++;
        }
    }
    return count;
}

/* function countVocal(T: Tabel) -> integer
	{mengembalikan banyak elemen T yang berupa karakter huruf vocal } */
int countVocal(Tabel T){
    // kamus lokal
    int count = 0;
    // algoritma
    for (int i = 1; i <= getSize(T); i++){
        if (T.wadah[i] == 'A' || T.wadah[i] == 'I' || T.wadah[i] == 'U' || T.wadah[i] == 'E' || T.wadah[i] == 'O'){
            count++;
        }
    }
    return count;
}

/*************************MUTATOR*************************/
/* procedure addXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai x}*/
void addXTable(Tabel *T, char x){
    // kamus lokal
    // algoritma
    if (!isFullTable(*T)){
        (*T).wadah[(*T).size + 1] = x;
        (*T).size++;
    }
}

/* procedure addUniqueXTable (input/output T:Tabel, input x: character)
	{I.S.: T terdefinisi, x terdefinisi }
	{F.S.: isi T.wadah bertambah 1 elemen jika x unik dan tabel belum penuh}
	{Proses: mengisi elemen T.wadah dengan nilai unik x}*/
void addUniqueXTable(Tabel *T, char x){
    // kamus lokal
    // algoritma
    if (!isFullTable(*T) && countX(*T, x) == 0){
        (*T).wadah[(*T).size + 1] = x;
        (*T).size++;
    }
}

/* procedure delXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi, x terdefinisi}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen bernilai x, geser semua elemen sisa}*/
void delXTable(Tabel *T, char x){
    // kamus lokal
    int i, j;
    // algoritma
    for (i = 1; (i <= (*T).size) && ((*T).wadah[i] != x); i++){
        if ((*T).wadah[i] == x){
            for(j = i; j <= (*T).size-1; j++){
                (*T).wadah[j] = (*T).wadah[j+1];
            }
        }
    }
    (*T).wadah[(*T).size] = ' ';
    (*T).size--;
}

/* procedure delTable (input/output T:Tabel, input idx:integer)
	{I.S.: T terdefinisi, idx antara 1...getSize(T)}
	{F.S.: isi T.wadah berkurang 1 elemen jika belum kosong}
	{Proses: menghapus 1 elemen pada posisi idx, geser semua elemen sisa}*/
void delTable(Tabel *T, int idx){
    // kamus lokal
    int i;
    // algoritma
    if(!isEmptyTable(*T)){
        for (i = idx; i <= (*T).size-1; i++){
            (*T).wadah[i] = (*T).wadah[i+1];
        }
        (*T).wadah[(*T).size] = ' ';
        (*T).size--;
    }
}

/* procedure delAllXTable (input/output T:Tabel, input x:character)
	{I.S.: T terdefinisi}
	{F.S.: isi T.wadah berkurang semua elemen bernilai X jika belum kosong}
	{Proses: menghapus semua elemen bernilai X, geser elemen sisa}*/
void delAllXTable(Tabel *T, char x){
    // kamus lokal
    // algoritma
    for (int i = 1; i <= 10; i++){
        if ((*T).wadah[i] == x){
            for(int j = i; j <= (*T).size-1; j++){
                (*T).wadah[j] = (*T).wadah[j+1];
            }
            if((*T).wadah[i] == x){
                i--;
            }
            (*T).wadah[(*T).size] = ' ';
            (*T).size--;
        }
    }
}

/*************************OPERASI BACA/TULIS*************************/
/* procedure printTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen T ke layar} */
void printTable(Tabel T){
    // kamus lokal
    // algoritma
    for (int i = 1; i <= 10; i++){
        printf("%c, ", T.wadah[i]);
    }
    printf("\n");
}

/* procedure viewTable (input T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen T yang terisi ke layar} */
void viewTable(Tabel T){
    // kamus lokal
    // algoritma
    for (int i = 1; i <= T.size; i++){
        if (T.wadah[i] != ' '){
            printf("%c, ", T.wadah[i]);
        }
    }
    printf("\n");
}

/* procedure populateTable (input/output T:Tabel, input N: integer)
	{I.S.: T terdefinisi, N terdefinisi dalam rentang 1..10}
	{F.S.: T.wadah terisi sebanyak N elemen }
	{Proses: mengisi elemen T.wadah sebanyak N kali dari keyboard}
	{Syarat: angka-angka masukan keyboard > 0 }*/
void populateTable(Tabel *T, int N){
    // kamus lokal
    int i;
    char input;
    // algoritma
    (*T).size = N;
    for (i = 1; i <= N; i++){
        scanf("%c", &input);
        (*T).wadah[i] = input;
    }
}

/*************************OPERASI STATISTIK*************************/
/*function Modus (T:Tabel ) -> character 
	{mengembalikan elemen pengisi T yang paling banyak muncul } */
	/*asumsi: bila terdapat banyak yang sama maka yang diambil yang pertama*/
char Modus(Tabel T){
    // kamus lokal
    int max = 0;
    int count = 0;
    int idx = 0;
    // algoritma
    for (int i = 1; i <= getSize(T); i++){
        count = countX(T, T.wadah[i]);
        if (count > max){
            max = count;
            idx = i;
        }
    }
    return T.wadah[idx];
}

/*************************OPERASI RELASIONAL*************************/
/* function IsEqualTable (T1:Tabel, T2: Table ) -> boolean 
	{mengembalikan true jika T1 memiliki elemen dan urutan yang sama dengan T2 } */
boolean isEqualTable(Tabel T1, Tabel T2){
    // kamus lokal
    // algoritma
    if(getSize(T1) != getSize(T2)){
        return false;
    }
    for (int i = 1; i <= getSize(T1); i++){
        if (T1.wadah[i] != T2.wadah[i]){
            return false;
        }
    }
    return true;
}

/*************************OPERASI LAINNYA*************************/
/* function getInverseTable(T:Tabel) -> Tabel 
	{mengembalikan tabel baru dengan isi elemen yang berkebalikan dengan tabel T } */
Tabel getInverseTable(Tabel T){
    // kamus lokal
    Tabel invT;
    // algoritma
    for (int i = 1; i <= getSize(T); i++){
        invT.wadah[getSize(T) - i + 1] = T.wadah[i];
    }
    return invT;
}

/* procedure inverseTable(input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah memiliki isi berkabalikan dengan isi tabel semula}
	{Proses: membalik isi elemen pada tabel T}*/
void inverseTable(Tabel *T){
    // kamus lokal
    Tabel invT = getInverseTable(*T);
    // algoritma
    for(int i = 1; i <= getSize(*T); i++){
        (*T).wadah[i] = invT.wadah[i];
    }
}

/*************************OPERASI PENGURUTAN*************************/
/* procedure SortAsc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad awal ke akhir}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad awal ke akhir}*/
void sortAsc(Tabel *T){
    // kamus lokal
    int i, j, temp;
    // algoritma
    for (i = 1; i <= (*T).size-1; i++){
        for (j = i+1; j <= (*T).size; j++){
            if((*T).wadah[i] > (*T).wadah[j]){
                temp = (*T).wadah[i];
                (*T).wadah[i] = (*T).wadah[j];
                (*T).wadah[j] = temp;
            }
        }
    }
    
}

/* procedure SortDesc ( input/output T:Tabel)
	{I.S.: T terdefinisi}
	{F.S.: elemen dalam T.wadah terurut dari huruf abjad akhir ke awal}
	{Proses: mengurutkan elemen dalam T.wadah dari huruf abjad akhir ke awal}*/
void sortDesc(Tabel *T){
    // kamus lokal
    int i, j, temp;
    // algoritma
    for (i = 1; i <= (*T).size-1; i++){
        for (j = i+1; j <= (*T).size; j++){
            if((*T).wadah[i] < (*T).wadah[j]){
                temp = (*T).wadah[i];
                (*T).wadah[i] = (*T).wadah[j];
                (*T).wadah[j] = temp;
            }
        }
    }
}

#endif