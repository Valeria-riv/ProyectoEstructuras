#include "./Jugador.h"

Jugador::Jugador(int id){

    this -> id = id;

};

void Jugador::recibirCarta(Carta carta){

    mano.push_back(carta);
}

Carta Jugador::tirarCarta(int indice){


        Carta carta = mano[indice];
        mano.erase(mano.begin() + indice);
        return carta;
    
}

    void Jugador::mostrarMano() {
    cout << "Jugador " << id + 1 << ", tu mano: ";
    for (size_t i = 0; i < mano.size(); i++) {
        cout << "[" << i << "] ";
        mano[i].mostrar();
    }
}