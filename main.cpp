#include <iostream>

#define  BG_BLACK    "\x1B[40m"
#define  BG_RED      "\x1B[41m"
#define  BG_GREEN    "\x1B[42m"
#define  BG_AMARILLO "\x1B[43m"
#define  BG_BLUE     "\x1B[44m"
#define  BG_MAGENTA  "\x1B[45m"
#define  BG_CYAN     "\x1B[46m"
#define  BG_BLANCO   "\x1B[47m"
#define  BG_NARANJA  "\x1B[48;2;255;128;0m"
#define  BG_LBLUE    "\x1B[48;2;53;149;240m"
#define  BG_LGREEN   "\x1B[48;2;17;245;120m"
#define  BG_GRAY     "\x1B[48;2;176;174;174m"
#define  BG_ROSE     "\x1B[48;2;255;151;203m"
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

Carta::Carta(){
    
    this->poder = 0;
    this->color = 0;
    
}

Carta::Carta(int poder, int color){
    
    this->poder = poder;
    this->color = color;
    
}

void Carta::mostrar(){
    
    cout << WHITE  << paleta[color] << poder  <<  RESET << " ";
    
}


class Mazo{
    
    public:
        int n;
        Carta Cartas[36];
        Mazo();
        void barajar();
        Carta repartir();
        void mostrar();
    
};

Mazo::Mazo(){
    
    int indice = 0;
    n = 36;
    
    for(int i = 0; i < 9; i++){
        
        for(int j = 0; j < 4; j++){
            
            
            indice = (4*i)+j;
            Cartas[indice].poder = i+1;
            Cartas[indice].color = j;
            
        }
        
    }
    
    
}

void Mazo::mostrar(){
    
    int indice = 0;
    
    for(int i = 0; i < 9; i++){
        
        for(int j = 0; j < 4; j++){
            
            indice = (4*i)+j;
            Cartas[indice].mostrar();
            
        }
        
    }
    
}

int main(){
    
    Carta unaCarta(3,1);
   // unaCarta.mostrar();
   // cout << endl;
    
    Mazo baraja;
    baraja.mostrar();

    return 0;
}