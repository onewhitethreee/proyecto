#include <fstream>
#include <string>
#include <cstring>
#include <iostream>

int main()
{
    char fileName[100];                             // Declara una variable de tipo char para almacenar el nombre del archivo
    std::cout << "Ingresa el nombre del archivo: "; // Pide al usuario que ingrese el nombre del archivo
    std::cin >> fileName;                           // Lee el nombre del archivo ingresado por el usuario
    char newName[100] = "UserLibroPrestado_";            // Declara una variable de tipo char para almacenar el nuevo nombre del archivo
    strcat(newName, fileName);                      // Concatena el nombre del archivo al final del nuevo nombre del archivo
    strcat(newName, ".txt");                        // Concatena la extensi?n ".txt" al final del nuevo nombre del archivo
    std::ofstream file(newName);                    // Crea el archivo con el nuevo nombre especificado
    if (file.is_open())
    {                                       // Comprueba si el archivo se ha abierto correctamente
        file << "Hola mundo!" << std::endl; // Escribe una l?nea de texto en el archivo
        file << "Este es un archivo de texto creado con C++." << std::endl;
        file.close(); // Cierra el archivo
    }
    return 0;
}
