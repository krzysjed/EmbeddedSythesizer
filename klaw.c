#include "klaw.h"
#include "frdm_bsp.h"
#include "fsm.h"
void buttonsInitialize(void){
	SIM->SCGC5 |=  SIM_SCGC5_PORTB_MASK; 
	//PORTB->PCR[BUTTON_1_POS] |= PORT_PCR_MUX(1);      	
	PORTB->PCR[BUTTON_5_POS] |= PORT_PCR_MUX(1);      	
	PORTB->PCR[BUTTON_9_POS] |= PORT_PCR_MUX(1); 
	
	//PORTB->PCR[BUTTON_1_POS] |=  PORT_PCR_PE_MASK |	PORT_PCR_PS_MASK;
	//PORTB->PCR[BUTTON_1_POS] |= 	PORT_PCR_IRQC(0xA);	
	PORTB->PCR[BUTTON_5_POS] |=  PORT_PCR_PE_MASK |		
											 PORT_PCR_PS_MASK;			
	PORTB->PCR[BUTTON_5_POS] |=  PORT_PCR_IRQC(0xA);	  

	PORTB->PCR[BUTTON_9_POS] |=  PORT_PCR_PE_MASK |		
											 PORT_PCR_PS_MASK;			
	PORTB->PCR[BUTTON_9_POS] |=  PORT_PCR_IRQC(0xA);
	NVIC_ClearPendingIRQ(myPORT_IRQn);				
	NVIC_EnableIRQ(myPORT_IRQn);							
	
	NVIC_SetPriority (myPORT_IRQn, 2);
	
}

void PORTB_IRQHandler(void){		
	
		if(PORTB->ISFR & (1 << BUTTON_5_POS)){
			fsmStartStop();
		while((FPTB->PDIR&(1<<BUTTON_5_POS))==0){
		
		}
		PORTB->PCR[BUTTON_5_POS] |= PORT_PCR_ISF_MASK; 
	}
}

