#ifndef Acoes_h
#define Acoes_h


#include "Arduino.h"
#include "MaxMatrix.h"

class Acoes{
  private:
    MaxMatrix Boca = MaxMatrix(12, 11, 10, 1);
    byte Pino_Buzzer; 
    byte buffer[500];  
  public:
    Acoes(byte Pino_Buzzer);
    void Iniciar();    
    void Apaga_Tudo();
    void Liga_Tudo();
    void Imprimir(char* c);
    void Animacao(char* s, int shift_speed);
    void Imprime_Frase(char* s, int shift_speed);
    void printCharWithShift(char c, int shift_speed);
    void Tom_Buzzer(float noteFrequency, long noteDuration, int silentDuration);
    void Transforma_Buzzer(float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration);
    void Toca_Buzzer(int songName);
    void Joga_Dado();
    void Imprime_Frase(String string, int shift_speed);
    void Pixel(int linha, char* codigo);
    void Limpar_Pixel();
};

#endif