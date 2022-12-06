#include "iostream"
#include "fstream"
#include "string"
#include <conio.h>
using namespace std;

#define SIZE 100 // maximo de usuarios
int scount = 0;  // usuarios registrados

// class User
class User
{
private:
    string accout;   // cuenta
    string password; // contrase?a
public:
    User(){};
    void Registers(); // registro
    void Login();     // login
    void save();      // guardar
    void read();      // leer
} us;

User user[SIZE];

// guardar
void User::save()
{
    ofstream ofile;
    ofile.open("user.txt", ios::out);

    for (int i = 0; i < scount; i++)
    {
        ofile << user[i].accout << endl;
        ofile << user[i].password << endl;
    }
    ofile.close();
}

// leer
void User::read()
{
    ifstream ifile;
    ifile.open("user.txt", ios::in);

    scount = 0;

    if (!ifile.is_open())
    {
        return;
    }

    for (int i = 0; !ifile.eof(); i++)
    {
        ifile >> user[i].accout;
        ifile >> user[i].password;
        scount++;
    }
    scount--;
    ifile.close();
}

// login
void User::Registers()
{
    us.read();  // leer
    string ph;  //cuenta
    string pw1; // contrase?a
    string pw2; // contrase?a
    for (int i = scount; i < SIZE; i++)
    {
    here:
        cout << "\t\t\tintro cuenta: ";
        cin >> ph;
        // verificar si la cuenta ya existe
        for (int i = 0; i < scount; i++)
        {
            if (ph == user[i].accout)
            {
                cout << "\t\t\t ya existe la cuenta" << endl;
                goto here;
            }
        }
        user[i].accout = ph;

        int chose = -1;
        cout << endl;
        cout << "\t\t\t©³©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©·\n";
        cout << "\t\t\t©§       1.ver passw     2.hide pa      ©§\t\n";
        cout << "\t\t\t©»©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¿\n";
        cout << "\t\t\t intro opcion: ";
        cin >> chose;
        if (chose > 2 || chose < -1)
        {
            cout << "\t\t\t opcion no valida";
            cin >> chose;
        }

        string pword;
        char ch, passwords0[20];
        int x = 0;
        string pword1;
        char ch1, passwords1[20];
        int x1 = 0;
        switch (chose)
        {
        case 1:
            cout << "\t\t\t intro passw: ";
            cin >> pword;
            user[i].password = pword;
            cout << "\t\t\t intro passw otra vez: ";
            cin >> pword1;
            if (pword1 != user[i].password)
            {
                cout << "\t\t\t las contrasenias no lo conincide" << endl;
                goto here;
            }
            else
            {
                scount++; // usuarios registrados+1
                cout << "\t\t\t registrado con exito!" << endl;
                us.save(); // guardar
            }
            break;
        case 2:
            cout << "\t\t\t intro passw:";
            while ((ch = _getch()) != '\r' && x <= 20)
            {
                if (ch == '\b')
                {
                    if (x > 0)
                    {
                        x--;
                        cout << "\b \b"; // volver a escribir
                    }
                    else
                        putchar(7);
                }
                else
                {
                    passwords0[x++] = ch;
                    printf("*");
                }
            }
            passwords0[x] = '\0';
            cout << endl;
            user[i].password = passwords0;

            cout << "\t\t\t intro passw otra vez:";
            while ((ch1 = _getch()) != '\r' && x1 <= 20)
            {
                if (ch1 == '\b')
                {
                    if (x1 > 0)
                    {
                        x1--;
                        cout << "\b \b"; // volver a escribir
                    }
                    else
                        putchar(7);
                }
                else
                {
                    passwords1[x1++] = ch1;
                    printf("*");
                }
            }
            passwords1[x1] = '\0';
            cout << endl;
            // verificar si las contrase?as coinciden
            if (passwords1 != user[i].password)
            {
                cout << "\t\t\t las contrasenias no lo coincide" << endl;
                goto here;
            }
            else
            {
                scount++; // usuarios registrados+1
                cout << "\t\t\t registrado con exito!" << endl;
                us.save(); // guardar
            }
            break;
        }
        char choice;
        cout << "\t\t\t quieres volver a registrar?:";
        while (1)
        {
            cin >> choice;
            if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
                break;
            else
                cout << "\t\t\t opcion no valida, intro otra vez:";
        }
        if (choice == 'n' || choice == 'N')
        {
            break;
        }
    }
}

// login
void User::Login()
{
    us.read();    // leer
    string ph;    //cuenta
    string pw;    // contrase?a
    int time = 0; // intentos
here:
    cout << "\t\t\t intro cuenta: ";
    cin >> ph;
    int chose = -1;
    cout << endl;
    cout << "\t\t\t©³©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©·\n";
    cout << "\t\t\t©§       1.ver contr     2.hide pas      ©§\t\n";
    cout << "\t\t\t©»©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¿\n";
    cout << "\t\t\t introduce la opcion que quieres hacer:";
    cin >> chose;
    if (chose > 2 || chose < -1)
    {
        cout << "\t\t\t opcion no valida";
        cin >> chose;
    }

    string pword;
    char ch, passwords0[20];
    int x = 0;
    switch (chose)
    {
    case 1:
        cout << "\t\t\t intro passw: ";
        cin >> pword;
        for (int i = 0; i < scount; i++)
        {
            if (ph == user[i].accout && pword == user[i].password)
            {
                time++;
                cout << "\t\t\t login con exito!" << endl;
            }
        }
        if (time == 0)
        {
            cout << "\t\t\t error de contrasenia o cuenta" << endl;
            goto here;
        }
        break;
    case 2:
        cout << "\t\t\t introduce la contrasenia: ";
        while ((ch = _getch()) != '\r' && x <= 20)
        {
            if (ch == '\b')
            {
                if (x > 0)
                {
                    x--;
                    cout << "\b \b"; //voler a escribir
                }
                else
                    putchar(7);
            }
            else
            {
                passwords0[x++] = ch;
                printf("*");
            }
        }
        passwords0[x] = '\0';
        cout << endl;
        // verificar si las contrase?as coinciden
        for (int i = 0; i < scount; i++)
        {
            if (ph == user[i].accout && passwords0 == user[i].password)
            {
                time++;
                cout << "\t\t\t login con exito!" << endl;
            }
        }
        if (time == 0)
        {
            cout << "\t\t\t erro de contrasenia o cuenta" << endl;
            goto here;
        }
        break;
    }
}

int main()
{
    User user;
    int chose = -1;
    cout << endl;
    cout << "\t\t\t©³©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©·\n";
    cout << "\t\t\t©§       1.REGISTRAR     2.LOGIN      ©§\t\n";
    cout << "\t\t\t©»©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¥©¿\n";
    cout << "\t\t\t introduce la opcion que quieres hacer:";
    cin >> chose;
    if (chose > 2 || chose < -1)
    {
        cout << "\t\t\t opcion no valida";
        cin >> chose;
    }
    switch (chose)
    {
    case 1:
        user.Registers();
        break;
    case 2:
        user.Login();
        break;
    }
}
