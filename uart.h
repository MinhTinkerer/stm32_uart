#ifndef UART_H
#define UART_H

#include "stm32f10x.h"

#define USART_Pin_Tx            GPIO_Pin_2
#define USART_Pin_Rx            GPIO_Pin_3
#define USART_GPIO              GPIOA
#define USARTx                  USART2
#define USART_BOUD_RATE         115200L

#define uartSIZE_OF_RING_BUFFER	128

//#define USE_FREERTOS			//uncomment this for using freeRTOS semaphore
#define NO_DATA		(-1)

void UART_Init(void);
void UART_SendChar(uint8_t data);
void UART_SendString(const char *str);
int UART_GetChar();
#ifdef USE_FREERTOS
int UART_GetCharBlocking();
#endif

#if (uartSIZE_OF_RING_BUFFER > 256)
#error "uartSIZE_OF_RING_BUFFER must be less then 256"
#endif
#endif
