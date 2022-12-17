#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;

const int MAX_LENGTH = 100; // Longitud m芍xima de los nombres de usuario y contrase?as

bool login(char username[], char password[])
{
    // Abrimos el archivo de texto
    ifstream file("user.txt");

    // Si el archivo no se puede abrir, devuelve false
    if (!file.is_open())
        return false;

    // Inicializamos las variables para almacenar los datos del archivo
    char fileUsername[MAX_LENGTH], filePassword[MAX_LENGTH];

    // Iteramos sobre cada l赤nea del archivo
    while (file >> fileUsername >> filePassword)
    {
        // Si encontramos una l赤nea que coincide con el nombre de usuario dado,
        // verificamos si la contrase?a coincide con la contrase?a en la l赤nea siguiente
        if (strcmp(fileUsername, username) == 0)
            return strcmp(filePassword, password) == 0;
    }

    // Si no se encontr車 una coincidencia, devuelve false
    return false;
}

int main()
{
    // Prueba la funci車n de inicio de sesi車n
    char username[MAX_LENGTH] = "112233";
    char password[MAX_LENGTH] = "11223344";
    bool success = login(username, password);

    if (success)
    {
        cout << "Inicio de sesi車n exitoso" << endl;
    }
    else
    {
        cout << "Error de inicio de sesi車n" << endl;
    }

    return 0;
}
