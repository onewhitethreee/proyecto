#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool main_login(char username[], char password[])
{
    ifstream file("user.txt");
    if (!file.is_open())
        return false;
    char fileUsername[100], filePassword[100];
    while (file >> fileUsername >> filePassword)
    {
        if (strcmp(fileUsername, username) == 0)
            return strcmp(filePassword, password) == 0;
    }
    return false;
}

void devolverUnLibro()
{
    char username[100], password[100];
    printf("Introduzca su cuenta: ");
    scanf("%s", username);
    printf("Introduzca su contrasena: ");
    scanf("%s", password);
    if (main_login(username, password))
    {
        printf("Bienvenido %s\n", username);
        // system("pause");
        system("read -p 'Press Enter to continue...' var");
    }
    else
    {
        printf("Cuenta o contrasena incorrecta\n");
        system("pause");
    }
}

