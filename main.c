#include <stdio.h>
#include <stdlib.h>

// ANSI escape codes for color
#define BLACK_TEXT "\033[0;30m"
#define RED_TEXT "\033[0;31m"
#define GREEN_TEXT "\033[0;32m"
#define YELLOW_TEXT "\033[0;33m"
#define BLUE_TEXT "\033[0;34m"
#define MAGENTA_TEXT "\033[0;35m"
#define CYAN_TEXT "\033[0;36m"
#define WHITE_TEXT "\033[0;37m"

#define RESET_COLOR "\033[0m"

void flushInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    int choice;
    int control = 1;
    system("cls"); // Clear the screen

    while (control)
    {
        printf(GREEN_TEXT "--Kutuphane Otomasyon Sistemi--" RESET_COLOR "\n");
        printf(BLUE_TEXT "1. Giris" RESET_COLOR "\n");
        printf(YELLOW_TEXT "2. Kayit" RESET_COLOR "\n");
        printf(MAGENTA_TEXT "3. Hakkinda" RESET_COLOR "\n");
        printf(CYAN_TEXT "4. Cikis" RESET_COLOR "\n");
        printf("\nSeciminiz: ");

        choice = getchar(); // Read a character
        choice = choice - '0'; // Convert character to integer

        flushInputBuffer(); // Consume newline character

        switch (choice)
        {
        case 1:
            control = 0;
            system("cls"); // Clear the screen
            printf("\nGiris yapiliyor");
            break;
        case 2:
            printf("\nKayit arayuzu");
            break;
        case 3:
            printf("\nBilgiler");
            break;
        case 4:
            return 0;
        default:
            system("cls"); // Clear the screen
            printf("Gecersiz secim. Tekrar deneyin.\n");
        }
    }
    return 0;
}