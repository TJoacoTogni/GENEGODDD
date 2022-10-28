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
void dibujarcuadrado(int posx,int posy );
void dibujardado(int posx,int posy,int num);

void unjugador(int respuesta){
int comb1a6[10]/*guarda el valor de las combinaciones (1 a 6)*/,vectoren1[10]/*vector todo en -1*/,dados[5],acumpuntos=0,acum=0,tiradasT=1,tiradas=1,ronda=1,jugadaDis=1;
    int i;
    while(respuesta==1){
    string nombre;
    bool generala=false;
    srand (time (NULL));
    vecen1(dados,5);
    vecen1(vectoren1,10);
    cargarPuntos(comb1a6);
    cout<<"Ingrese nombre"<<endl;
    cin>>nombre;
    system("cls");
     tiradasFunc(dados,tiradas,tiradasT,nombre,ronda,acumpuntos);
     if (repetidoss(dados,5)==1){
            cout<<"Generala servida";
            generala=true;
            acumpuntos=50;
     }
        while ((generala==false)&& (ronda<=10)){
            if(ronda!=1){
            tiradasFunc(dados,tiradas,tiradasT,nombre,ronda,acumpuntos);
           }

            tiradasT+=volvertirar(dados,tiradas,tiradasT,vectoren1,comb1a6,dados);
            jugadaDis+=jugadas(vectoren1,comb1a6,dados);
            jugadaDis+=combinaciones(dados,5,vectoren1);
            puntuacion(vectoren1,comb1a6,jugadaDis,acumpuntos);
            jugadaDis=0;
            tiradas=1;
            ronda++;
            system("cls");
            }
            respuesta=menu();
            }
}

