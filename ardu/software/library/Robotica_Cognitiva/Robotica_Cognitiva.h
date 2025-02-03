#define Robotica_Cognitiva_h

#define MatrizEmUso             1
#define Itensidade_Matrix       1

#include <Pinos.h>
#include <Caras.h>
#include <Letras.h>
#include <Animacoes.h>
#include <Sons.h>
#include <Estados.h>
#include <Acoes.h>
#include <Sentimentos.h>
#include <Relogio.h>
#include <Memoria.h>

MaxMatrix Boca = MaxMatrix(12, 11, 10, 1);
Estados Estado(_Pino_Botao_Direito, _Pino_Botao_Esquerdo, _Pino_Sensor_Som, _Pino_Echo, _Pino_Trigger);  
Acoes Acao(_Pino_Buzzer);
Sentimentos Sentimento(1);
Relogio Relogio(1);
Memoria Memoria(1);


void setup(){
    Boca.init(); 
    Boca.setIntensity(Itensidade_Matrix);	
    Estado.Iniciar(); 
    Acao.Iniciar();   
    Serial.begin(9600);
    byte buffer[500];
    randomSeed(analogRead(5));
}