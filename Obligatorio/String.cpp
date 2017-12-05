#include "String.h"

String::String()
{
    cadena = new char[1];
    cadena[0]='\0';
}

String::String(char *cad)
{
    int largo=strlen(cad);
    cadena = char [largo+1];
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

String::operator=(const String &str)
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

bool String::operator==(String str1, String str2)
{
    bool iguales=false;
    if(str1==str2)
        iguales=true;
    else
    {
        if(strlen(str1)!=strlen(str2))
        {
            int i=0;
            while(i<MAX && )
        }
    }
}

bool String::operator<(String str1, String str2)
{

}

String String::operator+(String str1, String str2)
{

}

void String::print(String str)
{

}

String String::scan()
{

}
