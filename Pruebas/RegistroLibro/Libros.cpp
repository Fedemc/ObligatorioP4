#include "Libros.h"

///Metodos Privados
int Libros:: funcionDispercion(long int cod){
    return (cod%TAMANIO);
}

void Libros:: crearLista(nodoH *&L){
    L = NULL;
}

bool Libros:: perteneceLista(nodoH * L, long int cod){
    bool existe=false;
    while(!existe&&L!=NULL){
        if(L->info->getIsbn()==cod)
           existe = true;
        else
            L=L->sig;
    }
    return existe;
}

void Libros:: insFront(nodoH *&L,Libro*lib){
    nodoH * aux = new nodoH;
    aux->info = lib;
    aux->sig=L;
    L=aux;
}

Libro * Libros:: obtenerEnLista(nodoH * L, int cod){
    while(L->info->getIsbn()!=cod)
        L=L->sig;
    return L->info;
}

void Libros:: cargarIteradorLibros(IteradorLibros& iter){
    for(int i=0;i<TAMANIO;i++){
        while(Hash[i]!=NULL){
            printf("\n llego %d",i);
            iter.insertarLibro(Hash[i]->info);
            Hash[i]=Hash[i]->sig;
        }
    }
}

///Metodos Publicos

Libros:: Libros(){
    for(int i=0;i<TAMANIO;i++)
        crearLista(Hash[i]);
}

Libros:: ~Libros(){
}

bool Libros:: Member(long int cod){
    int cubeta = funcionDispercion(cod);
    return perteneceLista(Hash[cubeta],cod);
}

void Libros:: Insert(Libro * lib){
    long int cod = lib->getIsbn();
    int cubeta = funcionDispercion(cod);
    insFront(Hash[cubeta],lib);
}

Libro* Libros:: Find(long int cod){
    int cubeta = funcionDispercion(cod);
    return obtenerEnLista(Hash[cubeta],cod);
}

void Libros:: ListarLibros(IteradorLibros& iter){
    cargarIteradorLibros(iter);
}
