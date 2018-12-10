//============================================================================
// Name        : Practica.cpp
// Author      : Chuyin Zhou Pan y Manuel Díaz del Campo Mínguez
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
#include <algorithm>
using namespace std;

const int LimiteInferior = 3, LimiteSuperior = 5,  Min = 8, Max = 40, ganaHumano = 1, ganaMaquina = 2;

typedef int tCartasPorAparecer [Min];
typedef int tAmazo [ Max ];
typedef struct {
	tAmazo baraja;
	int contador;
} tConjuntoCartas;

int menu ();
float modoA ( ifstream& file, int numCartas );
float modoBhumano ( ifstream& file, int numCartas );
float modoBmaquina ( ifstream& file, int numCartas, float puntosHumano );
int determinaGanador ( float puntosJugador, float puntosMaquina );
void modoChumano (ifstream& file, tCartasPorAparecer cartas, float& puntos);
void modoCmaquina (ifstream& file, tCartasPorAparecer cartas, float puntosHumano, float& puntos);
bool esProbablePasarse (float puntosMaquina, const tCartasPorAparecer cartas);
void inicializa ( tConjuntoCartas & cartas);
void sacarCarta ( tConjuntoCartas & cartas, int & carta);
void annadirCarta ( tConjuntoCartas & cartas, int carta);
void crearMazo ( tConjuntoCartas & mazo);
void modoDhumano ( tConjuntoCartas & mazo, tCartasPorAparecer cartas, tConjuntoCartas & cartasHumano, float & puntos);
void modoDmaquina( tConjuntoCartas & mazo, tCartasPorAparecer cartas, float puntosHumano, tConjuntoCartas & cartasMaquina, float & puntos);


int main () {
	tCartasPorAparecer sigcarta, resto;
	tConjuntoCartas mazo, cartasH, cartasM;
	ifstream mazo0;
	ofstream fichero;
	string baraja, ficheroSalida, ganador;
	int opn, max, numpartidas = 0;
	float puntosAhu, puntosAma, puntosBhu, puntosBma, puntosChumano, puntosCmaquina, resultado, puntosDhu, puntosDma;

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
				// Calcula cartas a robar
				max = LimiteInferior + rand() % (LimiteSuperior+1-LimiteInferior);
				cout << " El numero de cartas que vas a robar es: " << max << endl << endl;
				cout << " Cartas jugador1: " << endl;
				puntosAhu = modoA ( mazo0, max );
				if ( puntosAhu <= 7.5 ){
					cout << endl;
					cout << " Cartas jugador2: " << endl << endl;
					puntosAma = modoA ( mazo0, max );
					resultado = determinaGanador ( puntosAhu, puntosAma );
					// Muestra al ganador
					if ( resultado == ganaHumano ) {
						cout << " Has ganado " << endl << endl;
					}
					else {
						cout << " Has perdido " << endl << endl;
					}
				}
				else {
					cout << " Has perdido " << endl << endl;
				}
			}
			else {
				cout << " El archivo no existe " << endl << endl;
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
				cout << " El numero maximo de cartas que puedes robar es: " << max << endl << endl;
				cout << " Cartas jugador1: " << endl;
				puntosBhu = modoBhumano ( mazo0, max );
				if ( puntosBhu <= 7.5 ) {
					cout << endl;
					cout << " Cartas jugador2: " << endl << endl;
					puntosBma = modoBmaquina ( mazo0, max, puntosBhu );
					resultado = determinaGanador ( puntosBhu, puntosBma );
					if ( resultado == ganaHumano ) {
						cout << " Has ganado " << endl << endl;
					}
					else {
						cout << " Has perdido " << endl << endl;
					}
				}
				else {
					cout << " Has perdido " << endl << endl;
				}
		}
		else {
			cout << " El archivo no existe " << endl << endl;
		}
		mazo0.close();
        }
		break;

		case 3:
		{
			puntosChumano = 0;
			puntosCmaquina = 0;
			sigcarta [0] = 12;
			for ( int i = 1; i < Min; i++ ) {
				sigcarta [i] = 4;
			}
			cout << " Introduzca el mazo con el que desea jugar " << endl;
			cin >> baraja;
			mazo0.open ( baraja );
			if ( mazo0.is_open () ) {
				cout << endl;
				cout << " Cartas jugador1: " << endl;
				modoChumano ( mazo0, sigcarta, puntosChumano );
				if ( puntosChumano <= 7.5 ) {
					cout << endl;
					cout << " Cartas jugador2: " << endl << endl;
					modoCmaquina (mazo0, sigcarta, puntosChumano, puntosCmaquina);
					determinaGanador (puntosChumano, puntosCmaquina);
					if ( resultado == ganaHumano ) {
						cout << " Has ganado " << endl << endl;
					}
					else {
						cout << " Has perdido " << endl << endl;
					}
				}
				else {
					cout << " Has perdido " << endl << endl;
				}
			}
			else {
				cout << " El archivo no existe " << endl << endl;
			}
			mazo0.close();
        }
		break;

		case 4 :
		{
			cartasH.contador = 0;
			cartasM.contador = 0;
			puntosDhu = 0;
			puntosDma = 0;
			inicializa ( mazo );
			crearMazo ( mazo );
			resto [ 0 ] = 12;
			for ( int i = 1; i < Min; i++ ) {
				resto [ i ] = 4;
			}
			cout << " Cartas jugador1: " << endl;
			modoDhumano ( mazo, resto, cartasH, puntosDhu );
			if ( puntosDhu <= 7.5 ) {
				cout << endl;
				cout << " Cartas jugador2: " << endl;
				modoDmaquina ( mazo, resto, puntosDhu,cartasM, puntosDma );
				if ( ( puntosDhu == puntosDma ) && ( cartasM.contador != cartasH.contador ) ) {
					if ( cartasM.contador < cartasH.contador ) {
						cout << " Has perdido " << endl << endl;
						ganador = " Jugador2 ";
					}
					else {
						cout << " Has ganado " << endl << endl;;
						ganador = " Jugador1 ";
					}
				}
				else {
					resultado = determinaGanador ( puntosDhu, puntosDma );
					if ( resultado == 1 ) {
						cout << " Has ganado " << endl << endl;
						ganador = " Jugador1 ";
					}
					else {
						cout << " Has perdido " << endl << endl;
						ganador = " Jugador2 ";
					}
				}

			}
			else {
				cout << " Has perdido " << endl << endl;
				ganador = " Jugador2 ";
			}
			ficheroSalida = to_string ( numpartidas ) + ".txt";
			fichero.open ( ficheroSalida );
			fichero << " Partida: " << numpartidas << endl;
			fichero << " El ganador es: " << ganador << endl;;
			fichero << " Jugador1: " << puntosDhu << " puntos " << " y " << " cartas robadas: ";
			for ( int i = 0; i < cartasH.contador; i++ ) {
				fichero << " [ " << cartasH.baraja [ i ] << " ] " ;
			}
			fichero << endl;
			fichero << " Jugador2: " << puntosDma << " puntos " << " y " << " cartas robadas: ";
			for ( int i = 0; i < cartasM.contador; i++ ) {
				fichero << " [ " << cartasM.baraja [ i ] << " ] " ;
			}
			fichero <<  endl;
			fichero << " XXX " << endl;
			fichero.close ();
		}
		break;

		default:
		{
		cout << "La opcion es incorrecta" << endl;
		}
		}
		opn = menu ();
		numpartidas++;
		}
	return 0;
}

