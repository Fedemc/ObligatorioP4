#include "Fachada.h"

Fachada:: Fachada():libros(),autores(){
}

Fachada:: ~Fachada(){
}

void Fachada:: RegistrarLibro(Libro* l,TipoError&error){
    error = SIN_ERROR;
    long int cod = l->getIsbn();
    if(libros.Member(cod))
        error = LIBRO_YA_EXISTE;
    else
        libros.Insert(l);
}

void Fachada:: ListarLibrosRegistrados(IteradorLibros &iter){
    libros.ListarLibros(iter);
}

void Fachada:: RegistrarAutor(Autor * aut, TipoError&error){
    error = SIN_ERROR;
    long int ced = aut->getCedula();
    if(autores.MemberA(ced))
        error=AUTOR_YA_EXISTE;
    else
        autores.InsertA(aut);

}
