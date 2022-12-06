#include "iostream"
#include "fstream"
#include "string"
#include <conio.h>
using namespace std;

#define SIZE 100 // max users
int scout = 0;   // para almacenar los usaarios registrados

class User
{
private:
    string accout;
    string password;

public:
    User(){};
    void Register();
    void login();
    void save();
    void read();
} us;
User user[SIZE];

void User::save()
{ // guardar los datos de los usuarios
    ofstream ofile;
    ofile.open("user.txt", ios::out);

    for (int i = 0; i < scout; i++)
    {
        ofile << user[i].accout << endl;
        ofile << user[i].password << endl;
    }
    ofile.close();
}

void User::read()
{ // leer los datos de los usuarios
    ifstream ifile;
    ifile.open("user.txt", ios::in);

    scout = 0;

    if (!ifile.is_open())
    {
        return;
    }

    for (int i = 0; !ifile.eof(); i++)
    {
        ifile >> user[i].accout;
        ifile >> user[i].password;
        scout++;
    }
    scout--;
}

void User::Register()
{
    us.read();
    string accout;
    string password;
    string password2;
    for (int i = scout; i < SIZE; i++)
    {
    hre:
        printf("introduce el nombre/numero del usario que quieres registrar: ");
        scanf("%s", &accout);
        for (int j = 0; j < scout; j++)
        {
            if (accout == user[j].accout)
            {
                printf("el nombre de usuario ya existe, introduce otro nombre de usuario: ");
                goto hre;
            }
        }user[i].accout = accout;
        string pword;
        char ch, passwords[20];
        int x = 0;
        
    }
}