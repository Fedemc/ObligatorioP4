#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED
#include "IteradorLibros.h"
#include "Libro.h"


const int TAMANIO = 100;

class Libros{

private:
    struct nodoH {
        Libro * info;
        nodoH * sig;
    };
    nodoH * Hash[TAMANIO];

    int funcionDispercion(long int);
    void crearLista(nodoH *&);
    bool perteneceLista(nodoH *, long int);
    void insFront(nodoH *&,Libro*);
    Libro * obtenerEnLista(nodoH *, int);
    void cargarIteradorLibros(IteradorLibros&);

public:

    Libros();
    virtual ~Libros();

    bool Member(long int);
    void Insert(Libro *);
    Libro * Find(long int);
    void ListarLibros(IteradorLibros&);
};





#endif // LIBROS_H_INCLUDED
