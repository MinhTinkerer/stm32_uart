#include "stm32f10x.h"
#include "uart.h"

int main(void)
{
	UART_Init();
	UART_SendString("hello with new library");
    while(1)
    {
    	int result;

    	result = UART_GetChar();
    	if (result != NO_DATA)	{
    		UART_SendChar( ((uint8_t)result) + 1);
    	}
    }
}
