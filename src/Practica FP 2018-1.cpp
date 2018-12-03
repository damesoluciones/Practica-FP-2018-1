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

const int LimiteInferior = 3, LimiteSuperior = 5,  num = 8;

typedef int tCartasPorAparecer [num];


int menu ();
int menuB ();;
float modoA ( ifstream& file, int numCartas );
float modoBhumano ( ifstream& file, int numCartas );
float modoBmaquina ( ifstream& file, int numCartas, float puntosHumano );
int determinaGanador ( float puntosJugador, float puntosMaquina );
void modoChumano (ifstream& file, tCartasPorAparecer cartas, float& puntos);
void modoCmaquina (ifstream& file, tCartasPorAparecer cartas, float puntosHumano, float& puntos);
bool esProbablePasarse (float puntosMaquina, const tCartasPorAparecer cartas);




int main () {
	int opn, max;
	tCartasPorAparecer sigcarta;
	ifstream mazo0;
	string baraja;
	float puntosAhu, puntosAma, puntosBhu, puntosBma, puntosChumano = 0, puntosCmaquina = 0, resultado;

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
				max = LimiteInferior + rand() % (LimiteSuperior+1-LimiteInferior);
				puntosAhu = modoA ( mazo0, max );
				resultado  = determinaGanador ( puntosAhu, 0 ); //¿Por qué enviamos 0?
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
				max = LimiteInferior + rand() % (LimiteSuperior+1-LimiteInferior);
				puntosBhu = modoBhumano ( mazo0, max );
				puntosBma = modoBmaquina ( mazo0, max, puntosBhu );
				resultado = determinaGanador ( puntosBhu, puntosBma );
				if ( resultado == 1 ){
					cout << " Has ganado " << endl;
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


		case 3:
		{

			sigcarta [0] = 12; //inicializamos array
				for ( int i = 1; i < num; i++ ) {
					sigcarta [i] = 4;
				}

			cout << " Introduzca el mazo con el que desea jugar " << endl;
			cin >> baraja;
			mazo0.open ( baraja );
			if ( mazo0.is_open () ) {
				modoChumano ( mazo0, sigcarta, puntosChumano );
				modoCmaquina (mazo0, sigcarta, puntosChumano, puntosCmaquina);
				determinaGanador (puntosChumano, puntosCmaquina);
				if ( resultado == 1 ){
					cout << " Has ganado " << endl;
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


		default:
		{
		cout << "La opción es incorrecta" << endl;
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
	cout << " 3 para jugar en modo C " << endl;
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
	contador++;
	salida = menuB ();
	}
   return puntos;
}

float modoBmaquina ( ifstream& file, int numCartas, float puntosHumano ) {
	int carta, contador = 1;
	float puntos = 0;
	while ( ( contador <= numCartas ) && (  ) ) {
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

void modoChumano (ifstream& file, tCartasPorAparecer cartas, float& puntos){
	int roba;
	bool seguir = true;
	while ( seguir == true ) {
		file >> roba;
		cout << " La carta es: " << roba << endl;
		if ( roba <= 7 ) {
			puntos = roba + puntos;
			cartas [roba] = cartas [roba]-1;
		}
		else {
			puntos = puntos + 0.5;
			cartas [0] = cartas [0]-1;
		}
		cout << " Tus puntos son: " << puntos << endl;
		cout << "Quedan estas cartas: "<< endl;
		cout << "Figura " << cartas[0] << "  As " << cartas[1] << "  Dos " << cartas[2] << "  Tres " << cartas[3] << "  Cuatro " << cartas[4] << "  Cinco " << cartas[5] << "  Seis " << cartas[6] << "  Siete " << cartas[7] << endl;
		cout << "continuar" << endl;
		seguir = menuB ();  //llamar a la función menub
	}
}

void modoCmaquina (ifstream& file, tCartasPorAparecer cartas, float puntosHumano, float& puntos){
	int roba;
	//bool seguir = false ;


		if (puntosHumano > puntos) {
			file >> roba;
			cout << " La carta es: " << roba << endl;
			if ( roba <= 7 ) {
			puntos = roba + puntos;
			cartas [roba] = cartas [roba]-1;
			}
			else {
			puntos = puntos + 0.5;
			cartas [0] = cartas [0]-1;
			}
		}

		else {
			if ( puntosHumano == puntos ){
			while (esProbablePasarse( puntos, cartas ) == true)   {
		    file >> roba;
			cout << " La carta es: " << roba << endl;
			if ( roba <= 7 ) {
			puntos = roba + puntos;
			cartas [roba] = cartas [roba]-1;
			}
			else {
			puntos = puntos + 0.5;
			cartas [0] = cartas [0]-1;
			}

			}


		}
	}
}

bool esProbablePasarse (float puntosMaquina, const tCartasPorAparecer cartas){
	bool seguir;
	int CartasTotales = 0, CartasPosibles = 0, num = 7;
	//int PuntosHumanoInt =  modoChumano ( PuntosHumanoInt )

	for ( int i = 0; i < num; i++ ) {
		CartasTotales = cartas [i] + CartasTotales;

	}

	for ( int i = 7 - puntosMaquina + 1; i < num; i++ ) {
		CartasPosibles = cartas [i] + CartasPosibles;
	}
	if (( CartasPosibles / CartasTotales  > 0,5  )) {
		seguir = false;
	}
	else {
	seguir = true;

	}
	return seguir;
}

int determinaGanador ( float puntosJugador, float puntosMaquina ) {
	int resultado;
	const int RandomGanaHumano = 1;
	const int RandomGanaMaquina = 2;
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
		resultado = RandomGanaHumano + rand() % (RandomGanaMaquina+1-RandomGanaHumano);
	}
	return resultado;
}
