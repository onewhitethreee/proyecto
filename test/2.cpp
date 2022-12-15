#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string buscar_palabra(string frase, string palabra)
{
    // Convierte la frase y la palabra a min¨²sculas
    // para evitar problemas de may¨²sculas y min¨²sculas
    transform(frase.begin(), frase.end(), frase.begin(), ::tolower);
    transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);

    // Busca la palabra en la frase
    size_t posicion = frase.find(palabra);

    // Si se encuentra la palabra, la resalta en la frase
    // Si no se encuentra la palabra, devuelve la frase sin cambios
    if (posicion != string::npos)
    {
        frase.insert(posicion, "<b>"); // Agrega etiquetas de negrita al inicio y al final de la palabra
        frase.insert(posicion + palabra.length() + 3, "</b>");
    }

    return frase;
}

int main()
{
    // Prueba la funci¨®n con diferentes frases y palabras
    cout << buscar_palabra("Hola, mundo", "mundo") << endl; // Hola, <b>mundo</b>
    cout << buscar_palabra("Hola, mundo", "Mundo") << endl; // Hola, <b>mundo</b>
    cout << buscar_palabra("Hola, mundo", "HOLA") << endl;  // <b>Hola</b>, mundo
    cout << buscar_palabra("Hola, mundo", "casa") << endl;  // Hola, mundo

    return 0;
}
