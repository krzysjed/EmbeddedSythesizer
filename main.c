/*-------------------------------------------------------------------------
					Technika Mikroprocesorowa 2 - laboratorium
					Lab 4 - Ćwiczenie 1: PWM
					autor: Mariusz Sokołowski
					wersja: 02.11.2020r.
----------------------------------------------------------------------------*/
#include "frdm_bsp.h"
#include "DAC.h"
#include "MKL05Z4.h"
#include "klaw.h"
#include "pit.h"
#include "fsm.h"
#include <stdio.h>
#include "math.h"
#include "sintable.c"
#include <string.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846

void delay(int x){
	for(uint32_t i=0;i<(x*1000);i++)__nop();
}
int main (void) 
{
	buttonsInitialize();
	fsmInitialize();
	pitInitialize( 20900 );
	startPIT();
	int t[32000];
	for(int i=0;i<32000;i++){
		t[i] = ;
	}
	DAC_Init();
	int j = 0;
  while(1)
	{
		DAC_Load_Trig(t[j++]);
	}
}

