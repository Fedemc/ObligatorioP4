#include "Escolar.h"

Escolar::Escolar(long int cod, String tit, float pb, String mat, Fecha fp,int anio):Texto(cod,tit,pb,mat,fp){
    anioEscuela = anio;
}

Escolar:: ~Escolar(){
}

int Escolar:: getAnioEscuela(){
    return anioEscuela;
}

float Escolar:: PrecioVenta(){
    float total = Libro::PrecioVenta();
    Fecha fec (1,1,2017);
    if(anioEscuela<4&&anioEscuela>0)
        total = total*0.90;
    else
        if(fechaPublicacion<fec)
            total = total*0.75;

    return total;
}

String Escolar:: TipoLibro(){
    return (String)("Escolar");
}
