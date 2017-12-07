#include "String.h"
#include <iostream>
using namespace std;

String::String()
{
    cadena = new char[1];
    cadena[0]='\0';
}

String::String(char *cad)
{
    int largo=strlen(cad);
    cadena = new char [largo+1];
    strcpy(cadena,cad);
}

String::~String()
{
    delete [] cadena;
}

String::String(const String &str)
{
    int largo=strlen(str.cadena);
    cadena=new char[largo+1];
    strcpy(cadena, str.cadena);
}

String String::operator=(const String &str)
{
    //Pregunto si no son el mismo (si los punteros no apuntan al mismo valor)
    if(this != &str)
    {
        delete [] cadena;
        int largo=strlen(str.cadena);
        cadena=new char[largo+1];
        strcpy(cadena,str.cadena);
    }
    return (*this);
}

bool String::operator==(String str1)
{
    return (bool) (strcmp(cadena,str1.cadena) == 0);
}

bool String::operator<(String str1)
{
    return (bool) (strcmp(cadena,str1.cadena) < 0);
}

String String::operator+(String str1)
{
    String aux;
    int largo1 = strlen(cadena);
    int largo2 = strlen(str1.cadena);
    aux.cadena = new char [largo1 + largo2 + 1];
    strcpy(aux.cadena,cadena);
    strcat(aux.cadena,str1.cadena);
    return aux;
}

String String::scan()
{
    char aux[MAX];
    char c = cin.get();
     int i=0;
     while (c!='\n' && i<MAX-1)
    {
         aux[i] = c;
         i++;
         c = cin.get();
    }
    aux[i]='\0';
    cadena = new char[i+1];
    strcpy(cadena,aux);
}

void String::print()
{
    cout << cadena;
}
