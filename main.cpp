#include <iostream>
#include "./Jugador.h"
using namespace std;


int main() {
	Mazo mazo1;
	mazo1.barajar();


	int cantidadjug;
	cout << endl << "Ingrese la cantidad de jugadores (Min 2, Max 4):  ";
	cin >> cantidadjug;

	if (cantidadjug <=4){
		mazo1.barajar();

		
		vector<Jugador*> jugadores;
		
		for(int i = 0; i < cantidadjug; i++){
		    
		    jugadores.push_back( new Jugador(i));
		    
		}

        
		for (int i = 0; i < (36/cantidadjug); i++) {
			for (Jugador* Jugador: jugadores) {
				Jugador -> recibirCarta(mazo1.repartir());
			}
		}

		int jugadorInicial = rand() % cantidadjug;
		cout << "El jugador " << jugadorInicial + 1 << " empieza la partida." << endl;

		int ronda = 1;

		while (!jugadores[0]->mano.empty()) {
			int jugadorInicialRonda = jugadorInicial;
			vector<Carta> cartasTiradas;
			int colorObjetivo = -1;

			cout << "\n--- Ronda " << ronda << " ---" << endl;

			for (int i = 0; i < cantidadjug; i++) {
				int indiceJugadorActual = (jugadorInicialRonda + i) % cantidadjug;
				Jugador* jugador = jugadores[indiceJugadorActual];
				int indiceCarta;

				system("clear");

				cout << "\n--- Ronda " << ronda << " ---" << endl;
				if (i == 0) {
					cout << "Empieza el jugador " << (jugadorInicialRonda % cantidadjug) + 1 << endl;
				}

				if (!cartasTiradas.empty()) {
					cout << "Carta tirada: ";
					for ( Carta& carta : cartasTiradas) carta.mostrar();
					cout << endl;
				}

				jugador->mostrarMano();
				cout << endl << "Turno del jugador " << jugador->id + 1 << ". Elige una carta (0-" << jugador->mano.size() - 1 << "): ";
				cin >> indiceCarta;

				while (indiceCarta < 0 || indiceCarta >= jugador->mano.size()) {
					cout << "Carta invalida. Elige de nuevo: ";
					cin >> indiceCarta;
				}

				if (i == 0) {
					colorObjetivo = jugador->mano[indiceCarta].color;
				}

				cartasTiradas.push_back(jugador->tirarCarta(indiceCarta));
			}

			// Determinar ganador
			Carta ganadora = cartasTiradas[0];
			int indiceGanador = 0;
			for (size_t i = 0; i < cartasTiradas.size(); i++) {
				if (cartasTiradas[i].color == colorObjetivo && cartasTiradas[i].poder > ganadora.poder) {
					ganadora = cartasTiradas[i];
					indiceGanador = i;
				}
			}

			// Calcular jugador ganador de la ronda
			int jugadorGanador = (jugadorInicialRonda + indiceGanador) % cantidadjug;
			jugadores[jugadorGanador]->boveda++;

			cout << "\n--- Fin de la ronda " << ronda << " ---" << endl;
			cout << "El ganador de la ronda es el jugador: " << jugadores[jugadorGanador]->id + 1 << " con la carta ";
			ganadora.mostrar();
			cout << endl;

			// Preparar siguiente ronda
			jugadorInicial = (jugadorInicial + 1) % cantidadjug;
			ronda++;

			cout << "Presiona Enter para continuar...";
			cin.ignore();
			cin.get();
		}

		// Ganador final
		Jugador* ganadorFinal = jugadores[0];
		for (Jugador* jugador : jugadores) {
			if (jugador->boveda > ganadorFinal->boveda) {
				ganadorFinal = jugador;
			}
		}

		cout << "\n=== Fin del juego ===" << endl;
		cout << "El ganador es el jugador: " << ganadorFinal->id + 1<< " con " << ganadorFinal->boveda << " cartas ganadas." << endl;

	} else {
	    cout << "Ingreso una cantidad de jugadores invalida";
	}

	return 0;
}