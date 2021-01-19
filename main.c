/*
 * SmartHomeProjectSlave.c
 *
 * Created: 1/18/2021 11:19:17 PM
 * Author : Hussien Yasser
 *Program : Slave Device
 */ 

#include "avr/io.h"
#include "MDIO_interface.h"
#include "Lbit_math.h"
#include "Lstd_types.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "HLED_interface.h"
#define F_CPU 16000000UL
#include "util/delay.h"

//This program receives data from the master MCU to figure out which Lamp turns on based on the user's decision 
int main(void)
{
  //SPI SLAVE mode
	mdio_pinStatus(PORTB,PIN4,INPUT_FLOAT);
	mdio_pinStatus(PORTB,PIN5,INPUT_FLOAT);
	mdio_pinStatus(PORTB,PIN6,OUTPUT);
	mdio_pinStatus(PORTB,PIN7,INPUT_FLOAT);
	mspi_init(Slave,MSPI_SAMPLE_R_SETUP_F, MSPI_PRE_32);
	
	//initializing LAMPS
	hled_init(LED0);
	hled_init(LED1);
    
    while (1) 
    {
		if(mspi_sendRecvByte('k')) 
		{
			hled_ledON(LED0);//kitchen Lamp ON
		}
		
		else if(mspi_sendRecvByte('l'))
		
		{
			hled_ledOFF(LED0);//kitchen Lamp OFF
		}
		
		else if(mspi_sendRecvByte('n'))
		
		{
			hled_ledON(LED1);//Bathroom Lamp ON
		}
	
		
		else if(mspi_sendRecvByte('o'))
		
		{
			hled_ledOFF(LED1);//Bathroom Lamp OFF
		}
		
		else
		{
			//do nothing
		}
    }
}

