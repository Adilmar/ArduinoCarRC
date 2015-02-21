#include <SoftwareSerial.h>// biblioteca

SoftwareSerial Genotronex(6, 7); // RX, TX do Bluetooth
int frente=13;  
int re=12; 
int led=11; 
char BluetoothData; 
const int buzzer = 10;


void setup() {
  
  Genotronex.begin(9600);
  Genotronex.println("Conexao Realizada");
  pinMode(frente,OUTPUT);
  pinMode(re,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  
   if (Genotronex.available()){
   BluetoothData=Genotronex.read();
   
   //frente
   if(BluetoothData=='F'){   
   digitalWrite(re,0);
   digitalWrite(frente,1);
   //delay(100);
   }
   
   //back
  if (BluetoothData=='B'){
  digitalWrite(frente,0);
  digitalWrite(re,1);
  //delay(100);
  }
  
  //liga led carro
  if (BluetoothData=='W'){
  //digitalWrite(frente,0);
   digitalWrite(led,1);
  //delay(100);
 
  }
  //desliga led carro
   if (BluetoothData=='w'){
  //digitalWrite(frente,0);
  digitalWrite(led,0);
  //delay(100);

  }
  
  //liga buzina
   if (BluetoothData=='V'){
   tone(buzzer,1500);  
   delay(50); 
   
   }


  
  //desliga buzina
   if (BluetoothData=='v'){
    noTone(buzzer);
    delay(500); 

  }
  
  if (BluetoothData=='S'){
    digitalWrite(frente,0);
    digitalWrite(re,0);

  }
  
}
delay(100);// faz o controle dos motores para o proximo sinal enviado
//digitalWrite(frente,0);
//digitalWrite(re,0);

}


