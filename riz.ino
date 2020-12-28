int led = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
}

void loop()

{

  int mois = analogRead(A0);
  Serial.print(mois);
  Serial.print(" -");

  if (mois >= 1000) {
    Serial.println("Sensor is not in the Soil or DISCONNECTED");
  }

  if (mois < 1000 &&
    mois >= 600) {
    Serial.println("Soil is DRY");
  }

  if (mois < 600 &&
    mois >= 370) {
    Serial.println("Soil is HUMID");
  }

  if (mois < 370) {
    Serial.println("Sensor in WATER");
  }
  
  // map 0-1023 to 0-255
  int brightness = (255*mois)/1023;
  Serial.println(mois);
  Serial.println(brightness);
  if(mois > 400){
   analogWrite(led, brightness); 
  }else {
    analogWrite(led, 0);
  }
  delay(1000);

}
