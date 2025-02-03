#include <Robotica_Cognitiva.h>

void loop(){
  if(Estado.Botao_Esquerdo()&&Estado.Botao_Esquerdo()){
    Acao.Imprimir(raio); 
  }else{
    Acao.Apaga_Tudo();
  }
}
