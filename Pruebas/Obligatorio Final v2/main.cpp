#include <iostream>
#include "Fachada.h"
#include "Novela.h"
#include "Texto.h"
#include "Escolar.h"
#include "menu.h"
#include "Fecha.h"


using namespace std;

int main()
{
    TipoError error;
    Fachada fach;
    IteradorLibros iter;
    int opcion1=-1,opcion2;
    long int cod;
    float pb;
    String tit,nom,gen,mat;
    Fecha fecPub;


    do{
        system("CLS");
        fflush(stdin);

        menuPrincipal(opcion1);

        switch(opcion1)
        {

            ///Registro Libro
            case 1:
                {
                    system("CLS");
                    fflush(stdin);
                    cout<<"Registro de nuevo libro\n";
                    //ingreso datos del libro: isbn, titulo, precio base.
                    datosLibro(cod, tit,pb);
                    //consulto que tipo de libro registra.
                    menuTipoLibro(opcion2);
                    switch(opcion2)
                    {
                        system("CLS");
                        fflush(stdin);
                        ///Novela
                        case 1:
                            {
                                long int ced;
                                datosNovela(gen,ced);
                                //Me fijo si existe el autor en el diccionario Autores
                                if(fach.ExisteAutor(ced))   //Si el autor ya existe
                                {
                                    //creo la novela
                                    Libro * unaNovela = new Novela(cod,tit,pb,gen);
                                    //Voy a registrar la novela en el diccionario
                                    fach.RegistrarLibro(unaNovela,error);
                                    //Pregunto si hubo error, si el libro ya existe
                                    if(error==LIBRO_YA_EXISTE)
                                    {
                                        cout << "ERROR: Libro no registrado, ya existe un libro con ese ISBN"; //Despliego error para el usuario
                                        delete unaNovela;       //Libero la memoria donde guardé la novela
                                        cin.get();
                                    }
                                    else    //Si no hubo errores en el registro del libro en el diccionario de Libros
                                    {
                                        //Creo puntero a Autor y lo apunto al autor en el diccionario autores, buscandolo por cedula.
                                        Autor * aut=fach.autores.FindA(ced);
                                        ((Novela*)unaNovela)->unAutor = aut;
                                        cout << "Novela ingresada correctamente al sistema";
                                        cin.get();
                                    }
                                }
                                else
                                {

                                    fflush(stdin);
                                    cout << "ERROR: No existe un autor en el sistema con esa cedula.";
                                    cin.get();
                                }
                            }
                            break;
                        ///Texto
                        case 2:
                            {
                                int d,m,a;
                                datosTexto(mat,d,m,a);
                                fecPub=Fecha(d,m,a);
                                Libro * nuevoTexto = new Texto(cod,tit,pb,mat,fecPub);
                                fach.RegistrarLibro(nuevoTexto,error);
                                system("CLS");
                                fflush(stdin);
                                if(error!=SIN_ERROR)
                                {
                                    cout << "ERROR: Ya existe un libro en el sistema con ese ISBN";
                                    delete nuevoTexto;
                                    cin.get();
                                }
                                else
                                {
                                    cout<<"Libro de texto ingresado correctamente";
                                    cin.get();
                                }
                            }break;
                        ///Escolar
                        case 3:
                            {
                                int dd,mm,aa,ae;
                                datosTexto(mat,dd,mm,aa);
                                fecPub=Fecha(dd,mm,aa);
                                datosEscolar(ae);
                                Libro * nuevoEscolar = new Escolar(cod,tit,pb,mat,fecPub,ae);
                                fach.RegistrarLibro(nuevoEscolar,error);
                                system("CLS");
                                fflush(stdin);
                                if(error!=SIN_ERROR)
                                {
                                    cout << "ERROR: Ya existe un libro en el sistema con ese ISBN";
                                    delete nuevoEscolar;
                                }
                                else
                                    cout<<"Libro de textos escolar ingresado correctamente";
                                    cin.get();
                            }

                            break;

                        default:
                            {
                                cout << "ERROR: Debe ingresar un numero de opcion entre 1 y 3";

                            }break;
                    }

                }break;

            ///Listar libros registrados
            case 2:
                {
                    system("CLS");
                    fflush(stdin);
                    cout << "Listado de libros registrados\n";
                    //Creo el iterador de libros
                    IteradorLibros iterLibs=IteradorLibros();
                    //Invoco el metodo ListarLibrosRegistrados de la fachada, pasando como parámetro el iterador
                    fach.ListarLibrosRegistrados(iterLibs);

                    //Con el iterador cargado lo recorro y muestro los datos de los libros
                    while(iterLibs.hayMasLibros())
                    {
                        Libro *auxLib=iterLibs.proximoLibro();
                        cout << "Codigo: " << auxLib->getIsbn();
                        cout << " - Titulo: ";
                        auxLib->getTitulo().print();
                        cout << " - Tipo de libro: ";
                        auxLib->TipoLibro().print();
                        cout<<"\n\n";
                    }
                    cin.get();
                }
                break;
            ///Listar datos de un libro
            case 3:
                {
                    system("CLS");
                    fflush(stdin);
                    cout << "Datos de libro especifico\n";
                    cout << "Ingrese el ISBN del libro: ";
                    long int codigo;
                    scanf("%ld",&codigo);
                    Libro * auxLib;
                    fach.ListarDatosLibro(codigo,error,auxLib);
                    system("CLS");
                    fflush(stdin);
                    if(error !=SIN_ERROR)
                    {
                        cout << "ERROR: No existe el libro en el sistema";
                    }
                    else
                    {
                        cout << "ISBN: " << auxLib->getIsbn();
                        cout << "\nTitulo: ";
                        auxLib->getTitulo().print();
                        cout << "\nPrecio base: " << auxLib->getPrecioBase();
                        cout << "\nUnidades vendidas: " << auxLib->getUnidadesVendidas();
                        cout << "\n Tipo de Libro: ";
                        auxLib->TipoLibro().print();



                        //Preguntar que tipo es y mostrar datos correspondientes
                        if(auxLib->TipoLibro()=="Texto" || auxLib->TipoLibro()=="Escolar")
                        {
                            //Si es de Texto
                            cout << "\nMateria: ";
                            //Casteo auxLib como si fuera puntero a Texto para poder ingresar a metodos de un objeto Texto
                            ((Texto*)auxLib)->getMateria().print();
                            Fecha fecAux=((Texto*)auxLib)->getFechaPublicacion();       //Me guardo la fecha de publicacion para no utilizar toda la llamada completa al dato
                            cout << "\nFecha de Publicacion: " << fecAux.getDia() << "/" << fecAux.getMes() << "/" << fecAux.getAnio();
                            if(auxLib->TipoLibro()=="Escolar")
                            {
                                cout << "\nAnio escuela: " << ((Escolar*)auxLib)->getAnioEscuela();
                                //Casteo auxLib como si fuera puntero a Escolar para poder ingresar a metodos de un objeto Escolar
                            }
                        }
                        else //Si no es ni Texto ni Escolar, entonces es Novela
                        {
                            cout << "\nGenero: ";
                            ((Novela*)auxLib)->getGenero().print();
                            Autor * auxAut=((Novela*)auxLib)->getAutor();
                            cout << "\n\nDatos del autor\n";
                            cout << "\nCedula: " << auxAut->getCedula();
                            cout << "\nNombre: ";
                            auxAut->getNombre().print();
                            Fecha fecAux=auxAut->getFechaNacimiento();
                            cout << "\nFecha de nacimiento: " << fecAux.getDia() << "/" << fecAux.getMes() << "/" << fecAux.getAnio();
                        }
                    }
                    cin.get();
                }
                break;
             ///Registrar Autor
            case 4:
                {
                    system("CLS");
                    fflush(stdin);
                    long int ci;

                    int d,m,a;
                    datosAutor(ci,nom,d,m,a);
                    Fecha fecNac(d,m,a);
                    Autor * nuevoAutor = new Autor(ci,nom,fecNac);
                    fach.RegistrarAutor(nuevoAutor,error);
                    system("CLS");
                    fflush(stdin);
                    if(error!=SIN_ERROR)
                    {
                        cout << "ERROR: Ya existe un autor en el sistema con esa cedula";
                        delete nuevoAutor;
                    }
                    else
                    {
                        cout<<"Autor ingresado correctamente";
                    }
                    cin.get();
                }break;

            ///Listado de autores
            case 5:
                {
                    system("CLS");
                    fflush(stdin);
                    cout << "Listado de autores registrados\n";
                    //Creo el iterador de autores
                    IteradorAutores iterAuts=IteradorAutores();
                    //Invoco el metodo ListarLibrosRegistrados de la fachada, pasando como parámetro el iterador
                    fach.ListarAutoresRegistrados(iterAuts);

                    //Con el iterador cargado lo recorro y muestro los datos de los autores
                    while(iterAuts.hayMasAutores())
                    {
                        Autor * auxAutor=iterAuts.proxAutor();
                        cout << "Cedula: " << auxAutor->getCedula();
                        cout << " - Nombre: ";
                        auxAutor->getNombre().print();
                        Fecha fecNac=auxAutor->getFechaNacimiento();
                        cout << " - FechaNac:  " << fecNac.getDia() << "/" << fecNac.getMes() << "/" << fecNac.getAnio();
                        cout << "\n";
                    }
                    cin.get();
                }break;

            ///Calcular monto total de dinero recaudado por concepto de unidades de libros vendidas
            case 6:
                {
                    system("CLS");
                    fflush(stdin);
                    float monto=0;

                    monto=fach.MontoTotalVentas();

                    cout<< "\nEl monto total de dinero recaudado es: ";
                    printf("%f", monto);
                    cout << "\n";
                    cin.get();
                }break;

            ///Registrar venta de libro
            case 7:
                {
                    system("CLS");
                    fflush(stdin);
                    int uv=0;
                    cout << "Venta de un Libro\n";
                    cout << "Ingrese el ISBN del libro: ";
                    long int codigo;
                    scanf("%ld",&codigo);
                    fach.RegistrarVentaLibro(codigo,error);
                    system("CLS");
                    fflush(stdin);
                    if(error!=SIN_ERROR)
                    {
                        cout << "ERROR: El libro no existe en el sistema";
                    }
                    else
                    {
                        cout<<"Venta ingresada correctamente.";
                    }
                    cin.get();
                }break;

            ///Cantidad total de unidades vendidas por tipo de libro
            case 8:
                {
                    system("CLS");
                    fflush(stdin);
                    int unidadesVenNovela=0,unidadesVenTexto=0,unidadesVenEscolar=0;

                    fach.CantidadLibrosVendidosPorTipo(unidadesVenTexto,unidadesVenNovela,unidadesVenEscolar);

                    cout<< "\nEl total de unidades vendidas para la Novela es: "<<unidadesVenNovela;
                    cout << "\n";
                    cout<< "\nEl total de unidades vendidas para el Texto es: "<<unidadesVenTexto;
                    cout << "\n";
                    cout<< "\nEl total de unidades vendidas para el Escolar es: "<<unidadesVenEscolar;
                    cout << "\n";
                    cin.get();

                }break;

            ///Listado de datos del libro con la mayor cantidad de unidades vendidas
            case 9:
                {
                    system("CLS");
                    fflush(stdin);
                    Libro* auxLib=NULL;
                    fach.DatosLibroMasVendido(auxLib,error);
                    system("CLS");
                    fflush(stdin);
                    if(error!=SIN_ERROR)
                    {
                        cout << "ERROR: No hay libros ingresados en el sistema";
                    }
                    else
                    {
                        cout<<"Datos de libro mas vendido\n";
                        cout << "ISBN: " << auxLib->getIsbn();
                        cout << "\nTitulo: ";
                        auxLib->getTitulo().print();
                        cout << "\nPrecio base: " << auxLib->getPrecioBase();
                        cout << "\nUnidades vendidas: " << auxLib->getUnidadesVendidas();
                        cout << "\n Tipo de Libro: ";
                        auxLib->TipoLibro().print();

                        //Preguntar que tipo es y mostrar datos correspondientes
                        if(auxLib->TipoLibro()=="Texto" || auxLib->TipoLibro()=="Escolar")
                        {
                            //Si es de Texto
                            cout << "\nMateria: ";
                            //Casteo auxLib como si fuera puntero a Texto para poder ingresar a metodos de un objeto Texto
                            ((Texto*)auxLib)->getMateria().print();
                            Fecha fecAux=((Texto*)auxLib)->getFechaPublicacion();       //Me guardo la fecha de publicacion para no utilizar toda la llamada completa al dato
                            cout << "\nFecha de Publicacion: " << fecAux.getDia() << "/" << fecAux.getMes() << "/" << fecAux.getAnio();
                            if(auxLib->TipoLibro()=="Escolar")
                            {
                                cout << "\nAnio escuela: " << ((Escolar*)auxLib)->getAnioEscuela();
                                //Casteo auxLib como si fuera puntero a Escolar para poder ingresar a metodos de un objeto Escolar
                            }
                        }
                        else //Si no es ni Texto ni Escolar, entonces es Novela
                        {
                            cout << "\nGenero: ";
                            ((Novela*)auxLib)->getGenero().print();
                            Autor * auxAut=((Novela*)auxLib)->getAutor();
                            cout << "\n\nDatos del autor\n";
                            cout << "\nCedula: " << auxAut->getCedula();
                            cout << "\nNombre: ";
                            auxAut->getNombre().print();
                            Fecha fecAux=auxAut->getFechaNacimiento();
                            cout << "\nFecha de nacimiento: " << fecAux.getDia() << "/" << fecAux.getMes() << "/" << fecAux.getAnio();
                        }
                    }
                    cin.get();
                }break;

            ///Cantidad de autores registrados con fecha de nacimiento posterior a determinada fecha
            case 10:
                {
                    system("CLS");
                    fflush(stdin);
                    int d,m,a,total=0;
                    //Ingreso la fecha deseada
                    ingresarFecha(d,m,a);
                    Fecha fecIngresada (d,m,a);

                    total=fach.AutoresPosteriorAFecha(fecIngresada);
                    system("CLS");
                    fflush(stdin);
                    cout<< "\nHay " << total << " autores con fecha de nacimiento posteriores a la fecha ingresada";
                    cout << "\n";
                    cin.get();
                }break;

            case 0:
                {
                    system("CLS");
                    fflush(stdin);
                    cout<< "\n\n Hasta la Proxima\n\n";
                }break;

            default:
                {
                    system("CLS");
                    fflush(stdin);
                    cout << "ERROR: Debe ingresar un numero de opcion entre 1 y 10";
                    cin.get();
                }break;
        }
    }
    while(opcion1 != 0);

}
