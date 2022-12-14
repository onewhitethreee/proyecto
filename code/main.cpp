#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*cabezadas de las funciones*/

#include "loginn.cpp"               //funcion de login y registro
#include "buscarUnLibroNombre.cpp"  //funcion de buscar un libro por nombre
#include "buscarUnLibroAutor.cpp"   //funcion de buscar un libro por autor
#include "buscarUnLibroISBN.cpp"    //funcion de buscar un libro por ISBN
#include "buscarUnLibroGenero.cpp"  //funcion de buscar un libro por genero
#include "hacerPrestamoDeLibro.cpp" //funcion de hacer prestamo de un libro
#include "devolverUnLibro.cpp"      //funcion de devolver un libro
#include "verLibroPrestado.cpp"     //funcion de ver libro prestado
#include "bienvenido.cpp"           //funcion de bienvenido
/**/

int main()
{
    ptr_bienvenido();
    int opcion;
    scanf("%d", &opcion);
    system("clear");
    //如果是字母，会一直循环
    //这里有一个循环问题
    //全部都要写上回到主函数的语句
    switch (opcion)
    {
    case 1:
        main_register();
        main();//volver a funcion main
        break;
    case 2:
        main_login();
        main();//volver a funcion main
        break;
    case 3:
        buscarUnLibroNombre();
        break;
    case 4:
        buscarUnLibroAutor();
        break;
    case 5:
        buscarUnLibroISBN();
        break;
    case 6:
        buscarUnLibroGenero();
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
        system("pause");
        main();
        break;
    }
    return 0;
}
