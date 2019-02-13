
#include<avr/io.h>

#define MOVE_F 0b00010010  // move forward
#define MOVE_B 0b00001100  // move backward
#define MOVE_2R 0b00010100 // move to right (both wheel rotates in acti clk wise direction)
#define MOVE_2L 0b00001010 // move to left (both wheel rotates in acti clk wise direction)
#define MOVE_R 0b00010000  // move to right (left wheel=1 & right wheel =0) 
#define MOVE_L 0b00000010  // move to left (left wheel=0 & right wheel =1)
#define BRAKE 0b00000000   // both motor in OFF state

#define SENSOR_L 0b0000001
#define SENSOR_R 0b0001000 

  
void main()
{
	DDRC=0b0000000;  
	DDRB=0b00011110; 
    int ls=0, rs=0;  
	
	 
	while(1) 
	{
	
	ls=0;       
	rs=0;  
	
	ls=(PINC & SENSOR_L);
	rs=(PINC & SENSOR_R);
		
		if((ls==0b0000000)&(rs==0b0000000))
		PORTB=BRAKE;
							
		if((ls==0b0000001)&(rs==0b0000000))
		PORTB=MOVE_R;

		if((ls==0b0000000)&(rs==0b0001000))
		PORTB=MOVE_L;
	
	    if((ls==0b0000001)&(rs==0b0001000)) 
		PORTB=MOVE_F;
	}
}
