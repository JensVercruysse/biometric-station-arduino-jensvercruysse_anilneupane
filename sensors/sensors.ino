#include <SparkFunTMP102.h>  
#include <SparkFun_MMA8452Q.h>
#include <LiquidCrystal.h> 
#include <Wire.h>   
#define USE_ARDUINO_INTERRUPTS true   
#include <PulseSensorPlayground.h>  

// declarations
const int PulseWire = 0;      
const int LED13 = 13;                
int Threshold = 550;   
PulseSensorPlayground pulseSensor;
 
const int ALERT_PIN = A3;
TMP102 sensor0(0x48);    
     
LiquidCrystal lcd (8,9,4,5,6,7);

MMA8452Q accel;


void setup() {
  Serial.begin(115200); 
  lcd.begin(20,4);
  
 pulseSensor.analogInput(PulseWire);     //pulse
  pulseSensor.blinkOnPulse(LED13); 
   pulseSensor.setThreshold(Threshold); 
     if (pulseSensor.begin()) {
  //  Serial.println("We created a pulseSensor Object !");    
  }

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
 int myBPM = pulseSensor.getBeatsPerMinute();  
                                              

if (pulseSensor.sawStartOfBeat()) {            
// Serial.println("♥  A HeartBeat Happened ! "); 
 // Serial.print("BPM: ");                        
 // Serial.println(myBPM);                      
}
      


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
 // Serial.print("\t");
 // Serial.print(accel.cy, 3);
 // Serial.print("\t");
 // Serial.print(accel.cz, 3);
 // Serial.println("\t");


  }

  Serial.print(String("[") + myBPM + String("|") + ((temperature)-3) + String("#"));   
  // this string could be replaced by 
  /***Serial.print ("[");
  Serial.print (myBPM); 
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
lcd.print("BPM:");
lcd.print (myBPM);
lcd.print (" ");
lcd.print("T:");
lcd.print((temperature)-3);
     
 /*** lcd.print ("[");
  lcd.print (Signal/6); 
  lcd.print ("|");
  lcd.print ((temperature)-3);
  lcd.print("#");  ***/

  
lcd.setCursor(0, 1);
lcd.print(accel.cx, 2);
lcd.print(" ");
lcd.print(accel.cy, 2);
lcd.print(" ");
lcd.print(accel.cz, 2);


 
 delay(1000);
 lcd.clear();
   
}
