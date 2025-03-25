#include <iostream>
#include "./Jugador.h"
using namespace std;


int main() {
	Mazo mazo1;
	mazo1.barajar();


	int cantidadjug;
	cout << endl << "Ingrese la cantidad de jugadores (Min 2, Max 4):  ";
	cin >> cantidadjug;

	switch (cantidadjug) {
	case 2: {
		mazo1.barajar();

		Jugador jug1(1);
		Jugador jug2(2);

		vector<Jugador*> jugadores = {&jug1, &jug2};

		for (int i = 0; i < 18; i++) {
			for (Jugador* Jugador: jugadores) {
				Jugador -> recibirCarta(mazo1.repartir());
			}
		}

		int jugadorInicial = rand() % 2;
		cout << "El jugador " << jugadorInicial + 1 << " empieza la partida." << endl;

		int ronda = 1;

		while (!jugadores[0]->mano.empty()) {
			int jugadorInicialRonda = jugadorInicial;
			vector<Carta> cartasTiradas;
			int colorObjetivo = -1;

			cout << "\n--- Ronda " << ronda << " ---" << endl;

			for (int i = 0; i < 2; i++) {
				int indiceJugadorActual = (jugadorInicialRonda + i) % 2;
				Jugador* jugador = jugadores[indiceJugadorActual];
				int indiceCarta;

				system("clear");

				cout << "\n--- Ronda " << ronda << " ---" << endl;
				if (i == 0) {
					cout << "Empieza el jugador " << (jugadorInicialRonda % 2) + 1 << endl;
				}

				if (!cartasTiradas.empty()) {
					cout << "Carta tirada: ";
					for ( Carta& carta : cartasTiradas) carta.mostrar();
					cout << endl;
				}

				jugador->mostrarMano();
				cout << endl << "Turno del jugador " << jugador->id << ". Elige una carta (0-" << jugador->mano.size() - 1 << "): ";
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
			int jugadorGanador = (jugadorInicialRonda + indiceGanador) % 2;
			jugadores[jugadorGanador]->boveda++;

			cout << "\n--- Fin de la ronda " << ronda << " ---" << endl;
			cout << "El ganador de la ronda es el jugador: " << jugadores[jugadorGanador]->id << " con la carta ";
			ganadora.mostrar();
			cout << endl;

			// Preparar siguiente ronda
			jugadorInicial = (jugadorInicial + 1) % 2;
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
		cout << "El ganador es el jugador: " << ganadorFinal->id << " con " << ganadorFinal->boveda << " cartas ganadas." << endl;

		break;
	}

	case 3: {
		mazo1.barajar();

		Jugador jug1(1);
		Jugador jug2(2);
		Jugador jug3(3);

		vector<Jugador*> jugadores = {&jug1, &jug2, &jug3};

		for (int i = 0; i < 12; i++) {
			for (Jugador* Jugador: jugadores) {
				Jugador -> recibirCarta(mazo1.repartir());
			}
		}


		int jugadorInicial = rand() % 3;
		cout << "El jugador " << jugadorInicial + 1 << " empieza la partida." << endl;

		int ronda = 1;

		while (!jugadores[0]->mano.empty()) {
			int jugadorInicialRonda = jugadorInicial;
			vector<Carta> cartasTiradas;
			int colorObjetivo = -1;

			cout << "\n--- Ronda " << ronda << " ---" << endl;

			for (int i = 0; i < 3; i++) {
				int indiceJugadorActual = (jugadorInicialRonda + i) % 3;
				Jugador* jugador = jugadores[indiceJugadorActual];
				int indiceCarta;

				system("clear");

				cout << "\n--- Ronda " << ronda << " ---" << endl;
				if (i == 0) {
					cout << "Empieza el jugador " << (jugadorInicialRonda % 3) + 1 << endl;
				}

				if (!cartasTiradas.empty()) {
					cout << "Carta tirada: ";
					for ( Carta& carta : cartasTiradas) carta.mostrar();
					cout << endl;
				}

				jugador->mostrarMano();
				cout << endl << "Turno del jugador " << jugador->id << ". Elige una carta (0-" << jugador->mano.size() - 1 << "): ";
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

			Carta ganadora = cartasTiradas[0];
			int indiceGanador = 0;
			for (size_t i = 0; i < cartasTiradas.size(); i++) {
				if (cartasTiradas[i].color == colorObjetivo && cartasTiradas[i].poder > ganadora.poder) {
					ganadora = cartasTiradas[i];
					indiceGanador = i;
				}
			}

			int jugadorGanador = (jugadorInicialRonda + indiceGanador) % 3;
			jugadores[jugadorGanador]->boveda++;

			cout << "\n--- Fin de la ronda " << ronda << " ---" << endl;
			cout << "El ganador de la ronda es el jugador: " << jugadores[jugadorGanador]->id << " con la carta ";
			ganadora.mostrar();
			cout << endl;

			jugadorInicial = (jugadorInicial + 1) % 3;
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
		cout << "El ganador es el jugador: " << ganadorFinal->id << " con " << ganadorFinal->boveda << " cartas ganadas." << endl;

		break;
	}


	case 4: {
		mazo1.barajar();

		Jugador jug1(1);
		Jugador jug2(2);
		Jugador jug3(3);
		Jugador jug4(4);

		vector<Jugador*> jugadores = {&jug1, &jug2, &jug3, &jug4};

		for (int i = 0; i < 9; i++) {
			for (Jugador* Jugador: jugadores) {
				Jugador -> recibirCarta(mazo1.repartir());
			}
		}

		int jugadorInicial = rand() % 4;
		cout << "El jugador " << jugadorInicial + 1 << " empieza la partida." << endl;

		int ronda = 1;

		while (!jugadores[0]->mano.empty()) {
			int jugadorInicialRonda = jugadorInicial;
			vector<Carta> cartasTiradas;
			int colorObjetivo = -1;

			cout << "\n--- Ronda " << ronda << " ---" << endl;

			for (int i = 0; i < 4; i++) {
				int indiceJugadorActual = (jugadorInicialRonda + i) % 4;
				Jugador* jugador = jugadores[indiceJugadorActual];
				int indiceCarta;

				system("clear");

				cout << "\n--- Ronda " << ronda << " ---" << endl;
				if (i == 0) {
					cout << "Empieza el jugador " << (jugadorInicialRonda % 4) + 1 << endl;
				}

				if (!cartasTiradas.empty()) {
					cout << "Carta tirada: ";
					for ( Carta& carta : cartasTiradas) carta.mostrar();
					cout << endl;
				}

				jugador->mostrarMano();
				cout << endl << "Turno del jugador " << jugador->id << ". Elige una carta (0-" << jugador->mano.size() - 1 << "): ";
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

			Carta ganadora = cartasTiradas[0];
			int indiceGanador = 0;
			for (size_t i = 0; i < cartasTiradas.size(); i++) {
				if (cartasTiradas[i].color == colorObjetivo && cartasTiradas[i].poder > ganadora.poder) {
					ganadora = cartasTiradas[i];
					indiceGanador = i;
				}
			}

			int jugadorGanador = (jugadorInicialRonda + indiceGanador) % 4;
			jugadores[jugadorGanador]->boveda++;

			cout << "\n--- Fin de la ronda " << ronda << " ---" << endl;
			cout << "El ganador de la ronda es el jugador: " << jugadores[jugadorGanador]->id << " con la carta ";
			ganadora.mostrar();
			cout << endl;

			jugadorInicial = (jugadorInicial + 1) % 4;
			ronda++;

			cout << "Presiona Enter para continuar...";
			cin.ignore();
			cin.get();
		}

		Jugador* ganadorFinal = jugadores[0];
		for (Jugador* jugador : jugadores) {
			if (jugador->boveda > ganadorFinal->boveda) {
				ganadorFinal = jugador;
			}
		}

		cout << "\n=== Fin del juego ===" << endl;
		cout << "El ganador es el jugador: " << ganadorFinal->id << " con " << ganadorFinal->boveda << " cartas ganadas." << endl;

		break;
	}

	default:
		cout << "Ingrese una cantidad de jugadores invalida";
	}


	return 0;
}