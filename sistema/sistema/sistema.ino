#include<Adafruit_SSD1306.h>
Adafruit_SSD1306 tela(128,64,&Wire,-1);//define a tela

void setup() {
//configuração da tela
tela.begin(SSD1306_SWITCHCAPVCC, 0x3C);//ativa a tela
tela.clearDisplay();//limpa a tela
tela.display();//atualiza a tela
tela.setTextSize(1);//define o tamanho da tela
tela.setTextColor(SSD1306_WHITE);//defini a cor da tela
//ativação de pinos de teclado
pinMode(12,OUTPUT);
pinMode(14,OUTPUT);
pinMode(13,OUTPUT);
pinMode(27,OUTPUT);
pinMode(26,INPUT);
pinMode(25,INPUT);
pinMode(5,INPUT);
pinMode(18,INPUT);
Serial.begin(9600);
}

int grafico(int x,int y,char frase[25],int tamanho=1){
  tela.setTextSize(tamanho);
  tela.setCursor(x,y);
  tela.print(frase);
  tela.display();
  return 0;
}

int teclado(){
while(true){
  int pin1,pin2,pin3,pin4;
  delay(20);
  pinMode(12,HIGH);
  pinMode(13,LOW);
  pinMode(14,LOW);
  pinMode(27,LOW);
  pin1=analogRead(26);
  pin2=analogRead(25);
  pin3=analogRead(5);
  pin4=analogRead(18);
  if (pin1 == 4095){
    Serial.println(pin1);
    return 1;
  }
  if (pin2==4095){
    return 2;
  }
  if (pin3==4095){
    return 3;
  }
  if (pin4==4095){
    return 4;
  }
  delay(20);
  pinMode(12,LOW);
  pinMode(13,HIGH);
  pinMode(14,LOW);
  pinMode(27,LOW);
  pin1=digitalRead(26);
  pin2=digitalRead(25);
  pin3=digitalRead(5);
  pin4=digitalRead(18);
  if (pin1==4095){
    return 5;
  }
  if (pin2==4095){
    return 6;
  }
  if (pin3==4095){
    return 7;
  }
  if (pin4==4095){
    return 8;
  }
  pinMode(12,LOW);
  pinMode(13,LOW);
  pinMode(14,HIGH);
  pinMode(27,LOW);
  delay(20);
  pin1=digitalRead(26);
  pin2=digitalRead(25);
  pin3=digitalRead(5);
  pin4=digitalRead(18);
  if (pin1==4095){
    return 9;
  }
  if (pin2==4095){
    return 10;
  }
  if (pin3==4095){
    return 11;
  }
  if (pin4==4095){
    return 12;
  }
  delay(20);
  pinMode(12,LOW);
  pinMode(13,LOW);
  pinMode(14,LOW);
  pinMode(27,HIGH);
  pin1=digitalRead(26);
  pin2=digitalRead(25);
  pin3=digitalRead(5);
  pin4=digitalRead(18);
  if (pin1==4095){
    return 13;
  }
  if (pin2==4095){
    return 14;
  }
  if (pin3==4095){
    return 15;
  }
  if (pin4==4095){
    return 16;
  }
}
}

void loop() {
teclado();
delay(200);
}
