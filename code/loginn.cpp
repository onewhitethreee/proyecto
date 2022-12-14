using namespace std;
#include <iostream>
#include "iostream"
#include "fstream"
#include "string"
#include "stdio.h"
#include "stdlib.h"

void main_login()
{
    int cuenta;
    int contrasena;

    printf("Has seleccionado login\n");
    printf("Introduzca su cuenta: ");
    scanf("%d", &cuenta);
    printf("Introduzca su contrasena: ");
    scanf("%d", &contrasena);
    system("clear");

    char s[100];
    FILE *fp;
    int lines = 0;
    fp = fopen("user.txt", "r"); // abrir archivo user.txt
    if (fp)                      // si el archivo user.txt existe
    {
        while ((fgets(s, 100, fp)) != NULL) // leer el archivo user.txt
        {
            if (s[strlen(s) - 1] == '\n') // si el archivo user.txt tiene una nueva linea
            {
                lines++; // contar las lineas que hay dentro de arvhivo user.txt
            }
        }
        // printf("%d\n", lines);
        // si account y consesena son iguales a las que hay en el archivo user.txt
        if (cuenta == atoi(s) && contrasena == atoi(s))
        {
            printf("Has iniciado sesion!\n");
            system("pause");
            system("clear");
        }
        else
        {
            printf("Cuenta o contrasena incorrecta\n");
            system("pause");
            system("clear");
        }
        fclose(fp); // cerrar archivo user.txt
    }
}
void main_register()
{
    int opcion;
    int accout;
    int password;
    ofstream ofile;
    printf("1. Crear una cuenta\n");
    printf("2. Salir\n");
    printf("seleccione una opcion: ");
    scanf("%d", &opcion);
    system("clear");
    switch (opcion)
    {
    case 1: // 会造成用户名重复
        ofile.open("user.txt", ios::app);
        printf("introduzca su cuenta que quieres registrar: ");
        scanf("%d", &accout);
        printf("introduzca su contrasena que quieres registrar: ");
        scanf("%d", &password);

        ofile << accout << endl;
        ofile << password << endl;
        ofile.close();
        system("clear");
        printf("Has creado una cuenta!\n");
        system("pause");
        system("clear");
        main_register();
        break;
    case 2:
        printf("Has seleccionado salir\n");
        break;
    default:
        printf("Opcion no valida\n");
        break;
    }
}