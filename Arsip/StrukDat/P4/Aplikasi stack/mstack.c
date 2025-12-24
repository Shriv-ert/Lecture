#include <stdio.h>
#include <string.h>
#include "tstack.h"

/* procedure displayMenu()
    I.S.: - 
    F.S.: Menu ditampilkan ke layar */
void displayMenu() {
    printf("===MAJAPAHIT===\n");
    printf("1. Cari sesuatu\n");
    printf("2. Backward\n");
    printf("3. Forward\n");
    printf("4. Tampilkan status stack backward\n");
    printf("5. Tampilkan status stack forward\n");
    printf("6. Keluar\n");
    printf("Pilihan: ");
}

/* Program Utama: Search Engine
    I.S.: Program mulai berjalan
    F.S.: Program selesai dengan keluar normal */
int main() {
    Tstack undoStack, redoStack;
    createStack(&undoStack);
    createStack(&redoStack);
    
    int choice;
    char command[STRLEN];
    char temp[STRLEN];
    
    printf("Selamat datang di browser majapahit silahkan masukkan perintah\n");
    
    do {
        displayMenu();
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                printf("Silahkan cari sesuatu: ");
                fgets(command, STRLEN, stdin);
                command[strcspn(command, "\n")] = '\0'; 
                
                push(&undoStack, command);
                clearStack(&redoStack);
                printf("Anda sekarang berada di %s\n", command);
                break;
                
            case 2: 
                if (!isEmptyStack(undoStack)) {
                    pop(&undoStack, temp);
                    push(&redoStack, temp);
                    printf("Backward %s sekarang anda di %s\n", temp, infotop(undoStack));
                } else {
                    printf("Tidak ada browser yang dapat di-backward\n");
                }
                break;
                
            case 3:
                if (!isEmptyStack(redoStack)) {
                    pop(&redoStack, temp);
                    push(&undoStack, temp);
                    printf("Forward berhasil, sekarang anda di halaman '%s'\n", temp);
                } else {
                    printf("Tidak ada browser yang dapat di-forward\n");
                }
                break;
                
            case 4:
                printf("\n--- Status Stack Backward ---\n");
                printStack(undoStack);
                break;
                
            case 5:
                printf("\n--- Status Stack Forward ---\n");
                printStack(redoStack);
                break;
                
            case 6:
                printf("Keluar dari browser\n");
                break;
                
            default:
                printf("Pilihan tidak valid\n");
        }
    } while (choice != 6);
    
    return 0;
}