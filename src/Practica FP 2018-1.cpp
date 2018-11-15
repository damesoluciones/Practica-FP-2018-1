//============================================================================
// Name        : Practica.cpp
// Author      : Chuyin y Manuel
// Version     : 1.0
// Copyright   : Todos los derechos reservados
// Description : Práctica FP 2018-1
//============================================================================


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int menu ();
int menuB ();
int NumeroCartas ();
float modoA ( ifstream& file, int numCartas );
float modoBhumano ( ifstream& file, int numCartas );
float modoBmaquina ( ifstream& file, int numCartas, float puntosHumano );
int determinaGanador ( float puntosJugador, float puntosMaquina );
bool seguir ( float maquina, float humano );

int main () {
   int opn, max;
   ifstream mazo0;
   string baraja;
   float puntosAhu, puntosAma, puntosBhu, puntosBma;

   cout << "Hola" << endl;

   srand ( time( NULL ) );
   opn = menu ();
   while ( opn != 0 ) {

	   switch ( opn ) {

	      case 1:
            {
             cout << " Introduzca el mazo con el que desea jugar: " << endl;
             cin >> baraja;
             mazo0.open ( baraja );
                if ( mazo0.is_open () ) {
                   max = NumeroCartas ();
                   puntosAhu = modoA ( mazo0, max );
                   puntosAma = modoA ( mazo0, max );
                }
                else {
                   cout << " El archivo no existe " <<endl;
                }
             mazo0.close();
            }
                break;

//<<<<<<< Updated upstream
//=======
//<<<<<<< HEAD
//>>>>>>> Stashed changes
	      case 2:
            {
             cout << " Introduzca el mazo con el que desea jugar " << endl;
             cin >> baraja;
             mazo0.open ( baraja );
                if ( mazo0.is_open () ) {
                	max = NumeroCartas ();
                	puntosBhu = modoBhumano ( mazo0, max );
                	puntosBma = modoBmaquina ( mazo0, max, puntosBhu );
                }
                else {
                	cout << " El archivo no existe " << endl;
                }
                mazo0.close();
            }
//<<<<<<< Updated upstream
//=======
//=======
    int opn, max, ganador;
	ifstream mazo0;
	string baraja;

	float puntosAhu, puntosAma, puntosBhu, puntosBma;

	srand (time(NULL));
	opn = menu ();
    while (opn != 0) {

         switch (opn) {
            case 1:
                 {
                  cout << "Introduce el mazo con el que quieres jugar "<<endl;
                  cin >> baraja;
                  mazo0.open ( baraja );
                  if ( mazo0.is_open ()) {
                     max = NumeroCartas ();
                	 puntosAhu = modoA ( mazo0, max);
                	 puntosAma = modoA ( mazo0, max);
                	 //cout << "El ganador es " ;
                	 //cout << determinaGanador (puntosAhu,  puntosAma) << endl;
                  }

                  else {
                       cout << " El archivo no existe"<<endl;

                       }
                 }

                 break;
            case 2: //elige opción B
                 {

                	 //dato = pedirunidades (dato);
                     //cout<<"La conversión de "<<dato<<" millas = "<<convertirmiame(dato)<<" Kilómetros";
                 }
//>>>>>>> f896a88fde02a27986c6336cec148155ae4cffbd
//>>>>>>> Stashed changes
                break;

	      default:
	        {

	        }
        }
      opn = menu ();
   }

   return 0;
}

int menu () {
	int opcion;
    cout << " Elija una opci�n: " << endl;
    cout << " 1 para jugar en modo A " << endl;
    cout << " 2 para jugar en modo B " << endl;
    cout << " 0 para salir " << endl;
    cin >> opcion;
    return opcion;
}

int menuB () {
   int opcion;
   cout << " Elija una opci�n: " << endl;
   cout << " 1 para seguir robando cartas " << endl;
   cout << " 0 para dejar de robar cartas " << endl;
   cin >> opcion;
   return opcion;
}

int NumeroCartas () {
    int cartas;
    cartas = 3 + rand() % (5+1-3);
    return cartas;
}

bool seguir ( float maquina, float humano ) {
   bool decision = false;

   if ( ( maquina == 7.5 ) || ( maquina > humano ) ) {
      decision = true;
   }
   return decision;
}

float modoA ( ifstream& file, int numCartas ) {
    int carta, suma, contador = 1;
    float puntos = 0;
        while ( contador <= numCartas ) {
//<<<<<<< Updated upstream
        	file >> carta;
            cout << " La carta es: " << carta;
            if ( carta <= 7 ) {
//=======
//<<<<<<< HEAD
        	file >> carta;
            cout << " La carta es: " << carta;
            if ( carta <= 7 ) {
//=======
            file >> carta;
            cout << "la carta es ";
            cout << carta << endl;
            if (carta <= 7){
//>>>>>>> f896a88fde02a27986c6336cec148155ae4cffbd
//>>>>>>> Stashed changes
                puntos = carta + puntos;
            }
            else {
                puntos = puntos + 0.5;
            }
//<<<<<<< Updated upstream
            cout << " Tus puntos son: " << puntos;
//=======
//<<<<<<< HEAD
            cout << " Tus puntos son: " << puntos;
//=======
            cout << "los puntos son ";
            cout << puntos << endl;
//>>>>>>> f896a88fde02a27986c6336cec148155ae4cffbd
//>>>>>>> Stashed changes
            contador++;
        }
    return puntos;
}

//<<<<<<< Updated upstream
//=======
//<<<<<<< HEAD
//>>>>>>> Stashed changes
float modoBhumano ( ifstream& file, int numCartas ) {
   int salida, carta, contador = 1;
   float puntos = 0;
   while ( ( contador <= numCartas ) || ( salida == 0 ) ) {
      file >> carta;
      cout << " La carta es: " << carta;
         if ( carta <= 7 ) {
            puntos = carta + puntos;
         }
         else {
            puntos = puntos + 0.5;
         }
      cout << " Tus puntos son: " << puntos;
      salida = menuB ();
      contador++;
   }
   return puntos;
}

float modoBmaquina ( ifstream& file, int numCartas, float puntosHumano ) {
	int salida, carta, contador = 1;
	float puntos = 0;
	while ( ( contador <= numCartas ) || ( salida == 1 ) ) {
	   file >> carta;
	   cout << " La carta es: " << carta;
	      if ( carta <= 7 ) {
	         puntos = carta + puntos;
	      }
	      else {
	         puntos = puntos + 0.5;
	      }
	   cout << " Tus puntos son: " << puntos;
	   salida = seguir ( puntos, puntosHumano );
	   contador++;
//<<<<<<< Updated upstream
//=======
//=======
int determinaGanador (float puntosJugador, float puntosMaquina){

	int resultado;
	const int limiteInferior = 1;
	const int limiteSuperior = 2;

	if ((puntosJugador <= 7,5) && (puntosMaquina <= 7,5) && (puntosJugador < puntosMaquina)){
		resultado = 1;
	}
	else if ((puntosJugador <= 7,5) && (puntosMaquina <= 7,5) && (puntosJugador > puntosMaquina)){
			resultado = 2;
		}
	else if ((puntosJugador == 7,5) && (puntosMaquina == 7,5 )) {
		resultado = limiteInferior + rand() % (limiteSuperior+1-limiteInferior);
	}

	else if (( puntosJugador > 7,5 ) || (puntosMaquina > 7,5)){
		if (puntosJugador > 7,5){
			resultado = 2;
		}
		else {
			resultado = 1;
		}
//>>>>>>> f896a88fde02a27986c6336cec148155ae4cffbd
//>>>>>>> Stashed changes
	}
	return puntos;
}

//<<<<<<< Updated upstream
int determinaGanador ( float puntosJugador, float puntosMaquina ) {
}
//=======
//<<<<<<< HEAD
int determinaGanador ( float puntosJugador, float puntosMaquina ) {
}
//=======

return resultado;
	}

//>>>>>>> f896a88fde02a27986c6336cec148155ae4cffbd
//>>>>>>> Stashed changes
