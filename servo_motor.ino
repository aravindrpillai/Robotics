

#include <Servo.h> 

Servo myservo;  
int flag;
 
 
void setup()  
{  
Serial.begin(9600);
myservo.attach(2); 
pinMode(3, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
pinMode(5, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(10, INPUT_PULLUP);
pinMode(11, INPUT_PULLUP);
} 
 
void loop() 
{ 
  flag = 0;
  
 if( digitalRead(3) == LOW ) { myservo.write(20); flag=1; Serial.println("pin 3 low"); } 
 if( digitalRead(4) == LOW ) { myservo.write(40); flag=1; Serial.println("pin 4 low");  }
 if( digitalRead(5) == LOW ) { myservo.write(60); flag=1; Serial.println("pin 5 low");  }
 if( digitalRead(6) == LOW ) { myservo.write(80); flag=1; Serial.println("pin 6 low");  }
 if( digitalRead(7) == LOW ) { myservo.write(100); flag=1; Serial.println("pin 7 low");  }
 if( digitalRead(8) == LOW ) { myservo.write(120); flag=1; Serial.println("pin 8 low");  }
 if( digitalRead(9) == LOW ) { myservo.write(140); flag=1; Serial.println("pin 9 low");  }
 if( digitalRead(10) == LOW ) { myservo.write(160); flag=1; Serial.println("pin 10 low");  }
 if( digitalRead(11) == LOW ) { myservo.write(180); flag=1; Serial.println("pin 11 low");  } 


if(flag == 0) myservo.write(0);

//delay(100);
} 

