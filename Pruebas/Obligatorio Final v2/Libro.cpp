#include "Libro.h"

Libro::Libro():titulo(){
    isbn=0;
    precioBase=0;
    unidadesVendidas=0;
}

Libro::Libro(long int cod, String tit, float pb):titulo(tit){
    isbn=cod;
    precioBase=pb;
    unidadesVendidas=0;
}

Libro:: ~Libro(){
}

long int Libro:: getIsbn(){
    return isbn;
}

String Libro:: getTitulo(){
    return titulo;
}

float Libro:: getPrecioBase(){
    return precioBase;
}

int Libro:: getUnidadesVendidas(){
    return unidadesVendidas;
}

void Libro:: setUnidadesVendidas(){
    unidadesVendidas++;
}

String Libro::TipoLibro()
{

}




