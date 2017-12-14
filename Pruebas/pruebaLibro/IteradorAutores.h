#ifndef ITERADORAUTORES_H_INCLUDED
#define ITERADORAUTORES_H_INCLUDED
#include "Autor.h"

class IteradorAutores
{
    private:
        struct nodoL
        {
            Autor * info;
            nodoL * sig;
        };

        nodoL * prim;
        nodoL * actual;
        nodoL * ult;

    public:
        IteradorAutores();
        void insertarAutor(Autor*);
        bool hayMasAutores();
        Autor* proxAutor();
        ~IteradorAutores();
};


#endif // ITERADORAUTORES_H_INCLUDED
