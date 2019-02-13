// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN_l  47
#define ECHO_PIN_l     46

#define TRIGGER_PIN_c  49
#define ECHO_PIN_c     48

#define TRIGGER_PIN_r  51
#define ECHO_PIN_r     50

#define MAX_DISTANCE 800 

int dist_l,dist_c,dist_r;

/*-- sonar_l, sonar_c and sonar_r are objects --*/
NewPing sonar_l(TRIGGER_PIN_l, ECHO_PIN_l, MAX_DISTANCE);
NewPing sonar_c(TRIGGER_PIN_c, ECHO_PIN_c, MAX_DISTANCE);
NewPing sonar_r(TRIGGER_PIN_r, ECHO_PIN_r, MAX_DISTANCE);

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
   delay(50);
   dist_l = sonar_l.convert_cm(sonar_l.ping());
   dist_c = sonar_c.convert_cm(sonar_c.ping());
   dist_r = sonar_r.convert_cm(sonar_r.ping());
   
   Serial.print("L: "); Serial.print(dist_l);   Serial.print(" <<-->> C: "); Serial.print(dist_c);   Serial.print(" <<-->> R: "); Serial.print(dist_r); 
   Serial.println("");
  }
