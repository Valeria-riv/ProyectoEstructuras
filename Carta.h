#include <iostream>
#include <algorithm>
#include <random>

#define  BG_BLACK    "\x1B[40m"
#define  BG_RED      "\x1B[41m"
#define  BG_GREEN    "\x1B[42m"
#define  BG_BLUE     "\x1B[44m"
#define  WHITE       "\x1B[37m"
#define  RESET       "\x1b[0m"

using namespace std;

class Carta{
    
    public:
        string paleta[4] = {BG_RED,BG_BLUE,BG_BLACK,BG_GREEN};
        int poder;
        int color;
        Carta();
        Carta(int poder, int color);
        void mostrar();
};
