/*
* SPI_LCD
*
* Created: 12/30/2020 1:59:11 PM
* Author : karim
*/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "CPU_CONFIGURATION.h"
#include "SPI.h"
#include "SPI_CONFIG.h"
#include "UART.h"
#include "UART_CONFIG.h"
#include "DIO.h"
#include "DIO_CONFIG.h"
#include "util/delay.h"

#define F_CPU 16000000UL

int main(void)
{
	SPI_INIT();

	DIO_SetPin_Direction(DDRC,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_SetPin_Direction(DDRC,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_SetPin_Direction(DDRC,DIO_PIN2,DIO_PIN_OUTPUT);

	Uint8t Data_in;

		while(1)
		{
//			SPI_RECEIVE(&Data_in);
			Data_in = '1';
			if (Data_in =='1')
			{
				DIO_SetPin_Value(DIO_PORTC,DIO_PIN0 ,DIO_PIN_HIGH);
				DIO_SetPin_Value(DIO_PORTC,DIO_PIN1 ,DIO_PIN_LOW);
				DIO_SetPin_Value(DIO_PORTC,DIO_PIN2 ,DIO_PIN_LOW);
			}
			else if(Data_in =='2')
			{
				DIO_SetPin_Value(DIO_PORTC,DIO_PIN0 ,DIO_PIN_LOW);
				DIO_SetPin_Value(DIO_PORTC,DIO_PIN1 ,DIO_PIN_HIGH);
				DIO_SetPin_Value(DIO_PORTC,DIO_PIN2 ,DIO_PIN_LOW);
			}
			else if(Data_in =='3')
			{
				DIO_SetPin_Value(DIO_PORTC,DIO_PIN0 ,DIO_PIN_LOW);
				DIO_SetPin_Value(DIO_PORTC,DIO_PIN1 ,DIO_PIN_LOW);
				DIO_SetPin_Value(DIO_PORTC,DIO_PIN2 ,DIO_PIN_HIGH);
			}
		}

	return 0;
}
