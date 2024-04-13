//umidificador automático. 15º projeto.linguagem utilizada c++
#include <DHT.h>
#include <DHT_U.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define endereco 0x27
#define colunas 16
#define linha 2

int SENSOR = 2; // pim 2 sensor
int HUMIDADE;

DHT dht (SENSOR, DHT22); // sensor dht22

LiquidCrystal_I2C lcd (endereco,colunas,linha); // lcd i2c



void setup()
{
   lcd.init(); //  INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear();//limpar lcd

  dht.begin();
  Serial.println("Usando o Sensor DHT");
  sensor_t sensor;

  pinMode(3, OUTPUT); // peno do umidificador
}


void loop()
{
   //float HUMIDADE=dht.readHumidity(); // transforma a humidade em numero com vergula "EX 50.30"

   HUMIDADE= dht.readHumidity(); // usar a humidade
   lcd.setCursor(0, 1);
  lcd.print("umidade: ");
  lcd.setCursor(11, 1);
  lcd.print("%");
   lcd.setCursor(9, 1);
  lcd.print(HUMIDADE);
  
   if (HUMIDADE <=50){ // umidade baixa 
    digitalWrite(3, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("umidade baixa");
    delay(1000);
    lcd.clear();
   }
 else if (HUMIDADE >50 && HUMIDADE < 70){ // comando <else if> humidade boa 
    digitalWrite(3, LOW);
    lcd.setCursor(0, 0);
    lcd.print("umidade boa");
    delay(1000);
    lcd.clear();
  }
 else if (HUMIDADE >= 70) {  //comando <else if> humidade alta 
   digitalWrite(3, LOW);
    lcd.setCursor(0, 0);
    lcd.print("umidade alta ");
    delay(1000);
    lcd.clear();
 }
}
   

  
   

   
  
  
   