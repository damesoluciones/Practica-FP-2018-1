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

int menu();
int NumeroCartas ();
double pasarCartasAPuntos ( int carta );
float modoA (ifstream& file, int numCartas);
float modoBhumano (ifstream& file, int numCartas);
float modoBmaquina (ifstream& file, int numCartas, float puntosHumano);
int determinaGanador (float puntosJugador, float puntosMaquina);

int main () {

    int opn, max;
	ifstream mazo0;
	string baraja;

	double puntosA, puntosBhu, puntosBma;

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
                	 puntosA = modoA ( mazo0, max);
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
                break;


        }
      opn = menu ();
    }
return 0;
}

int menu () {
	int opcion;
    cout << " Elija una opción: " << endl;
    cout << " 1 para jugar en modo A " << endl;
    cout << " 2 para jugar en modo B " << endl;
    cout << " 0 para salir " << endl;
    cin >> opcion;
    return opcion;
}

int NumeroCartas(){
    int cartas;
    cartas = 3 + rand() % (5+1-3);
    return cartas;
}

float modoA ( ifstream& file, int numCartas ){
    int carta, suma, contador = 1;
    float puntos = 0;
        while ( contador <= numCartas ) {
            file >> carta;
            if (carta <= 7){
                puntos = carta + puntos;
            }
            else {
                puntos = puntos + 0.5;
            }
            contador++;
        }
    return puntos;
}

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
	}


return resultado;
	}
}
