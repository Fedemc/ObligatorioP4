#ifndef FACHADA_H_INCLUDED
#define FACHADA_H_INCLUDED
#include "Libros.h"
#include "Autores.h"
#include "TipoError.h"

class Fachada{

private:



public:
    Libros libros;
    Autores autores;
    //Autores autores;

    Fachada();
    ~Fachada();
    void RegistrarLibro(Libro*,TipoError&);
    void ListarLibrosRegistrados(IteradorLibros &iter);
    void RegistrarAutor(Autor *, TipoError&);


};


#endif // FACHADA_H_INCLUDED
