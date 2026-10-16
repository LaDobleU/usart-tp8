#include "usart.h"
void usart_init(USART_TypeDef * USARTx, uint32_t baudrate){
if(USARTx = 1) { RCC -> APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN;
GPIOA -> CRH &= ~(0XF << (9%8 * 4));
GPIOA -> CRH |= (0x3 << (9%8 * 4));
GPIOA -> CRH &= ~(0XF << (10%8 * 4));
GPIOA -> CRH |= (0X4 << (10%8 * 4));
clock_72MHz();
float velocidad = 72000000 / (16 * baudrate);
int valor_mantissa = velocidad;
int valor_fraction = (velocidad - valor_mantissa) * 100;
 valor_mantissa = (valor_mantissa << 4);
 USARTx -> BRR |= (valor_mantissa | valor_fraction);
 }
 if(USARTx = 2) { RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
RCC -> APB2ENR |= RCC_APB2ENR_IOPAEN;
GPIOA -> CRL &= ~(0XF << 2);
GPIOA -> CRL |= (0x3 << 2);
GPIOA -> CRL &= ~(0XF << 3);
GPIOA -> CRL |= (0X4 << 3);
float velocidad = 36000000 / (16 * baudrate);
int valor_mantissa = velocidad;
int valor_fraction = (velocidad - valor_mantissa) * 100;
valor_mantissa = (valor_mantissa << 4);
USARTx -> BRR |= (valor_mantissa | valor_fraction);
}
if(USARTx = 3) { RCC -> APB1ENR |= RCC_APB1ENR_USART3EN;
RCC -> APB2ENR |= RCC_APB2ENR_IOPBEN; 
GPIOB -> CRH &= ~(0XF << (10%8 * 4));
GPIOB -> CRH |= (0x3 << (10%8 * 4));
GPIOB -> CRH &= ~(0XF << (11%8 * 4));
GPIOB -> CRH |= (0X4 << (11%8 * 4));       
float velocidad = 36000000 / (16 * baudrate);
int valor_mantissa = velocidad;
int valor_fraction = (velocidad - valor_mantissa) * 100; 
valor_mantissa = (valor_mantissa << 4); 
USARTx -> BRR |= (valor_mantissa | valor_fraction); 
 }
USARTx -> CR1 |= USART_CR1_UE; 
USARTx -> CR1 &= ~USART_CR1_PCE; 
USARTx -> CR1 |= USART_CR1_TE; 
USARTx -> CR1 |= USART_CR1_RE; 
}
void usart_send_char(USART_TypeDef * USARTx, uint8_t data){
while(!(USARTx -> SR & USART_SR_TXE));
 USARTx -> DR = data;
}

void usart_send_string(USART_TypeDef *USARTx, char* txt){
while(txt) {
usart_send_char(USARTx, txt);
txt++;
    }
}
uint8_t usart_receive_char(USART_TypeDef * USARTx){
while(!(USARTx -> SR & USART_SR_RXNE));
    return  USARTx -> DR;

}