#include <stdio.h>

int buscarUnLibroGenero()
{
    printf("1. si\n2. no\n?Quieres buscar por genero?");
    int genero;
    int generos;
    const int LONGITUD_MAXIMA_LINEA = 1024;
    const int NUMERO_MAXIMO_LINEAS = 100;
    char registro[NUMERO_MAXIMO_LINEAS][LONGITUD_MAXIMA_LINEA];

    // Contador para llevar el número de líneas leídas
    int contador = 0;

    // Lee cada línea del archivo y la agrega al registro
    char linea[LONGITUD_MAXIMA_LINEA];
    scanf("%d", &genero);

    if (genero == 1)
    {
        system("cls");
        printf("1. ciencia\n2. empresa\n3. historia\n4. politica\n5. sociologia\n6. literatura\n\nque genero quieres buscar? ");
        scanf("%d", &generos);
        if (generos == 1)
        {
            printf("ciencia\n");
            ifstream archivo("../libro/ciencia.csv");
            if (!archivo.is_open())
            {
                cerr << "Error al abrir el archivo" << endl; // mostrar el error
                return 1;                                    // salir del programa
            }
            // Define un arreglo de caracteres para almacenar el registro
            while (contador < NUMERO_MAXIMO_LINEAS && archivo.getline(linea, LONGITUD_MAXIMA_LINEA))
            {
                // Copia la línea leída en el registro
                strcpy(registro[contador], linea);
                contador++;
            }
            archivo.close();

            // Muestra el contenido del registro estos puedes ser util para buscar libro por genero.
            for (int i = 0; i < contador; i++)
            {
                cout << "Libro de la ciencia: " << registro[i] << endl;
            }
        }
        if (generos == 2)
        {
            printf("empresa\n");
            ifstream archivo("../libro/empresa.csv");
            if (!archivo.is_open())
            {
                cerr << "Error al abrir el archivo" << endl; // mostrar el error
                return 1;                                    // salir del programa
            }
            // Define un arreglo de caracteres para almacenar el registro
            while (contador < NUMERO_MAXIMO_LINEAS && archivo.getline(linea, LONGITUD_MAXIMA_LINEA))
            {
                // Copia la línea leída en el registro
                strcpy(registro[contador], linea);
                contador++;
            }
            archivo.close();
            for (int i = 0; i < contador; i++)
            {
                cout << "Libro de la empresa: " << registro[i] << endl;
            }
        }
        if (generos == 3)
        {
            printf("historia\n");
            ifstream archivo("../libro/historiaPoliticaSociologia.csv");
            if (!archivo.is_open())
            {
                cerr << "Error al abrir el archivo" << endl; // mostrar el error
                return 1;                                    // salir del programa
            }
            // Define un arreglo de caracteres para almacenar el registro
            while (contador < NUMERO_MAXIMO_LINEAS && archivo.getline(linea, LONGITUD_MAXIMA_LINEA))
            {
                // Copia la línea leída en el registro
                strcpy(registro[contador], linea);
                contador++;
            }
            archivo.close();
            for (int i = 0; i < contador; i++)
            {
                cout << "Libro de la historia: " << registro[i] << endl;
            }
        }
        if (generos == 4)
        {
            printf("politica\n");
            ifstream archivo("../libro/historiaPoliticaSociologia.csv");
            if (!archivo.is_open())
            {
                cerr << "Error al abrir el archivo" << endl; // mostrar el error
                return 1;                                    // salir del programa
            }
            // Define un arreglo de caracteres para almacenar el registro
            while (contador < NUMERO_MAXIMO_LINEAS && archivo.getline(linea, LONGITUD_MAXIMA_LINEA))
            {
                // Copia la línea leída en el registro
                strcpy(registro[contador], linea);
                contador++;
            }
            archivo.close();
            for (int i = 0; i < contador; i++)
            {
                cout << "Libro de la politica: " << registro[i] << endl;
            }
        }
        if (generos == 5)
        {
            printf("sociologia\n");
            ifstream archivo("../libro/historiaPoliticaSociologia.csv");
            if (!archivo.is_open())
            {
                cerr << "Error al abrir el archivo" << endl; // mostrar el error
                return 1;                                    // salir del programa
            }
            // Define un arreglo de caracteres para almacenar el registro
            while (contador < NUMERO_MAXIMO_LINEAS && archivo.getline(linea, LONGITUD_MAXIMA_LINEA))
            {
                // Copia la línea leída en el registro
                strcpy(registro[contador], linea);
                contador++;
            }
            archivo.close();
            for (int i = 0; i < contador; i++)
            {
                cout << "Libro de la sociologia: " << registro[i] << endl;
            }
        }
        if (generos == 6)
        {
            printf("literatura\n");
            ifstream archivo("../libro/literatura.csv");
            if (!archivo.is_open())
            {
                cerr << "Error al abrir el archivo" << endl; // mostrar el error
                return 1;                                    // salir del programa
            }
            // Define un arreglo de caracteres para almacenar el registro
            while (contador < NUMERO_MAXIMO_LINEAS && archivo.getline(linea, LONGITUD_MAXIMA_LINEA))
            {
                // Copia la línea leída en el registro
                strcpy(registro[contador], linea);
                contador++;
            }
            archivo.close();
            for (int i = 0; i < contador; i++)
            {
                cout << "Libro de la literatura: " << registro[i] << endl;
            }
        }
    }
    return 0;
}
