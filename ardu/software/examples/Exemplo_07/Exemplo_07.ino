#include <Robotica_Cognitiva.h>

long tempoInicial = millis();
long intervalo = 6000;

void loop(){
 long tempoAtual = millis();
 long tempoDiferenca = tempoAtual - tempoInicial;
 if(tempoDiferenca>intervalo){
  Sentimento.Feliz();
  Acao.Toca_Buzzer(Feliz_1);
  tempoInicial=tempoAtual;
 }else{

  Acao.Apaga_Tudo();
  delay(2000);
 }
}
