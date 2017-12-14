#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <stdio.h>

class Fecha
{
    private:
        int dia, mes, anio;

        void incrementar();

    public:
        Fecha();
        Fecha(int d, int m, int a);
        Fecha(const Fecha &);
        int getDia();
        int getMes();
        int getAnio();

        bool EsBisiesto();
        bool operator < (Fecha);
        bool operator == (Fecha);
        Fecha operator ++ ();
        Fecha operator ++ (int);
        Fecha operator + (int);
        int operator - (Fecha);
        bool esValida();
        void MostrarFecha();

};

#endif // FECHA_H_INCLUDED
