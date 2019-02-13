
#include<avr/io.h>
#include<util/delay.h>



/* value listings are a, b, c, d, e, f, g, point. ground pos are not allocated */

// prints from 0 to 9 without decimal point
#define zero 0b11111100
#define one 0b01100000
#define two 0b11011010
#define three 0b11110010
#define four 0b01100110
#define five 0b10110110
#define six 0b00111110
#define seven 0b11100010
#define eight 0b11111110
#define nine 0b11100110

#define point 0b00000001  // prints only decimal point

// value listings including decimal point
#define p_zero 0b11111101
#define p_one 0b01100001
#define p_two 0b11011011
#define p_three 0b11110011
#define p_four 0b01100111
#define p_five 0b10110111
#define p_six 0b00111111
#define p_seven 0b11100011
#define p_eight 0b11111111
#define p_nine 0b11100111



  
void main()
{
		DDRB=0b11111111; 
     
	while(1) 
	{
		PORTB = zero;
_delay_ms(5000);
		PORTB = one;
_delay_ms(5000);
		PORTB = two;
_delay_ms(5000);
		PORTB = three;
_delay_ms(5000);
		PORTB = four;
_delay_ms(5000);
		PORTB = five;
_delay_ms(5000);
		PORTB = six;
_delay_ms(5000);
		PORTB = seven;
_delay_ms(5000);
		PORTB = eight;
_delay_ms(5000);
		PORTB = nine;
_delay_ms(5000);
		
		PORTB = point;
_delay_ms(5000);
		
		PORTB = p_zero;
_delay_ms(5000);
		PORTB = p_one;
_delay_ms(5000);
		PORTB = p_two;
_delay_ms(5000);
		PORTB = p_three;
_delay_ms(5000);
		PORTB = p_four;
_delay_ms(5000);
		PORTB = p_five;
_delay_ms(5000);
		PORTB = p_six;
_delay_ms(5000);
		PORTB = p_seven;
_delay_ms(5000);
		PORTB = p_eight;
_delay_ms(5000);
		PORTB = p_nine;
_delay_ms(5000);
		
	
	
}


}
