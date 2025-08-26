#include <Adafruit_SSD1306.h>
Adrafruit_SSD1306 tela(128,64,&wire,-1);
void setup() {
tela.begin(SSD1306_SWITCHCAPVCC, 0x3C);
tela.clearDisplay();
tela.display();
}
void loop() {

}
