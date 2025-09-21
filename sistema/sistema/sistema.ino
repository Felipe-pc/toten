#include<Adafruit_SSD1306.h>
Adafruit_SSD1306 tela(128,64,&Wire,-1);//define a tela

void setup() {
//configuração da tela
tela.begin(SSD1306_SWITCHCAPVCC, 0x3C);//ativa a tela
tela.clearDisplay();//limpa a tela
tela.display();//atualiza a tela
tela.setTextSize(1);//define o tamanho da tela
tela.setTextColor(SSD1306_WHITE);//defini a cor da tela
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
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  pin1=digitalRead(5);
  pin2=digitalRead(4);
  pin3=digitalRead(3);
  pin4=digitalRead(2);
  if (pin1 == 1){
    return 1;
  }
  if (pin2== 1){
    return 2;
  }
  if (pin3== 1){
    return 3;
  }
  if (pin4== 1){
    return 4;
  }
  delay(20);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  pin1=digitalRead(5);
  pin2=digitalRead(4);
  pin3=digitalRead(3);
  pin4=digitalRead(2);
  if (pin1== 1){
    return 5;
  }
  if (pin2== 1){
    return 6;
  }
  if (pin3== 1){
    return 7;
  }
  if (pin4== 1){
    return 8;
  }
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  delay(20);
  pin1=digitalRead(5);
  pin2=digitalRead(4);
  pin3=digitalRead(3);
  pin4=digitalRead(2);
  if (pin1== 1){
    return 9;
  }
  if (pin2== 1){
    return 10;
  }
  if (pin3== 1){
    return 11;
  }
  if (pin4== 1){
    return 12;
  }
  delay(20);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  pin1=digitalRead(5);
  pin2=digitalRead(4);
  pin3=digitalRead(3);
  pin4=digitalRead(2);
  if (pin1== 1){
    return 13;
  }
  if (pin2== 1){
    return 14;
  }
  if (pin3== 1){
    return 15;
  }
  if (pin4== 1){
    return 16;
  }
}
}

void loop() {
delay(2000);
grafico(0,0,"funciona",2);
delay(4000);
tela.clearDisplay();
tela.display();
delay(2000);
}
