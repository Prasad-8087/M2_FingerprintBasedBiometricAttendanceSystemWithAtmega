#define F_CPU 16000000UL /* Define CPU Frequency 1MHz */
#include <avr/io.h> /* Include AVR std. library file */
#include <util/delay.h> /* Include delay header file */
 
 
int main(void)
{
 
//int period;
DDRA = 0x0F; /* Make PORTA lower pins as output */
    int period = 6; /* Set period in between two steps */
 
while (1)
{
 
/* Rotate Stepper Motor clockwise with Half step sequence */
for(int i=0;i<50;i++)
{
PORTA = 0x09;
_delay_ms(period);
PORTA = 0x08;
_delay_ms(period);
PORTA = 0x0C;
_delay_ms(period);
PORTA = 0x04;
_delay_ms(period);
PORTA = 0x06;
_delay_ms(period);
PORTA = 0x02;
_delay_ms(period);
PORTA = 0x03;
_delay_ms(period);
PORTA = 0x01;
_delay_ms(period);
}
PORTA = 0x09; /* Last step to initial position */
_delay_ms(period);
_delay_ms(1000);
 
/* Rotate Stepper Motor Anticlockwise with Full step sequence */
for(int i=0;i<50;i++)
{
PORTA = 0x01;
_delay_ms(period);
PORTA = 0x03;
_delay_ms(period);
PORTA = 0x02;
_delay_ms(period);
PORTA = 0x06;
_delay_ms(period);
PORTA = 0x04;
_delay_ms(period);
PORTA = 0x0C;
_delay_ms(period);
PORTA = 0x08;
_delay_ms(period);
PORTA = 0x09;
_delay_ms(period);
 
}
PORTA = 0x09;
_delay_ms(period);
_delay_ms(1000);
}
}