#include <iostream>
#include "Libro.h"
#include "Novela.h"
#include "Texto.h"
#include "Escolar.h"


using namespace std;

int main()
{

Fecha fec (1,10,2016);

//Novela  a1 = Novela(1111,"uno",0,1,"Terror");
//Novela  a1 = Novela(1111,"uno",0,100,"Infantil");
//Texto a1 = Texto (1111,"uno",0,100, "Ingles", fec);
//Escolar a1 = Escolar (1111, "uno", 0, 100, "Aleman", fec,3);
Escolar a1 = Escolar (1111, "uno", 0, 100, "Aleman", fec,5);

cout<< a1.getIsbn();
printf("\n");
a1.getTitulo().print();
printf("\n");
cout<< a1.getUnidadesVendidas();
printf("\n");
cout<< a1.getPrecioBase();
printf("\n");
/* Novela
a1.getGenero().print();*/
/*Texto
a1.getMateria().print();
printf("\n");
*/
/*Escolar
cout<<a1.getAnioEscuela();
printf("\n");
*/
cout<<a1.PrecioVenta();
printf("\n");
a1.TipoLibro().print();

}
