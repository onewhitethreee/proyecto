using namespace std;
#include <iostream>
#include "iostream"
#include "fstream"
#include "string"
#include "stdio.h"
#include "stdlib.h"

bool main_login()
{
    int cuentas;
    int contrasenas;
    int contador = 0;
    bool login = false;
    const int LONGITUD_MAXIMA_LINEA = 1024;
    const int NUMERO_MAXIMO_LINEAS = 100;
    char registro[NUMERO_MAXIMO_LINEAS][LONGITUD_MAXIMA_LINEA];
    ifstream archivo("user.txt");
    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo" << endl; // mostrar el error
        return false;                                // salir del programa
    }
    // leer el archivo
    char linea[100];
    while (archivo.getline(linea, 100)) // hasta 100 caracteres
    {
        strcpy(registro[contador], linea);
        contador++;
    }
    printf("introduzca su cuenta que quieres iniciar sesion: ");
    scanf("%d", &cuentas);
    
    printf("introduzca su contrasena que quieres iniciar sesion: ");
    scanf("%d", &contrasenas);
    for (int i = 0; i < contador; i++)
    {
        if (i % 2 == 0)
        {
            if (cuentas == atoi(registro[i]) && contrasenas == atoi(registro[i + 1]))
            {
                login = true; // si ha iniciado sesion, login = true
                break;
            }
            else
            {
                // login = false;//si no ha iniciado sesion, login = false, pero no es necesario
                break;
            }
        }
    }
    return login;
}
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
        printf("introduzca su cuenta que quieres registrar(mas de 6 digitos): ");
        scanf("%d", &accout);

        // 判断是否是6位以上的数字
        if (accout < 100000)
        {
            printf("la cuenta tiene que ser mas de 6 digitos\n");
            system("pause");
            system("clear");
            break;;
        }
        if (isalpha(accout))
        {
            printf("la cuenta solo puede ser numero\n");
            system("pause");
            system("clear");
            break;;
        }
        printf("introduzca su contrasena que quieres registrar(mas de 6 digitos): ");
        scanf("%d", &password);
        if (password < 100000)
        {
            printf("la contrasena tiene que ser mas de 6 digitos\n");
            system("pause");
            system("clear");
            break;;
        }
        if (isalpha(password))
        {
            printf("la contrasena solo puede ser numero y la cuenta tambien\n");
            system("pause");
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
            system("pause");
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