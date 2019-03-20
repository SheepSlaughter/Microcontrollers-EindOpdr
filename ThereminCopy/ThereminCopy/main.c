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

void wait( int ms );

void playTune(long frequency, long milis)
{
	long t = 0;
	long delay = 8000000L / frequency / 2L;
	long count = milis * 8000L;
	while(t < count)
	{
		if(TCNT3 >= delay)
		{
			PORTE ^= (0xFF);
			t += TCNT3;
			TCNT3 = 0;
		}
	}
}

int main(void)
{
	DDRE = 0b00001000;			//set DDRD3 as output
	TCCR3B |= 0b00000001;	//set up timer
	while(1)
	{
		playTune(660 ,100);
		wait(150);
		playTune(660 ,100);
		wait(300);
		playTune(660 ,100);
		wait(300);
		playTune(510 ,100);
		wait(100);
		playTune(660 ,100);
		wait(300);
		playTune(770 ,100);
		wait(550);
		playTune(380 ,100);
		wait(575);

		playTune(510 ,100);
		wait(450);
		playTune(380 ,100);
		wait(400);
		playTune(320 ,100);
		wait(500);
		playTune(440 ,100);
		wait(300);
		playTune(480 ,80);
		wait(330);
		playTune(450 ,100);
		wait(150);
		playTune(430 ,100);
		wait(300);
		playTune(380 ,100);
		wait(200);
		playTune(660 ,80);
		wait(200);
		playTune(760 ,50);
		wait(150);
		playTune(860 ,100);
		wait(300);
		playTune(700 ,80);
		wait(150);
		playTune(760 ,50);
		wait(350);
		playTune(660 ,80);
		wait(300);
		playTune(520 ,80);
		wait(150);
		playTune(580 ,80);
		wait(150);
		playTune(480 ,80);
		wait(500);

		playTune(510 ,100);
		wait(450);
		playTune(380 ,100);
		wait(400);
		playTune(320 ,100);
		wait(500);
		playTune(440 ,100);
		wait(300);
		playTune(480 ,80);
		wait(330);
		playTune(450 ,100);
		wait(150);
		playTune(430 ,100);
		wait(300);
		playTune(380 ,100);
		wait(200);
		playTune(660 ,80);
		wait(200);
		playTune(760 ,50);
		wait(150);
		playTune(860 ,100);
		wait(300);
		playTune(700 ,80);
		wait(150);
		playTune(760 ,50);
		wait(350);
		playTune(660 ,80);
		wait(300);
		playTune(520 ,80);
		wait(150);
		playTune(580 ,80);
		wait(150);
		playTune(480 ,80);
		wait(500);

		playTune(500 ,100);
		wait(300);

		playTune(760 ,100);
		wait(100);
		playTune(720 ,100);
		wait(150);
		playTune(680 ,100);
		wait(150);
		playTune(620 ,150);
		wait(300);

		playTune(650 ,150);
		wait(300);
		playTune(380 ,100);
		wait(150);
		playTune(430 ,100);
		wait(150);

		playTune(500 ,100);
		wait(300);
		playTune(430 ,100);
		wait(150);
		playTune(500 ,100);
		wait(100);
		playTune(570 ,100);
		wait(220);

		playTune(500 ,100);
		wait(300);

		playTune(760 ,100);
		wait(100);
		playTune(720 ,100);
		wait(150);
		playTune(680 ,100);
		wait(150);
		playTune(620 ,150);
		wait(300);

		playTune(650 ,200);
		wait(300);

		playTune(1020,80);
		wait(300);
		playTune(1020,80);
		wait(150);
		playTune(1020,80);
		wait(300);

		playTune(380 ,100);
		wait(300);
		playTune(500 ,100);
		wait(300);

		playTune(760 ,100);
		wait(100);
		playTune(720 ,100);
		wait(150);
		playTune(680 ,100);
		wait(150);
		playTune(620 ,150);
		wait(300);

		playTune(650 ,150);
		wait(300);
		playTune(380 ,100);
		wait(150);
		playTune(430 ,100);
		wait(150);

		playTune(500 ,100);
		wait(300);
		playTune(430 ,100);
		wait(150);
		playTune(500 ,100);
		wait(100);
		playTune(570 ,100);
		wait(420);

		playTune(585 ,100);
		wait(450);

		playTune(550 ,100);
		wait(420);

		playTune(500 ,100);
		wait(360);

		playTune(380 ,100);
		wait(300);
		playTune(500 ,100);
		wait(300);
		playTune(500 ,100);
		wait(150);
		playTune(500 ,100);
		wait(300);

		playTune(500 ,100);
		wait(300);

		playTune(760 ,100);
		wait(100);
		playTune(720 ,100);
		wait(150);
		playTune(680 ,100);
		wait(150);
		playTune(620 ,150);
		wait(300);

		playTune(650 ,150);
		wait(300);
		playTune(380 ,100);
		wait(150);
		playTune(430 ,100);
		wait(150);

		playTune(500 ,100);
		wait(300);
		playTune(430 ,100);
		wait(150);
		playTune(500 ,100);
		wait(100);
		playTune(570 ,100);
		wait(220);

		playTune(500 ,100);
		wait(300);

		playTune(760 ,100);
		wait(100);
		playTune(720 ,100);
		wait(150);
		playTune(680 ,100);
		wait(150);
		playTune(620 ,150);
		wait(300);

		playTune(650 ,200);
		wait(300);

		playTune(1020,80);
		wait(300);
		playTune(1020,80);
		wait(150);
		playTune(1020,80);
		wait(300);

		playTune(380 ,100);
		wait(300);
		playTune(500 ,100);
		wait(300);

		playTune(760 ,100);
		wait(100);
		playTune(720 ,100);
		wait(150);
		playTune(680 ,100);
		wait(150);
		playTune(620 ,150);
		wait(300);

		playTune(650 ,150);
		wait(300);
		playTune(380 ,100);
		wait(150);
		playTune(430 ,100);
		wait(150);

		playTune(500 ,100);
		wait(300);
		playTune(430 ,100);
		wait(150);
		playTune(500 ,100);
		wait(100);
		playTune(570 ,100);
		wait(420);

		playTune(585 ,100);
		wait(450);

		playTune(550 ,100);
		wait(420);

		playTune(500 ,100);
		wait(360);

		playTune(380 ,100);
		wait(300);
		playTune(500 ,100);
		wait(300);
		playTune(500 ,100);
		wait(150);
		playTune(500 ,100);
		wait(300);

		playTune(500 ,60);
		wait(150);
		playTune(500 ,80);
		wait(300);
		playTune(500 ,60);
		wait(350);
		playTune(500 ,80);
		wait(150);
		playTune(580 ,80);
		wait(350);
		playTune(660 ,80);
		wait(150);
		playTune(500 ,80);
		wait(300);
		playTune(430 ,80);
		wait(150);
		playTune(380 ,80);
		wait(600);

		playTune(500 ,60);
		wait(150);
		playTune(500 ,80);
		wait(300);
		playTune(500 ,60);
		wait(350);
		playTune(500 ,80);
		wait(150);
		playTune(580 ,80);
		wait(150);
		playTune(660 ,80);
		wait(550);

		playTune(870 , 80);
		wait(325);
		playTune(760 , 80);
		wait(600);

		playTune(500 ,60);
		wait(150);
		playTune(500 ,80);
		wait(300);
		playTune(500 ,60);
		wait(350);
		playTune(500 ,80);
		wait(150);
		playTune(580 ,80);
		wait(350);
		playTune(660 ,80);
		wait(150);
		playTune(500 ,80);
		wait(300);
		playTune(430 ,80);
		wait(150);
		playTune(380 ,80);
		wait(600);

		playTune(660 ,100);
		wait(150);
		playTune(660 ,100);
		wait(300);
		playTune(660 ,100);
		wait(300);
		playTune(510 ,100);
		wait(100);
		playTune(660 ,100);
		wait(300);
		playTune(770 ,100);
		wait(550);
		playTune(380 ,100);
		wait(575);
	}
	
	return 0;	                  // Standard Return Code
}

void wait( int ms )

{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );
	}
}