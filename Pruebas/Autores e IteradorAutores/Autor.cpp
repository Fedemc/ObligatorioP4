#include "Autor.h"

Autor::Autor ():nombre(),fechaNacimiento()
{
    cedula=1;
}

Autor::Autor (long int ced,String nom,Fecha fec):nombre(nom),fechaNacimiento(fec)
{
    cedula=ced;
}

long int Autor::getCedula()
{
    return cedula;
}

String Autor::getNombre()
{
    return nombre;
}

Fecha Autor::getFechaNacimiento()
{
    return fechaNacimiento;
}

///hacer!
Autor::Autor(const Autor &aut)
{
    cedula=aut.cedula;
    nombre=aut.nombre;
    fechaNacimiento=aut.fechaNacimiento;
}

Autor::~Autor()
{

}
