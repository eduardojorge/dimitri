#include "Arduino.h"
#include <Acoes.h>
#include <Letras.h>
#include <Sons.h>
#include <Animacoes.h>

char pixel[] ={8,8, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000};

Acoes::Acoes(byte _Pino_Buzzer){
    Pino_Buzzer = _Pino_Buzzer;
}

void Acoes::Iniciar(){
    pinMode(Pino_Buzzer,OUTPUT);
}


void Acoes::Limpar_Pixel(){
  for(int i=0;i<8;i++){
    for(int z=2; z<10;z++){
       pixel[z]=(0<<i);
    }
  }
  Boca.writeSprite(0, 0, pixel); 
}

void Acoes::Pixel(int linha, char* codigo){
  for(int coluna = 2,i=0;i<strlen(codigo);i++){ 
      if(codigo[i]=='1'){
        pixel[coluna]+=(1<<linha);
        Boca.writeSprite(0, 0, pixel); 
        coluna++;
      }else{
        pixel[coluna]+=(0<<linha);
        Boca.writeSprite(0, 0, pixel); 
        coluna++;
      } 
   }     
}

void Acoes::Apaga_Tudo(){
  Boca.clear();
}

void Acoes::Liga_Tudo(){
  Boca.TurnOn();
}

void Acoes::Imprimir(char* c){
    Boca.writeSprite(0, 0, c);
}

void Acoes::Animacao(char* s, int shift_speed){
  for(int i=1; i < s[0]; i++){
    memcpy_P(buffer, s + 10*i, 10);
    Boca.writeSprite(0, 0, buffer);
    delay(shift_speed);
    Boca.clear();
  }   
}

void Acoes::printCharWithShift(char c, int shift_speed){
  if (c < 32) return;
  c -= 32;
  memcpy_P(buffer, Letras + 7*c, 7);
  Boca.writeSprite(8, 0, buffer);
  Boca.setColumn(8 + buffer[0], 0); 
  for (int i=0; i<buffer[0]+1; i++){
    delay(shift_speed);
    Boca.shiftLeft(false, false);
  }
}


void Acoes::Imprime_Frase(String string, int shift_speed){
  char* s= string.c_str();
  while (*s != 0){
    printCharWithShift(*s, shift_speed);
    s++;
  }
}

void Acoes::Imprime_Frase(char* s, int shift_speed){
  char i[] = "  ";  
  char *y = i;
  char *x = i;
  while (*x != 0){
    printCharWithShift(*x, shift_speed);
    x++;
  }
  while (*s != 0){
    printCharWithShift(*s, shift_speed);
    s++;
  }
  while (*y != 0){
    printCharWithShift(*y, shift_speed);
    y++;
  }
}

void Acoes::Tom_Buzzer(float noteFrequency, long noteDuration, int silentDuration){
       if(silentDuration==0){
         silentDuration=1;
      }
      tone(Pino_Buzzer, noteFrequency, noteDuration);
      delay(noteDuration);       
      delay(silentDuration);     
}

void Acoes::Transforma_Buzzer (float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration){
  if(initFrequency < finalFrequency){
      for (int i=initFrequency; i<finalFrequency; i=i*prop){
          Tom_Buzzer(i, noteDuration, silentDuration);
      }
  } else{
      for (int i=initFrequency; i>finalFrequency; i=i/prop){
          Tom_Buzzer(i, noteDuration, silentDuration);
      }
  }
}

void Acoes::Toca_Buzzer(int songName){
  switch(songName){
    case Conectado:
      Tom_Buzzer(note_E5,50,30);
      Tom_Buzzer(note_E6,55,25);
      Tom_Buzzer(note_A6,60,10);
    break;

    case Desconectado:
      Tom_Buzzer(note_E5,50,30);
      Tom_Buzzer(note_A6,55,25);
      Tom_Buzzer(note_E6,50,10);
    break;

    case Botao_Apertado:
      Transforma_Buzzer (note_E6, note_G6, 1.03, 20, 2);
      delay(30);
      Transforma_Buzzer (note_E6, note_D7, 1.04, 10, 2);
    break;

    case Modo_1:
      Transforma_Buzzer (note_E6, note_A6, 1.02, 30, 10);  //1318.51 to 1760
    break;

    case Modo_2:
      Transforma_Buzzer (note_G6, note_D7, 1.03, 30, 10);  //1567.98 to 2349.32
    break;

    case Modo_3:
      Tom_Buzzer(note_E6,50,100); //D6
      Tom_Buzzer(note_G6,50,80);  //E6
      Tom_Buzzer(note_D7,300,0);  //G6
    break;

    case Surpresa:
      Transforma_Buzzer(800, 2150, 1.02, 10, 1);
      Transforma_Buzzer(2149, 800, 1.03, 7, 1);
    break;

    case OhOoh:
      Transforma_Buzzer(880, 2000, 1.04, 8, 3); //A5 = 880
      delay(200);

      for (int i=880; i<2000; i=i*1.04) {
           Tom_Buzzer(note_B5,5,10);
      }
    break;

    case OhOoh_2:
      Transforma_Buzzer(1880, 3000, 1.03, 8, 3);
      delay(200);

      for (int i=1880; i<3000; i=i*1.03) {
          Tom_Buzzer(note_C6,10,10);
      }
    break;

    case Carinhoso:
      Transforma_Buzzer(700, 900, 1.03, 16, 4);
      Transforma_Buzzer(899, 650, 1.01, 18, 7);
    break;

    case Sono:
      Transforma_Buzzer(100, 500, 1.04, 10, 10);
      delay(500);
      Transforma_Buzzer(400, 100, 1.04, 10, 1);
    break;

    case Feliz_1:
      Transforma_Buzzer(1500, 2500, 1.05, 20, 8);
      Transforma_Buzzer(2499, 1500, 1.05, 25, 8);
    break;

    case Super_Feliz:
      Transforma_Buzzer(2000, 6000, 1.05, 8, 3);
      delay(50);
      Transforma_Buzzer(5999, 2000, 1.05, 13, 2);
    break;

    case Feliz_2:
      Transforma_Buzzer(1500, 2000, 1.05, 15, 8);
      delay(100);
      Transforma_Buzzer(1900, 2500, 1.05, 10, 8);
    break;

    case Triste_1:
      Transforma_Buzzer(880, 669, 1.02, 20, 200);
    break;

    case Confuso:
      Transforma_Buzzer(1000, 1700, 1.03, 8, 2); 
      Transforma_Buzzer(1699, 500, 1.04, 8, 3);
      Transforma_Buzzer(1000, 1700, 1.05, 9, 10);
    break;

    case Pum_1:
      Transforma_Buzzer(1600, 3000, 1.02, 2, 15);
    break;

    case Pum_2:
      Transforma_Buzzer(2000, 6000, 1.02, 2, 20);
    break;

    case Pum_3:
      Transforma_Buzzer(1600, 4000, 1.02, 2, 20);
      Transforma_Buzzer(4000, 3000, 1.02, 2, 20);
    break;
  }
}

void Acoes::Joga_Dado(){
  int resultado = random(1, 7);  
  for(int i=1, d=50; d<200; d=d+10, i++){
      memcpy_P(buffer, dado + 10*i, 10);
      Boca.writeSprite(0, 0, buffer);
      delay(d);
      Boca.clear();
      if(i==7){
         i=1;
      }
  }
  memcpy_P(buffer, dado + 10*resultado, 10);
  Boca.writeSprite(0, 0, buffer); 
  delay(50); 
}