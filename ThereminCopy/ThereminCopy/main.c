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

int duration;
int distance;

void echoNoTimer(void){
	/* Replace with your application code */

	DDRD = 0b00000100;
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	
	EICRB = 0b00000001;
	EIMSK = 0b00010000;
	sei();
	
	while (1)
	{
		
		
		//digitalWrite(trigPin, HIGH);
		PORTE = 0b00000100;
		
		//delayMicroseconds(1000);
		_delay_us(1000);
		
		//digitalWrite(trigPin, LOW);
		PORTE = 0b00000000;
		
		_delay_ms(500);
	}
}


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
		//todo get timer number
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
	}
}

int main(void)
{
    echoNoTimer();
}


