#ifndef ITERADORLIBROS_H_INCLUDED
#define ITERADORLIBROS_H_INCLUDED
#include "Libro.h"



class IteradorLibros
{
    private:
        struct nodoIterL
        {
            Libro * info;
            nodoIterL * sig;
        };

        nodoIterL * prim;
        nodoIterL * actual;
        nodoIterL * ult;

    public:
        IteradorLibros();
        ~IteradorLibros();
        bool hayMasLibros();
        Libro* proximoLibro();
        void insertarLibro(Libro*);
};


#endif // ITERADORLIBROS_H_INCLUDED
