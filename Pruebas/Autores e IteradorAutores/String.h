#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <string.h>


const int MAX=40;

class String
{
    private:
        char *cadena;

    public:
        /*Constructores*/

        //Por defecto
        String();

        //Constructor comun
        String (char *);

        //Destructor
        ~String();

        //De copia
        String(const String&);

        /*Metodos*/
        //Sobrecarga del =
        String operator=(const String&);

        //Sobrecarga del ==
        bool operator==(String);

        //Sobrecarga del <
        bool operator<(String);

        //Sobrecarga del +
        String operator+(String);

        //Desplegar en pantalla una cadena
        void print();

        //Leer una cadena desde teclado
        String scan();

};


#endif // STRING_H_INCLUDED
