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
/*
 * ThereminCopy.c
 *
 * Created: 20/03/2019 10:05:39
 * Author : Tim
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "audio.h"
#include "song.h"

#define BIT(x) (1<<x)
int duration; // keeps track of the duration of the echo from the ultra sonic sensor in micro seconds
int distance; // keeps track of the distance calculated using the duration of the echo in cm

/************************************************************************/
/*
Sends a pulse of 1000 Microseconds to the trigger pin of the Ultra Sonic sensor
and Sets the counter of timer 1 to 0
                                                                     */
/************************************************************************/
void echo(void){
		
		PORTE = 0b00000100;
		
		_delay_us(1000);
		
		PORTE = 0b00000000;
		TCNT1 = 0;
}

/************************************************************************/
/* 
Interrupts when Port E4 is changes State

This interrupt happens twice after the trigger pin is send a pulse.
The first time E4 triggers a rising edge:
	In this case timer 1 is started
	
The second time E4 triggers a falling edge:
	In this case timer 1 is stopped and the value is read and translated to a distance the ultra sonic sensor has detected
                                                                     */
/************************************************************************/
ISR(INT4_vect)
{
	if (PINE & 0b00010000)
	{
		duration = 0;
		TCNT1 = 0;
		TCCR1B |= 0b10;	
	}else
	{
		TCCR1B = 0;
		duration = TCNT1;
		distance = (duration/2) / 29.1;
		PORTB = duration/10;
		if (distance >= 200 || distance <= 0){
			PORTA = 0b11111111; //If the value returned from the ultrasonic reading is invalid or too big
		}
		else {
			PORTA = distance; 
		}
	}
}

ISR( INT0_vect )
{
	setIneterupt(1);
	PORTD &= ~(1<<5);
}

int main(void)
{
	int tune = 0; 
	int oct = 0; // octave
	int tonelen = 200;// tone length
	int lastOct = 0; // last Played octave
	DDRD = 0b00000000; // set port D as read only
	DDRA = 0b11111111; // set port A as write only
	DDRB = 0b11111111; // set port B as write only
	DDRC = 0;
	
	EICRA = 0b00000001; // set interupt 1 to rising edge
	EICRB = 0b00000001; // set interupt 4 to trigger on rising and falling edge
	EIMSK = 0b00010001; // the interrupt 4 and 1 is enabled 
	sei();
	
	DDRF = 0b00001000;		//set pin 4 from PORTF as output
	TCCR3B |= 0b00000001;	//set up timer
	while(1)
	{
		echo();
		if(PORTA < 0b11111111){
			tune = 1050 - (PORTA * 4);
		}
		if(tune > 100)
		{
			//playTune(tune, 100);
			oct = PORTA / 8;
			if(lastOct != oct){
				lastOct = oct;
				switch(oct)
				{
					case (0):
						playTune(261, tonelen);
						break;
					case (1):
						playTune(293,tonelen);
						break;
					case (2):
						playTune(329,tonelen);
						break;
					case (3):
						playTune(349,tonelen);
						break;
					case (4):
						playTune(391,tonelen);
						break;
					case (5):
						playTune(440,tonelen);
						break;
					case (6):
						playTune(493,tonelen);
						break;
					case (7):
						playTune(523,tonelen);
						break;
					case (8):
						playTune(587,tonelen);
						break;
					default:
						wait(tonelen);
						break;
				}
			}else{
				wait(100);
			}
		}else{
			wait(100);
		}
		if (PINC & BIT(0))
			marioTheme();
	}
	
	return 0;	                  // Standard Return Code
}

