#ifndef Memoria_h
#define Memoria_h


#include "EEPROM.h"


class Memoria{
  private:
    
  public:
    Memoria(byte Pino_Buzzer);
    void Grava_MeuNome(String nome);
    String Ler_MeuNome();
    void erase(int tamanho);
    String Memoria::readMsg(size_t len);
    void writeMsg(byte* first, size_t len);

  
};

#endif