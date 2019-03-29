/*
 * audio.c
 *
 * Created: 29-Mar-19 9:43:32
 *  Author: Gerdtinus
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

/*
Method for having a variable delay in microseconds
Count is the amount of microseconds
*/
inline static void delay_us(int count) {
	while(count--) {
		_delay_us(1);
	}
}

/*
Method for playing a sound at a certain frequency for a chosen amount of time
Frequency is the frequency in hz to play the sound at
Milis is the amount of time in milliseconds to play the sound at
*/
void playTune(long frequency, long milis)
{
	long t = 0;
	//long delay = 8000000L / frequency / 2L;
	long count = milis * 8000L;
	while(t < count)
	{
		delay_us(1000000/frequency/2);
		PORTF ^= (0b00001000);
		t += TCNT3;
		TCNT3 = 0;
	}
}

/*
A wait method to wait for a chosen amount of ms
ms is the amount of milliseconds to wait
*/
void wait( int ms )

{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}