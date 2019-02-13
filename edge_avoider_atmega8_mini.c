#include<avr/io.h>
#include<util/delay.h>

void main()
{
	DDRC=0b0000000;   //set PORTC as input port
	DDRB=0b00011110;  //PB1, PB2, PB3, PB4 as output port
    int ls=1, rs=1;   // define & initialize ls, rs integer as 1 to 
					  // acquire the left sensor status in ls and right sensor
					  // status in rs 
	while(1)          // create infinite loop
	{
	ls=(PINC&0b0000001);   //acquire only left sensor status connected at PC0
	rs=(PINC&0b0001000);   // acquire only right sensor status connected at PC3
		
	if((ls==0b0000000)&(rs==0b0000000)) //check sensor status for both sensor OFF 
		{
			PORTB=0b00001100;  //move back
			_delay_ms(800);    //keep on moving back for 0.8 sec
			PORTB=0b00010000;
			_delay_ms(800);    //keep on turning right for 0.8 sec
			ls=1;              //set sensor status on
			rs=8;              //set sensor status on
		}

		if((ls==0b0000001)&(rs==0b0000000))  //check sensor status for left sensor=ON and
		                                     // right sensor=OFF
		{
			PORTB=0b00001100;   //move back
			_delay_ms(800);     //keep on moving back for 0.8 sec
			PORTB=0b00010000;   //turn right
			_delay_ms(800);     //keep on turning right for 0.8 sec

			ls=1;               //set sensor status on
			rs=8;               //set sensor status on
		}
		
		if((ls==0b0000000)&(rs==0b0001000))  //check sensor status for left sensor=OFF and
		                                     // right sensor=ON
		{
			PORTB=0b00001100;   //move back
			_delay_ms(800);     //keep on moving back for 0.8 sec
			PORTB=0b00000010;   //turn left
			_delay_ms(800);     //keep on turning left for 0.8 sec
			ls=1;               //set sensor status on
			rs=8;               //set sensor status on
		}
        if((ls==0b0000001)&(rs==0b0001000)) //check sensor status for both sensor ON 
		{
			PORTB=0b00010010;  //move forward
			ls=1;              //set sensor status on
			rs=8;              //set sensor status on
		}
	}
}

