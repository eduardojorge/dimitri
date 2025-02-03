#include "Arduino.h"
#include "EEPROM.h"
#include "Memoria.h"


Memoria::Memoria(byte _Pino_Buzzer){
}
    

void Memoria::Grava_MeuNome(String nome){

 char c[10];
 strcpy( c, nome.c_str() );
 erase(12);
 writeMsg(c, nome.length());



  
}

String Memoria::Ler_MeuNome(){
  return readMsg(12);
}

void Memoria::writeMsg(byte* first, size_t len)
{
  for(int i = 0; i < len; i++)
  {
 	 EEPROM.write(i, first[i]);
  }
}

void Memoria::erase(int tamanho)
{
  for (int i = 0 ; i < tamanho ; i++)
  EEPROM.write(i, 0);
}

String Memoria::readMsg(size_t len)
{
  byte res;

  String conteudo = "";
  char caractere;
 
  for(int i = 0; i < len; i++)
  {
    res = EEPROM.read(i);
    if ((char)res != '\n'){
    
      conteudo.concat((char)res);
    }
 
  }
  return conteudo;
  
}


