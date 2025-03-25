#include "./Mazo.h"

class Jugador {
    public:
    int id;
    int boveda = 0;
    vector<Carta> mano;

    
    Jugador(int id);

    void recibirCarta(Carta carta);

    Carta tirarCarta(int indice);

    void mostrarMano();

};