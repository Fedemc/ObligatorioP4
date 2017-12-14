#ifndef TEXTO_H_INCLUDED
#define TEXTO_H_INCLUDED
#include "Libro.h"
#include "Fecha.h"

class Texto: public Libro{

private:
    String materia;


public:
    Fecha fechaPublicacion;

    Texto(long int, String, int, float,String,Fecha);
    ~Texto();
    String getMateria();
    Fecha getFechaPublicacion();

    float PrecioVenta();
    String TipoLibro();
};


#endif // TEXTO_H_INCLUDED
