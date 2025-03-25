#include "./Carta.h"
#include <algorithm>
#include <random>

class Mazo{
    
    public:
        int n;
        Mazo();
        void barajar();
        Carta repartir();
        void mostrar();
        vector<Carta> cartas;

};