/*

Code 
by  : Aravind R Pillai
for : Path Follower
On  : 24 july 2013

Feature : PF having middle sensor

*/



const int l_sensor = 3;      // Left sensor
const int m_sensor = 4;      // Middle sensor
const int r_sensor = 5;      // Right sensor

const int l_motor_a = 11;    // Left Motor terminal A
const int l_motor_b = 12;    // Left Motor terminal B
const int r_motor_a = 13;    // Right Motor terminal A
const int r_motor_b = 14;    // Right Motor terminal B     


//--------  Variables for reading status of sensors  ----------------------------
int l_s = 0;                 // left status
int m_s = 0;                 // middle status
int r_s = 0;                 // right status
//-------------------------------------------------------------------------------


void setup() 
{
  pinMode(l_sensor , INPUT);      
  pinMode(m_sensor , INPUT);      
  pinMode(r_sensor , INPUT);      
  
  pinMode(l_motor_a , OUTPUT);      
  pinMode(l_motor_b , OUTPUT);      
  pinMode(r_motor_a , OUTPUT);      
  pinMode(r_motor_b , OUTPUT);      
}



void loop()
{

  l_s = digitalRead(l_sensor);
  m_s = digitalRead(m_sensor);
  r_s = digitalRead(r_sensor);


if ( (l_s == LOW) && (m_s == HIGH) && (r_s == LOW) )
{
digitalWrite(l_motor_a , LOW);
digitalWrite(l_motor_b , LOW);
digitalWrite(r_motor_a , LOW);
digitalWrite(r_motor_b , LOW);  
}


if ( (l_s == HIGH) && (r_s == HIGH) )
{
digitalWrite(l_motor_a , HIGH);
digitalWrite(l_motor_b , LOW);
digitalWrite(r_motor_a , HIGH);
digitalWrite(r_motor_b , LOW);  
}

    
if ( (l_s == LOW) && (r_s == HIGH) )
{
digitalWrite(l_motor_a , LOW);
digitalWrite(l_motor_b , HIGH);
digitalWrite(r_motor_a , HIGH);
digitalWrite(r_motor_b , LOW);  
}



if ( (l_s == HIGH) && (r_s == LOW) )
{
digitalWrite(l_motor_a , HIGH);
digitalWrite(l_motor_b , LOW);
digitalWrite(r_motor_a , LOW);
digitalWrite(r_motor_b , HIGH);
}

    

    
}