void dosjugadores(){
    int controndas=0;
    bool generala=false;
    srand (time (NULL));

    int /*JUGADOR 1*/ comb1a6[10]/*guarda el valor de las combinaciones (1 a 6)*/,vectoren1[10]/*vector todo en -1*/,dados[5],acumpuntos=0,acum=0,tiradasT=1,tiradas=1,ronda=1,jugadaDis=1;
    int /*JUGADOR 2*/ vectoren1JUG2[10],comb1a6JUG2[10],acumpuntosJUG2=0,acumJUG2=0,tiradasTJUG2=1,tiradasJUG2=1,rondaJUG2=1,jugadaDisJUG2=1;
    string nombre1,nombre2;
    controndas++;
    vecen1(vectoren1,10);
    vecen1(vectoren1JUG2,10);


    cout<<"INGRESE NOMBRE JUGADOR 1: ";
    cin>>nombre1;

    cout<<"INGRESE NOMBRE JUGADOR 2: ";
    cin>>nombre2;

    tiradasFunc(dados,tiradas,tiradasT,nombre1,ronda,acumpuntos);


     if (repetidoss(dados,5)==1){

            cout<<"Generala servida";
            generala=true;
            vectoren1[9]=0;
            acumpuntos=50;
            cout<<"Se le dara una oportunidad al jugador 2";
            tiradasFunc(dados,tiradasJUG2,tiradasTJUG2,nombre2,rondaJUG2,acumpuntosJUG2);


            if (repetidoss(dados,5)==1){
            cout<<"EMPATE";
            vectoren1JUG2[9]=0;
            generala=false;
            acumpuntos=50;
            }
            else{
            cout<<"GANADOR JUGADOR 1";
            }
     }
     else{
         tiradasT+=volvertirar(dados,tiradas,tiradasT,vectoren1,comb1a6,dados);
            jugadaDis+=jugadas(vectoren1,comb1a6,dados);
            jugadaDis+=combinaciones(dados,5,vectoren1);
            puntuacion(vectoren1,comb1a6,jugadaDis,acumpuntos);
            jugadaDis=0;
            tiradas=1;
            ronda++;

     }

    ///JUGADOR 1 LOS IMPARES
    ///JUGADOR 2 LOS PARES


    while((controndas<20) && (generala==false)){

            if(controndas%2==0){

            if(ronda!=1){
            tiradasFunc(dados,tiradas,tiradasT,nombre1,ronda,acumpuntos);

            tiradasT+=volvertirar(dados,tiradas,tiradasT,vectoren1,comb1a6,dados);
            jugadaDis+=jugadas(vectoren1,comb1a6,dados);
            jugadaDis+=combinaciones(dados,5,vectoren1);
            puntuacion(vectoren1,comb1a6,jugadaDis,acumpuntos);
            jugadaDis=0;
            tiradas=1;
            ronda++;
            }
            rlutil::cls();
            }
            else{
                    rlutil::cls();
            tiradasFunc2(dados,tiradasJUG2,tiradasTJUG2,nombre2,rondaJUG2,acumpuntosJUG2);
            tiradasTJUG2+=volvertirar(dados,tiradasJUG2,tiradasTJUG2,vectoren1JUG2,comb1a6JUG2,dados);
            jugadaDisJUG2+=jugadas(vectoren1JUG2,comb1a6JUG2,dados);
            jugadaDisJUG2+=combinaciones(dados,5,vectoren1JUG2);
            puntuacion2(vectoren1JUG2,comb1a6JUG2,jugadaDisJUG2,acumpuntosJUG2);
            jugadaDisJUG2=0;
            tiradasJUG2=1;
            rondaJUG2++;
            }
            controndas++;
            }
 }

 void puntuacion2(int vec12[]/*vectoren1*/,int vec22[]/*comb1a6*//*respuesta*/,int jugada2 /*jugadasDis*/,int& acupuntos2){
 int resj,i,j,anu,anular,re;

    if(jugada2>0){
        cout<<"1- Anotar combinacion"<<endl;
        cout<<"2- Anular combinacion"<<endl;
    }else{
        cout<<"2- Anular combinacion"<<endl;
    }
    cin>>re;
if(re==1){
    cout<<"Que juego quiere guardar?"<<endl;
    cin>>resj;
    vec12[resj-1]=vec22[resj-1];
    vec22[resj-1]=0;
    acupuntos2=acupuntos2+vec12[resj-1];
    rlutil::cls();
}
else {
    for(int i=0;i<10;i++){
        if(vec12[i]<0){
            switch(i){
                case 0 ... 5 :cout<<"Juego de "<<i+1<< ". Presiona "<<i+1<< " para anular"<<endl;break;
                case 6:cout<<"Juego de Escalera. Presiona 7 para anular"<<endl;break;
                case 7: cout<<"Juego de Full. Presiona 8 para anular"<<endl;break;
                case 8: cout<<"Juego de Poker. Presiona 9 para anular"<<endl;break;
                case 9: cout<<"Juego de Generala. Presiona 10 para anular"<<endl;break;
            }
        }
     }
     cout << "¿Que combinacion quiere anular?" << endl;
cin>>anular;

vec12[anular-1]=0;
}

}

int tiradasFunc2(int dados[], int tiradas2,int tiradasT2,string nombre2, int ronda2,int& acupuntoss2){
 cout<<"TURNO DE "<<nombre2<<"| ";
    cout<<"Ronda numero:"<<ronda2<<" |"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Tirada n°: "<<tiradas2<<" - ";
    cout<<"Tiradas totales: " <<tiradasT2<<endl;
    if(tiradasT2>1){
        cout<<"Puntos acumulados: "<<acupuntoss2<<endl;
    }
    tirardados(dados,6);


    return tiradasT2;
}



void vecen1(int vec[],int tam){
    int i;
    for(i=0;i<tam;i++){
        vec[i]=-1;
    }
    }

void tirardados(int vec[], int tam){
    int i;
    for(i=0;i<5;i++){
    vec[i]=1+rand()%6;



    dibujardado(i*10,rand()%3+6,vec[i]);
    }

    rlutil::setBackgroundColor(0);
    rlutil::setColor(15);

    rlutil::locate(1,16);



}

void dibujarcuadrado(int posx,int posy){
    int c;
    for(int x=1; x<=8;x++){
        for(int y=1;y<=5 ;y++){
            rlutil::locate(x + posx,y + posy);
            rlutil::setBackgroundColor(15);
            cout<<" ";
        }
    }

    rlutil::setBackgroundColor(0);
    cout<<" ";

//dibujardado(5,5,1);


}

