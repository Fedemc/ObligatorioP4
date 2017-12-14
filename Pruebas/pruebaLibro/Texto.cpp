#include "Texto.h"

Texto:: Texto(long int cod, String tit, int uv, float pb, String mat, Fecha fp):Libro(cod,tit,uv,pb),materia(mat),fechaPublicacion(fp){
}

Texto::~Texto(){
}

String Texto:: getMateria(){
    return materia;
}

Fecha Texto:: getFechaPublicacion(){
    return fechaPublicacion;
}

float Texto:: PrecioVenta(){
    float total = Libro::PrecioVenta();
    Fecha fec (1,1,2017);
    if(fechaPublicacion<fec)
        total= total*0.75;

    return total;
}

String Texto:: TipoLibro(){
    return (String)("Texto Comun");
}


