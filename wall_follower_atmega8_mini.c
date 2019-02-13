// Project name : Wall follower for Atmega8 mini
// Compile Date : 31/10/2011 Time : (16:21)
// Designed By  : ROBOSAPIENS INDIA 
//                http://www.robosapiensindia.com
/* Program for "Wall follower" 
 ___________________________________________________
Connection settings of Kit

LEDs---@------------->PB1
LEDs---@------------->PB2
LEDs---@------------->PB3
LEDs---@------------->PB4
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
#include<util/delay.h>


int main(void)
{
	DDRC=0b0000000;   //set PORTC as input port
	DDRB=0b00011110;  //PB1, PB2, PB3, PB4 as output port
    int ws=0;         // define & initialize ws integer as  0 to acquire the wall sensor status in ws
	                  // connect wall sensor at left side of the Robot
	while(1)          // create infinite loop
	{
	ws=(PINC&0b0000001);  //acquire  sensor's status connected at PC0
		
	if(ws==0b0000001)       //check the sensor status
	     PORTB=0b00010000;  //turn right
	   
       else 
	   PORTB=0b00000010;  //turn left
	
	}
}

