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
int menuB ();;
float modoA ( ifstream& file, int numCartas );
float modoBhumano ( ifstream& file, int numCartas );
float modoBmaquina ( ifstream& file, int numCartas, float puntosHumano );
int determinaGanador ( float puntosJugador, float puntosMaquina );
bool seguir ( float maquina, float humano );

int main () {
	int opn, max;
	ifstream mazo0;
	string baraja;
	float puntosAhu, puntosAma, puntosBhu, puntosBma, resultado;

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
				max = 3 + rand() % (5+1-3);
				puntosAhu = modoA ( mazo0, max );
				resultado  = determinaGanador ( puntosAhu, 0 );
				if ( resultado == 1 ){
					puntosAma = modoA ( mazo0, max );
					resultado = determinaGanador ( puntosAhu, puntosAma );
					if ( resultado == 1 ){
						cout << " Has ganado " << endl;
					}
					else {
						cout << " Has perdido " << endl;
					}
				}
				else {
					cout << " Has perdido " << endl;
				}
			}
			else {
				cout << " El archivo no existe " <<endl;
			}
			mazo0.close();
            }
		break;
		case 2:
		{
			cout << " Introduzca el mazo con el que desea jugar " << endl;
			cin >> baraja;
			mazo0.open ( baraja );
			if ( mazo0.is_open () ) {
				max = 3 + rand() % (5+1-3);
				puntosBhu = modoBhumano ( mazo0, max );
				puntosBma = modoBmaquina ( mazo0, max, puntosBhu );
				resultado = determinaGanador ( puntosBhu, puntosBma );
			}
			else {
				cout << " El archivo no existe " << endl;
			}
                mazo0.close();
            }
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
	cout << " Elija una opcion: " << endl;
	cout << " 1 para jugar en modo A " << endl;
	cout << " 2 para jugar en modo B " << endl;
	cout << " 0 para salir " << endl;
	cin >> opcion;
	return opcion;
}

int menuB () {
	int opcion;
	cout << " Elija una opcion: " << endl;
	cout << " 1 para seguir robando cartas " << endl;
	cout << " 0 para dejar de robar cartas " << endl;
	cin >> opcion;
	return opcion;
}

bool seguir ( float maquina, float humano ) {
	bool decision = false;

	if ( ( maquina == 7.5 ) || ( maquina > humano ) ) {
		decision = true;
	}
	return decision;
}

float modoA ( ifstream& file, int numCartas ) {
	int carta, contador = 1;
	float puntos = 0;
	while ( contador <= numCartas ) {
		file >> carta;
		cout << " La carta es: " << carta << endl;
		if ( carta <= 7 ) {
			puntos = carta + puntos;
		}
		else {
			puntos = puntos + 0.5;
		}
		cout << " Tus puntos son: " << puntos << endl;
		contador++;
	}
	return puntos;
}

float modoBhumano ( ifstream& file, int numCartas ) {
	int salida = 1, carta, contador = 1;
	float puntos = 0;
	while ( ( contador <= numCartas ) && ( salida == 1 ) ) {
	file >> carta;
	cout << " La carta es: " << carta << endl;
	if ( carta <= 7 ) {
		puntos = carta + puntos;
	}
	else {
		puntos = puntos + 0.5;
	}
	cout << " Tus puntos son: " << puntos << endl;
	salida = menuB ();
	contador++;
	}
   return puntos;
}

float modoBmaquina ( ifstream& file, int numCartas, float puntosHumano ) {
	int salida = 1, carta, contador = 1;
	float puntos = 0;
	while ( ( contador <= numCartas ) && ( salida == 1 ) ) {
		file >> carta;
		cout << " La carta es: " << carta << endl;
		if ( carta <= 7 ) {
			puntos = carta + puntos;
		}
		else {
			puntos = puntos + 0.5;
		}
		cout << " Tus puntos son: " << puntos << endl;
		salida = seguir ( puntos, puntosHumano );
		contador++;
	}
	return puntos;
}

int determinaGanador ( float puntosJugador, float puntosMaquina ) {
	int resultado;
	const int limiteInferior = 1;
	const int limiteSuperior = 2;
	if ( puntosJugador > puntosMaquina ) {
		if ( puntosJugador < 7.5 ) {
			resultado = 1;
		}
		else if (( puntosJugador > 7.5 ) && ( puntosMaquina < 7.5 )) {
			resultado = 2;
		}
		else {
			resultado = 2;
		}
	}
	else if ( puntosMaquina > puntosJugador ) {
		if ( puntosMaquina < 7.5 ) {
			resultado = 2;
		}
		else if (( puntosMaquina > 7.5 ) && ( puntosJugador < 7.5 )) {
			resultado = 1;
		}
		else {
			resultado = 1;
		}
	}
	else {
		resultado = limiteInferior + rand() % (limiteSuperior+1-limiteInferior);
	}
	return resultado;
}
