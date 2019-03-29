/*
 * audio.c
 *
 * Created: 29-Mar-19 9:43:32
 *  Author: svber
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

inline static void delay_us(int count) {
	while(count--) {
		_delay_us(1);
	}
}

void playTune(long frequency, long milis)
{
	long t = 0;
	long count = milis * 8000L;
	while(t < count)
	{
		delay_us(1000000/frequency/2);
		PORTF ^= (0b00001000);
		t += TCNT3;
		TCNT3 = 0;
	}
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}