#include "menu.h"
#include <iostream>
#include "String.h"


void menuPrincipal(int &op1)
{
    system("CLS");
    cout<<"\nMenu Principal\n";
    cout<<"\n1-  Registrar Libro";
    cout<<"\n2-  Listar libros registrados";
    cout<<"\n3-  Listar datos de un libro";
    cout<<"\n4-  Registrar autor";
    cout<<"\n5-  Listados de autores registrados";
    cout<<"\n6-  Calcular monto total de dinero por concepto de unidades vendidas";
    cout<<"\n7-  Registrar venta de libro";
    cout<<"\n8-  Obtener la cantidad total de unidades vendidas de cada tipo de libro";
    cout<<"\n9-  Libro mas vendido";
    cout<<"\n10- Dada una fecha, contar cuantos autores hay registrados cuya fecha de nacimiento sea posterior a dicha fecha";
    cout<<"\n0-  SALIR";
    cout<<"\n";
    cout<<"\n Ingrese la opcion correcta\n";
    scanf("%d",&op1);
}

void menuTipoLibro(int &op2){
    system("CLS");
    cout<<"\nIngrese el Tipo de Libro\n";
    cout<<"\n1-  Novela";
    cout<<"\n2-  Texto";
    cout<<"\n3-  Escolar\n";
    scanf("\n%d",&op2);
}

void datosLibro(long int &cod, String &tit,float &pb){

    cout<<"Ingrese el ISBN\n";
    scanf("\n%ld",&cod);
    cout<<"Ingrese el Titulo\n";
    tit.scan();
    tit.scan();
    cout<<"\nIngrese el precio base\n";
    scanf("%f",&pb);
}

void datosNovela(String &gen,long int &ced){
    cout<<"Ingrese el genero\n";
    gen.scan();
    gen.scan();
    cout<<"Ingrese la CI del Autor\n";
    scanf("%ld",&ced);
}

void datosTexto(String &mat, int &d, int &m, int &a){
    cout<<"Ingrese la materia\n";
    mat.scan();
    mat.scan();
    cout<<"Fecha de publicacion\n";
    cout<<"Ingrese el dia\n";
    scanf("%d",&d);
    cout<<"Ingrese el mes\n";
    scanf("%d",&m);
    cout<<"Ingrese el anio\n";
    scanf("%d",&a);
}

void datosEscolar( int &a){
    cout<<"Ingrese el anio escolar\n";
    scanf("%d",&a);
}

void datosAutor(long int &ci,String &nom,int &d, int &m, int &a){
    cout<<"Datos del Autor\n";
    cout<<"Ingrese la CI\n";
    scanf("%ld",&ci);
    cout<<"Ingrese nombre\n";
    nom.scan();
    nom.scan();
    cout<<"\nFecha de nacimiento\n";
    cout<<"Ingrese el dia\n";
    scanf("%d",&d);
    cout<<"\nIngrese el mes\n";
    scanf("%d",&m);
    cout<<"\nIngrese el anio\n";
    scanf("%d",&a);
}

void ingresarFecha(int &d, int &m, int &a){
    cout<<"Ingrese Fecha\n\n";
    cout<<"Ingrese el dia\n";
    scanf("%d",&d);
    cout<<"Ingrese el mes\n";
    scanf("%d",&m);
    cout<<"Ingrese el anio\n";
    scanf("%d",&a);
}

