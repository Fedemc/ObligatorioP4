#include "Fachada.h"

Fachada:: Fachada():libros(),autores(){
}

Fachada:: ~Fachada(){
}

void Fachada:: RegistrarLibro(Libro* l,TipoError &error){
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

void Fachada::ListarDatosLibro(int cod,TipoError &err, Libro* &lib)
{
    err==SIN_ERROR;
    if(libros.Member(cod))
    {
        lib=libros.Find(cod);
    }
    else
    {
        err=LIBRO_NO_EXISTE;
    }
}

void Fachada:: RegistrarAutor(Autor * aut, TipoError&error){
    error = SIN_ERROR;
    long int ced = aut->getCedula();
    if(autores.MemberA(ced))
        error=AUTOR_YA_EXISTE;
    else
        autores.InsertA(aut);

}

bool Fachada::ExisteAutor(long int ced)
{
    return (bool)(autores.MemberA(ced));
}

void Fachada::ListarAutoresRegistrados(IteradorAutores &iter)
{
    autores.ListarAutoresRegistrados(iter);
}

float Fachada::MontoTotalVentas()
{
    return libros.MontoTotalVentasLibros();
}

void Fachada::RegistrarVentaLibro(long int cod, TipoError &error)
{
    if(libros.Member(cod))
    {
        error=SIN_ERROR;
        libros.RegistrarVentaLibro(cod);
    }
    else
        error=LIBRO_NO_EXISTE;

}

void Fachada::CantidadLibrosVendidosPorTipo(int &texto,int &novela,int &escolar)
{
    libros.CantidadLibrosVendidosPorTipo(texto,novela,escolar);
}

void Fachada::DatosLibroMasVendido(Libro* &lib, TipoError &error)
{
    //Verificar si hay algun libro registrado
    if(!libros.diccionarioVacio())
    {
        error=SIN_ERROR;
        libros.DatosLibroMasVendido(lib);
    }
     else
        error=SIN_LIBROS_REGISTRADOS;
}

int Fachada::AutoresPosteriorAFecha(Fecha fec)
{
    return autores.AutoresPosteriorAFecha(fec);
}
