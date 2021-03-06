#ifndef NOVELA_H_INCLUDED
#define NOVELA_H_INCLUDED
#include "Autor.h"
#include "Libro.h"


class Novela: public Libro{

private:
    String genero;
    Autor * autor;

public:

    Novela(long int, String, float, String);
    virtual ~Novela();

    String getGenero();
    Autor * getAutor();

    float PrecioVenta();
    String TipoLibro();

    //Precondicion: El autor existe en el diccionario Autores
    void AsociarAutor(Autor*);




};


#endif // NOVELA_H_INCLUDED
