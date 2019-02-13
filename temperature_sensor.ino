


const int tempPin = A0;
float temp;
void setup() {
  Serial.begin(9600); 

}

void loop() {
temperature();
}


void temperature()  
{
//tempC = (5.0 * analogRead(temperature_pin) * 100.0) / 1024;
temp = analogRead(tempPin);
  temp = temp * 0.48828125;
  Serial.print("TEMPRATURE = ");
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
  delay(1000);}


