#include <Robotica_Cognitiva.h>

int x=0;

void loop(){
  if(Estado.Botao_Direito()){
   x++;
   Acao.Toca_Buzzer(Botao_Apertado);
  }
  if(x==3){
    Sentimento.Feliz();
    delay(2000);
    Acao.Apaga_Tudo();
    x=0;
  }
}
