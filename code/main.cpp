#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*cabezadas de las funciones*/

#include "loginn.cpp"                        //funcion de login y registro
#include "buscarUnLibroGenero.cpp"           //funcion de buscar un libro por genero
#include "hacerPrestamoDeLibro.cpp"          //funcion de hacer prestamo de un libro
#include "devolverUnLibro.cpp"               //funcion de devolver un libro
#include "verLibroPrestado.cpp"              //funcion de ver libro prestado
#include "bienvenido.cpp"                    //funcion de bienvenido
#include "buscarLirpoPorAutorNombreISBN.cpp" //funcion de buscar un libro por nombre
/**/

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
        if (strcmp(fileUsername, username) == 0)     // compare the username
            if (strcmp(filePassword, password) == 0) // compare the password
            {
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
        if (loginss() == true)
        {
            printf("Bienvenido\n");
            main();
        }
        else
        {
            printf("Cuenta o contrasena incorrecta\n");
            main();
        }
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
        buscarUnLibroGenero(); // 在这个函数里面有一加一个延迟
        break;
    case 7:
        if (loginss() == true)
        {

            std::cout << "Introduce tu tu cuenta para hacer el prestamo: ";
            std::cin >> fileName;
            strcat(newName, fileName);
            strcat(newName, ".txt");//sumar el nombre del archivo
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
            std::cout << "Introduce tu cuenta para hacer devolver el libro: ";
            std::cin >> fileName;
            strcat(newName, fileName);
            strcat(newName, ".txt");
            std::ofstream file(newName);
            /*好像会一直卡在创建文件，按照只读方法来进行读取，然后删除*/
            if(file.is_open())
            {
                // devolver el libro
                //muestra el libro prestado del usuario
                cout << "Tienes estos libros para devolver: " << endl;
                file.close();
                devolverUnLibro();
            }
            
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
            verLibroPrestado();
        }
        else
        {
            printf("No tienes acceso debido mal cuenta o contraseña\n");
            main();
        }
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

/*在出书的时候延迟一点点，判断用户有没有登录已经写好了，现在要写的就是完成那三个funciones*/
/*123 line*/