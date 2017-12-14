#include "Novela.h"

Novela::Novela(long int cod, String tit, float pb, String gen):Libro(cod,tit,pb),genero(gen){
    unAutor = NULL;
}

Novela::~Novela(){

}

String Novela:: getGenero(){
    return genero;
}

Autor * Novela:: getAutor(){
    return unAutor;
}

float Novela:: PrecioVenta(){
    float total = getPrecioBase();
    if(genero=="Infantil")
        total= total*0.80;
    return total;
}

String Novela::TipoLibro(){
    return (String)("Novela");
}

