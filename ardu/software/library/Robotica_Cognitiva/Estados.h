#ifndef Estados_h

#define Estados_h

#include "Arduino.h"
#include <US.h>

class Estados{
  private:
    byte Pino_Echo;
    byte Pino_Trigger;
    byte Pino_Botao_Direito;
    byte Pino_Botao_Esquerdo;
    byte Pino_Sensor_Som;
    US us;
  public:
    Estados(byte Pino_Botao_Direito, byte Pino_Botao_Esquerdo, byte Pino_Sensor_Som, byte Pino_Echo, byte Pino_Trigger);
    void Iniciar();
    int Botao_Direito();   
    int Botao_Esquerdo();
    int Sensor_Som();
    float Sensor_Distancia();
};

#endif