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
	//
//Uint8t dataSent = 'B';
//	LCD_Init();
//	SPI_INIT();
//	SPI_SLAVESELECT(0);
//	while (1)
//	{
//		LCD_Clear();
//		SPI_TRANSMIT(dataSent);
//		LCD_Write_Data(dataSent);
//		_delay_ms(250);

//		DIO_SetPin_Direction(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
//		DIO_SetPin_Value(DIO_PORTC, DIO_PIN7, DIO_PIN_HIGH);

	SPI_INIT();
	SPI_SLAVESELECT(0);
	UART_Init();

\
	DIO_SetPin_Direction(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT);
	DIO_SetPin_Direction(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT);

	Uint8t data;
	while (1)
	{
	data = UART_Receive();
	SPI_TRANSMIT(data);
	_delay_ms(150);
	}

	return 0;
}
