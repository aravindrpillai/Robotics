

#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>
#include"lcd_16.h" 
#include"lcd_16.c" 

#define F_CPU 8000000UL

int i=0;
 
void wait(float x)
{
for(i=0;i<(int)(1302*x);i++)
_delay_loop_1(0);
}

void USARTInit(uint16_t ubrr_value)
{
/*
Baud rate = 9600
Data bits =8
Parity = None
Stop bits = 1
Flow Control = None
Transmission Mode = Asynchronous
USART Reciever = ON
USART Transmitter = ON
U2X = 0
UBRR value = 51

ATMega16 Calibrated Internal RC Oscilator Frequency = 8 MHz

*/




   UBRRL = ubrr_value;
   UBRRH = (ubrr_value>>8);
   
   //UCSRC|=(1<<URSEL);
   UCSRC|=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);


   UCSRB=(1<<RXEN)|(1<<TXEN);


}

unsigned char USARTReadChar()
{


   while(!(UCSRA & (1<<RXC)));



   return UDR;
}

void USARTWriteChar(char data)
{

   while(!(UCSRA & (1<<UDRE)))
   ;
 

   UDR=data;
}
char buffer[16];

void main()
{
   unsigned char data;

DDRC=0xFF;
DDRA=0x00;
char sentence[100],lattitude[11],longitude[11];
char *str;
   USARTInit(51);  

lcd_init(LCD_DISP_ON);
int c=0,r=0,i=0,j=0,k=0,a=0,l=0;

   while(1)
   {



      data=USARTReadChar();
	  

	  
	  if(data=='$')
		if(USARTReadChar()=='G')
			if(USARTReadChar()=='P')
				if(USARTReadChar()=='G')
					if(USARTReadChar()=='G')
						if(USARTReadChar()=='A')
							{
							for(l=1;l<=12;l++)
								data=USARTReadChar();
							for(a=0;a<=8;a++,l++)
								lattitude[a]=USARTReadChar();
							lattitude[a]='\0';
							for(a=0;a<3;a++)
								data=USARTReadChar();
							for(a=0;a<=9;a++,l++)
								longitude[a]=USARTReadChar();
							longitude[a]='\0';

							lcd_gotoxy(0,0);
							sprintf(buffer,"Latt:%s",lattitude);
							lcd_puts(buffer);
							lcd_gotoxy(0,1);
							sprintf(buffer,"Long:%s",longitude);
							lcd_puts(buffer);
							}


str=lattitude;

while(*str!='\0')
{
USARTWriteChar(*str);
str++;
}
USARTWriteChar('\r');
USARTWriteChar('\n');

str=longitude;
while(*str!='\0')
{
USARTWriteChar(*str);
str++;
}
USARTWriteChar('\r');
USARTWriteChar('\n');



	  	  if(r==0&&c==15)
	     {r=1; c=0;}
      else if(r==1&&c==15)
	        {r=0;c=0;}
	       else
		     c++;
			 
//wait(.1);
	}
}

      //wait(.01);


    
   

