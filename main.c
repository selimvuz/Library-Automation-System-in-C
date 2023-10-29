#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

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

void printLoginMenu();
void handleLoginMenuChoice();
void handleMainMenuChoice();
void handleLogin();
void returnText();
void openBookText();
void initUser();
void handleRegister();
void handleMainPage();
void mainPage();
void handleBooks();
void flushInputBuffer();
void initializeBooks();
void bookOneRead();
void bookOneReadTwo();
void bookOneReadThree();
void bookOneReadFour();
void bookTwoRead();
void bookTwoReadTwo();
void bookTwoReadThree();
void bookTwoReadFour();
void bookThreeRead();
void bookThreeReadTwo();
void bookThreeReadThree();
void bookThreeReadFour();
void bookFourRead();
void bookFourReadTwo();
void bookFourReadThree();
void bookFourReadFour();
void bookFiveRead();
void bookFiveReadTwo();
void bookFiveReadThree();
void bookFiveReadFour();

enum UserType
{
    STUDENT,
    INSTRUCTOR,
    MANAGER
};

const char *userTypeStrings[] = {
    "Ogrenci",
    "Ogretmen",
    "Yonetici"};

struct User
{
    char username[100];
    char password[100];
    enum UserType type;
};

struct Book
{
    char bookName[100];
    char authorName[100];
    char publisherName[100];
    int bookID;
    bool borrowed;
    char borrowedBy[100];
};

struct User users[100];
struct Book books[10];
int numUsers = 0;
char currentUser[100];

void initializeBooks(struct Book *books)
{
    strcpy(books[0].bookName, "KrmPzt.");
    strcpy(books[0].authorName, "Gabriel Garcia");
    strcpy(books[0].publisherName, "Can Yayinlari");
    books[0].bookID = 1;
    books[0].borrowed = true;
    strcpy(books[0].borrowedBy, "yavuz");

    strcpy(books[1].bookName, "Simyaci");
    strcpy(books[1].authorName, "Paulo Coelho");
    strcpy(books[1].publisherName, "Can Yayinlari");
    books[1].bookID = 2;
    books[1].borrowed = true;
    strcpy(books[1].borrowedBy, "yavuz");

    strcpy(books[2].bookName, "1984");
    strcpy(books[2].authorName, "George Orwell");
    strcpy(books[2].publisherName, "Can Yayinlari");
    books[2].bookID = 3;
    books[2].borrowed = false;

    strcpy(books[3].bookName, "HynCft.");
    strcpy(books[3].authorName, "George Orwell");
    strcpy(books[3].publisherName, "Can Yayinlari");
    books[3].bookID = 4;
    books[3].borrowed = false;

    strcpy(books[4].bookName, "SkrPrt.");
    strcpy(books[4].authorName, "Jose Mauro De");
    strcpy(books[4].publisherName, "Can Yayinlari");
    books[4].bookID = 5;
    books[4].borrowed = true;
    strcpy(books[4].borrowedBy, "yavuz");

    strcpy(books[5].bookName, "KckPrn.");
    strcpy(books[5].authorName, "Antoine De");
    strcpy(books[5].publisherName, "Can Yayinlari");
    books[5].bookID = 6;
    books[5].borrowed = false;
}

void displayBooks(struct Book *books)
{
    printf(GREEN_TEXT "Kitap ID\tKitap Adi\tYazar Adi\t\tYayin Evi\t\tOdunc Alinmis\n" RESET_COLOR);
    for (int i = 0; i < 6; i++)
    {
        printf(BLUE_TEXT "%d\t\t%s\t\t%s\t\t%s\t\t%s\n",
               books[i].bookID,
               books[i].bookName,
               books[i].authorName,
               books[i].publisherName,
               books[i].borrowed ? "Evet" : "Hayir" RESET_COLOR);
    }
    printf(GREEN_TEXT "\n\n1) Kitap odunc al\n");
    printf("2) Kitap oku\n");
    printf("3) Geri don\n" RESET_COLOR);
    handleBooks();
}

