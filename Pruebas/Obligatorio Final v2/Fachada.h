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
    void ListarDatosLibro(int,TipoError&, Libro*&);
    void RegistrarAutor(Autor *, TipoError&);
    bool ExisteAutor(long int);
    void ListarAutoresRegistrados(IteradorAutores &iter);
    float MontoTotalVentas();
    void RegistrarVentaLibro(long int, TipoError&);
    void CantidadLibrosVendidosPorTipo(int&,int&,int&);
    void DatosLibroMasVendido(Libro*&, TipoError&);
    int AutoresPosteriorAFecha(Fecha);


};


#endif // FACHADA_H_INCLUDED
