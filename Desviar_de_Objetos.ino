//Incluindo biblioteca Ultrasonic.h
#include "Ultrasonic.h"

//Criando objeto ultrasonic e definindo as portas digitais
//do Trigger - 9 - e Echo - 10
Ultrasonic SensorUltrassonico1(9, 10);


long Microsegundos = 0;// Variável para armazenar o valor do tempo da reflexão do som refletido pelo objeto fornecido pela biblioteca do sensor
float DistanciaemCM = 0;// Variável para armazenar o valor da distância a ser convertido por uma função da própria bilbioteca do sensor


#define MotorEsquerdo1 4
#define MotorEsquerdo2 5
#define MotorDireito1  6
#define MotorDireito2  7


void setup() {

  //Definições de entrada e saída 
  
  pinMode(MotoEsquerdo1, OUTPUT);
  pinMode(MotorEsquerdo2, OUTPUT);
  pinMode(MotorDireito1, OUTPUT);
  pinMode(MotorDireito2, OUTPUT);

  Serial.begin(115200);// Inicia a comunicação seria com velocidade de 115200 bits por segundo

  delay(4000);// Vamos dar um tempo de 4 segundos aqui o suficiente para ligar o carrinho e colocar no chao
}

void loop() {

  //Convertendo a distância em CM e mostrando da porta serial
  DistanciaemCM = SensorUltrassonico1.convert(SensorUltrassonico1.timing(), Ultrasonic::CM);

  Serial.print(DistanciaemCM);
  Serial.println(" cm");


  if (DistanciaemCM <= 30) {// Se a distância lida pelo sensor for menor ou igual que 30 centimetros

    // Motor lado esquerdo para trás
    digitalWrite(MotorEsquerdo1, HIGH);
    digitalWrite(MotorEsquerdo2, LOW);


    // Motor lado direito para trás
    digitalWrite(MotorDireito1, HIGH);
    digitalWrite(MotoDireito2, LOW);

    delay(1000);// o carrinho ira se mover para tras durante 1 segundo


    // Motor lado esquerdo para frente
    digitalWrite(MotorEsquerdo1, LOW);
    digitalWrite(MotorEsquerdo2, HIGH);


    // Motor lado direito para trás
    digitalWrite(MotorDireito1, HIGH);
    digitalWrite(MotorDireito2, LOW);

    delay(200);// após ele ir para tras ira rodar para o lado direito durante 200 milisegundos

  }


  else {// Se a distancia for maior que 30 centimetros o carrinho pode ir para frente ate encontrar um obstaculo

   
    // Motor lado esquerdo para frente
    digitalWrite(MotorEsquerdo1, LOW);
    digitalWrite(MotorEsquerdo2, HIGH);


    // Motor lado direito para frente
    digitalWrite(MotorDireito1, LOW);
    digitalWrite(MotorDireito2, HIGH);
  }

}