void handleBooks()
{
    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        printf("\nHangi kitabi odunc alacaksiniz? (Kitap ID)\n");
        int bookToBorrow;
        bookToBorrow = getchar();
        flushInputBuffer();
        bookToBorrow = bookToBorrow - '0';

        if (bookToBorrow < 1 || bookToBorrow > 6)
        {
            printf("\nGecersiz kitap ID'si!\n");
            Sleep(2000);
            returnText();
            system("cls");
            displayBooks(books);
        }

        if (books[bookToBorrow - 1].borrowed)
        {
            printf("\nBu kitap zaten odunc alinmis!\n");
            Sleep(2000);
            returnText();
            system("cls");
            displayBooks(books);
        }

        books[bookToBorrow - 1].borrowed = true;
        strcpy(books[bookToBorrow - 1].borrowedBy, currentUser);

        printf("\nKitap (%s), %s tarafindan odunc alindi!\n", books[bookToBorrow - 1].bookName, currentUser);
        Sleep(2000);
        returnText();
        system("cls");
        mainPage();
        break;
    case 2:
        printf("\nHangi kitabi okumak istiyorsunuz? (Kitap ID)\n");
        int bookToRead;
        bookToRead = getchar();
        flushInputBuffer();
        bookToRead = bookToRead - '0';

        if (bookToRead < 1 || bookToRead > 6)
        {
            printf("\nGecersiz kitap ID'si!\n");
            Sleep(2000);
            returnText();
            system("cls");
            displayBooks(books);
        }
        if (bookToRead == 1)
        {
            system("cls");
            openBookText();
            bookOneRead();
        }
        else if (bookToRead == 2)
        {
            system("cls");
            openBookText();
            bookFiveRead();
        }
        else if (bookToRead == 3)
        {
            system("cls");
            openBookText();
            bookFourRead();
        }
        else if (bookToRead == 4)
        {
            system("cls");
            openBookText();
            bookTwoRead();
        }
        else if (bookToRead == 5)
        {
            system("cls");
            openBookText();
            //
        }
        else if (bookToRead == 6)
        {
            system("cls");
            openBookText();
            bookThreeRead();
        }
        break;
    case 3:
        system("cls");
        returnText();
        mainPage();
        break;
    default:
        printf("Gecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        displayBooks(books);
    }
}

void bookOneRead()
{
    // Declare a file pointer
    FILE *file;

    // Open the file in read mode
    file = fopen(".././Books/KirmiziPazartesi/KP-Sayfa-1.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 1\n\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookOneReadTwo();
        break;
    case 2:
        system("cls");
        mainPage();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookOneRead();
    }
}

void bookOneReadTwo()
{
    // Declare a file pointer
    FILE *file2;

    // Open the file in read mode
    file2 = fopen(".././Books/KirmiziPazartesi/KP-Sayfa-2.txt", "r");

    // Check if the file was opened successfully
    if (file2 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 2\n\n");

    while (fgets(buffer, sizeof(buffer), file2) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file2);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookOneReadThree();
        break;
    case 2:
        system("cls");
        bookOneRead();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookOneReadTwo();
    }
}

void bookOneReadThree()
{
    // Declare a file pointer
    FILE *file3;

    // Open the file in read mode
    file3 = fopen(".././Books/KirmiziPazartesi/KP-Sayfa-3.txt", "r");

    // Check if the file was opened successfully
    if (file3 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 3\n\n");

    while (fgets(buffer, sizeof(buffer), file3) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file3);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookOneReadFour();
        break;
    case 2:
        system("cls");
        bookOneReadTwo();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookOneReadThree();
    }
}

