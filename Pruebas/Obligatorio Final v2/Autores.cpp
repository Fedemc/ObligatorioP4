#include "Autores.h"

///Metodos Privados

void Autores::destruirArbol(nodo * &abb)
{
    if(abb != NULL)
    {
        destruirArbol(abb->hIzq);
        destruirArbol(abb->hDer);
        delete(abb->info);
        delete (abb);
        abb= NULL;
    }
}

bool Autores::perteneceEnArbol(nodo * abb, long int ced)
{
    bool encontre=false;

    while(!encontre && abb!=NULL)
    {
        if(ced == abb->info->getCedula())
            encontre=true;
        else
        {
            if(ced < abb->info->getCedula())
                abb=abb->hIzq;
            else
                abb=abb->hDer;
        }
    }

    return encontre;
}

void Autores::insertEnArbol(nodo * &abb, Autor * aut)
{
    if(abb==NULL)
    {
        abb=new nodo;
        abb->info=aut;
        abb->hIzq=NULL;
        abb->hDer=NULL;
    }
    else
    {
        if(aut->getCedula() < abb->info->getCedula())
            insertEnArbol(abb->hIzq,aut);
        else
            insertEnArbol(abb->hDer,aut);
    }
}

Autor* Autores::obtenerEnArbol(nodo *abb, long int ced)
{
    while(ced != abb->info->getCedula())
    {
        if(ced < abb->info->getCedula())
            abb=abb->hIzq;
        else
            abb=abb->hDer;
    }

    return (abb->info);
}

void Autores::cargarIteradorAutores(nodo *abb, IteradorAutores &iterAuts)
{
    if(abb!=NULL)
    {
        cargarIteradorAutores(abb->hIzq,iterAuts);
        iterAuts.insertarAutor(abb->info);
        cargarIteradorAutores(abb->hDer,iterAuts);
    }
}

int Autores::posteriorFechaAux(nodo *abb,Fecha fec)
{
    if(abb!=NULL)
    {
        if(fec < abb->info->getFechaNacimiento())
        {
            return 1 + posteriorFechaAux(abb->hIzq,fec) + posteriorFechaAux(abb->hDer,fec);
        }
        else
            return posteriorFechaAux(abb->hIzq,fec) + posteriorFechaAux(abb->hDer,fec);
    }
    else
        return 0;
}


///Metodos publicos
Autores::Autores()
{
    arbol=NULL;
}

bool Autores::MemberA(long int ced)
{
    return perteneceEnArbol(arbol,ced);
}

void Autores::InsertA(Autor * aut)
{
    insertEnArbol(arbol,aut);
}

Autor* Autores::FindA(long int ced)
{
    return obtenerEnArbol(arbol,ced);
}

Autores::~Autores()
{
    destruirArbol(arbol);
}

int Autores::AutoresPosteriorAFecha(Fecha fec)
{
    int resu=0;
    if(arbol!=NULL)
        resu= posteriorFechaAux(arbol,fec);

    return resu;
}

//Precondicion: El iterador iterAuts pasado como parámetro viene vacío
void Autores::ListarAutoresRegistrados(IteradorAutores &iterAuts)
{
    cargarIteradorAutores(arbol,iterAuts);
}

