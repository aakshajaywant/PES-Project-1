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
 
/**
 * @file    MKL25Z128xxx4_Project.c
 * @brief   Application entry point.
 */

#include <stdio.h>
#include <stdint.h>
#include "time.h"
#ifdef PC_RUN
#include <windows.h>
#endif

#ifdef FB_RUN
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "led.h"
#endif

#ifdef FB_DEBUG
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "led.h"
#endif

//uint16_t table[200]= {3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600,3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600};

//int delay(uint64_t k)
//{
//	k=k*1000*2.4;
//	while(k!=0)
//	{
//		k--;
//	}
//	return 0;
//}


/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

int main(void)
{

uint8_t i=0,j=0;
time_t rawtime;
struct tm *info;


#ifdef FB_RUN
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
    LED_RED_INIT(1);
    LED_BLUE_INIT(1);
    LED_GREEN_INIT(1);
    while(1)
    {
    	LED();
    }
#endif


#ifdef FB_DEBUG
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
    LED_RED_INIT(1);
    LED_BLUE_INIT(1);
    LED_GREEN_INIT(1);
    while(1)
    {
    	LED();
    }
#endif

#ifdef PC_RUN
    while(1)
    {
    	for(j=0;j<3;j++)
    	{
    		printf("\nLED RED ON");
    		Sleep(table[i]);
    		i++;
    		printf("\nLED RED OFF");
    		Sleep(table[i]);
    		i++;
    	}
    	for(j=0;j<3;j++)
    	{
    		printf("\nLED GREEN ON");
    		Sleep(table[i]);
    		i++;
    		printf("\nLED GREEN OFF");
    		Sleep(table[i]);
    		i++;
    	}
    	for(j=0;j<3;j++)
    	{
    		printf("\nLED BLUE ON");
    		Sleep(table[i]);
    		i++;
    		printf("\nLED BLUE OFF");
    		Sleep(table[i]);
    		i++;
    	}
		if(i==200) break;
    }
#endif

#ifdef PC_DEBUG
    while(1)
    {
    	for(j=0;j<3;j++)
    	{
    		time( &rawtime );
			info = localtime( &rawtime );
			printf("\nLED GREEN ON\t%s\t%lu\n",asctime(info),table[i]);
			Sleep(table[i]);
			i++;
			time( &rawtime );
			info = localtime( &rawtime );
			printf("\nLED GREEN OFF\t%s\t%lu\n",asctime(info),table[i]);
			i++;
    	}
    	for(j=0;j<3;j++)
    	{
    		time( &rawtime );
    		info = localtime( &rawtime );
    		printf("\nLED GREEN ON\t%s\t%lu\n",asctime(info),table[i]);
    		Sleep(table[i]);
    		i++;
    		time( &rawtime );
    		info = localtime( &rawtime );
    		printf("\nLED GREEN OFF\t%s\t%lu\n",asctime(info),table[i]);
    		i++;
    	}
    	for(j=0;j<3;j++)
    	{
    		time( &rawtime );
    		info = localtime( &rawtime );
    		printf("\nLED GREEN ON\t%s\t%lu\n",asctime(info),table[i]);
    		Sleep(table[i]);
    		i++;
    		time( &rawtime );
    		info = localtime( &rawtime );
    		printf("\nLED GREEN OFF\t%s\t%lu\n",asctime(info),table[i]);
    		i++;
    	}
    	if(i==200) break;
    }
#endif

    return 0;
}




