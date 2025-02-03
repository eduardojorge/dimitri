#include <Robotica_Cognitiva.h>

void loop(){
  if(Estado.Botao_Direito()){
    Acao.Liga_Tudo();
  }
  if(Estado.Botao_Esquerdo()){
    Acao.Apaga_Tudo();
  }
}
