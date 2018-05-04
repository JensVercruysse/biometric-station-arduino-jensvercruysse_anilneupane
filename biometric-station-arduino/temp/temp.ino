#include <LiquidCrystal.h>

#include <Wire.h> 
#include "SparkFunTMP102.h" r
// Connections
// VCC = 3.3V
// GND = GND
// SDA = A4
// SCL = A5
const int ALERT_PIN = A3;
TMP102 sensor0(0x48); 
LiquidCrystal lcd (8,9,4,5,6,7);
void setup() {
  
  Serial.begin(115200); 
  pinMode(ALERT_PIN,INPUT);  
  sensor0.begin();  
  sensor0.setFault(0);  
  sensor0.setAlertPolarity(1); 
  sensor0.setAlertMode(0); 
  sensor0.setConversionRate(2);
  sensor0.setExtendedMode(0);
  sensor0.setHighTempC(32);  
  sensor0.setLowTempC(20); 
  lcd.begin(16, 2);
}
void loop()
{
  LiquidCrystal lcd (8,9,4,5,6,7);
  float temperature;
  boolean alertPinState, alertRegisterState;

  sensor0.wakeup();
  temperature = sensor0.readTempC();
  Serial.print("Temperature: ");
  Serial.println((temperature)-3);
  lcd.setCursor(0, 1); 
  lcd.print((temperature)-3);
                  
  
  delay(1000);  
}

