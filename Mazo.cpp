#include "./Mazo.h"

Mazo::Mazo(){
    
    int indice = 0;
    n = 36;
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 4; j++){
            cartas.push_back(Carta(i + 1, j));

        }
        
    }
    
    
}

void Mazo::mostrar(){
   
    int indice = 0;
   
    for(int i = 0; i < 9; i++){
       
        for(int j = 0; j < 4; j++){
           
            indice = (4*i)+j;
            cartas[indice].mostrar();
           
        }
       
    }
   
}

void Mazo::barajar(){
    
    random_device semilla;
    mt19937 generador(semilla()); 
    shuffle(begin(cartas), end(cartas), generador);
}

Carta Mazo::repartir(){
    Carta carta = cartas.back();
    cartas.pop_back();
    return carta;
}