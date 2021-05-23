/*******************************************************************************
 * 
 *	TempSensor
 *	Michael Gietl
 *	20210505
 * 
 * 	Uart0.h
 * 
 *******************************************************************************/


/*******************************************************************************
 * Global Function
 *******************************************************************************/
#define USART0_UBRR0 103		// Value for 16 MHz clock and 9600 Baudrate
								// Page 163 Datasheet
#define UART0_FIFOSIZE 32

typedef struct {
	int UartMsg;
	int UartMsgSize;
	int UartStatus;
} UartFifo_t;


/*******************************************************************************
 * Global Function
 *******************************************************************************/
void Uart0Init(void);		// Configuration of Uart0 hardware

void Uart0FifoInit(UartFifo_t*);		// Initialize Uart0 Fifo

void Uart0Transmit(void);		// Transmit of char via Uart0

void Uart0FifoWrite(int*, int*, int*);

void Uart0SetStatus(int*);
