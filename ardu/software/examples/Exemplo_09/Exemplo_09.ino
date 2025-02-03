#include <Robotica_Cognitiva.h>

void loop(){
 while(Estado.Sensor_Distancia()<15){
  Acao.Imprime_Frase("Ardu",80);
 }
 Acao.Liga_Tudo();
}
