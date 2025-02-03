#include "Arduino.h"
#include <virtuabotixRTC.h>
#include <Relogio.h>
#include "MaxMatrix.h"


  
 
Relogio::Relogio(int i){

    virtuabotixRTC myRTC(4, 3, 2);
    myRTC.setDS1302Time(00, 27, 7, 1, 2, 8, 2019);
    
}


boolean Relogio::Dormir(int hora,int minuto,int repeticao){

   myRTC.updateTime(); 

   if ( ((myRTC.hours>=hora) && (myRTC.minutes>=minuto))  && (repeticao_dormir<repeticao) ){
       
       repeticao_dormir++;
       return true;

   }else{
       return false; 

   }

 }


boolean Relogio::Acordar(int hora,int minuto, int repeticao){

   myRTC.updateTime(); 

   if ( ((myRTC.hours>=hora) && (myRTC.minutes>=minuto) && (repeticao_acordar<repeticao) )){
       repeticao_acordar++;
       return true;
   }else{
       return false; 

   }


 


 }

  boolean Relogio::Tarde(int horaInicio,int horaFim){

   myRTC.updateTime(); 

   if ((myRTC.hours>=horaInicio) && (myRTC.hours<=horaFim)){
       return true;
   }else{
       return false; 

   }
 }

 boolean Relogio::Manha(int horaInicio,int horaFim){

   myRTC.updateTime(); 

   if ((myRTC.hours>=horaInicio) && (myRTC.hours<=horaFim)){
       return true;
   }else{
       return false; 

   }


 }

 boolean Relogio::Noite(int horaInicio,int horaFim){

   myRTC.updateTime(); 

   if ((myRTC.hours>=horaInicio) && (myRTC.hours<=horaFim)){
       return true;
   }else{
       return false; 

   }


 }

 

 

 
 String Relogio::Imprime_Relogio(){


    myRTC.updateTime(); 

    String tempo= "  ";

   
    // Adiciona um 0 caso o valor da hora seja <10
    if (myRTC.hours < 10)
    {
      tempo.concat("0");
     // Acao.Imprime_Frase("0",80);
    }
    tempo.concat(myRTC.hours);

  
    tempo.concat(":");
    // Adiciona um 0 caso o valor dos minutos seja <10
    if (myRTC.minutes < 10)
    {
        tempo.concat(0);
    }
     tempo.concat(myRTC.minutes);
     tempo.concat(":");

    // Adiciona um 0 caso o valor dos segundos seja <10
    if (myRTC.seconds < 10)
    {
        tempo.concat(0);
    
    }
     tempo.concat(myRTC.seconds);

    
    //return tempo.c_str();
     
    return tempo;
  
  
}


String Relogio::Imprime_Dia_Da_Semana()
{
  myRTC.updateTime(); 

  int dia=myRTC.dayofweek;
   String temp= " ";
  switch (dia)
  {
    case 1:
     temp.concat("Domingo");
    break;
    case 2:
      temp.concat("Segunda");
    break;
    case 3:
     temp.concat("Terca");
    break;
    case 4:
     temp.concat("Quarta");
    break;
    case 5:
     temp.concat("Quinta");
    break;
    case 6:
     temp.concat("Sexta");
    break;
    case 7:
     temp.concat("Sabado");
    break;
  }

  return temp;

}




  
