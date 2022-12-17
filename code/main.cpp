#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*cabezadas de las funciones*/

#include "loginn.cpp"               //funcion de login y registro
#include "buscarUnLibroGenero.cpp"  //funcion de buscar un libro por genero
#include "hacerPrestamoDeLibro.cpp" //funcion de hacer prestamo de un libro
#include "devolverUnLibro.cpp"      //funcion de devolver un libro
#include "verLibroPrestado.cpp"     //funcion de ver libro prestado
#include "bienvenido.cpp"           //funcion de bienvenido
#include "buscarLirpoPorAutorNombreISBN.cpp"  //funcion de buscar un libro por nombre
/**/

int main()
{

    system("clear");
    ptr_bienvenido();
    int opcion;
    scanf("%d", &opcion);
    system("clear");
    // 这里有一个循环问题
    while (getchar() != '\n')
        ; // 这里是清空缓冲区，不然会出现循环问题
    // 全部都要写上回到主函数的语句
    switch (opcion)
    {
    case 1:
        main_register();
        main(); // volver a funcion main
        break;
    case 2:
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
            main(); // volver a funcion main
        }
        else
        {
            printf("Cuenta o contrasena incorrecta\n");
            system("pause");
            main();
        }
        break;
    case 3:
        buscarLibroPorAutorNombreISBN();
        break;
    case 4:
        buscarLibroPorAutorNombreISBN();
        break;
    case 5:
        buscarLibroPorAutorNombreISBN();
        break;
    case 6:
        buscarUnLibroGenero();//在这个函数里面有一加一个延迟
        break;
    case 7:
        hacerPrestamoDeLibro();
        break;
    case 8:
        devolverUnLibro();
        break;
    case 9:
        verLibroPrestado();
        break;
    case 10:
        printf("Has seleccionado salir\n");
        system("pause");
        break;
    default:
        printf("Opcion no valida\n");
        // 替换为linux的pause
        system("read -p 'Press Enter to continue...' var");
        main();
        break;
    }
    return 0;
}