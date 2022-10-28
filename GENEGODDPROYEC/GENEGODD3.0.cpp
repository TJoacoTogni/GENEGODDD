#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
using namespace std;
#include "funcionesgenerala.h"
#include "rlutil.h"


void tirardados(int vec[],int tam);
void vecen1(int vec[],int tam);
void cargarPuntos(int v2[]);
int repetidoss(int v[],int tam);
int volvertirar(int vec[],int t,int tiradasTota,int vecenuno[],int vec1a6[],int dados[]/*vec en 1 y comb1a6 solo para pasar como parametro a funcion anidada*/);
void repetidos1a6(int v[],int num, int tam, int v2 []);//función para guardar en el vector comb1a6 los repetidos (la multiplicación) de las jugadas 1  a 6
int jugadas(int vecen1[],int vec1a6[],int v[]);
int combinaciones(int v[],int t,int vec[]);
void puntuacion(int vec1[]/*vectoren1*/,int vec2[]/*comb1a6*//*respuesta*/,int jugada /*jugadasDis*/,int& acupuntos); //anula o guarda las puntuaciones
int tiradasFunc(int dados[], int tiradas,int tiradasT,string nombre, int ronda,int& acupuntoss);
/////////////////////////////////////////////////////////////////////////////////////////////////////
void puntuacion2(int vec12[]/*vectoren1*/,int vec22[]/*comb1a6*//*respuesta*/,int jugada2 /*jugadasDis*/,int& acupuntos2); //anula o guarda las puntuaciones
int tiradasFunc2(int dados[], int tiradas2,int tiradasT2,string nombre2, int ronda2,int& acupuntoss2);
/////////////////////////////////////////////////////////////////////////////////////////////////////
int menu();
void unjugador(int respuesta);
void dosjugadores();



int main(){
    rlutil::hidecursor();
    setlocale(LC_ALL, "");
    int rmenu,i;

    rmenu=menu();


    switch(rmenu){
    case 1: unjugador(rmenu); break;
    case 2: dosjugadores(); break;
    case 3: cout<<"no hay no existe, saludos :) <3"<<endl;
    case 4: rlutil::anykey(); return 0; break;
    }

    cout<<" "<<endl;
}


