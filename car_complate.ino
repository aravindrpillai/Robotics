
#include <NewPing.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
const int buzzer_pin = 13;



/*----------------- REVERSE SENSOR DECLARATIONS ------------------------*/
const int min_dist = 30; 
//Syntax -> NewPing sonar_r(TRIGGER_PIN_r, ECHO_PIN_r, MAX_DISTANCE);

NewPing sonar_l(47, 46, 800);
NewPing sonar_c(49, 48, 800);
NewPing sonar_r(51, 50, 800);
int dist_l,dist_c,dist_r,dist_l_prv,dist_r_prv,dist_c_prv,r_status=0;
const int reverse_status = 52;

/*---------------------------------------------------------------------------*/


const int dtmf_key_press = 31;
const int dtmf_in_pin_1 = 33;
const int dtmf_in_pin_2 = 35;
const int dtmf_in_pin_3 = 37;
const int dtmf_in_pin_4 = 39;

int a,b,c,d,pre_num,num;


/*------------------ TEMPERATURE SENSOR DECLARATION -------------------------*/
const int temperature_pin = A0;
float tempC;




/*---------------------------------------------------------------------------*/

const int auto_start_switch = 36;
const int ignition_pin = 26;
const int start_motor_pin = 28;

/*------------------------------------------------------------------------------*/


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 4);
  pinMode(11, OUTPUT);       // Left park light
  pinMode(12, OUTPUT);       // Right park light
  pinMode(buzzer_pin, OUTPUT);       // Buzzer pin
  pinMode(reverse_status, INPUT);    // Reverse Status

pinMode(32,INPUT);
pinMode(22,OUTPUT);
pinMode(24,OUTPUT);


pinMode(auto_start_switch,INPUT);
pinMode(ignition_pin,OUTPUT);
pinMode(start_motor_pin,OUTPUT);


 pinMode(dtmf_in_pin_1,INPUT);
 pinMode(dtmf_in_pin_2,INPUT);
 pinMode(dtmf_in_pin_3,INPUT);
 pinMode(dtmf_in_pin_4,INPUT);

pinMode(36, INPUT_PULLUP); // engine dtmf start pin
pinMode(38, INPUT_PULLUP); // dtmf enable /disable
pinMode(40, INPUT_PULLUP); // head light enable disable

}


int disp_date_time = 1;
int key = 1;
void loop() 
{ 
if(digitalRead(reverse_status) == HIGH) { reverse(); disp_date_time = 0; } else { disp_date_time = 1; digitalWrite(13,LOW); }

if(disp_date_time == 1)  date_temp();


dtmf_start();
auto_dim_bright();
}



/*============================================================================================================================================================*/


void temperature()
{
tempC = (5.0 * analogRead(temperature_pin) * 100.0) / 1024;
lcd.setCursor(0, 1); lcd.print("Temp : "); lcd.print(tempC); lcd.print(" dC");
delay(300);
}


void date_temp()
{
lcd.clear();  
lcd.print("14 Jan, 12:05 pm");
temperature();
}


/*--------------------------------------------------------------------------------------------------------------*/
// PIN 11 -> Park light -> Left Side
// PIN 12 -> Park Light -> Right side

void park_light(int flag)
{
  if(flag == 0) { digitalWrite(11, LOW);  digitalWrite(12, LOW); }
  if(flag == 1) { digitalWrite(11, HIGH);  digitalWrite(12, HIGH); }
  if(flag == 2) { digitalWrite(11, HIGH);  digitalWrite(12, LOW); }
  if(flag == 3) { digitalWrite(11, LOW);  digitalWrite(12, HIGH); }
}



/*--------------------------------------------------------------------------------------------------------------*/
// PIN 22 -> Head light -> micontroller to relay (to turn on)
// PIN 24 -> Head Light -> micontroller to relay (dim/bright )
// PIN 40 -> I/P from Auto dim/bright enable/disable (side switch-> [internal pullup] )
// PIN 32 -> I/P from Auto light sensor (pin32) )

void auto_dim_bright()
{
  if(digitalRead(40) == LOW) 
  {
    digitalWrite(22,HIGH);
        
        if(digitalRead(32) == HIGH ) digitalWrite(24,HIGH);
        else digitalWrite(24,LOW); 
        
  }
  else { digitalWrite(22,LOW); digitalWrite(24,LOW); }   
  
}
/*--------------------------------------------------------------------------------------------------------------*/

