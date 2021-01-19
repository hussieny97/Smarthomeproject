/************************************************************************/
/* Name: MDIO_program.c                                                  */
/* Author: Hussien Heikal                                                */
/* Date: 11-7-2020                                                       */
/* Version: v1.0                                                         */
/* Description: This file contains program information for DIO modules   */
/*********************************************************************** */
/************************************************************************/
/*                             Includes                                  */
#include "Lbit_math.h"
#include "Lstd_types.h"
#include "MDIO_interface.h"
#include "MDIO_private.h"


/************************************************************************/

/************************************************************************/
/*                         Functions definitions                        */
/************************************************************************/
//This Function is responsible for setting the status pin or pins for a dedicated port
void mdio_pinStatus(u8_t port,u8_t pin, u8_t pin_status)
{
	/* Switching between ports A,B,C,D*/
	switch(port)
	{
		/* In case of port A set the status of port A*/
		case PORTA:
		     switch(pin_status)
			 {
				 /* In case of Output */
				 case OUTPUT:
				 /* Set bits to 1 in DDRA*/
						MDIO_DDRA |=pin; //DDRA: ob01010000 || pin: 00110011 = 01110011
				      break;
					  /* In case of Input*/
					  case INPUT_FLOAT:
					  /*Clear Bits to 0 in DDRA*/
					  MDIO_DDRA &= ~pin;
					  break;
					  /*In case of Input pull up*/
					  case INPUT_PULLUP:
					  /*Clear Bits to 0 in DDRA */
					  MDIO_DDRA &= ~ pin;
					  /*Set Bits to 1 in PortA to enable pull up */
					  MDIO_PORTA |= pin;
					  break;
			 }
			 break;
			 /* In case of port A set the status of port A*/
		case PORTB:
		     switch(pin_status)
			 {
				  /* In case of Output */
				 case OUTPUT:
				 /* Set bits to 1 in DDRA*/
						MDIO_DDRB |=pin; //DDRA: ob01010000 || pin: 00110011 = 01110011
				      break;
					  /* In case of Input*/
					  case INPUT_FLOAT:
					  MDIO_DDRB &= ~pin;
					  break;
					  case INPUT_PULLUP:
					  MDIO_DDRB &= ~ pin;
					  MDIO_PORTB |= pin;
					  break;
			 }
			 break;
			 /* In case of port A set the status of port A*/
	   case PORTC:
		     switch(pin_status)
			 {
				  /* In case of Output */
				 case OUTPUT:
				 /* Set bits to 1 in DDRA*/
						MDIO_DDRC |=pin; //DDRA: ob01010000 || pin: 00110011 = 01110011
				      break;
					  /* In case of Input*/
					  case INPUT_FLOAT:
					  MDIO_DDRC &= ~pin;
					  break;
					  case INPUT_PULLUP:
					  MDIO_DDRC &= ~ pin;
					  MDIO_PORTC |= pin;
					  break;
			 }
			 break;
			 /* In case of port A set the status of port A*/
	   case PORTD:
		     switch(pin_status)
			 {
				  /* In case of Output */
				 case OUTPUT:
				 /* Set bits to 1 in DDRA*/
						MDIO_DDRD |=pin; //DDRA: ob01010000 || pin: 00110011 = 01110011
				      break;
					  /* In case of Input*/
					  case INPUT_FLOAT:
					  MDIO_DDRD &= ~pin;
					  break;
					  case INPUT_PULLUP:
					  MDIO_DDRD &= ~ pin;
					  MDIO_PORTD |= pin;
					  break;
			 }
			 break;			 
			 
	}
	return;
}
//This Function is responsible for setting pin or pins dedicated value
void mdio_pinValue(u8_t port,u8_t pin, u8_t pin_value)
{
	switch(port)
	{
		/* In case of port A set the Value of port A*/
		case PORTA:
		switch(pin_value)
		{
			/* In case of HIGH */
			case HIGH:
			/* Set bits to 1 in PORT*/
			MDIO_PORTA |=pin; //DDRA: ob01010000 || pin: 00110011 = 01110011
			break;
			/* In case of LOW*/
			case LOW:
			/*Clear Bits to 0 in PORTA*/
			MDIO_PORTA &= ~pin;
			break;
			
		}
		break;
		case PORTB:
		switch(pin_value)
		{
			/* In case of HIGH */
			case HIGH:
			/* Set bits to 1 in PORTB*/
			MDIO_PORTB |=pin; //DDRA: ob01010000 || pin: 00110011 = 01110011
			break;
			/* In case of LOW*/
			case LOW:
			/*Clear Bits to 0 in PORTB*/
			MDIO_PORTB &= ~pin;
			break;
			
		}
		break;
		case PORTC:
		switch(pin_value)
		{
			/* In case of HIGH */
			case HIGH:
			/* Set bits to 1 in PORTC*/
			MDIO_PORTC |=pin; //DDRA: ob01010000 || pin: 00110011 = 01110011
			break;
			/* In case of LOW*/
			case LOW:
			/*Clear Bits to 0 in PORTC*/
			MDIO_PORTC &= ~pin;
			break;
			
		}
		break;
		case PORTD:
		switch(pin_value)
		{
			/* In case of HIGH */
			case HIGH:
			/* Set bits to 1 in PORTD*/
			MDIO_PORTD |=pin; //DDRA: ob01010000 || pin: 00110011 = 01110011
			break;
			/* In case of LOW*/
			case LOW:
			/*Clear Bits to 0 in PORTD*/
			MDIO_PORTD &= ~pin;
			break;
			
		}
		break;
	}
	return;
}
//This Function is responsible for toggling a dedicated value for a pin or pins
void mdio_togglePinvalue(u8_t port,u8_t pin)
{
	switch(port)
	{
		/* In case of port A set of port A*/
		case PORTA:
		/*Toggling dedicated pins value*/
		MDIO_PORTA ^=pin;
		break;
		case PORTB:
		/*Toggling dedicated pins value*/
		MDIO_PORTB ^=pin;
			break;
		case PORTC:
		/*Toggling dedicated pins value*/
		MDIO_PORTC ^=pin;
			break;
		case PORTD:
		/*Toggling dedicated pins value*/
		MDIO_PORTD ^=pin;
			break;
	}
	
		return;
	
}
//This Function is responsible for getting a dedicated pin value
u8_t mdio_getPinValue(u8_t port,u8_t pin)
{
	/* Local variable used to get a dedicated pin value*/
	u8_t pinValue=0; 
	/*Switching over DIO ports*/
	switch(port)
	{
		/* In case of port A set of port A*/
		case PORTA:
		/*reading  dedicated pins value*/
		if(MDIO_PINA &pin)//PINA=0b10001001 & pin =0b0101000 gives 0 so its low
		{
			//if any other value than 0 then pin value is high
			pinValue=HIGH;
		}
		else
		{
			//if value is 0 its low
			pinValue=LOW;
		}
		break;
	
		/* In case of port B
		case PORTB:
		/*reading  dedicated pins value*/
		if(MDIO_PINB &pin)//PINA=0b10001001 & pin =0b0101000 gives 0 so its low
		{
			//if any other value than 0 then pin value is high
			pinValue=HIGH;
		}
		else
		{
			//if value is 0 its low
			pinValue=LOW;
		}
		break;
			//In case of port C
		case PORTC:
		/*reading  dedicated pins value*/
		if(MDIO_PINC &pin)//PINA=0b10001001 & pin =0b0101000 gives 0 so its low
		{
			//if any other value than 0 then pin value is high
			pinValue=HIGH;
		}
		else
		{
			//if value is 0 its low
			pinValue=LOW;
		}
		break;
			//In case of port D
		case PORTD:
		/*reading  dedicated pins value*/
		if(MDIO_PIND &pin)//PINA=0b10001001 & pin =0b0101000 gives 0 so its low
		{
			//if any other value than 0 then pin value is high
			pinValue=HIGH;
		}
		else
		{
			//if value is 0 its low
			pinValue=LOW;
		}
		break;
		
	}
	
	/*Return the real value of the pin*/
		return pinValue;
}