void dibujardado(int posx,int posy,int num){
   dibujarcuadrado(posx,posy);
    switch(num)
    {
    case 1:
    rlutil::locate(posx+4,posy+3);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)254<<endl;
    break;

    case 2:
    rlutil::locate(posx+7,posy+2);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)220<<endl;

    rlutil::locate(posx+2,posy+4);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)223<<endl;
    break;

    case 3:
    rlutil::locate(posx+4,posy+3);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)254<<endl;

    rlutil::locate(posx+7,posy+2);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)220<<endl;

    rlutil::locate(posx+2,posy+4);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)223<<endl;
    break;

    case 4:
    rlutil::locate(posx+7,posy+2);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)220<<endl;

    rlutil::locate(posx+7,posy+4);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)223<<endl;

    rlutil::locate(posx+2,posy+4);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)223<<endl;

    rlutil::locate(posx+2,posy+2);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)220<<endl;
    break;

    case 5:
    rlutil::locate(posx+4,posy+3);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)254<<endl;

    rlutil::locate(posx+7,posy+2);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)220<<endl;

    rlutil::locate(posx+7,posy+4);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)223<<endl;

    rlutil::locate(posx+2,posy+4);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)223<<endl;

    rlutil::locate(posx+2,posy+2);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)220<<endl;
    break;

    case 6:
    rlutil::locate(posx+4,posy+2);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)220<<endl;

    rlutil::locate(posx+7,posy+2);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)220<<endl;

    rlutil::locate(posx+7,posy+4);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)223<<endl;

    rlutil::locate(posx+2,posy+4);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)223<<endl;

    rlutil::locate(posx+2,posy+2);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)220<<endl;

    rlutil::locate(posx+4,posy+4);
    rlutil::setBackgroundColor(15);
    rlutil::setColor(0);
    cout << (char)223<<endl;

    break;
    default:
    break;

    }

}

void cargarPuntos(int v2[]){
    v2[6]=25;
    v2[7]=30;
    v2[8]=40;
    v2[9]=50;
}
int repetidoss(int v[],int tam){
    int cGenerala=0, cant=0, i;
    for(i=0;i<tam;i++){
       if (v[0]==v[i]){
            cant=cant+1;
       }
    }
    if(cant==5){
        cGenerala=1;
    }
return cGenerala;
}
int volvertirar(int vec[],int t, int tiradasTo,int vecenuno[],int vec1a6[],int dados[]){
    char r;
    int tiradasTota=1,i,CD,D,res;
    int band=0;
        while((band==0)&&(t<3)){
        cout<<"¿Volver a tirar?"<<endl;
        cin>>r;
            if ((r=='s') && (t<3)){

                tiradasTota++;
                tiradasTo++;
                t++;
                cout<<"Tirada n°: "<<t<<" - ";
                cout<<"Tiradas totales: " <<tiradasTo<<endl;
                cout<<"¿Cuántos dados quieres tirar?"<<endl;
                cin>>CD;
                if(CD==5){
                    srand (time (NULL));
                    for(i=0;i<CD;i++){
                        vec[i]=1+rand()%6;
                    }
                }
                else{
                    cout<<"¿Qué dados quiere tirar?"<<endl;
                    for(i=0;i<CD;i++){
                        cin>>D;
                        vec[D-1]=1+rand()%6;
                    }
                }
                system("cls");
                cout<<"Su nueva jugada"<<endl;
                for(i=0;i<5;i++){
                    dibujardado(i*10,rand()%3+2,vec[i]);
                    rlutil::setBackgroundColor(0);
                    rlutil::setColor(15);
                    rlutil::locate(1,12);

                }

            }else{
                band=1;
            }
        }
return tiradasTota;
}
void repetidos1a6(int v[],int num, int tam, int v2 []){
    int cant=0,i;
    for(i=0;i<tam;i++){
        if(v[i]==num){
            cant=cant+1;
        }
    }
    cant*=num;
    v2[num-1]=cant;
}
int jugadas(int vecen1[],int vec1a6[],int ve[]){
    int i, jugada=0;
     for(i=0;i<=5;i++){
            if(vecen1[i]<0){
            repetidos1a6(ve,i+1,5,vec1a6);
                if(vec1a6[i]>0){

                    cout<<"En juego de "<<i+1<<" tiene "<<vec1a6[i]<<" puntos. Presiona "<<i+1<<endl;
                    jugada++;
                }
            }
     }
     return jugada;
}
int combinaciones(int v[],int t,int vec[]){
    int band=1,cont1=1,cont2=1,c=0,cont=0,vect,i,j,temp,jugada=0;
    for(i=1;i<t;i++){
        if(v[c]==v[i]){
            cont1++;
        }
        else if(band==1){
            vect=v[i];
            band=0;
        }
        else if(vect==v[i]){
            cont2++;
        }
    }
    if((cont2==2 && cont1==3)||(cont2==3&&cont1==2)&&(vec[7]<0)){
        cout<<"Tiene juego de Full. Presiona 8 para seleccionarlo"<<endl;
        jugada++;
    }
    else if((cont2==4)||(cont1==4&&(vec[8]<0))  ){
        cout<<"Tiene juego de Poker. Presiona 9 para seleccionarlo"<<endl;
        jugada++;
    }
    else if((repetidoss(v,5)==1)&&(vec[9]<0)){
        cout<<"Tiene juego de Generala. Presiona 10 para seleccionarlo"<<endl;
        jugada++;
    }
    else{
        for(i=0;i<t;i++){
            for(j=i+1;j<t;j++){
                if(v[i]>v[j]){
                    temp=v[i];
                    v[i]=v[j];
                    v[j]=temp;
                }
            }
        }
        for(c=0;c<=3;c++){
            if(v[c]+1==v[c+1]){
                cont++;
            }
            if((cont==4)&&(vec[6]<0)){
                cout<<"Tiene juego de escalera. Presiona 7 para seleccionarlo"<<endl;
                jugada++;
            }
        }
    }
    return jugada;
}

