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
    const int LONGITUD_MAXIMA_LINEA = 1024;
    const int NUMERO_MAXIMO_LINEAS = 100;
    char registro[NUMERO_MAXIMO_LINEAS][LONGITUD_MAXIMA_LINEA];

    // Contador para llevar el n��mero de l��neas le��das
    int contador = 0;

    // Lee cada l��nea del archivo y la agrega al registro
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
                // Copia la l��nea le��da en el registro
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
        if (generos == 2){
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
                // Copia la l��nea le��da en el registro
                strcpy(registro[contador], linea);
                contador++;
            }
            archivo.close();
            for(int i = 0; i < contador; i++){
                cout << "Libro de la empresa: " << registro[i] << endl;
            }
        }
        if(generos == 3){
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
                // Copia la l��nea le��da en el registro
                strcpy(registro[contador], linea);
                contador++;
            }
            archivo.close();
            for(int i = 0; i < contador; i++){
                cout << "Libro de la historia: " << registro[i] << endl;
            }
        }
        if(generos == 4){
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
                // Copia la l��nea le��da en el registro
                strcpy(registro[contador], linea);
                contador++;
            }
            archivo.close();
            for(int i = 0; i < contador; i++){
                cout << "Libro de la politica: " << registro[i] << endl;
            }
        }
        if(generos == 5){
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
                // Copia la l��nea le��da en el registro
                strcpy(registro[contador], linea);
                contador++;
            }
            archivo.close();
            for(int i = 0; i < contador; i++){
                cout << "Libro de la sociologia: " << registro[i] << endl;
            }
        }
        if(generos == 6){
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
                // Copia la l��nea le��da en el registro
                strcpy(registro[contador], linea);
                contador++;
            }
            archivo.close();
            for(int i = 0; i < contador; i++){
                cout << "Libro de la literatura: " << registro[i] << endl;
            }
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

    Abre el archivo en modo de lectura

    ifstream archivo("../libro/ciencia.csv");

    Verifica que el archivo se haya abierto correctamente
    if (!archivo.is_open())
    {
        cerr << "Error al abrir el archivo" << endl; // mostrar el error
        return 1;                                    // salir del programa
    }

    Define un arreglo de caracteres para almacenar el registro
    const int LONGITUD_MAXIMA_LINEA = 1024;
    const int NUMERO_MAXIMO_LINEAS = 100;
    char registro[NUMERO_MAXIMO_LINEAS][LONGITUD_MAXIMA_LINEA];

    Contador para llevar el n��mero de l��neas le��das
    int contador = 0;

    Lee cada l��nea del archivo y la agrega al registro
    char linea[LONGITUD_MAXIMA_LINEA];
    while (contador < NUMERO_MAXIMO_LINEAS && archivo.getline(linea, LONGITUD_MAXIMA_LINEA))
    {
        Copia la l��nea le��da en el registro
        strcpy(registro[contador], linea);
        contador++;
    }

    Cierra el archivo
    archivo.close();

    Muestra el contenido del registro estos puedes ser util para buscar libro por genero.
    for (int i = 0; i < contador; i++)
    {
        cout << registro[i] << endl;
    }

    // definir un char para buscar la palabra
    char palabra[100];
    cout << "Ingrese una el nombre/autor/ISBN de libro: "; // �и���Сд����
    cin >> palabra;
    // ��registro������������Ҫ���������ҽ�Ҫ����һ��i��i<contador,Ȼ����contador�����ҵ�������Ȼ����������Ϣ���
    for (int i = 0; i < contador; i++)
    {
        if (strstr(registro[i], palabra) != nullptr)
        {                                                                     // str str��һ������������ҵ��˾ͷ��ص�һ���ҵ���λ�ã����û���ҵ��ͷ��ؿ�ָ��
            cout << "Encontrado el libro siguiente: " << registro[i] << endl; /*���и��Ҳ�����һֱѭ���Ĵ���*/
        }
    }
    return 0;
}
