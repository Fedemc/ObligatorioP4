#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED
#include "String.h"
#include "Fecha.h"

class Autor
{
private:
    long int cedula;
    String nombre;
    Fecha fechaNacimiento;

public:
    Autor ();
    Autor (long int,String,Fecha);
    long int getCedula();
    String getNombre();
    Fecha getFechaNacimiento();
    Autor(const Autor&);
    ~Autor();
};


#endif // AUTOR_H_INCLUDED
