#include "Arduino.h"
#include <Sentimentos.h>
#include <Caras.h>



Sentimentos::Sentimentos(int x){
        
};

void Sentimentos::Feliz(){
        Acao.Imprimir(feliz);
}

void Sentimentos::Triste(){
        Acao.Imprimir(triste);
}

void Sentimentos::Raiva(){
        Acao.Imprimir(raiva);
        
}