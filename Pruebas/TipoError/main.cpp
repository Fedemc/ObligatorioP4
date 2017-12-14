#include <iostream>
#include "Libros.h"
#include "Autores.h"


using namespace std;

int main()
{
    Libro* nov1=new Novela(1111,"Novela 1",25,"Terror");

    cout << "ISBN: " << nov1->getIsbn();
    cout << "\nTitulo: ";
    nov1->getTitulo().print();
    cout << "\nUnidades vendidas: " << nov1->getUnidadesVendidas();
    cout << "\nPrecio base: " << nov1->getPrecioBase();
    cout << "\nGenero: ";
    ((Novela*)nov1)->getGenero().print();
}
