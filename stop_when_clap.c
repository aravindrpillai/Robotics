// Project name :  for Atmega8 mini
// Compile Date : 31/10/2011 Time : (16:21)
// Designed By  : ROBOSAPIENS INDIA 
//                http://www.robosapiensindia.com
/* Program for "BLINKING LED" 
 ___________________________________________________
Connection settings of Kit
sound sensor--------->PC0
LEDs---@------------->PB1
LEDs---@------------->PB2
LEDs---@------------->PB3
LEDs---@------------->PB4
left sensor---------->PC0
right sensor--------->PC3
RIGHT MOTOR(+)------->PB1
RIGHT MOTOR(-)------->PB2
LEFT MOTOR(-)-------->PB3
LEFT MOTOR(+)-------->PB4
BOOTLooder Condition Check----->PC5(f 0 bootler section else program execution
							  section of Flash memory)
RESET-------------------------->PC6
Crystal Ossilator-------------->PB6 and PB7
VB=Battery Supply
VCC=regulated 5V+
Gnd=Ground(0V)
*/
#include<avr/io.h>


int main(void)
{
	DDRC=0b0000000;   //set PORTC as input port
	DDRB=0b00011110;  //PB1, PB2, PB3, PB4 as output port
    int ss=0;         // define & initialize ss integer as  0 to acquire the sound sensor status in ss
	while(1)          // create infinite loop
	{
	ss=(PINC&0b0000001);  //acquire only sound sensor status connected at PC0
		
	if(ss==0b0000001)     //check for sound sensor ON status at PC0
	   PORTB=0b00000000;  //stop
       else 
	   PORTB=0b00010010;  //forward
			
	
	}
}

