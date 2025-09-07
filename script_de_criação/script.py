arquivo = open('sistema.ino','a')
arquivo.white("""
#include<Adafruit_SSD1306.h>
Adafruit_SSD1306 tela(128,64,&Wire,-1);//define a tela

void setup() {
tela.begin(SSD1306_SWITCHCAPVCC, 0x3C);//ativa a tela
tela.clearDisplay();//limpa a tela
tela.display();//atualiza a tela
tela.setTextSize(1);//define o tamanho da tela
tela.setTextColor(SSD1306_WHITE);//defini a cor da tela
}""")
arquivo.white("""
int grafico(int x,int y,char frase[25],int tamanho=1){
tela.setTextSize(tamanho);
tela.setCursor(x,y);
tela.print(frase);
tela.display();
return 0;
}""")
arquivo.white("""
void loop() {
grafico(0,0,"ola,mundo",2);
grafico(0,16,"12 douze");
delay(5000);
tela.clearDisplay();
delay(2000);
}""")
