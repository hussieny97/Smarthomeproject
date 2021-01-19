/************************************************************************/
/* Name: MDIO_private.h                                                      */
/* Author: Hussien Heikal                                                   */ 
/* Date: 11-7-2020                                                         */    
/* Version: v1.0                                                          */
/* Description: This file contains private information for DIO modules   */
/************************************************************************/
#ifndef MDIO_PRIVATE_H_
#define MDIO_PRIVATE_H_
/************************************************************************/
/*                       DIO Register                                   */
/************************************************************************/
//GPIOA
#define MDIO_PORTA (*(volatile u8_t*)(0x3B))
#define MDIO_DDRA  (*(volatile u8_t*)(0x3A))
#define MDIO_PINA  (*(volatile u8_t*)(0x39))
//GPIOB
#define MDIO_PORTB (*(volatile u8_t*)(0x38))
#define MDIO_DDRB  (*(volatile u8_t*)(0x37))
#define MDIO_PINB  (*(volatile u8_t*)(0x36))
//GPIOC
#define MDIO_PORTC (*(volatile u8_t*)(0x35))
#define MDIO_DDRC  (*(volatile u8_t*)(0x34))
#define MDIO_PINC  (*(volatile u8_t*)(0x33))
//GPIOD
#define MDIO_PORTD (*(volatile u8_t*)(0x32))
#define MDIO_DDRD  (*(volatile u8_t*)(0x31))
#define MDIO_PIND  (*(volatile u8_t*)(0x30))


#endif /* MDIO_PRIVATE_H_ */