int start_car(int action)
{
   if(action == 1)
      {
        digitalWrite(ignition_pin,HIGH);
        digitalWrite(start_motor_pin,HIGH);
        delay(1000);
        digitalWrite(start_motor_pin,LOW);
        return 1;   // return 1 after turning on the engine
      }
    
    else if(action == 2)
      {
        digitalWrite(ignition_pin,LOW);
        digitalWrite(start_motor_pin,LOW);
        return 2;  // return 2 if successfully turned off the engine
      }
    
    else return 3; // the car has started; 
  
}






void dtmf_start()
{
  if(digitalRead(38) == LOW) 
  {

  if(digitalRead(dtmf_in_pin_1) == HIGH) a=1; else a=0;
 if(digitalRead(dtmf_in_pin_2) == HIGH) b=1; else b=0;
 if(digitalRead(dtmf_in_pin_3) == HIGH) c=1; else c=0;
 if(digitalRead(dtmf_in_pin_4) == HIGH) d=1; else d=0;
 
   if((a==0) && (b==0) && (c==0) && (d==0)) num = 0;
   if((a==0) && (b==0) && (c==0) && (d==1)) num = 1;
   if((a==0) && (b==0) && (c==1) && (d==0)) num = 2;
   if((a==0) && (b==0) && (c==1) && (d==1)) num = 3;
   if((a==0) && (b==1) && (c==0) && (d==0)) num = 4;
   if((a==0) && (b==1) && (c==0) && (d==1)) num = 5;
   if((a==0) && (b==1) && (c==1) && (d==0)) num = 6;
   if((a==0) && (b==1) && (c==1) && (d==1)) num = 7;
   if((a==1) && (b==0) && (c==0) && (d==0)) num = 8;
   if((a==1) && (b==0) && (c==0) && (d==1)) num = 9;

  if(digitalRead(36) == LOW) 
  {
  if( (num != pre_num) && (num==5) && (key==1) ) { start_car(key); key =3; }
  if( (num != pre_num) && (num==8)) { start_car(2); key =1; }
  }

  if( (num != pre_num) && (num==4)) park_light(1);
  if( (num != pre_num) && (num==7)) park_light(0);
  
 pre_num = num;
 
  }
}



void reverse()
{
dist_l = sonar_l.convert_cm(sonar_l.ping());
dist_c = sonar_c.convert_cm(sonar_c.ping());
dist_r = sonar_r.convert_cm(sonar_r.ping());
   
if( (dist_l < min_dist) || (dist_c < min_dist) || (dist_r < min_dist) ) digitalWrite(buzzer_pin, HIGH);
else  digitalWrite(buzzer_pin, LOW);

lcd.clear();
lcd.setCursor(0, 0);  lcd.print("Left   : ");  if( (dist_l > (dist_l_prv+1)) || (dist_l < (dist_l_prv-1)) ) lcd.print(dist_l); else lcd.print(dist_l_prv); lcd.print(" cm"); 
lcd.setCursor(0, 1);  lcd.print("Center : ");  if( (dist_c > (dist_c_prv+1)) || (dist_c < (dist_c_prv-1)) ) lcd.print(dist_c); else lcd.print(dist_c_prv); lcd.print(" cm"); 
lcd.setCursor(-4, 2); lcd.print("Right  : ");  if( (dist_r > (dist_r_prv+1)) || (dist_r < (dist_r_prv-1)) ) lcd.print(dist_r); else lcd.print(dist_r_prv); lcd.print(" cm"); 

dist_l_prv = dist_l; dist_c_prv = dist_c; dist_r_prv = dist_r;

delay(300);
}





// PIN 22 -> Head light -> micontroller to relay (to turn on)
// PIN 24 -> Head Light -> micontroller to relay (dim/bright )
// PIN 40 -> I/P from Auto dim/bright enable/disable (side switch-> [internal pullup] )
// PIN 32 -> I/P from Auto light sensor (pin32-> [internal pullup] )

// PIN 11 -> Park light -> Left Side
// PIN 12 -> Park Light -> Right side

