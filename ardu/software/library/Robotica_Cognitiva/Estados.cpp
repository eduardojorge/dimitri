#include "Arduino.h"
#include <Estados.h>


Estados::Estados(byte _Pino_Botao_Direito, byte _Pino_Botao_Esquerdo, byte _Pino_Sensor_Som, byte _Pino_Echo, byte _Pino_Trigger){
  Pino_Botao_Direito = _Pino_Botao_Direito;          
  Pino_Botao_Esquerdo = _Pino_Botao_Esquerdo; 
  Pino_Sensor_Som = _Pino_Sensor_Som;
  Pino_Echo = _Pino_Echo;
  Pino_Trigger = _Pino_Trigger;
}

void Estados::Iniciar(){
	pinMode(Pino_Botao_Direito, INPUT_PULLUP);	
  pinMode(Pino_Botao_Esquerdo,  INPUT_PULLUP);
  pinMode(Pino_Sensor_Som, INPUT);
  us.init(Pino_Trigger, Pino_Echo);	
}

int Estados::Botao_Direito(){
  return(digitalRead(Pino_Botao_Direito)==LOW);
}

int Estados::Botao_Esquerdo(){
  return(digitalRead(Pino_Botao_Esquerdo)==LOW);
}

int Estados::Sensor_Som(){ 
  return !(digitalRead(Pino_Sensor_Som));
}

float Estados::Sensor_Distancia(){
  return us.read();
}
