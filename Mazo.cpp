#include "./Mazo.h"

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