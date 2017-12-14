#ifndef NOVELA_H_INCLUDED
#define NOVELA_H_INCLUDED
#include "Autor.h"
#include "Libro.h"


class Novela: public Libro{

private:
    String genero;


public:

    Autor * unAutor;
    Novela(long int, String, float, String);
    virtual ~Novela();

    String getGenero();
    Autor * getAutor();

    float PrecioVenta();
    String TipoLibro();

};


#endif // NOVELA_H_INCLUDED
