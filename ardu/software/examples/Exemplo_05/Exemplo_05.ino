#include <Robotica_Cognitiva.h>

void loop(){
  if(Estado.Botao_Esquerdo()){
    Acao.Imprimir(um);
    delay(2000);
    Acao.Imprimir(dois);
    delay(2000);
    Acao.Imprimir(tres);
    delay(2000);
    Acao.Apaga_Tudo();
  }
}
