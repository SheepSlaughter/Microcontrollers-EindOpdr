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
}

