#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int buscarLibroPorAutorNombreISBN()
{
    ifstream archivo("../libro/todoLibro.csv");

    if (!archivo.is_open())
    {
        sleep(1);//sleep un segundo
        cerr << "Error al abrir el archivo" << endl; // mostrar el error
        return 1;                                    // salir del programa
    }

    const int LONGITUD_MAXIMA_LINEA = 1024;
    const int NUMERO_MAXIMO_LINEAS = 100;
    char registro[NUMERO_MAXIMO_LINEAS][LONGITUD_MAXIMA_LINEA];

    int contador = 0;

    char linea[LONGITUD_MAXIMA_LINEA];
    while (contador < NUMERO_MAXIMO_LINEAS && archivo.getline(linea, LONGITUD_MAXIMA_LINEA))
    {
        strcpy(registro[contador], linea);
        contador++;
    }

    archivo.close();

    for (int i = 0; i < contador; i++)
    {
            ;
    }

    // definir un char para buscar la palabra
    char palabra[100];
    cout << "Ingrese una el nombre/autor/ISBN de libro: "; // 有个大小写问题
    cin >> palabra;
    for (int i = 0; i < contador; i++)
    {
        if (strstr(registro[i], palabra) != nullptr)//comparar si la palabra esta en el registro
        {                                                          
            cout << "Encontrado el libro siguiente: " << registro[i] << endl;
        }
    }
    return 0;
}
