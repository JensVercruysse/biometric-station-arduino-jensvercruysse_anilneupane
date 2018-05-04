#include <LiquidCrystal.h>


 //Hardware hookup:
 // Arduino --------------- MMA8452Q Breakout
 //  3.3V  ---------------     3.3V
 //   GND   ---------------     GND
 // SDA (A4) --\/330 Ohm\/--    SDA
 // SCL (A5) --\/330 Ohm\/--    SCL

#include <Wire.h> 
#include <SparkFun_MMA8452Q.h> 
LiquidCrystal lcd (8,9,4,5,6,7);
MMA8452Q accel;
void setup()
{
  Serial.begin(115200);
  accel.init();
  accel.init(SCALE_4G); 
  accel.init(SCALE_8G, ODR_6);
  lcd.begin(16, 2);
}
void loop()
{  
  if (accel.available())
  {
    accel.read();
    printCalculatedAccels();
 
    Serial.println();
    
     delay(1000); 
  }
}

void printCalculatedAccels()
{ 
  Serial.print(accel.cx, 3);
  Serial.print("\t");
  Serial.print(accel.cy, 3);
  Serial.print("\t");
  Serial.print(accel.cz, 3);
  Serial.print("\t");

  
  lcd.setCursor(0, 0);  
  lcd.print(accel.cx, 2);
  lcd.print(",");
  lcd.print(accel.cy, 2);
  lcd.print(",");
  lcd.print(accel.cz, 2);
 
}



