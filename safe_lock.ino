#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
Servo myservo;

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() 
{
  pinMode(7,OUTPUT);
   myservo.attach(9,600,2300);
 Serial.begin(9600);
  lcd.begin(20,4);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(6,1);
  lcd.print("SAFELOCK");
  lcd.setCursor(7,2);
  lcd.print("HOLMES");
}

void loop() 
{
  
  if(Serial.available()>0)
  {
    char data = Serial.read();
    
    if(data=='a')
    {
      myservo.write(180);
      lcd.clear();
   lcd.setCursor(6,0);
  lcd.print("SAFELOCK");
  lcd.setCursor(7,1);
  lcd.print("HOLMES");
  lcd.setCursor(7,2);
  lcd.print("LOCKED");
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
    }
    if(data=='b')
    {
     myservo.write(90);
     lcd.clear();
     lcd.setCursor(6,0);
      lcd.print("SAFELOCK");
  lcd.setCursor(7,1);
  lcd.print("HOLMES");
  lcd.setCursor(6,2);
  lcd.print("UNLOCKED");
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(7,LOW);
    }
      }
  
}
