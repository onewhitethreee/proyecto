#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
int main()
{
    ifstream archivo("../libro/todoLibro.csv");

    if (!archivo.is_open())
    {
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
        cout << registro[i] << endl;
    }

    // definir un char para buscar la palabra
    char palabra[100];
    cout << "Ingrese una el nombre/autor/ISBN de libro: "; // 有个大小写问题
    cin >> palabra;
    // 在registro里面有所有需要的书名，我将要定义一个i，i<contador,然后在contador里面找到书名，然后将书名的信息输出
    for (int i = 0; i < contador; i++)
    {
        if (strstr(registro[i], palabra) != nullptr)
        {                                                                     // str str是一个函数，如果找到了就返回第一个找到的位置，如果没有找到就返回空指针
            cout << "Encontrado el libro siguiente: " << registro[i] << endl; /*会有个找不到书一直循环的错误*/
        }
    }
    return 0;
}
