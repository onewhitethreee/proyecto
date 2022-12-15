#include "iostream"
#include "fstream"
#include "string"
#include <conio.h>
#include <cstring>

using namespace std;
int main()
{
    int cuentas;
    int contrasenas;
    int contador = 0;
    const int LONGITUD_MAXIMA_LINEA = 1024;
    const int NUMERO_MAXIMO_LINEAS = 100;
    char registro[NUMERO_MAXIMO_LINEAS][LONGITUD_MAXIMA_LINEA];
    ifstream archivo("user.txt");
    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo" << endl; // mostrar el error
        return 1;                                    // salir del programa
    }
    // leer el archivo
    char linea[100];
    // 1ÎªÕËºÅ£¬2ÎªÃÜÂë£¬3ÎªÕËºÅ£¬4ÎªÃÜÂë
    while (archivo.getline(linea, 100)) // hasta 100 caracteres
    {
        strcpy(registro[contador], linea);
        contador++;
    }
    //cout << contador << endl;//4
    //cout << registro[3] << endl;
    scanf("%d", &cuentas);
    scanf("%d", &contrasenas);
    for (int i = 0; i < contador; i++)
    {//?????????????????????1234 ????????????????????1234?????????
        int k = 1;//login??????????
        if (i % 2 == 0)//???????
        {
            k++;
            printf("dasd");
            if (cuentas == atoi(registro[k]) && contrasenas == atoi(registro[k+1]))
            {
                cout << "Has iniciado sesion" << endl;
                break;
            }
        }
        else
        {
            cout << "Has introducido mal la cuenta o la contrasena" << endl;
            break;
        }
    }
}
