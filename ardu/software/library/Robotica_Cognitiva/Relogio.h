#ifndef Relogio_h
#define Relogio_h
#include <virtuabotixRTC.h>
#include "MaxMatrix.h"


class Relogio{
  private:
    
   virtuabotixRTC myRTC = virtuabotixRTC(4,3,2);
   int repeticao_dormir=0;
   int repeticao_acordar=0;
    
   // 
    
  
  public:
    Relogio(int i);


    boolean Manha(int horaInicio,int horaFim);
    boolean Tarde(int horaInicio,int horaFim);
    boolean Noite(int horaInicio,int horaFim);

    boolean Dormir(int hora,int minuto,int repeticao);
    boolean Acordar(int hora,int minuto,int repeticao);

    String  Imprime_Dia_Da_Semana();

     String Imprime_Relogio();
     


};

#endif