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
    float pb = 30;
    String tit,nom,gen,mat;
    Fecha fecPub;


    do{
        system("CLS");
        fflush(stdin);

        menuPrincipal(opcion1);

        switch(opcion1){

        ///Registro Libro
        case 1:
            system("CLS");
            fflush(stdin);
            //ingreso datos del libro: isbn, titulo, precio base.
            datosLibro(cod, tit,pb);
            //consulto que tipo de libro registra.
            menuTipoLibro(opcion2);
            switch(opcion2){
                system("CLS");
                fflush(stdin);
                ///Novela
                case 1:

                    long int ced;
                    datosNovela(gen,ced);
                    //verifico que el autor exista
                    if(fach.autores.MemberA(ced)){
                        //creo la novela
                        Novela * unaNovela = new Novela(cod,tit,pb,gen);
                        //registro la novela en el diccionario
                        fach.RegistrarLibro(unaNovela,error);
                        //apunto el autor de la novela al autor del diccionario autores.
                        Autor * aut=fach.autores.FindA(ced);
                        unaNovela->unAutor = aut;
                        error=SIN_ERROR;
                        cout<<"OK";
                    }else{
                        error= AUTOR_NO_REGISTRADO;
                        cout<<"Autor no Registrado";
                    }
                    break;
                ///Texto
                case 2:

                    int d,m,a;
                    datosTexto(mat,d,m,a);
                    Fecha fecPub(d,m,a);
                    Texto * nuevoTexto = new Texto(cod,tit,pb,mat,fecPub);
                    fach.RegistrarLibro(nuevoTexto,error);
                    cout<<"OK";
                    break;

                ///Escolar
                case 3:
                    int dd,mm,aa,ae;
                    datosTexto(mat,dd,mm,aa);
                    fecPub(dd,mm,aa);
                    datosEscolar(ae);
                    Escolar * nuevoEscolar = new Escolar(cod,tit,pb,mat,fecPub,ae);
                    fach.RegistrarLibro(nuevoEscolar,error);
                    cout<<"OK";
                    break;
            }
            break;
        ///Registrar Autor

        case 4:
            system("CLS");
            fflush(stdin);
            long int ci;

            int d,m,a;
            datosAutor(ci,nom,d,m,a);
            Fecha fecNac(d,m,a);
            Autor * nuevoAutor = new Autor(ci,nom,fecNac);
            fach.RegistrarAutor(nuevoAutor,error);
            cout<<"OK";
            break;

        }


    }while(opcion1!=0);
    cout<< "\n\n Hasta la Proxima\n\n";
}
