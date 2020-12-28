int led_analog = 9;
int led_dry = 7;
int led_humid = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(led_analog, OUTPUT);
  pinMode(led_dry, OUTPUT);
  pinMode(led_humid, OUTPUT);
}

void loop()
{
  int mois = analogRead(A0);
  Serial.print(mois);
  Serial.print(" -");
  
  // map 0-1023 to 0-255
  int brightness = (255 * mois) / 1023; 

  analogWrite(led_analog, brightness);
  
  if (mois >= 1000) {
    Serial.println("Sensor is not in the Soil or DISCONNECTED");
    digitalWrite(led_dry,LOW);
    digitalWrite(led_humid,LOW);

  }else if (mois < 1000 && mois >= 600) {
    
    Serial.println("Soil is DRY");
    digitalWrite(led_dry,HIGH);
    digitalWrite(led_humid,LOW);

  }else if (mois < 600 &&  mois >= 350) {
    
    digitalWrite(led_dry,LOW);
    digitalWrite(led_humid,HIGH);
    Serial.println("Soil is HUMID");

  }else if (mois < 350) {

    digitalWrite(led_dry,HIGH);
    digitalWrite(led_humid,HIGH);
    Serial.println("Sensor in WATER");

  }

  delay(1000);

}
