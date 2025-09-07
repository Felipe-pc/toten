arquivo = open('sistema.ino','a')

linhas=[]
colunas=[]
print("iniciando criação...")
print("para iniciar vamos definir os pinos de colunas e linhas no teclado")
print("primeiro 4 colunas, digite o numero dos quatro pinos")
for i in range(0,4):
    recebe=int(input(">>>"))
    colunas.append(recebe)
print("agora 4 linhas, digite o numero dos quatro outros pinos")
for i in range(0,4):
    recebe2=int(input(">>>"))
    linhas.append(recebe2)

#cabeçalho
arquivo.write(f"""
#include<Adafruit_SSD1306.h>
Adafruit_SSD1306 tela(128,64,&Wire,-1);//define a tela

void setup() {'{'}
    //configuração da tela
    tela.begin(SSD1306_SWITCHCAPVCC, 0x3C);//ativa a tela
    tela.clearDisplay();//limpa a tela
    tela.display();//atualiza a tela
    tela.setTextSize(1);//define o tamanho da tela
    tela.setTextColor(SSD1306_WHITE);//defini a cor da tela
    //ativação de pinos de teclado
    pinMode({linhas[0]},OUTPUT);
    pinMode({linhas[1]},OUTPUT);
    pinMode({linhas[2]},OUTPUT);
    pinMode({linhas[3]},OUTPUT);
    pinMode({colunas[0]},INPUT);
    pinMode({colunas[1]},INPUT);
    pinMode({colunas[2]},INPUT);
    pinMode({colunas[3]},INPUT);
{'}'}
""")

#grafivo
arquivo.write("""
int grafico(int x,int y,char frase[25],int tamanho=1){
tela.setTextSize(tamanho);
tela.setCursor(x,y);
tela.print(frase);
tela.display();
return 0;
}""")

#teclado
arquivo.write(f"""
int teclado(){'{'}
while(true){'{'}
  int pin1,pin2,pin3,pin4;
  delay(200);
  pinMode({linhas[0]},HIGH);
  pinMode({linhas[1]},LOW);
  pinMode({linhas[2]},LOW);
  pinMode({linhas[3]},LOW);
  pin1=digitalRead({colunas[0]});
  pin2=digitalRead({colunas[1]});
  pin3=digitalRead({colunas[2]});
  pin4=digitalRead({colunas[3]});
  if (pin1==4095){'{'}
    return 1;
  {'}'}
  if (pin2==4095){'{'}
    return 2;
  {'}'}
  if (pin3==4095){'{'}
    return 3;
  {'}'}
  if (pin4==4095){'{'}
    return 4;
  {'}'}
  delay(200);
  pinMode({linhas[0]},LOW);
  pinMode({linhas[1]},HIGH);
  pinMode({linhas[2]},LOW);
  pinMode({linhas[3]},LOW);
  pin1=digitalRead({colunas[0]});
  pin2=digitalRead({colunas[1]});
  pin3=digitalRead({colunas[2]});
  pin4=digitalRead({colunas[3]});
  if (pin1==4095){'{'}
    return 5;
  {'}'}
  if (pin2==4095){'{'}
    return 6;
  {'}'}
  if (pin3==4095){'{'}
    return 7;
  {'}'}
  if (pin4==4095){'{'}
    return 8;
  {'}'}
  pinMode({linhas[0]},LOW);
  pinMode({linhas[1]},LOW);
  pinMode({linhas[2]},HIGH);
  pinMode({linhas[3]},LOW);
  delay(200);
  pin1=digitalRead({colunas[0]});
  pin2=digitalRead({colunas[1]});
  pin3=digitalRead({colunas[2]});
  pin4=digitalRead({colunas[3]});
  if (pin1==4095){'{'}
    return 9;
  {'}'}
  if (pin2==4095){'{'}
    return 10;
  {'}'}
  if (pin3==4095){'{'}
    return 11;
  {'}'}
  if (pin4==4095){'{'}
    return 12;
  {'}'}
  delay(200);
  pinMode({linhas[0]},LOW);
  pinMode({linhas[1]},LOW);
  pinMode({linhas[2]},LOW);
  pinMode({linhas[3]},HIGH);
  pin1=digitalRead({colunas[0]});
  pin2=digitalRead({colunas[1]});
  pin3=digitalRead({colunas[2]});
  pin4=digitalRead({colunas[3]});
  if (pin1==4095){'{'}
    return 13;
  {'}'}
  if (pin2==4095){'{'}
    return 14;
  {'}'}
  if (pin3==4095){'{'}
    return 15;
  {'}'}
  if (pin4==4095){'{'}
    return 16;
  {'}'}
{'}'}
{'}'}
""")
#loop
arquivo.write("""
void loop() {
grafico(0,0,"ola,mundo",2);
grafico(0,16,"12 douze");
delay(5000);
tela.clearDisplay();
delay(2000);
}""")
