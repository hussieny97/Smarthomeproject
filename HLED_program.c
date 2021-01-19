/**************************************************************************/
/* Name:    HLED_program.c                                                */
/* Author:  Hussien Yasser                                               */
/* Version: v1.0                                                          */
/* Date: 11-11-2020                                                       */
/* Description: This file contains LED module logical program             */
/**************************************************************************/

/************************************************************************/
/*                               Includes                               */
/************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HLED_interface.h"
#include "HLED_private.h"
#include "MDIO_interface.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/
// Make LED output
void hled_init(u8_t led_number)
{
	//Depending one the led number this function makes the corresponding LED pin an output pin
	switch(led_number)
	{
		case LED0:
			mdio_pinStatus(LED0_PORT,LED0_PIN,OUTPUT);
		break;
 		case LED1:
 			mdio_pinStatus(LED1_PORT,LED1_PIN,OUTPUT);
 		break;
	 	case LED2:
	 		mdio_pinStatus(LED2_PORT,LED2_PIN,OUTPUT);
	 	break;
	}
	/*Return from this function*/
	return;
}
//This function switches LED ON
void hled_ledON(u8_t led_number)
{
	//Depending one the led number this function turns on the corresponding LED
	switch(led_number)
	{
		//LED0 turns ON
		case LED0:
			mdio_pinValue(LED0_PORT,LED0_PIN,HIGH);
		break;
		//LED1 turns ON
		case LED1:
			mdio_pinValue(LED1_PORT,LED1_PIN,HIGH);
		break;
		//LED2 turns ON
		case LED2:
			mdio_pinValue(LED2_PORT,LED2_PIN,HIGH);
		break;
	}
	
	/*Return from this function*/
	return;
}
//This function switches LED off
void hled_ledOFF(u8_t led_number)
{
	//Depending one the led number this function turns off the corresponding LED
	switch(led_number)
		{
		//LED0 turns OFF
		case LED0:
			mdio_pinValue(LED0_PORT,LED0_PIN,LOW);
		break;
		//LED1 turns OFF
		case LED1:
			mdio_pinValue(LED1_PORT,LED1_PIN,LOW);
		break;
		//LED2 turns OFF
		case LED2:
			mdio_pinValue(LED2_PORT,LED2_PIN,LOW);
		break;
		}
		
	/*Return from this function*/
	return;
}