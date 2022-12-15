#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    // pregutar a usuario si quiere buscar por genero. si quiere buscar por genero, muestra todas los libros que hay en ese genero, si no lo quiere buscar por genero, pues buscar libro por nombre/autor/ISBN
    printf("1. si\n2. no\n?Quieres buscar por genero?");
    int genero;
    int generos;

    scanf("%d", &genero);
    if (genero == 1)
    {
        system("cls");
        printf("1. ciencia\n2. empresa\n3. historia\n4. politica\n5. sociologia\n6. infantil\n7. literatura\nque genero quieres buscar? ");
        scanf("%d", &generos);
        switch (generos)
        {
        case 1:
            printf("ciencia\n");
            ifstream archivo("../libro/ciencia.csv");
            if (!archivo.is_open())
            {
                cerr << "Error al abrir el archivo" << endl; // mostrar el error
                return 1;                                    // salir del programa
            }
            // Define un arreglo de caracteres para almacenar el registro
            const int LONGITUD_MAXIMA_LINEA = 1024;
            const int NUMERO_MAXIMO_LINEAS = 100;
            char registro[NUMERO_MAXIMO_LINEAS][LONGITUD_MAXIMA_LINEA];

            // Contador para llevar el número de líneas leídas
            int contador = 0;

            // Lee cada línea del archivo y la agrega al registro
            char linea[LONGITUD_MAXIMA_LINEA];
            while (contador < NUMERO_MAXIMO_LINEAS && archivo.getline(linea, LONGITUD_MAXIMA_LINEA))
            {
                // Copia la línea leída en el registro
                strcpy(registro[contador], linea);
                contador++;
            }

            // Cierra el archivo
            archivo.close();

            //Muestra el contenido del registro estos puedes ser util para buscar libro por genero.
            for (int i = 0; i < contador; i++)
            {
                cout << "Libro de la ciencia: "<<registro[i] << endl;
            }
            break;
        }
    }
    else if (genero == 2)
    {
        printf("quieres buscar por nombre/autor/ISBN?");
    }
    else
    {
        printf("parece que hay un error, por favor intenta de nuevo de forma correcta");
    }
    // Abre el archivo en modo de lectura

    // ifstream archivo("../libro/ciencia.csv");

    // // Verifica que el archivo se haya abierto correctamente
    // if (!archivo.is_open())
    // {
    //     cerr << "Error al abrir el archivo" << endl; // mostrar el error
    //     return 1;                                    // salir del programa
    // }

    // // Define un arreglo de caracteres para almacenar el registro
    // const int LONGITUD_MAXIMA_LINEA = 1024;
    // const int NUMERO_MAXIMO_LINEAS = 100;
    // char registro[NUMERO_MAXIMO_LINEAS][LONGITUD_MAXIMA_LINEA];

    // // Contador para llevar el número de líneas leídas
    // int contador = 0;

    // // Lee cada línea del archivo y la agrega al registro
    // char linea[LONGITUD_MAXIMA_LINEA];
    // while (contador < NUMERO_MAXIMO_LINEAS && archivo.getline(linea, LONGITUD_MAXIMA_LINEA))
    // {
    //     // Copia la línea leída en el registro
    //     strcpy(registro[contador], linea);
    //     contador++;
    // }

    // // Cierra el archivo
    // archivo.close();

    // // Muestra el contenido del registro estos puedes ser util para buscar libro por genero.
    // // for (int i = 0; i < contador; i++)
    // // {
    // //     cout << registro[i] << endl;
    // // }

    // // definir un char para buscar la palabra
    // char palabra[100];
    // cout << "Ingrese una el nombre/autor/ISBN de libro: "; // 有个大小写问题
    // cin >> palabra;
    // // 在registro里面有所有需要的书名，我将要定义一个i，i<contador,然后在contador里面找到书名，然后将书名的信息输出
    // for (int i = 0; i < contador; i++)
    // {
    //     if (strstr(registro[i], palabra) != nullptr)
    //     {                                                                     // str str是一个函数，如果找到了就返回第一个找到的位置，如果没有找到就返回空指针
    //         cout << "Encontrado el libro siguiente: " << registro[i] << endl; /*会有个找不到书一直循环的错误*/
    //     }
    // }
    return 0;
}
