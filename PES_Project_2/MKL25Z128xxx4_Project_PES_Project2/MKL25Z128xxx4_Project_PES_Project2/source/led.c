/********************************************************************************/
/********************************************************************************/
/* Name of the program : PES PROGRAM 2											*/
/* 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	*/
/* Authors: Aaksha Jaywant, Sarayu Managoli										*/
/*																				*/
/* Compiler used: MCUXPRESSO IDE												*/
/* 																				*/
/*																				*/
/* Program statement: You will develop a C program to drive the					*/
/* 					multicolor LED through multiple timing cycles on			*/
/*					board the Freedom KL25Z. Perform fb_run, fb_debug,			*/
/* 					 pc_run, pc_debug											*/
/*																				*/
/*																				*/
/* Applicable Link: https://www.gnu.org/software/make/	,						*/
/* 						ECEN5813_001_B_ECCR1B55_9_26_2019 lecture														*/





#include "led.h"
#include <stdio.h>
#include <stdint.h>

#ifdef FB_RUN
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif

#ifdef FB_DEBUG
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif

void LED(void);

uint8_t i=0;
uint16_t table[]= {3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600};

int delay(uint64_t k)
{
	k=k*1000*2.4;
	while(k!=0)
	{
		k--;
	}
	return 0;
}

#ifdef FB_RUN
void LED(void)
{
	uint8_t j=0;
	for(j=0;j<3;j++)
	{
		LED_RED_ON();
		delay(table[i]);
		i++;
		LED_RED_OFF();
		delay(table[i]);
		i++;
	}
	if(i==200)
	{
		LED_RED_OFF();
		LED_GREEN_OFF();
		LED_BLUE_OFF();
	}
		for(j=0;j<3;j++)
	{
		LED_GREEN_ON();
		delay(table[i]);
		i++;
		LED_GREEN_OFF();
		delay(table[i]);
		i++;
	}
	if(i==200)
	{
		LED_RED_OFF();
		LED_GREEN_OFF();
		LED_BLUE_OFF();
	}
	for(j=0;j<3;j++)
	{
		LED_BLUE_ON();
		delay(table[i]);
		i++;
		LED_BLUE_OFF();
		delay(table[i]);
		i++;
	}
	if(i==200)
	{
		LED_RED_OFF();
		LED_GREEN_OFF();
		LED_BLUE_OFF();
	}

}
#endif

#ifdef FB_DEBUG
void LED(void)
{
	uint8_t j=0;
	uint64_t waittime=0;
	for(j=0;j<3;j++)
	{
		LED_RED_ON();
		PRINTF("\nLED RED ON");
		delay(table[i]);
		PRINTF("\t%d\n",table[i]);
		i++;
		LED_RED_OFF();
		PRINTF("\nLED RED OFF");
		delay(table[i]);
		PRINTF("\t%d\n",table[i]);
		i++;
	}
	if(i==200)
	{
		LED_RED_OFF();
		LED_GREEN_OFF();
		LED_BLUE_OFF();
	}
	for(j=0;j<3;j++)
	{
		LED_GREEN_ON();
		PRINTF("\nLED GREEN ON");
		delay(table[i]);
		PRINTF("\t%d\n",table[i]);
		i++;
		LED_GREEN_OFF();
		PRINTF("\nLED GREEN OFF");
		delay(table[i]);
		PRINTF("\t%d\n",table[i]);
		i++;
	}
	if(i==200)
	{
		LED_RED_OFF();
		LED_GREEN_OFF();
		LED_BLUE_OFF();
	}
	for(j=0;j<3;j++)
	{
		LED_BLUE_ON();
		PRINTF("\nLED BLUE ON");
		delay(table[i]);
		PRINTF("\t%d\n",table[i]);
		i++;
		LED_BLUE_OFF();
		PRINTF("\nLED BLUE OFF");
		delay(table[i]);
		PRINTF("\t%d\n",table[i]);
		i++;
	}
	if(i==200)
	{
		LED_RED_OFF();
		LED_GREEN_OFF();
		LED_BLUE_OFF();
	}

}
#endif




