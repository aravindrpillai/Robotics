
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 9 // Onboard LED


int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance, dist_prv; // Duration used to calculate distance

void setup() {
 Serial.begin (9600);
 lcd.begin(16, 2);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
lcd.print("U Sonic ");
 
}

void loop() {
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 if(dist_prv != distance)
 {
   lcd.clear();
 lcd.setCursor(0,1);
 lcd.print("Distance : ");
 lcd.print(distance);
 lcd.print("c");
 digitalWrite(LEDPin, LOW); 
 }
 delay(50);
 dist_prv = distance;
}
