// Project name : Blinking LED's for Atmega8 mini
// Compile Date : 31/10/2011 Time : (16:21)
// Designed By  : ROBOSAPIENS INDIA 
//                http://www.robosapiensindia.com
/* Program for "BLINKING LED" 
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

DDRB=0b00011110;  // PB1,PB2,PB3 and PB4 of PORT B are set as output pins.  
 while(1)
    {
    PORTB=0b00011110;  //PB1,PB2,PB3 and PB4 Led's are set ON 
    _delay_ms(700);

    PORTB=0b00000000; // PB1,PB2,PB3 and PB4 Led's are set OFF  
    _delay_ms(700);
	}
}
