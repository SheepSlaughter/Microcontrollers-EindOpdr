<<<<<<< HEAD
//***************************************************************************
//  File Name    : basicsound.c
//  Version      : 1.0
//  Description  : Basic AVR Sound with PWM
//  Author(s)    : RWB
//  Target(s)    : AVRJazz Mega168 Learning Board
//  Compiler     : AVR-GCC 4.3.0; avr-libc 1.6.2 (WinAVR 20080610)
//  IDE          : Atmel AVR Studio 4.14
//  Programmer   : AVRJazz Mega168 STK500 v2.0 Bootloader
//               : AVR Visual Studio 4.14, STK500 programmer
//  Last Updated : 02 Jan 2008
//***************************************************************************
=======
/*
 * ThereminCopy.c
 *
 * Created: 20/03/2019 10:05:39
 * Author : Tim
 */ 

>>>>>>> develop
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
<<<<<<< HEAD

void wait( int ms );

void playTune(int delay, long count)
{
	long t = 0;
	while(t < count)
	{
		if(TCNT3 >= delay)
		{
			PORTD ^= 0xFF;
			t += TCNT3;
			TCNT3 = 0;
		}
	}
}

int main(void)
{
	DDRD = 0b00001000;			//set DDRD3 as output
	TCCR3B |= (1 << CS10);	//set up timer
	while(1)
	{
		playTune(1000, 10000000);
		playTune(2000, 10000000);
		playTune(3000, 10000000);
		playTune(4000, 10000000);
		playTune(5000, 10000000);
		playTune(6000, 10000000);
		playTune(7000, 10000000);
		playTune(8000, 10000000);
		playTune(9000, 10000000);
		playTune(10000, 10000000);
		playTune(11000, 10000000);
		playTune(12000, 10000000);
		playTune(13000, 10000000);
		playTune(14000, 10000000);
		playTune(15000, 10000000);
		playTune(14000, 10000000);
		playTune(13000, 10000000);
		playTune(12000, 10000000);
		playTune(11000, 10000000);
		playTune(10000, 10000000);
		playTune(9000, 10000000);
		playTune(8000, 10000000);
		playTune(7000, 10000000);
		playTune(6000, 10000000);
		playTune(5000, 10000000);
		playTune(4000, 10000000);
		playTune(3000, 10000000);
		playTune(2000, 10000000);
	}
	
	return 0;	                  // Standard Return Code
=======

int main(void)
{
    /* Replace with your application code */
	DDRD = 0b00000100;
	DDRA = 0b11111111;
	DDRB = 0b11111111;
    while (1) 
    {
		int duration, distance;
		
		//digitalWrite(trigPin, HIGH);
		PORTD = 0b00000100;
		
		//delayMicroseconds(1000);
		_delay_us(1000);
		
		//digitalWrite(trigPin, LOW);
		PORTD = 0b00000000;
		
		//duration = pulseIn(echoPin, HIGH);
		
		
		duration = 0;
		int temp;
		temp = PIND & 0b00000001;
		while(!temp){
			temp = PIND & 0b00000001;
		}
		while(temp && duration < 10000){
			temp = PIND & 0b00000001;
			_delay_us(1);
			duration++;
		}
		
		distance = (duration/2) / 29.1;
		PORTB = duration/10;
		if (distance >= 200 || distance <= 0){
			//Serial.println("Out of range");
			PORTA = 0b11111111;
		}
		else {
			//Serial.print(distance);
			//Serial.println(" cm");
			PORTA = distance;
		}
		_delay_ms(200);
    }
>>>>>>> develop
}

void wait( int ms )

{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}