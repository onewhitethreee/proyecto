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
    bool loginn = false;
    system("clear");
    ptr_bienvenido();
    int opcion;
    scanf("%d", &opcion);
    system("clear");
    // 这里有一个循环问题
    while (getchar() != '\n');// 这里是清空缓冲区，不然会出现循环问题
    // 全部都要写上回到主函数的语句
    switch (opcion)
    {
    case 1:
        main_register();
        main(); // volver a funcion main
        break;
    case 2:
        if (main_login() == true)
        {
            printf("Has iniciado sesion\n");
            loginn = true;
            system("pause");
            main();
        }
        else
        {
            printf("Has introducido mal la cuenta o la contrasena\n");
            system("read -p 'Press Enter to continue...' var");
            main();
        }
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
        printf("Has seleccionado devolver un libro\n");
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
/*12.15 19.27 /*解决了scanf获取非法字符的错误，解决了死循环，但是在linux下会一跳而过，要加上一个pause，解决了login和register，应该不会有错误了，要在main加入个状态判断，不然的话其他功能会用不了，会多次要求输入账号密码，在login还是会有一个scanf错误，你需要解决它*/