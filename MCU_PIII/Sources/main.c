/* ###################################################################
**     Filename    : main.c
**     Project     : MCU_PIII
**     Processor   : MC9S08QE128CLK
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-09-30, 07:20, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.12
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "M_1.h"
#include "M_2.h"
#include "LED_OUT.h"
#include "Serial_1.h"
#include "Serial_2.h"
#include "LED_1.h"
#include "ADC.h"
#include "US.h"
#include "Encoder_1_t.h"
#include "Encoder_2_t.h"
#include "Enconder_Int_1.h"
#include "Enconder_Int_2.h"
#include "B_1.h"
#include "Bit1.h"
#include "M1_P.h"
#include "M2_P.h"
#include "TI1.h"
#include "LED_OUT_1K_SQ.h"
#include "ACKNOWLEDGE_LED.h"
#include "DISPARO_OUT.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Tanque.h"


byte DUTY_CYCLE;
byte RECEPTOR_1;
byte RECEPTOR_2;
byte VEL_MAX_1 = 200;
byte VEL_MAX_2 = 150;



void main(void)
{
  /* Write your local variable definition here */
	
	byte enviado;
	float PWM_DUTY;
	byte ConstanteEnvio = 0xFE;
	int PROMEDIO_RECEPTOR_1 = 0x00;
	int PROMEDIO_RECEPTOR_2 = 0x00;
	byte N_MUESTRAS = 0x00;
	Serial_1_TComData ENVIO_S[] = {0x00,0x00,0x00,0x00};
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  VEL_MAX_1 = 200;
  VEL_MAX_2 = 200;
  fPERIMETRO = (2*PI*fRADIO)/fN;
  DUTY_CYCLE = 0x00;
  ACKNOWLEDGE_LED_PutVal(TRUE);
  DISPARO_OUT_PutVal(TRUE);
    (void)M_1_Enable();
  	(void)M_1_SetRatio8(0xFF);
  	(void)M_2_Enable();
  	(void)M_2_SetRatio8(0xFF);
  	(void)ADC_Measure(TRUE);
  	
  	
  for(;;)
  {
	(void)ADC_Measure(TRUE);
	(void)ADC_GetChanValue8(0,&DUTY_CYCLE);
	(void)ADC_GetChanValue8(1,&RECEPTOR_1);
	(void)ADC_GetChanValue8(2,&RECEPTOR_2);
	
	  //LED_1_NegVal();
	  //(void)Serial_1_SendBlock(&DUTY_CYCLE,1,&enviado);
	  //DUTY_CYCLE << 4;
	  //PWM_DUTY = MapF(DUTY_CYCLE,0x00,0xFF,0,1);
	  //(void)Serial_1_SendBlock(&DUTY_CYCLE,1,&enviado);
	  //MovimientoLineal(DUTY_CYCLE,'a');
	 // MovimientoLineal(DUTY_CYCLE,'r');
	//(void)Serial_1_SendBlock(0xFE,1,&enviado);
	

	//(void)Serial_1_SendBlock(&ConstanteEnvio,1,&enviado);
	/*
	 * se procede a realizar un promedio de las muestras obtenidas por el ADC
	 */
	
	if(N_MUESTRAS < 200)
	{
		PROMEDIO_RECEPTOR_1 = PROMEDIO_RECEPTOR_1 + RECEPTOR_1;
		PROMEDIO_RECEPTOR_2 = PROMEDIO_RECEPTOR_2 + RECEPTOR_2;
		N_MUESTRAS++;
	}
	else
	{
		RECEPTOR_1 = (byte)(PROMEDIO_RECEPTOR_1/N_MUESTRAS);
		RECEPTOR_2 = (byte)(PROMEDIO_RECEPTOR_2/N_MUESTRAS);
		
		/*
		ENVIO_S[0x00] = 0xFF;
		ENVIO_S[0x01] = RECEPTOR_1;
		ENVIO_S[0x02] = RECEPTOR_2;
		ENVIO_S[0x03] = 0xFF;*/
								
		//(void)Serial_1_SendBlock(&ENVIO_S,4,&enviado);
		//(void)Serial_1_ClearTxBuf();
		//(void)Serial_1_SendChar(0x01);
		//(void)Serial_1_SendChar(RECEPTOR_1);
		//(void)Serial_1_SendChar(RECEPTOR_2);
		if(RECEPTOR_1 > RECEPTOR_2) DIFERENCIA = RECEPTOR_1 - RECEPTOR_2;
		
		else DIFERENCIA = RECEPTOR_2 - RECEPTOR_1;
		(void)Serial_1_SendChar(0xFE);
		//(void)Serial_1_ClearTxBuf();
		(void)Serial_1_SendChar(DIFERENCIA);
		(void)Serial_1_SendChar(RECEPTOR_1);
		(void)Serial_1_SendChar(RECEPTOR_2);
		(void)Serial_1_SendChar(0xFF);
		
		N_MUESTRAS = 0;
		PROMEDIO_RECEPTOR_1 = 0x0000;
		PROMEDIO_RECEPTOR_2 = 0x0000;
		/*
		 * Se obtuvo para el receptor 1, 133 a 25 cm.
		 * Con todo apagado, cercano a los 57.
		 * Como máximo, se obtuvo 143.
		 */
		
		/*
				 * Se obtuvo para el receptor 2, 133 a 25 cm.
				 * Con todo apagado, cercano a los 57.
				 * Como máximo, se obtuvo 143.
				 */
		
		//Si el tanque esta lejos de algún emisor, busca
		/*
		if(RECEPTOR_1 < 80 && RECEPTOR_2 < 80)
		{
			Movimiento2Motores(VEL_MAX_1,VEL_MAX_2,'a');
		}
		
		else //Si esta cerca del emisor
		{
			//if(RECEPTOR_1 < 130 && RECEPTOR_2 < 130)
			//{
				Movimiento2Motores(RECEPTOR_1+50,RECEPTOR_2+50,'a');
			//}
			//else Movimiento2Motores(0x00,0x00,'a');
		}
		if(RECEPTOR_1 > 120 && RECEPTOR_2 > 120) Movimiento2Motores(0x00,0x00,'a');
		//Movimiento2Motores(0xFF,0x00,'a');
	
	//(void)Serial_1_SendBlock(&RECEPTOR_2,1,&enviado);
	//(void)Serial_1_SendBlock(&ConstanteEnvio,1,&enviado);
	
	//(void)Serial_1_SendBlock(&0xFE,1,&enviado);

	//ConstanteEnvio = 0xFE;
	//MovimientoLineal(RECEPTOR_1,'a');
	//MovimientoDual(RECEPTOR_1,RECEPTOR_2,FALSE);
	  //Movimiento2Motores(RECEPTOR_1,RECEPTOR_2,'a');
	  //M_1_SetRatio8(RECEPTOR_1);
	  //M_2_SetRatio8(RECEPTOR_2);
	    
	   
	   */
  }
 }
  
  
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
