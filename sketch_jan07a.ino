
const int reverse_l_echo  = 46;
const int reverse_l_trigger = 47;
float l_dist,c_dist,r_dist;

void setup() {
Serial.begin(9600); 
  pinMode(reverse_l_trigger,OUTPUT);    // Reverse Trigger
  pinMode(reverse_l_echo, INPUT);     // Reverse Left Input

}

void loop() {
 digitalWrite(reverse_l_trigger, LOW); 
 delayMicroseconds(2); 
 digitalWrite(reverse_l_trigger, HIGH);
 delayMicroseconds(10); 
 digitalWrite(reverse_l_trigger, LOW); 
 l_dist=  pulseIn(reverse_l_echo, HIGH)/58.20;

Serial.println(l_dist);
delay(150);
}


