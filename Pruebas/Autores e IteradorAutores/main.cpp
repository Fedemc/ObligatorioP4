#include <iostream>
#include "Autores.h"

using namespace std;

int main()
{
    Autor a1= Autor();

    String nombre = String("Pepe");

    Fecha fec= Fecha(12,12,1988);

    Autor* a2=new Autor(12345679,nombre,fec);

    Autor a3=Autor(144,"Jose",Fecha(01,04,1959));
    Autor a4=a3;

    cout << "OK\n";

    //Creo un puntero a Autor a5 y lo apunto al valor de a4
    Autor * a5=&a4;

    //Creo el dicc de autores
    Autores diccAutores= Autores();
    //Inserto los punteros a Autores a2 y a5
    diccAutores.Insert(a2);
    diccAutores.Insert(a5);

    //Me creo el IteradorAutores
    IteradorAutores iterAutsMain= IteradorAutores();

    //Cargo el iterador con todos los autores
    diccAutores.ListarAutoresRegistrados(iterAutsMain);

    //Leo el iterador y muestro el contenido
    while(iterAutsMain.hayMasAutores())
    {
        Autor * autAux= iterAutsMain.proxAutor();
        cout << "Cedula: " << autAux->getCedula() << " - ";
        autAux->getNombre().print();
        cout << " - " << autAux->getFechaNacimiento().getDia() << "/" << autAux->getFechaNacimiento().getMes() << "/" << autAux->getFechaNacimiento().getAnio();
        cout << "\n";
    }
}
