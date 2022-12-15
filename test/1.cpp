#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    // Abre el archivo en modo de lectura
    ifstream archivo("ciencia.csv");

    // Verifica que el archivo se haya abierto correctamente
    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    // Define un arreglo de caracteres para almacenar el registro
    const int LONGITUD_MAXIMA_LINEA = 1024;
    const int NUMERO_MAXIMO_LINEAS = 100;
    char registro[NUMERO_MAXIMO_LINEAS][LONGITUD_MAXIMA_LINEA];

    // Contador para llevar el n¨²mero de l¨ªneas le¨ªdas
    int contador = 0;

    // Lee cada l¨ªnea del archivo y la agrega al registro
    char linea[LONGITUD_MAXIMA_LINEA];
    while (contador < NUMERO_MAXIMO_LINEAS && archivo.getline(linea, LONGITUD_MAXIMA_LINEA))
    {
        // Copia la l¨ªnea le¨ªda en el registro
        strcpy(registro[contador], linea);
        contador++;
    }

    // Cierra el archivo
    archivo.close();

    // Muestra el contenido del registro
    // for (int i = 0; i < contador; i++)
    // {
    //     cout << registro[i] << endl;
    // }

    // Busca una palabra en el registro
    string palabra;
    cout << "Ingrese una palabra: ";
    cin >> palabra;
    for (int i = 0; i < contador; i++)
    {
        // Busca la palabra en la l¨ªnea
        char *posicion = strstr(registro[i], palabra.c_str());

        // Si se encuentra la palabra, la muestra en pantalla
        if (posicion != nullptr)
        {
            cout << registro[i] << "'" << endl;
        }
    }

    return 0;
}
