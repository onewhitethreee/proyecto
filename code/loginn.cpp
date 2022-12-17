using namespace std;
#include <iostream>
#include "fstream"
#include "string"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <cstring>


void main_register()
{
    int opcion;
    int accout;
    int password;
    ofstream ofile;
    bool register_ = false;
    printf("1. Crear una cuenta\n");
    printf("2. Salir\n");
    printf("seleccione una opcion: ");
    scanf("%d", &opcion);
    system("clear");
    switch (opcion)
    {
    case 1:
        ofile.open("user.txt", ios::app);
        printf("introduzca su cuenta que quieres registrar(mas de 6 digitos), no introduzca letra: ");
        scanf("%d", &accout);

        // 判断是否是6位以上的数字
        if (accout < 100000)
        {
            printf("la cuenta tiene que ser mas de 6 digitos, no introduzca letra\n");
            //system("pause");
            system("read -p 'Press Enter to continue...' var");
            system("clear");
            break;
        }

        printf("introduzca su contrasena que quieres registrar(mas de 6 digitos), no introduzca letra: ");
        scanf("%d", &password);
        if (password < 100000)
        {
            printf("la contrasena tiene que ser mas de 6 digitos, no introduzca letra\n");
            //system("pause");
            system("read -p 'Press Enter to continue...' var");
            system("clear");
            break;
        }
        else
        {
            ofile << accout << endl;
            ofile << password << endl;
            ofile.close();
            system("clear");
            printf("Has creado una cuenta!\n");
            //system("pause");
            system("read -p 'Press Enter to continue...' var");
            system("clear");
            main_register();
        }
    case 2:
        printf("Has seleccionado salir\n");
        break;
    default:
        printf("Opcion no valida\n");
        break;
    }
}