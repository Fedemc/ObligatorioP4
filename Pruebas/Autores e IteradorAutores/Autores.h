#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED
#include "IteradorAutores.h"

class Autores
{
    private:
        struct nodo
        {
            Autor * info;
            nodo * hIzq;
            nodo * hDer;
        };

        nodo * arbol;

        //Metodos primitivos, auxiliares para el manejo del arbol
        void destruirArbol(nodo * &);
        bool perteneceEnArbol(nodo *, long int);
        void insertEnArbol(nodo * &, Autor *);
        Autor* obtenerEnArbol(nodo *, long int);
        void cargarIteradorAutores(nodo *, IteradorAutores &);

    public:
        Autores();
        bool Member(long int);
        void Insert(Autor*);
        Autor* Find(long int);
        ~Autores();
        int AutoresPosteriorAFecha(Fecha, nodo*);
        void ListarAutoresRegistrados(IteradorAutores &);
};


#endif // AUTORES_H_INCLUDED
