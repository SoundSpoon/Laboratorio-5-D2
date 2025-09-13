
#include <Arduino.h>
#include <stdint.h>
#include <LiquidCrystal.h>

#define rs 32
#define en 33
#define d4 25
#define d5 26 
#define d6 27
#define d7 14
#define pot1 2
#define pot2 4
#define btnMas 35
#define btnMenos 34
int contador = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pot1: Pot2: CNT:");

}

void loop() {
  float lectura1 = analogRead(pot1);
  float lectura2 = analogRead(pot2);
  const float Vref = 3.3;                           // Alimentación/escala aprox
  float volts = (lectura2 / 4095.0f) * Vref;    
  lcd.setCursor(0,1);
  lcd.print(lectura1);
  lcd.setCursor(4,1);
  lcd.print("  ");
  lcd.setCursor(6,1);
  lcd.print(volts);
  lcd.setCursor(9,1);
  lcd.print(" ");
  lcd.setCursor(11,1);
  lcd.print("  ");
  lcd.setCursor(12,1);
  lcd.print(contador);
  if (digitalRead(btnMas) == HIGH){
    contador = contador + 1;
        Serial.println(contador);
    if (contador == 255){
      contador = 0;
    }
    Serial.println(contador);
  }
  if (digitalRead(btnMenos) == HIGH){
    contador = contador - 1;
    if (contador == 0){
      contador = 255;
    }
    Serial.println(contador);
  }
delay (100);
}