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

void loop() {
delay(2000);
grafico(0,0,"funciona",2);
delay(4000);
tela.clearDisplay();
tela.display();
delay(2000);
}
