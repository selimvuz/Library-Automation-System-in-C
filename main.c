#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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
void initUser();

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
    char username[50];
    char password[50];
    enum UserType type;
};

struct User users[10];
int numUsers = 0;

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

struct User *findUser(const char *username, const char *password)
{
    for (int i = 0; i < numUsers; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
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
    printf("\nSeciminiz: ");
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

void handleMainMenuChoice()
{
    int choice;
    choice = getchar();    // Read a character
    choice = choice - '0'; // Convert character to integer
    flushInputBuffer();    // Consume newline character

    switch (choice)
    {
    case 1:
        printLoginMenu();
        break;
    case 2:
        printf("\nKayit arayuzu");
        break;
    case 3:
        printf("\nBilgiler");
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
    printf("\nSeciminiz: ");
    handleLoginMenuChoice();
}

void handleLoginMenuChoice()
{
    int choice;
    choice = getchar();
    choice = choice - '0';
    flushInputBuffer();

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Ogrenci girisi\n");
        handleLogin();
        break;
    case 2:
        printf("Personel girisi\n");
        break;
    case 3:
        printf("Yonetici girisi\n");
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

void handleLogin()
{
    printf("\nKullanici adi: ");
    char username[20];
    scanf("%s", username);

    printf("\nSifre: ");
    char password[20];
    scanf("%s", password);

    struct User *user = findUser(username, password);
    if (user != NULL)
    {
        printf("\nGiris basarili!\n");
        printUser(user); // Print user details if needed
    }
    else
    {
        printf("\nKullanici adi veya sifre hatali!\n");
        Sleep(2000);
        returnText();
        system("cls");
        printLoginMenu();
    }
}

int main()
{
    users[numUsers++] = *createUser("john_doe", "password123", STUDENT);

    system("cls");
    printMainMenu();

    return 0;
}