#include <stdio.h>

int crearUnaCuenta()
{
    int opcion;
    printf("Has introducido la opcion crear una cuenta\n");
    printf("1. Crear una cuenta\n");
    printf("2. Salir\n");
    printf("seleccione una opcion: ");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        printf("Has seleccionado crear una cuenta\n");
        break;
    case 2:
        printf("Has seleccionado salir\n");
        break;
    default:
        printf("Opcion no valida\n");
        break;
    }
    return 0;
}

int buscarUnLibroNombre()
{
    char nombre[20];
    printf("Has seleccionado buscar un libro por nombre\n");
    printf("introduce el nombre del libro\n");
    /*加入找书命令*/
    return 0;
}

int buscarUnLibroAutor()
{
    char autor[20];
    printf("Has seleccionado buscar un libro por autor\n");
    printf("introduce el nombre del autor\n");
    /*加入找书命令*/
    return 0;
}

int buscarUnLibroISBN()
{
    /*这个需要用strut来，有-和数字*/
    printf("Has seleccionado buscar un libro por ISBN\n");
    printf("introduce el ISBN del libro\n");
    /*加入找书命令*/
    return 0;
}
int buscarUnLibroGenero()
{
    char genero[20];
    printf("Has seleccionado buscar un libro por genero\n");
    printf("introduce el genero del libro\n");
    /*这里出现几个选项让用户选*/
    return 0;
}

int hacerPrestamoDeLibro()
{
    /*判断用户有没有登录*/
    printf("Has seleccionado hacer prestamo de libro\n");
    printf("introduce el ISBN, autor, nombre o genero del libro para hacer el prestamo\n");
    /*借书，创建一个文件来读取用户的借书情况。用上面的方法来查找书籍，ISBN为唯一，如果输入了autor nombre o genero 的话需要进一步的询问到底是上面书*/
    return 0;
}

int devolverUnLibro()
{
    /*判断用户有没有登录*/
    printf("Has seleccionado devolver un libro\n");
    printf("Tines siguientes libro para devolver\n");
    /*还书，需要读取用户的借书情况，这个应该会在一个txt里面或者数据库里面，然后显示有哪些书可以还，如果没有书可以还直接告诉用户没有书可还*/
    return 0;
}

int verLibroPrestado()
{
    /*判断用户有没有登录*/
    printf("Has seleccionado ver libro prestado\n");
    printf("Tines siguientes libro prestado: \n");
    /*读取用户的借书情况，这个应该会在一个txt里面或者数据库里面，然后显示有哪些书*/
    return 0;
}

int main()
{
    int opcion;
    bool seleccion = true;
    /*用户需要先进行注册才能使用功能*/
    do
    {
        printf("Bienvenido al sistema de gestion de libro\nsi no tiene una cuenta, por favor crear una para hacer el uso de sistema.\n");
        printf("\n");

        printf("0. Crear una cuenta\n");
        printf("1. login\n");
        printf("2. Buscar un libro segun su nombre\n");
        printf("3. Buscar un libro segun el autor\n");
        printf("4. Buscar un libro segun su genero\n");
        printf("5. Buscar un libro segun su ISBN\n");
        printf("6. Hacer un prestamo de libro\n");
        printf("7. Devolver un libro\n");
        printf("8. Ver los libros que tengo prestados\n");
        printf("9. pulsar cualquier otro numero o letra para salir de sistema\n");
        printf("introduce el numero de opcion que quieres hacer: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 0:
            crearUnaCuenta();
            break;
        case 1:
            printf("Has seleccionado login\n");
            /*加入登陆命令*/
            break;
        case 2:
            buscarUnLibroNombre();
            break;
        case 3:
            buscarUnLibroAutor();
            break;
        case 4:
            buscarUnLibroGenero();
            break;
        case 5:
            buscarUnLibroISBN();
            break;
        case 6:
            hacerPrestamoDeLibro();
            break;
        case 7:
            devolverUnLibro();
            break;
        case 8:
            verLibroPrestado();
            break;
        default:
            printf("Saliendo de sistema....\n");
            /*加一个定时器来延迟退出*/
        }
    } while (seleccion == false);

    return 0;
}