// Project name : DTMF controlled robot for Atmega8 mini
// Compile Date : 31/10/2011 Time : (16:21)
// Designed By  : ROBOSAPIENS INDIA 
//                http://www.robosapiensindia.com
/* Program for "DTMF controlled robot" 
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
*********DTMF sensor connection********

DTMF D0---->PB0
DTMF D1---->PD7
DTMF D2---->PD6
DTMF D3---->PB5
*/

#include<avr/io.h>

int main(void)
{
int d=0;
int b=0;      
DDRB=0b11111111;  //PORTB as output Port connected to motors
DDRD=0b00000000;  //PORTD Input port connected to DTMF decoder IC
while(1)          // infinite loop
{
b=PINB&0b00000001;
d=PIND&0b11100000; 

if(d==0b10000000 && b==0b00000000)          //if Key 2 of cell phone pressed
{
PORTB=0b00010010;    // move straight
}

if(d==0b01000000 && b==0b00000000)          // if Key 4 of cell phone pressed
{
PORTB=0b00000010;    // turn left
}

if(d==0b11000000 && b==0b00000000)          // if Key 6 of cell phone pressed
{
PORTB=0b000010000;   // turn right
}

if(d==0b00100000 && b==0b00000000)          // if Key 8 of cell phone pressed
{
PORTB=0b00001100;    // move back
}

if(d==0b01000000 && b==0b00000001)          // if Key 5 of cell phone pressed
{
PORTB=0b00000000;    //stop
}


}   //while closed
}   //main closed


