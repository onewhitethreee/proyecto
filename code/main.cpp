#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include <unistd.h> //sleep

/*cabezadas de las funciones*/

#include "loginn.cpp"                        //funcion de login y registro
#include "buscarUnLibroGenero.cpp"           //funcion de buscar un libro por genero
#include "hacerPrestamoDeLibro.cpp"          //funcion de hacer prestamo de un libro
#include "devolverUnLibro.cpp"               //funcion de devolver un libro
#include "bienvenido.cpp"                    //funcion de bienvenido
#include "buscarLirpoPorAutorNombreISBN.cpp" //funcion de buscar un libro por nombre
/**/

bool loginss()
{
    char username[100], password[100];
    printf("Introduzca su cuenta: ");
    scanf("%s", username);
    sleep(1);
    printf("comprobando la cuenta...\n");
    printf("Introduzca su contrasena: ");
    sleep(1);
    scanf("%s", password);    
    printf("comprobando la contrasena...\n");

    ifstream file("user.txt");
    if (!file.is_open())
        return false;
    char fileUsername[100], filePassword[100];
    while (file >> fileUsername >> filePassword)
    {
        if (strcmp(fileUsername, username) == 0)     // compare the username
            if (strcmp(filePassword, password) == 0) // compare the password
            {
                sleep(3);
                printf("Bienvenido %s\n", username); // si el usuario y la contrasena son correctos
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
    char libro[100];
    char fileName[100];
    char newName[100] = "UserLibroPrestado_";

    system("clear");
    sleep(1);
    printf("Entrando al sistema...\n");
    sleep(1);
    ptr_bienvenido();
    int opcion;
    scanf("%d", &opcion);
    system("clear");
    while (getchar() != '\n')
        ; // 这里是清空缓冲区，不然会出现循环问题
    // 全部都要写上回到主函数的语句
    switch (opcion)
    {
    case 1:
        main_register();
        sleep(1);
        main(); // volver a funcion main
        break;
    case 2:
        if (loginss() == true)
        {
            printf("Bienvenido\n");
            sleep(1);
            main();
        }
        else
        {
            printf("Cuenta o contrasena incorrecta\n");
            main();
        }
    case 3:
        buscarLibroPorAutorNombreISBN();
        sleep(2);
        system("read -p 'Press Enter to continue...' var");
        main();
        break;
    case 4:
        buscarLibroPorAutorNombreISBN();
        sleep(2);
        system("read -p 'Press Enter to continue...' var");
        main();
        break;
    case 5:
        buscarLibroPorAutorNombreISBN();
        sleep(2);
        system("read -p 'Press Enter to continue...' var");
        main();
        break;
    case 6:
        buscarUnLibroGenero();
        sleep(2);
        system("read -p 'Press Enter to continue...' var");
        main();
        break;
    case 7:
        if (loginss() == true)
        {

            std::cout << "Introduce tu tu cuenta para hacer el prestamo: ";
            std::cin >> fileName;
            strcat(newName, fileName);
            strcat(newName, ".txt"); // sumar el nombre del archivo
            std::ofstream file(newName);
            if (file.is_open())
            {
                // prestamo de libro
                // preguntares el ISBN, autor, nombre o genero del libro para hacer el prestamo
                // si el usuario introduce el ISBN, autor, nombre o genero del libro para hacer el prestamo
                cout << "Introduce el ISBN, autor, nombre o genero del libro para hacer el prestamo:";
                cin >> libro;

                file << libro << std::endl;
                file.close();
                hacerPrestamoDeLibro();
                sleep(2);
                printf("Prestamo de libro exitoso\n");
                sleep(2);
                system("read -p 'Press Enter to continue...' var");
            }
        }
        else
        {
            printf("No tienes acceso debido mal cuenta o contraseña\n");
            main();
        }
        break;
    case 8:
        if (loginss() == true)
        {
            sleep(1);
            devolverUnLibro(); // falta funcion
            main();
        }

        else
        {
            printf("No tienes acceso debido mal cuenta o contraseña\n");
            main();
        }
        break;
    case 9:
        if (loginss() == true)
        {
            char nombreArchivo[256];

            cout << "Ingrese tu cuenta para ver tu libro prestado: ";
            scanf("%s", nombreArchivo);
            // cin.getline(nombreArchivo);
            char nombreInvariable[100] = "UserLibroPrestado_";
            strcat(nombreInvariable, nombreArchivo);
            strcat(nombreInvariable, ".txt");
            ifstream archivo(nombreInvariable);
            if (!archivo)
            {
                cerr << "No lo tienes libros prestado" << nombreInvariable << endl;
                return 1;
            }

            char linea[256];
            while (archivo.getline(linea, 256))
            {
                cout << "Tienes siguientes libros prestado: " << linea << endl;
                sleep(2);
                system("read -p 'Press Enter to continue...' var");
            }
            archivo.close();
            main();
            return 0;
        }
        else
        {
            printf("No tienes acceso debido mal cuenta o contraseña\n");
            main();
        }
        break;
    case 10:
        printf("Has seleccionado salir\n");
        system("read -p 'Press Enter to continue...' var");
        break;
    default:
        sleep(1);
        printf("Opcion no valida\n");
        sleep(1);
        system("read -p 'Press Enter to continue...' var");
        main();
        break;
    }
    return 0;
}