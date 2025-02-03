#include <Robotica_Cognitiva.h>

void loop(){
  if(Estado.Sensor_Som()){
    Acao.Toca_Buzzer(Surpresa);
    delay(2000);
  }
}
