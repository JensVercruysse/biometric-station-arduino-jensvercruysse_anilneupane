void setup() {
  Serial.begin(115200);
  Serial.println("Hello World"); 
  
}

void loop() {
  double waterLevel = 12.33;
  int ranking = 1234;
  String output = "";
  Serial.println(String("[") + waterLevel + String("|") + ranking + String("]"));
  delay(1000);
}
