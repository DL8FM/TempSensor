/*******************************************************************************
 * 
 * TempSensor
 * Michael Gietl
 * 20210505
 * 
 * Uart0.c
 * 
 *******************************************************************************/


/*******************************************************************************
 * System Includes
 *******************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>


/*******************************************************************************
 * Project Includes
 *******************************************************************************/
#include "Uart0.h"
#include "main.h"
 

/*******************************************************************************
 * Local Variables
 *******************************************************************************/
UartFifo_t Uart0Fifo_s;


/*******************************************************************************
 * Local Functions
 *******************************************************************************/
 
 
/*******************************************************************************
 * Uart0Init
 * Param: void
 * Return: void
 *******************************************************************************/
void Uart0Init(void) {
	UBRR0H = (USART0_UBRR0 >> 8);
	UBRR0L = USART0_UBRR0;
	UCSR0B = (1 << RXEN0) | (1<<TXEN0) | (1<<RXCIE0);
	UCSR0C = (1 << UCSZ00) | (1 << UCSZ01);
	Uart0FifoInit(&Uart0Fifo_s);
	Uart0Transmit();
}


/*******************************************************************************
 * Uart0FifoInit
 * Initialize every element of the struct to default
 * Param: Pointer to Uart0Fifo_t
 * Return: void
 *******************************************************************************/
void Uart0FifoInit(UartFifo_t *pUart0Fifo_s) {
	pUart0Fifo_s->UartMsgSize = 7;		// Set MessageSize to 8
	pUart0Fifo_s->UartMsg = 65;
	pUart0Fifo_s->UartStatus = 1;
}
 
 
/*******************************************************************************
 * Uart0Transmit
 * Param: void
 * Return: void
 *******************************************************************************/
void Uart0Transmit(void) {
	if(Uart0Fifo_s.UartStatus == 1) {
		for(int x = 0; x < 1; x++) {
		for(int a = 0; a <= Uart0Fifo_s.UartMsgSize;a++) {
			while (!(UCSR0A & (1<<UDRE0)));
			UDR0 = Uart0Fifo_s.UartMsg;
		}
	}
	Uart0Fifo_s.UartStatus = 0;
	}
}

void Uart0SetStatus(int *pSetStatus) {
	Uart0Fifo_s.UartStatus = *pSetStatus;
}



void Uart0FifoWrite(int *a, int *b, int *c) {
	Uart0Fifo_s.UartMsg = *b;
	Uart0Fifo_s.UartMsgSize = *a;
	Uart0Fifo_s.UartStatus = *c;
}

/*******************************************************************************
 * Interrupt Service Routine
 *******************************************************************************/
ISR (USART_RX_vect) {
	//
}
