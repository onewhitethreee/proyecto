#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int devolverUnLibro()
{
    char nombreArchivo[256];
    char nombreInvariable[100] = "UserLibroPrestado_";
    cout << "Ingrese tu cuenta para ver tu libro prestado: ";
    scanf("%s", nombreArchivo);
    strcat(nombreInvariable, nombreArchivo);
    strcat(nombreInvariable, ".txt");
    ifstream archivo(nombreInvariable);

    if (!archivo.is_open())
    {
        sleep(1);                                    // sleep un segundo
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
        printf("%s\n", registro[i]);
    }
    if (contador == 0)
    {
        cout << "No tienes libros prestados" << endl;
        printf("Volver al menu principal en 5 segundos\n");
        sleep(5);
    }
    else
    {
        char palabra[100];
        cout << "Ingrese el libro para devolver: ";
        cin >> palabra;
        for (int i = 0; i < contador; i++)
        {
            if (strstr(registro[i], palabra) != nullptr) // comparar si la palabra esta en el registro
            {
                cout << "quieres devolver este libro?: " << registro[i] << endl;
                char opcion;
                cout << "Si o No: ";
                cin >> opcion;
                if (opcion == 's' || opcion == 'S')
                {
                    FILE *fp = fopen(nombreInvariable, "w");
                    //truncate(nombreInvariable, 0);
                    cout << "Se ha devuelto el libro" << endl;
                }
                else
                {
                    cout << "No se ha devuelto el libro" << endl;
                }
            }
            else
            {
                cout << "No se ha encontrado el libro para devolver" << endl;
            }
        }
    }
    return 0;
}
