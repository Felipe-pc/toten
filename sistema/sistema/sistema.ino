#include<Adafruit_SSD1306.h>
Adafruit_SSD1306 tela(128,64,&Wire,-1);
void setup() {
  // put your setup code here, to run once:
tela.begin(SSD1306_SWITCHCAPVCC, 0x3C);
tela.clearDisplay();
tela.display();
tela.setTextSize(1);
tela.setTextColor(SSD1306_WHITE);
}

void loop() {
  // put your main code here, to run repeatedly:
tela.setCursor(0,0);
tela.println("ola,mundo");
tela.setCursor(0,16);
tela.println("12");
tela.display();
delay(5000);
}
