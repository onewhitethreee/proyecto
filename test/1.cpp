#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include <fstream>
#include <iostream>
bool loginss()
{
    char username[100], password[100];
    printf("Introduzca su cuenta: ");
    scanf("%s", username);
    printf("Introduzca su contrasena: ");
    scanf("%s", password);
    ifstream file("user.txt");
    if (!file.is_open())
        return false;
    char fileUsername[100], filePassword[100];
    while (file >> fileUsername >> filePassword)
    {
        if (strcmp(fileUsername, username) == 0)
            if (strcmp(filePassword, password) == 0)
            {
                printf("Bienvenido %s\n", username);
                return true;
            }
            else
            {
                printf("Cuenta o contrasena incorrecta\n");
                return false;
            }
    }
    return false;
}

int main()
{
    if(loginss()==true)
    {
        printf("Bienvenido\n");
    }
    else
    {
        printf("Cuenta o contrasena incorssssssssssrecta\n");
    }

    return 0;
}