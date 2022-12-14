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
    system("cls");
    if (cuenta == 1234 && contrasena == 1234)
    {
        printf("Has iniciado sesion\n");
    }
    else
    {
        printf("Cuenta o contrasena incorrecta\n");
    }
}
void main_register()
{
    int opcion;
    int scount = 1;
    int accout;
    int password;
    ofstream ofile;
    printf("1. Crear una cuenta\n");
    printf("2. Salir\n");
    printf("seleccione una opcion: ");
    scanf("%d", &opcion);
    system("cls");
    switch (opcion)
    {
    case 1://只能注册一次
        ofile.open("user.txt", ios::out);
        printf("introduzca su cuenta que quieres registrar: ");
        scanf("%d", &accout);
        printf("introduzca su contrasena que quieres registrar: ");
        scanf("%d", &password);

        for (int i = 0; i < scount; i++)
        {
            ofile << accout << endl;
            ofile << password << endl;
        }
        ofile.close();
        system("cls");
        printf("Has creado una cuenta!\n");
        system("pause");
        system("cls");
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