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
void handleRegister();

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

struct User users[100];
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
    printf("\nSeciminiz: ");
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

    if (strlen(username) < 6)
    {
        printf("\nKullanici adi en az 6 karakterden olusmalidir!\n");
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