#include <LiquidCrystal.h>



int PulseSensorPurplePin = 0;       
int LED13 = 13;   
int Signal;                
int Threshold = 550;            
LiquidCrystal lcd (8,9,4,5,6,7);
void setup() {
  pinMode(LED13,OUTPUT);         
   Serial.begin(115200);  
   lcd.begin(16, 2);          
}  
void loop() {

  Signal = analogRead(PulseSensorPurplePin);                                           
  Serial.println(Signal/6); 
   lcd.setCursor(0, 1);                
  lcd.print(Signal/6);
delay(1000);
   
   
}
