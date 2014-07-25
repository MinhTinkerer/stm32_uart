#include "stm32f10x.h"
#include "uart.h"

int main(void)
{
	UART_Init();
	UART_SendString("Hello with UART library\n");
    while(1)
    {
    	int result;

    	result = UART_GetChar();
    	if (result != UART_NO_DATA)	{
    		UART_SendChar( ((uint8_t)result) + 1);
    	}
    }
}
