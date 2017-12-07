#include "IteradorAutores.h"

IteradorAutores::IteradorAutores()
{
    prim = NULL;
    actual= NULL;
    ult= NULL;
}

void IteradorAutores::insertarAutor(Autor *aut)
{
    nodoL * nuevo= new nodoL;
    nuevo->info=aut;
    nuevo->sig=NULL;
    if(prim == NULL)
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

bool IteradorAutores::hayMasAutores()
{
    return (bool)(actual!=NULL);
}

Autor* IteradorAutores::proxAutor()
{
    Autor* autAux=actual->info;
    actual=actual->sig;
    return autAux;
}

IteradorAutores::~IteradorAutores()
{
    nodoL * aux=prim;
    while(aux != NULL)
    {
        prim=prim->sig;
        delete aux;
        aux=prim;
    }
}
