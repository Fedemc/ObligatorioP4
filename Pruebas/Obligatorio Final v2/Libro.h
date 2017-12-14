#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED
#include "String.h"
#include "Fecha.h"



class Libro{

private:
    long int isbn;
    String titulo;
    int unidadesVendidas;

public:
    float precioBase;

    Libro();
    Libro(long int, String,float);
    virtual ~Libro();

    long int getIsbn();
    String getTitulo();
    float getPrecioBase();
    int getUnidadesVendidas();

    void setUnidadesVendidas();

    virtual float PrecioVenta()=0;
    virtual String TipoLibro();
};


#endif // LIBRO_H_INCLUDED