void puntuacion(int vec1[]/*vecen1*/,int vec2[]/*comb1a6*/,int jugada,int& acupuntos){
int resj,i,j,anu,anular,re;

    if(jugada>0){
        cout<<"1- Anotar combinacion"<<endl;
        cout<<"2- Anular combinacion"<<endl;
    }else{
        cout<<"2- Anular combinacion"<<endl;
    }
    cin>>re;
if(re==1){
    cout<<"Que juego quiere guardar?"<<endl;
    cin>>resj;
    vec1[resj-1]=vec2[resj-1];
    vec2[resj-1]=0;
    acupuntos=acupuntos+vec1[resj-1];
}
else {
    for(int i=0;i<10;i++){
        if(vec1[i]<0){
            switch(i){
                case 0 ... 5 :cout<<"Juego de "<<i+1<< ". Presiona "<<i+1<< " para anular"<<endl;break;
                case 6:cout<<"Juego de Escalera. Presiona 7 para anular"<<endl;break;
                case 7: cout<<"Juego de Full. Presiona 8 para anular"<<endl;break;
                case 8: cout<<"Juego de Poker. Presiona 9 para anular"<<endl;break;
                case 9: cout<<"Juego de Generala. Presiona 10 para anular"<<endl;break;
            }
        }
     }
     cout << "¿Que combinacion quiere anular?" << endl;
cin>>anular;
vec1[anular-1]=0;
}

}
 int tiradasFunc(int dados[], int tiradas,int tiradasT,string nombre, int ronda,int& acupuntoss){
      cout<<"TURNO DE "<<nombre<<"| ";
    cout<<"Ronda numero:"<<ronda<<" |"<<endl;
    cout<<"----------------------------------------------------"<<endl;
    cout<<"Tirada n°: "<<tiradas<<" - ";
    cout<<"Tiradas totales: " <<tiradasT<<endl;
    if(tiradasT>1){
        cout<<"Puntos acumulados: "<<acupuntoss<<endl;
    }
    tirardados(dados,6);


    return tiradasT;
 }

 int menu(){
     int respuesta;

 cout<<"MENÚ GENERALA"<<endl;
 cout<<"-------------"<<endl;
 cout<<"UN JUGADOR 1"<<endl;
 cout<<"DOS JUGADORES 2"<<endl;
 cout<<"MOSTRAR MAYOR PUNTAJE 3"<<endl;
 cout<<"SALIR 4"<<endl;
 cout<<"-------------"<<endl;

 cin>>respuesta;
 system("cls");
 return respuesta;
 }

