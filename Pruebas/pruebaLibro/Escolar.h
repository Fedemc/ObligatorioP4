#ifndef ESCOLAR_H_INCLUDED
#define ESCOLAR_H_INCLUDED
#include "Texto.h"

class Escolar: public Texto{

private:
    int anioEscuela;

public:
    Escolar(long int, String, int, float, String, Fecha,int);
    virtual ~Escolar();

    int getAnioEscuela();

    float PrecioVenta();
    String TipoLibro();


};

#endif // ESCOLAR_H_INCLUDED
