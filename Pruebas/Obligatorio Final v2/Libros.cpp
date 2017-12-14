#include "Libros.h"

///Metodos Privados
int Libros:: funcionDispersion(long int cod){
    return (cod%TAMANIO);
}

void Libros:: crearLista(nodoH *&L){
    L = NULL;
}

void Libros::destruirLista(nodoH *&L)
{
    nodoH *aux=L;
    while(aux != NULL)
    {
        L=aux->sig;
        delete (aux);
        aux=L;
    }
    L=aux;
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

void Libros:: cargarIteradorLibros(IteradorLibros &iter){
    for(int i=0;i<TAMANIO;i++)
    {
        cargarIteradorLibrosLista(Hash[i], iter);
    }
}

void Libros:: cargarIteradorLibrosLista(nodoH *L, IteradorLibros &iter)
{
    nodoH * aux = L;
    while(aux!=NULL)
    {
        iter.insertarLibro(aux->info);
        aux=aux->sig;
    }
}

void Libros:: montoVentasLibroAux(nodoH *L, float &monto)
{
    nodoH*aux=L;
    while(aux!=NULL)
    {
        Libro* auxLib=aux->info;
        monto=monto + (auxLib->PrecioVenta() * auxLib->getUnidadesVendidas());
        aux=aux->sig;
    }
}

void Libros::cantidadVentasLibroAux(nodoH* L, int &t, int &n, int &e)
{
    nodoH * aux =L;
    while(aux!=NULL)
    {
        Libro* auxLib=aux->info;
        if(auxLib->TipoLibro()=="Texto")
        {
            t=t+auxLib->getUnidadesVendidas();
        }
        else
        {
            if(auxLib->TipoLibro()=="Novela")
            {
                n=n+auxLib->getUnidadesVendidas();
            }
            else
                e=e+auxLib->getUnidadesVendidas();
        }
        aux=aux->sig;
    }
}


bool Libros::esVacioNodo(nodoH* L)
{
    bool vacio=true;
    if(L!=NULL)
        vacio=false;

    return vacio;
}

void Libros::libroMasVendidoAux(nodoH* L, Libro* &lib, int &cantVentas)
{
    nodoH * aux=L;
    while(aux!=NULL)
    {
        Libro* auxLib=aux->info;
        if(auxLib->getUnidadesVendidas() >= cantVentas)
        {
            cantVentas=auxLib->getUnidadesVendidas();
            lib=auxLib;
        }
        aux=aux->sig;
    }
}

///Metodos Publicos

Libros:: Libros(){
    for(int i=0;i<TAMANIO;i++)
        crearLista(Hash[i]);
}

Libros:: ~Libros()
{
    for(int i=0; i<TAMANIO;i++)
    {
        destruirLista(Hash[i]);
    }
}


bool Libros:: Member(long int cod){
    int cubeta = funcionDispersion(cod);
    return perteneceLista(Hash[cubeta],cod);
}

void Libros:: Insert(Libro * lib){
    long int cod = lib->getIsbn();
    int cubeta = funcionDispersion(cod);
    insFront(Hash[cubeta],lib);
}

Libro* Libros:: Find(long int cod){
    int cubeta = funcionDispersion(cod);
    return obtenerEnLista(Hash[cubeta],cod);
}

void Libros:: ListarLibros(IteradorLibros& iter){
    cargarIteradorLibros(iter);
}

float Libros::MontoTotalVentasLibros()
{
    float resu=0;

    for(int i=0;i<TAMANIO;i++)
    {
        montoVentasLibroAux(Hash[i],resu);
    }

    return resu;
}

void Libros::RegistrarVentaLibro(long int cod)
{
    Libro* auxLib=Find(cod);
    auxLib->setUnidadesVendidas();
}

void Libros::CantidadLibrosVendidosPorTipo(int &texto,int &novela,int &escolar)
{
    for(int i=0;i<TAMANIO;i++)
    {
        cantidadVentasLibroAux(Hash[i], texto, novela, escolar);
    }
}

void Libros::DatosLibroMasVendido(Libro* &lib)
{
    int cantVentas=0;

    for(int i=0;i<TAMANIO;i++)
    {
        libroMasVendidoAux(Hash[i], lib, cantVentas);
    }
}

bool Libros::diccionarioVacio()
{
    bool vacio=true;
    int i=0;

    while(vacio && i<TAMANIO)
    {
        vacio=esVacioNodo(Hash[i]);
        i++;
    }

    return vacio;
}