void bookOneReadFour()
{
    // Declare a file pointer
    FILE *file4;

    // Open the file in read mode
    file4 = fopen(".././Books/KirmiziPazartesi/KP-Sayfa-4.txt", "r");

    // Check if the file was opened successfully
    if (file4 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 4\n\n");

    while (fgets(buffer, sizeof(buffer), file4) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file4);

    printf("\n\n1) Ana menuye don\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        mainPage();
        break;
    case 2:
        system("cls");
        bookOneReadThree();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookOneReadFour();
    }
}

void bookTwoRead()
{
    // Declare a file pointer
    FILE *file;

    // Open the file in read mode
    file = fopen(".././Books/HayvanCiftligi/HC-Sayfa-1.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 1\n\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookTwoReadTwo();
        break;
    case 2:
        system("cls");
        mainPage();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookTwoRead();
    }
}

void bookTwoReadTwo()
{
    // Declare a file pointer
    FILE *file2;

    // Open the file in read mode
    file2 = fopen(".././Books/HayvanCiftligi/HC-Sayfa-2.txt", "r");

    // Check if the file was opened successfully
    if (file2 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 2\n\n");

    while (fgets(buffer, sizeof(buffer), file2) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file2);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookTwoReadThree();
        break;
    case 2:
        system("cls");
        bookTwoRead();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookTwoReadTwo();
    }
}

void bookTwoReadThree()
{
    // Declare a file pointer
    FILE *file3;

    // Open the file in read mode
    file3 = fopen(".././Books/HayvanCiftligi/HC-Sayfa-3.txt", "r");

    // Check if the file was opened successfully
    if (file3 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 3\n\n");

    while (fgets(buffer, sizeof(buffer), file3) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file3);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookTwoReadFour();
        break;
    case 2:
        system("cls");
        bookTwoReadTwo();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookTwoReadThree();
    }
}

void bookTwoReadFour()
{
    // Declare a file pointer
    FILE *file4;

    // Open the file in read mode
    file4 = fopen(".././Books/HayvanCiftligi/HC-Sayfa-4.txt", "r");

    // Check if the file was opened successfully
    if (file4 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 4\n\n");

    while (fgets(buffer, sizeof(buffer), file4) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file4);

    printf("\n\n1) Ana menuye don\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        mainPage();
        break;
    case 2:
        system("cls");
        bookTwoReadThree();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookTwoReadFour();
    }
}

void bookThreeRead()
{
    // Declare a file pointer
    FILE *file;

    // Open the file in read mode
    file = fopen(".././Books/KucukPrens/KP-Sayfa-1.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 1\n\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookThreeReadTwo();
        break;
    case 2:
        system("cls");
        mainPage();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookThreeRead();
    }
}

void bookThreeReadTwo()
{
    // Declare a file pointer
    FILE *file2;

    // Open the file in read mode
    file2 = fopen(".././Books/KucukPrens/KP-Sayfa-2.txt", "r");

    // Check if the file was opened successfully
    if (file2 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 2\n\n");

    while (fgets(buffer, sizeof(buffer), file2) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file2);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookThreeReadThree();
        break;
    case 2:
        system("cls");
        bookThreeRead();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookThreeReadTwo();
    }
}

void bookThreeReadThree()
{
    // Declare a file pointer
    FILE *file3;

    // Open the file in read mode
    file3 = fopen(".././Books/KucukPrens/KP-Sayfa-3.txt", "r");

    // Check if the file was opened successfully
    if (file3 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 3\n\n");

    while (fgets(buffer, sizeof(buffer), file3) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file3);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookThreeReadFour();
        break;
    case 2:
        system("cls");
        bookThreeReadTwo();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookThreeReadThree();
    }
}

void bookThreeReadFour()
{
    // Declare a file pointer
    FILE *file4;

    // Open the file in read mode
    file4 = fopen(".././Books/KucukPrens/KP-Sayfa-4.txt", "r");

    // Check if the file was opened successfully
    if (file4 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 4\n\n");

    while (fgets(buffer, sizeof(buffer), file4) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file4);

    printf("\n\n1) Ana menuye don\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        mainPage();
        break;
    case 2:
        system("cls");
        bookThreeReadThree();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookThreeReadFour();
    }
}

void bookFourRead()
{
    // Declare a file pointer
    FILE *file;

    // Open the file in read mode
    file = fopen(".././Books/1984/Sayfa-1.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 1\n\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookFourReadTwo();
        break;
    case 2:
        system("cls");
        mainPage();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookFourRead();
    }
}

void bookFourReadTwo()
{
    // Declare a file pointer
    FILE *file2;

    // Open the file in read mode
    file2 = fopen(".././Books/1984/Sayfa-2.txt", "r");

    // Check if the file was opened successfully
    if (file2 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 2\n\n");

    while (fgets(buffer, sizeof(buffer), file2) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file2);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookFourReadThree();
        break;
    case 2:
        system("cls");
        bookFourRead();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookFourReadTwo();
    }
}

void bookFourReadThree()
{
    // Declare a file pointer
    FILE *file3;

    // Open the file in read mode
    file3 = fopen(".././Books/1984/Sayfa-3.txt", "r");

    // Check if the file was opened successfully
    if (file3 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 3\n\n");

    while (fgets(buffer, sizeof(buffer), file3) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file3);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookFourReadFour();
        break;
    case 2:
        system("cls");
        bookFourReadTwo();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookFourReadThree();
    }
}

void bookFourReadFour()
{
    // Declare a file pointer
    FILE *file4;

    // Open the file in read mode
    file4 = fopen(".././Books/1984/Sayfa-4.txt", "r");

    // Check if the file was opened successfully
    if (file4 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 4\n\n");

    while (fgets(buffer, sizeof(buffer), file4) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file4);

    printf("\n\n1) Ana menuye don\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        mainPage();
        break;
    case 2:
        system("cls");
        bookFourReadThree();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookFourReadFour();
    }
}

void bookFiveRead()
{
    // Declare a file pointer
    FILE *file;

    // Open the file in read mode
    file = fopen(".././Books/Simyaci/Sayfa-1.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 1\n\n");

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookFiveReadTwo();
        break;
    case 2:
        system("cls");
        mainPage();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookFiveRead();
    }
}

void bookFiveReadTwo()
{
    // Declare a file pointer
    FILE *file2;

    // Open the file in read mode
    file2 = fopen(".././Books/Simyaci/Sayfa-2.txt", "r");

    // Check if the file was opened successfully
    if (file2 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 2\n\n");

    while (fgets(buffer, sizeof(buffer), file2) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file2);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookFiveReadThree();
        break;
    case 2:
        system("cls");
        bookFiveRead();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookFiveReadTwo();
    }
}

void bookFiveReadThree()
{
    // Declare a file pointer
    FILE *file3;

    // Open the file in read mode
    file3 = fopen(".././Books/Simyaci/Sayfa-3.txt", "r");

    // Check if the file was opened successfully
    if (file3 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 3\n\n");

    while (fgets(buffer, sizeof(buffer), file3) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file3);

    printf("\n\n1) Sonraki sayfa\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        bookFiveReadFour();
        break;
    case 2:
        system("cls");
        bookFiveReadTwo();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookFiveReadThree();
    }
}

void bookFiveReadFour()
{
    // Declare a file pointer
    FILE *file4;

    // Open the file in read mode
    file4 = fopen(".././Books/Simyaci/Sayfa-4.txt", "r");

    // Check if the file was opened successfully
    if (file4 == NULL)
    {
        perror("Bir seyler ters gitti");
        exit(EXIT_FAILURE);
    }

    // Read and print the contents of the file
    char buffer[80]; // Create a buffer to store each line

    system("cls");
    printf("Sayfa 4\n\n");

    while (fgets(buffer, sizeof(buffer), file4) != NULL)
    {
        printf("%s", buffer);
    }

    // Close the file
    fclose(file4);

    printf("\n\n1) Ana menuye don\n");
    printf("2) Geri don\n");

    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        mainPage();
        break;
    case 2:
        system("cls");
        bookFiveReadThree();
        break;
    default:
        printf("\nGecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        bookFiveReadFour();
    }
}

void initUser(struct User *user, const char *username, const char *password, enum UserType type)
{
    strcpy(user->username, username);
    strcpy(user->password, password);
    user->type = type;
}

struct User *createUser(const char *username, const char *password, enum UserType type)
{
    struct User *user = (struct User *)malloc(sizeof(struct User));
    initUser(user, username, password, type);
    return user;
}

struct User *findUser(const char *username, const char *password, enum UserType type)
{
    for (int i = 0; i < numUsers; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0 && users[i].type == type)
        {
            return &users[i];
        }
    }
    return NULL; // User not found
}

void printUser(struct User *user)
{
    printf("Kullanici Adi: %s\n", user->username);
    printf("Sifre: %s\n", user->password);
    printf("Rol: %s\n", userTypeStrings[user->type]);
}

void flushInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void printMainMenu()
{
    printf(GREEN_TEXT "--Kutuphane Otomasyon Sistemi--" RESET_COLOR "\n");
    printf(BLUE_TEXT "1) Giris" RESET_COLOR "\n");
    printf(YELLOW_TEXT "2) Kayit" RESET_COLOR "\n");
    printf(MAGENTA_TEXT "3) Hakkinda" RESET_COLOR "\n");
    printf(CYAN_TEXT "4) Cikis" RESET_COLOR "\n");
    printf(GREEN_TEXT "\nSeciminiz: " RESET_COLOR);
    handleMainMenuChoice();
}

void returnText()
{
    system("cls");
    printf("Geri donuluyor.\n");
    Sleep(200);
    system("cls");
    printf("Geri donuluyor..\n");
    Sleep(200);
    system("cls");
    printf("Geri donuluyor...\n");
    Sleep(200);
    system("cls");
    printf("Geri donuluyor....\n");
    Sleep(200);
    system("cls");
    printf("Geri donuluyor.....\n");
    Sleep(200);
    system("cls");
}

void openBookText()
{
    system("cls");
    printf("Kitap aciliyor.\n");
    Sleep(200);
    system("cls");
    printf("Kitap aciliyor..\n");
    Sleep(200);
    system("cls");
    printf("Kitap aciliyor...\n");
    Sleep(200);
    system("cls");
    printf("Kitap aciliyor....\n");
    Sleep(200);
    system("cls");
    printf("Kitap aciliyor.....\n");
    Sleep(200);
    system("cls");
}

void loginText()
{
    system("cls");
    printf("Giris yapiliyor.\n");
    Sleep(200);
    system("cls");
    printf("Giris yapiliyor..\n");
    Sleep(200);
    system("cls");
    printf("Giris yapiliyor...\n");
    Sleep(200);
    system("cls");
    printf("Giris yapiliyor....\n");
    Sleep(200);
    system("cls");
    printf("Giris yapiliyor.....\n");
    Sleep(200);
    system("cls");
}

void handleMainMenuChoice()
{
    int choice;
    choice = getchar();    // Read a character
    flushInputBuffer();    // Flush the input buffer
    choice = choice - '0'; // Convert character to integer

    switch (choice)
    {
    case 1:
        printLoginMenu();
        break;
    case 2:
        system("cls");
        printf("\nKayit arayuzu\n");
        handleRegister();
        break;
    case 3:
        system("cls");
        printf("Hakkinda");
        printf("\n\nKutuphane Otomasyon Sistemi\n");
        printf("\nIleri programlama teknikleri ders projesi olarak Yavuz Selim Dogdu tarafindan hazirlanmistir.");
        printf("\nProje icerisinde kullanilan tum kodlar ve kaynaklar github.com/selimvuz adresinde bulunmaktadir.");
        printf("\n\n2023");
        Sleep(5000);
        returnText();
        printMainMenu();
        break;
    case 4:
        exit(0);
    default:
        printf("Gecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        printMainMenu();
    }
}

void printLoginMenu()
{
    system("cls");
    printf(GREEN_TEXT "--Giris--" RESET_COLOR "\n");
    printf(BLUE_TEXT "----1.1) Ogrenci" RESET_COLOR "\n");
    printf(YELLOW_TEXT "----1.2) Personel" RESET_COLOR "\n");
    printf(MAGENTA_TEXT "----1.3) Yonetici" RESET_COLOR "\n");
    printf(CYAN_TEXT "----1.4) Geri don" RESET_COLOR "\n");
    printf(GREEN_TEXT "\nSeciminiz: " RESET_COLOR);
    handleLoginMenuChoice();
}

void handleLoginMenuChoice()
{
    int choice;
    choice = getchar();
    flushInputBuffer();
    choice = choice - '0';

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Ogrenci girisi\n");
        handleLogin(STUDENT);
        break;
    case 2:
        system("cls");
        printf("Personel girisi\n");
        handleLogin(INSTRUCTOR);
        break;
    case 3:
        system("cls");
        printf("Yonetici girisi\n");
        handleLogin(MANAGER);
        break;
    case 4:
        returnText();
        printMainMenu();
        break;
    default:
        printf("Gecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        printLoginMenu();
    }
}

void handleRegister()
{
    printf("\nKullanici adi: ");
    char username[100];
    scanf("%10s", username);
    flushInputBuffer();

    if (strlen(username) < 4)
    {
        printf("\nKullanici adi en az 4 karakterden olusmalidir!\n");
        Sleep(2000);
        returnText();
        system("cls");
        printMainMenu();
    }
    else if (strlen(username) > 10)
    {
        printf("\nKullanici adi en fazla 10 karakterden olusmalidir!\n");
        Sleep(2000);
        returnText();
        system("cls");
        printMainMenu();
    }

    for (int i = 0; i < numUsers; i++)
    {
        if (strcmp(users[i].username, username) == 0)
        {
            printf("\nBu kullanici adi zaten alinmis!\n");
            Sleep(2000);
            returnText();
            system("cls");
            printMainMenu();
        }
    }

    printf("\nSifre: ");
    char password[100];
    scanf("%10s", password);
    flushInputBuffer();

    if (strlen(password) < 6)
    {
        printf("\nSifre en az 6 karakterden olusmalidir!\n");
        Sleep(2000);
        returnText();
        system("cls");
        printMainMenu();
    }
    else if (strlen(password) > 10)
    {
        printf("\nSifre en fazla 10 karakterden olusmalidir!\n");
        Sleep(2000);
        returnText();
        system("cls");
        printMainMenu();
    }

    printf("\nSifre tekrar: ");
    char password2[100];
    scanf("%10s", password2);
    flushInputBuffer();

    if (strcmp(password, password2) != 0)
    {
        printf("\nSifreler uyusmuyor!\n");
        Sleep(2000);
        returnText();
        system("cls");
        printMainMenu();
    }

    printf("\nRol: (1: Ogrenci, 2: Personel, 3: Yonetici)\n");
    int role;
    scanf("%d", &role);
    flushInputBuffer();

    if (role < 1 || role > 3)
    {
        printf("\nGecersiz rol!\n");
        Sleep(2000);
        returnText();
        system("cls");
        printMainMenu();
    }

    users[numUsers++] = *createUser(username, password, role - 1);
    printf("\nKayit basarili!\n");
    Sleep(2000);
    returnText();
    printMainMenu();
}

void handleLogin(int roleType)
{
    printf("\nKullanici adi: ");
    char username[100];
    scanf("%10s", username);
    flushInputBuffer();

    printf("\nSifre: ");
    char password[100];
    scanf("%10s", password);
    flushInputBuffer();

    struct User *user = findUser(username, password, roleType);
    if (user != NULL)
    {
        loginText();
        printf("Giris basarili!\n");
        strcpy(currentUser, user->username);
        Sleep(2000);
        system("cls");
        mainPage();
    }
    else
    {
        loginText();
        printf("Kullanici adi veya sifre hatali!\n");
        Sleep(2000);
        returnText();
        system("cls");
        printLoginMenu();
    }
}

void mainPage()
{
    system("cls");
    printf(GREEN_TEXT "\t\t--Ana Sayfa--\t\t" RESET_COLOR "\n");
    printf("\nHosgeldiniz, ");
    printf(GREEN_TEXT "%s!\n\n" RESET_COLOR, currentUser);
    printf(BLUE_TEXT "1) Kitaplar" RESET_COLOR "\n");
    printf(YELLOW_TEXT "2) Kitap iade et" RESET_COLOR "\n");
    printf(MAGENTA_TEXT "3) Kitap bagisla" RESET_COLOR "\n");
    printf(CYAN_TEXT "4) Geri don" RESET_COLOR "\n");
    printf(GREEN_TEXT "\nSeciminiz: " RESET_COLOR);
    handleMainPage();
}

void handleMainPage()
{
    int choice;
    choice = getchar();    // Read a character
    flushInputBuffer();    // Flush the input buffer
    choice = choice - '0'; // Convert character to integer

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Kitaplar\t\t\t\t\t\t\t\t(Kullanici: %s)\n\n", currentUser);
        displayBooks(books);
        break;
    case 2:
        system("cls");
        printf("Kitap iade et\n");
        break;
    case 3:
        system("cls");
        printf("Kitap bagisla\n");
        break;
    case 4:
        returnText();
        printMainMenu();
        break;
    default:
        printf("Gecersiz secim. Tekrar deneyin.\n");
        Sleep(2000);
        system("cls");
        printMainMenu();
    }
}

int main()
{
    users[numUsers++] = *createUser("yavuz", "123", STUDENT);
    initializeBooks(books);

    system("cls");
    printMainMenu();

    return 0;
}