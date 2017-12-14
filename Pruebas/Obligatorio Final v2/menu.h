#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "String.h"
#include "Fecha.h"

using namespace std;

void menuPrincipal(int &op1);

void menuTipoLibro(int &op2);

void datosLibro(long int &cod, String &tit,float &pb);

void datosNovela(String &gen,long int &ced);

void datosTexto(String &mat, int &d, int &m, int &a);

void datosEscolar(int &an);

void datosAutor(long int &ci,String &nom,int &d, int &m, int &a);

void ingresarFecha(int &d, int &m, int &a);

#endif // MENU_H_INCLUDED
