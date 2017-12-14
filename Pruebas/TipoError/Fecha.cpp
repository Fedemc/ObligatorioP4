#include "Fecha.h"

void Fecha::incrementar()
{
    switch(dia)
    {
        case 28:
            if(mes==2 && !EsBisiesto())
            {
                dia=1;
                mes=3;
            }
            else
            {
                dia++;
            }

            break;

        case 29:
            if(mes==2 && EsBisiesto())
            {
                dia=1;
                mes=3;
            }
            else
                dia++;

            break;

        case 30:
            if(mes==4 || mes==6 || mes==9 || mes==11)
            {
                dia=1;
                mes++;
            }
            else
                dia++;
            break;

        case 31:
            if(mes==12)
            {
                dia=1;
                mes=1;
                anio++;
            }
            else
            {
                dia=1;
                mes++;
            }
            break;

        default:
            dia++;
            break;
    }

    //return *this;
}


Fecha::Fecha()
{
    dia=1;
    mes=1;
    anio=1901;
}

Fecha::Fecha(int d, int m, int a)
{
    dia=d;
    mes=m;
    anio=a;
}

Fecha::Fecha(const Fecha &fec)
{
    dia=fec.dia;
    mes=fec.mes;
    anio=fec.anio;
}

int Fecha::getDia()
{
    return dia;
}

int Fecha::getMes()
{
    return mes;
}

int Fecha::getAnio()
{
    return anio;
}

//Verifica si un año es bisiesto
bool Fecha::EsBisiesto()
{
    return (bool)(anio%4==0);
}

bool Fecha::operator < (Fecha f)
{
    bool retorno=false;
    if(anio<f.getAnio())
        retorno=true;
    else
    {
        if(anio==f.getAnio())
        {
            if(mes<f.getMes())
                retorno=true;
            else
            {
                if(mes==f.getMes())
                {
                    if(dia<f.getDia())
                        retorno=true;
                }float PrecioVenta();
            }
        }
    }
    return retorno;
}

bool Fecha::operator == (Fecha f)
{
    bool retorno=false;

    if(anio==f.getAnio())
    {
        if(mes==f.getMes())
        {
            if(dia==f.getDia())
                retorno=true;
        }
    }
    return retorno;
}




//Devuelve la fecha correspondiente al dia siguiente a la fecha dada
//PREFIJO
Fecha Fecha::operator ++ ()
{
    (*this).incrementar();

    return (*this);
}

//Devuelve la fecha correspondiente al dia siguiente a la fecha dada
//PREFIJO
Fecha Fecha::operator ++ (int)
{
    Fecha fecTemp= *this;
    fecTemp.incrementar();

    return fecTemp;
}
Fecha Fecha::operator + (int d)
{
    Fecha auxFecha=*this;

    for(int i=0; i<d; i++)
    {
        auxFecha.incrementar();
    }

    return auxFecha;
}


int Fecha::operator - (Fecha f)
{
    Fecha menor, mayor;
    int cont=0;

    if(*this<f)
    {
        menor=*this;
        mayor=f;
    }
    else
    {
        menor=f;
        mayor=*this;
    }

    while(menor<mayor)
    {
        menor.incrementar();
        cont++;
    }

    return cont;
}

bool Fecha::esValida()
{
    bool valido=false, bisiesto=false;

    if(anio%4==0)
        bisiesto=true;

    if(mes>0 && mes<13 &&  dia>0 &&  dia<32 &&  anio>0)
    {
        if( mes==4 ||  mes==6 ||  mes==9 ||  mes==11)
        {
            if( dia<=30)
            {
                valido=true;
            }
            else
                valido=false;
        }
        else
            if( mes==2 &&  dia<30 && bisiesto)
                valido=true;
    }

    return valido;
}


void Fecha::MostrarFecha()
{
    printf("El dia es: %d\n",dia);
    printf("El mes es: %d\n",mes);
    printf("El anio es: %d\n",anio);
}
