#include <SparkFunTMP102.h>  // librabry for temp sensor
#include <SparkFun_MMA8452Q.h> // library for accelerometer
#include <LiquidCrystal.h>    // library for lcd display
#include <Wire.h>             // library to communicate with the sensor


// declarations

int PulseSensorPurplePin = 0;       
int LED13 = 13;   
int Signal;                
int Threshold = 550;    
const int ALERT_PIN = A3;
TMP102 sensor0(0x48);         
LiquidCrystal lcd (8,9,4,5,6,7);
MMA8452Q accel;


void setup() {
  Serial.begin(115200); 
  lcd.begin(20,4);
  
  pinMode(LED13,OUTPUT);      //pulse 
     
  pinMode(ALERT_PIN,INPUT);    // temperature
  sensor0.begin();  
  sensor0.setFault(0);  
  sensor0.setAlertPolarity(1); 
  sensor0.setAlertMode(0); 
  sensor0.setConversionRate(2);
  sensor0.setExtendedMode(0);
  sensor0.setHighTempC(32);  
  sensor0.setLowTempC(20); 

  accel.init();              //accelerometer
  accel.init(SCALE_4G); 
  accel.init(SCALE_8G, ODR_6);
}  
void loop() {
  lcd.setCursor(0, 0); 
  Signal = analogRead(PulseSensorPurplePin);        //pulse                                   
 // Serial.println(Signal/6); 
                 


  float temperature;                          //temperature
  boolean alertPinState, alertRegisterState;
  sensor0.wakeup();
  temperature = sensor0.readTempC();
//  Serial.print("Temperature: ");
//  Serial.println((temperature)-3 + String("°C"));


   
  if (accel.available())                      // accelerometer
  {
    accel.read();
    
  // Serial.print(accel.cx, 3);
//  Serial.print("\t");
 // Serial.print(accel.cy, 3);
 // Serial.print("\t");
 // Serial.print(accel.cz, 3);
 // Serial.println("\t");


  }

  Serial.print(String("[") + Signal/6 + String("|") + ((temperature)-3) + String("#"));   
  // this string could be replaced by 
  /***Serial.print ("[");
  Serial.print (Signal/6); 
  Serial.print ("|");
  Serial.print ((temperature)-3);
  Serial.print("#");
   ***/
  Serial.print(accel.cx, 3);
  Serial.print("$");
  Serial.print(accel.cy, 3);
  Serial.print("€");
  Serial.print(accel.cz, 3);
  Serial.println("]"); 

lcd.setCursor(0, 0);
  lcd.print(String("[") + Signal/6 + String("|") + ((temperature)-3) + String("#"));
 /*** lcd.print ("[");
  lcd.print (Signal/6); 
  lcd.print ("|");
  lcd.print ((temperature)-3);
  lcd.print("#");  ***/
  lcd.setCursor(0, 1);
  lcd.print(accel.cx, 2);
  lcd.print("$");
  lcd.print(accel.cy, 2);
  lcd.print("€");
  lcd.print(accel.cz, 2);
  lcd.print("]");

 
 delay(1000);
   
   
}
