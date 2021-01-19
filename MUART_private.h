/************************************************************************/
/* Name:    MUART_private.h                                             */
/* Author:  Hussien Yasser                                                */
/* Version: v1.0     
 * Created: 1/18/2021 10:10:54 PM                                         */
/* Description: This file contains private information for UART module  */
/************************************************************************/

/*Header file guard*/
#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/************************************************************************/
/*                            UART Registers                            */
/************************************************************************/

#define MUART_UBRRL   (*(volatile u8_t*)(0x29))
#define MUART_UCSRB   (*(volatile u8_t*)(0x2A))
#define MUART_UCSRA   (*(volatile u8_t*)(0x2B))
#define MUART_UDR     (*(volatile u8_t*)(0x2C))
#define MUART_UBRRH   (*(volatile u8_t*)(0x40))
#define MUART_UCSRC   (*(volatile u8_t*)(0x40))


#endif /* UART_PRIVATE_H_ */