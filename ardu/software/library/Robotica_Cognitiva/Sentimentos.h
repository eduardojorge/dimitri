#ifndef Sentimentos_h

#define Sentimentos_h


#include "Arduino.h"
#include "Acoes.h"

class Sentimentos{
    private:
        Acoes Acao = Acoes(13);
        
    public:
      Sentimentos(int x);
      void Feliz();
      void Triste();
      void Raiva();
};
#endif