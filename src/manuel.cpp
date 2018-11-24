


//determinar ganador 22/11/2018

int determinaGanador ( float puntosJugador, float puntosMaquina ){
	int resultado;
	const int limiteInferior = 1;
	const int limiteSuperior = 2;
	if (( puntosMaquina > puntosJugador ) && (puntosMaquina <= 7,5 )){

		resultado = 2;
	}
		else if ( puntosMaquina > 7,5 ) && ( puntosJugador <= 7,5 ){

			resultado = 1;
		}
		else {

			resultado = 1;

		 }

		else if (( puntosMaquina < puntosJugador ) && ( puntosJugador < 7,5 )){

					resultado = 1;
				}
				else if ((puntosJugador > 7,5 ) && ( puntosMaquina < 7,5 )){
					resultado = 2;
				}
					else{
						resultado = 2;
					}
					else{
						resultado = limiteInferior + rand() % (limiteSuperior+1-limiteInferior);
					}
      }

					return resultado;









