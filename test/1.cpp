using namespace std;
#include <iostream>
#include "iostream"
#include "fstream"
#include "string"
#include "stdio.h"
#include "stdlib.h"


void save()
{
    int scount = 1;
    int accout;
    int password;
    ofstream ofile;
    ofile.open("user.txt", ios::out);
    printf("introduzca su cuenta que quieres registrar: ");
    scanf("%d", &accout);
    printf("introduzca su contrasena que quieres registrar: ");
    scanf("%d", &password);

    for (int i = 0; i < scount; i++)
    {
        ofile << accout << endl;
        ofile << password << endl;
    }
    ofile.close();
}

int main(){
    save();
}