int menu () {
	int opcion;
	cout << " Elija una opcion: " << endl;
	cout << " 1 para jugar en modo A " << endl;
	cout << " 2 para jugar en modo B " << endl;
	cout << " 3 para jugar en modo C " << endl;
	cout << " 4 para jugar en modo D " << endl;
	cout << " 0 para salir " << endl;
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
	int salir = 1, carta, contador = 1;
	float puntos = 0;
	while ( ( contador <= numCartas ) && ( salir == 1 ) ) {
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
	cout << " ¿ Quieres seguir robando ? " << endl;
	cout << " 1 = si, 0 = no " << endl;
	cin >> salir;
	}
   return puntos;
}

float modoBmaquina ( ifstream& file, int numCartas, float puntosHumano ) {
	int carta, contador = 1;
	bool plantarse = true;
	float puntos = 0;
	while ( ( contador <= numCartas ) && ( plantarse ) ) {
		file >> carta;
		cout << " La carta es: " << carta << endl;
		if ( carta <= 7 ) {
			puntos = carta + puntos;
		}
		else {
			puntos = puntos + 0.5;
		}
		cout << " Los puntos son: " << puntos << endl;
		if (( puntos == 7.5 ) || ( puntos > puntosHumano ) ) {
			plantarse = false;
		}
		contador++;
	}
	return puntos;
}

int determinaGanador ( float puntosJugador, float puntosMaquina ) {
	int resultado;
	// Determina el ganador
	if ( puntosJugador > puntosMaquina ) {
		resultado = ganaHumano;
	}
	else if ( puntosMaquina > puntosJugador ) {
		if ( puntosMaquina > 7.5 ) {
			resultado = ganaHumano;
		}
		else {
			resultado = ganaMaquina;
		}
	}
	else {
		resultado = ganaHumano + rand() % ( ganaMaquina+1-ganaHumano );
	}
	return resultado;
}

void modoChumano (ifstream& file, tCartasPorAparecer cartas, float& puntos){
	int roba, seguir = true;
	while ( seguir == 1 ) {
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
		cout << "Quedan en el mazo: "<< endl;
		cout << " Figuras = " << cartas [0] << " ; ";
		for ( int i = 1; i < Min; i++ ) {
			cout << " [ " << i << " ]= " << cartas [ i ] << " ; ";
		}
		cout << endl;
		cout << " ¿ Quieres seguir robando ? " << endl;
		cout << " 1 = si, 0 = no " << endl;
		cin >> seguir;	}
}

