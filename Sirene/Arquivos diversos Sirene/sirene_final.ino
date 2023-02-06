// projeto final sirene 02 tons (horn hi-yelp)
// finalizado dia 18/09/2016

#define tempo 10
int frequencia = 0;
int Pinofalante = 10;
int Botao1 = 3; // aciona o horn
int Botao2 = 6; // aciona/desaciona yelp
int led=13;      // led no pino 13
int var2=0;     // valor guardado
int estado=0;  // guarda o valor 0 ou 1 (HIGH ou LOW)
int val1 = HIGH;
int val2 = HIGH;


#include <NewTone.h>

void setup()
{
  pinMode(Pinofalante,OUTPUT); //Pino do buzzer
  pinMode(Botao1,INPUT); //Pino do Botao1
  pinMode(Botao2,INPUT); //Pino do Botao2
}

void loop()
{
  int sirene; // declara a varivel da funcao de sirene
  
  val1 = digitalRead(Botao1); // passa valor do Botao1 e verifica se Botao1 foi pressionado
  val2 = digitalRead(Botao2); // passa valor do Botao2 e verifica se Botao2 foi pressionado

  // o Botao1 pressionado em negativo, positivo no resistor
  if (val1 == LOW) {
         sirene = sirene_0(); // executa o horn

  }  
  
  if ((val2 == LOW) && (var2 == HIGH)) {
    estado = 1 - estado;
  }
  var2=val2;
  if (estado == 1) {
    sirene = sirene_1();
  } else {
    //
  }
}

  int sirene_0(){
     for (frequencia = 400; frequencia <= 1000; frequencia += 5) 
     {
       NewTone(Pinofalante, frequencia, tempo);
        if (digitalRead(Botao1) == HIGH) { // se o Botao1 foi solto, interrompa a funcao
          return 0;
        }       
     }
  }
  
  // sirene yelp com interrupcao no Botao1
  int sirene_1(){
     for (frequencia = 300; frequencia < 1500; frequencia += 1) 
     {
        // parada atraves do Botao1
        if (digitalRead(Botao1) == LOW) {
          return 0;
        }
        else if (digitalRead(Botao2) == LOW) {
          return 0;
        }

        
       NewTone(Pinofalante, frequencia, tempo); 
       
     }
     for (frequencia = 1500; frequencia > 300; frequencia -= 1) 
     {
        // parada atraves do Botao1
        if (digitalRead(Botao1) == LOW) {
          return 0;
        }       
        else if (digitalRead(Botao2) == LOW) {
          return 0;
        }
       NewTone(Pinofalante, frequencia, tempo); 
       
     }
  }
