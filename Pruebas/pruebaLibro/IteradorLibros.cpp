#include "IteradorLibros.h"

IteradorLibros::IteradorLibros()
{
    prim=NULL;
    actual=NULL;
    ult=NULL;
}

IteradorLibros::~IteradorLibros()
{
    nodoIterL * aux=prim;
    while(aux != NULL)
    {
        prim=prim->sig;
        delete aux;
        aux=prim;
    }
}

bool IteradorLibros::hayMasLibros()
{
    return (bool)(actual != NULL);
}

Libro* IteradorLibros::proximoLibro()
{
    Libro* resu=actual->info;
    actual=actual->sig;

    return resu;
}

void IteradorLibros::insertarLibro(Libro* l)
{
    nodoIterL * nuevo=new nodoIterL;
    nuevo->info=l;
    nuevo->sig=NULL;
    if(prim==NULL)
    {
        prim=nuevo;
        ult=nuevo;
        actual=nuevo;
    }
    else
    {
        ult->sig=nuevo;
        ult=ult->sig;
    }
}
