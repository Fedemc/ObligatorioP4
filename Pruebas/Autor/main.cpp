#include <iostream>
#include "Autor.h"

using namespace std;

int main()
{
    Autor a1= Autor();

    cout << a1.getCedula();
    cout << "\n";
    a1.getFechaNacimiento().MostrarFecha();
    cout << "\n";
    a1.getNombre().print();

    String nombre = String("Pepe");

    Fecha fec= Fecha(12,12,1988);

    Autor* a2=new Autor(12345679,nombre,fec);

    cout << a2->getCedula();
    cout << "\n";
    a2->getFechaNacimiento().MostrarFecha();
    a2->getNombre().print();

    Autor a3=Autor(144,"Jose",Fecha(01,04,1959));
    Autor a4=a3;

    cout << "\n\nMuestro copia:\n";
    cout << a4.getCedula();
    cout << "\n";
    a4.getFechaNacimiento().MostrarFecha();
    a4.getNombre().print();
}
