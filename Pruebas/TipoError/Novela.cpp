#include "Novela.h"

Novela::Novela(long int cod, String tit, float pb, String gen):Libro(cod,tit,pb),genero(gen){

}

Novela::~Novela(){

}

String Novela:: getGenero(){
    return genero;
}

Autor * Novela:: getAutor(){
    return autor;
}

float Novela:: PrecioVenta(){
    float total = Libro::PrecioVenta();
    if(genero=="Infantil")
        total= total*0.80;
    return total;

}

String Novela::TipoLibro(){
    return (String)("Novela");
}

void Novela::AsociarAutor(Autor *aut)
{

}
