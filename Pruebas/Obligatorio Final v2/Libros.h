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

    int funcionDispersion(long int);
    void crearLista(nodoH *&);
    void destruirLista(nodoH *&);
    bool perteneceLista(nodoH *, long int);
    void insFront(nodoH *&,Libro*);
    Libro * obtenerEnLista(nodoH *, int);
    void cargarIteradorLibros(IteradorLibros&);
    void cargarIteradorLibrosLista(nodoH *, IteradorLibros&);
    void montoVentasLibroAux(nodoH*, float&);
    void cantidadVentasLibroAux(nodoH*,int&,int&,int&);
    bool esVacioNodo(nodoH*);
    void libroMasVendidoAux(nodoH*, Libro*&, int&);

public:

    Libros();
    virtual ~Libros();

    bool Member(long int);
    void Insert(Libro *);
    Libro * Find(long int);
    void ListarLibros(IteradorLibros&);
    float MontoTotalVentasLibros();
    void RegistrarVentaLibro(long int);
    void CantidadLibrosVendidosPorTipo(int&,int&,int&);
    void DatosLibroMasVendido(Libro*&);
    bool diccionarioVacio();
};





#endif // LIBROS_H_INCLUDED