void modoCmaquina (ifstream& file, tCartasPorAparecer cartas, float puntosHumano, float& puntos){
	int roba;
	bool pasarse = false;
	do {
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
		cout << " Los puntos son: " << puntos << endl;
		cout << "Quedan en el mazo: "<< endl;
		cout << " Figuras = " << cartas [0] << " ; ";
		for ( int i = 1; i < Min; i++ ) {
			cout << " [" << i << "]= " << cartas [ i ] << " ; ";
		}
		cout << endl;
		pasarse = esProbablePasarse ( puntos, cartas );
	} while ( !pasarse );
}

bool esProbablePasarse (float puntosMaquina, const tCartasPorAparecer cartas){
	bool seguir;
	float CartasTotales = 0, CartasPosibles = 0, diferencia;
	for ( int i = 0; i < Min; i++ ) {
		CartasTotales = cartas [i] + CartasTotales;
	}
	diferencia = 8 - puntosMaquina;
	// Te pasas con el numero 8
	for ( int i = diferencia; i < Min; i++ ) {
		CartasPosibles = cartas [i] + CartasPosibles;
	}
	if (( CartasPosibles / CartasTotales ) > 0.5 ) {
		seguir = true;
	}
	else {
		seguir = false;
	}
	return seguir;
}

void inicializa ( tConjuntoCartas & cartas ) {
	for ( int i = 0; i < Max; i = i+10 ) {
		for ( int j = 0; j <= 10; j++ ) {
			if ( j < 7 ) {
				cartas.baraja[ i+j ] = j+1;
			}
			else {
				cartas.baraja[ i+j ] = j+3;
			}
		}
	}
	cartas.contador = Max;
}

void crearMazo ( tConjuntoCartas & mazo) {
	random_shuffle ( &mazo.baraja [ 0 ], &mazo.baraja [ 39 ] );
}

void sacarCarta ( tConjuntoCartas & cartas, int & carta) {
	carta = cartas.baraja[ cartas.contador-1 ];
	cartas.contador--;
	// Actualizamos contador
}

void annadirCarta ( tConjuntoCartas & cartas, int carta) {
	cartas.baraja [ cartas.contador ] = carta;
	cartas.contador++;
	// Actualizamos contador
}

void modoDhumano ( tConjuntoCartas & mazo, tCartasPorAparecer cartas, tConjuntoCartas & cartasHumano, float & puntos) {
	int robo, respuesta;
	do {
		sacarCarta ( mazo, robo );
		annadirCarta ( cartasHumano, robo );
		if ( robo <= 7 ) {
			puntos = puntos + robo;
			cartas [ robo ] = cartas [ robo ]-1;
		}
		else {
			puntos = puntos + 0.5;
			cartas [ 0 ] = cartas [ 0 ]-1;
		}
		cout << " La carta es: " << robo << endl;
		cout << " Tus puntos son: " << puntos << endl;
		cout << " Las cartas que tienes son: " << endl;
		for ( int i = 0; i < cartasHumano.contador; i++ ) {
			cout << " [ " << cartasHumano.baraja [ i ] << " ] " << " ; ";
		}
		cout << endl;
		cout << " Las cartas que quedan en el mazo son: " << endl;
		cout << " Figuras = " << cartas [ 0 ] << " ; ";
		for ( int i = 1; i < Min; i++ ) {
			cout << " [ " << i << " ] " << " = " << cartas [ i ] << " ; ";
		}
		cout << endl;
		cout << " ¿ Quieres seguir robando ? " << endl;
		cout << " 1 = si, 0 = no " << endl;
		cin >> respuesta;
	} while ( respuesta == 1);
}

void modoDmaquina( tConjuntoCartas & mazo, tCartasPorAparecer cartas, float puntosHumano, tConjuntoCartas & cartasMaquina, float & puntos) {
	int robo;
	bool pasarse;
	do {
		sacarCarta ( mazo, robo );
		annadirCarta ( cartasMaquina, robo );
		if ( robo <= 7 ) {
			puntos = puntos + robo;
			cartas [ robo ] = cartas [ robo ]-1;
		}
		else {
			puntos = puntos + 0.5;
			cartas [ 0 ] = cartas [ 0 ]-1;
		}
		cout << " La carta es: " << robo << endl;
		cout << " Los puntos son: " << puntos << endl;
		cout << " Las cartas robadas son: " << endl;
		for ( int i = 0; i < cartasMaquina.contador; i++ ) {
			cout << " [ " << cartasMaquina.baraja [ i ] << " ] " << " ; " ;
		}
		cout << " Las cartas que quedan por robar son: " << endl;
		cout << " Figuras = " << cartas [ 0 ] << " ; " ;
		for ( int i = 1; i < Min; i++ ) {
			cout << " [ " << i << " ] " << " = " << cartas [ i ] << " ; " ;
		}
		cout << endl;
		pasarse = esProbablePasarse ( puntos, cartas );
	} while ( !pasarse );
}
