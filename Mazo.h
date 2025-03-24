#include "./Carta.h"
#include <algorithm>
#include <random>

class Mazo{
    
    public:
        int n;
        Carta Cartas[36];
        Mazo();
        void barajar();
        Carta repartir();
        void mostrar();
    
};