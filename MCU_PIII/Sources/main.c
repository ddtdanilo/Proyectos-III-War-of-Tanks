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
#include "ULTRA.h"
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
byte VEL_MAX_1 = 150;
byte VEL_MAX_2 = 105;
bool objeto_cerca = FALSE;
bool movimiento = TRUE;


void main(void)
{
  /* Write your local variable definition here */
	
	byte enviado;
	float PWM_DUTY;
	byte ConstanteEnvio = 0xFE;
	int PROMEDIO_RECEPTOR_1 = 0x00;
	int PROMEDIO_RECEPTOR_2 = 0x00;
	byte N_MUESTRAS = 0x00;
	bool EXPLORACION = FALSE;
	Serial_1_TComData ENVIO_S[] = {0x00,0x00,0x00,0x00};
	
	
	//Ultrasonido
	
		unsigned int tiempo; //Tiempo de ultrasonido
		int distancia;
	
	
	/* Rangos:*/
			 
		
			 bool direccion; //RECEPTOR_1 > RECEPTOR_2 -> FALSE
			 byte CERCANIA_1_MIN = 5;
			 byte CERCANIA_2_MIN = 5;
			 byte CERCANIA_1_MAX = 120;
			 byte CERCANIA_2_MAX = 120;

			 //R1
			 byte DIFERENCIA_MIN = 10; 
			 byte DIFERENCIA_MAX = ((CERCANIA_1_MAX + CERCANIA_2_MAX)/2) - ((CERCANIA_1_MIN + CERCANIA_2_MIN)/2); 
			
		
			 //R2
			 byte R2_MIN = 10;
			 byte R2_MAX = 60;

			 //R3
			 byte R3_MIN = 60;
			 byte R3_MAX = 80;

			 //R4
			 byte R4_MIN = 80;
			 byte R4_MAX = CERCANIA_2_MAX - 1;

			 //R5
			 byte R5_MIN = 10;
			 byte R5_MAX = 60;

			 //R6
			 byte R6_MIN = 60;
			 byte R6_MAX = 80;

			 //R7
			 byte R7_MIN = 80;
			 byte R7_MAX = CERCANIA_1_MAX - 1;
			 
			 
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  //VEL_MAX_1 = 200;
  //VEL_MAX_2 = 200;
  fPERIMETRO = (2*PI*fRADIO)/fN;
  DUTY_CYCLE = 0x00;
  ACKNOWLEDGE_LED_PutVal(TRUE);
  DISPARO_OUT_PutVal(TRUE);
    (void)M_1_Enable();
  	(void)M_1_SetRatio8(0xFF);
  	(void)M_2_Enable();
  	(void)M_2_SetRatio8(0xFF);
  	(void)ADC_Measure(TRUE);
  	
  	//ULTRA_Enable();
  	//ULTRA_SetRatio8(127);
  	
  	
  	
  	/*
  	 * 
  	 * 
  	 */
  	//LED_OUT_ClrValue();
  	
  	/*
  	 * 
  	 * 
  	 * 
  	 */
  for(;;)
  {
	 
	(void)ADC_Measure(TRUE);
	(void)ADC_GetChanValue8(0,&DUTY_CYCLE);
	(void)ADC_GetChanValue8(1,&RECEPTOR_1);
	(void)ADC_GetChanValue8(2,&RECEPTOR_2);
	//ULTRA_SetRatio8(128);
	/*
	 * ultrasonido
	 */
	
	
	
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
		
		
		
		
		
		//Envio por serial para verificacion
		
		/*
		(void)Serial_1_SendChar(0xFE);
		(void)Serial_1_SendChar(DIFERENCIA);
		(void)Serial_1_SendChar(RECEPTOR_1);
		(void)Serial_1_SendChar(RECEPTOR_2);
		(void)Serial_1_SendChar(0xFF);
		*/
		
		
		//
		//VEL_MAX_1 = DUTY_CYCLE;
		
		N_MUESTRAS = 0;
		PROMEDIO_RECEPTOR_1 = 0x0000;
		PROMEDIO_RECEPTOR_2 = 0x0000;
		//VEL_MAX_2 = VEL_MAX_1*(70/100);
		
		
		
		
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
		
		/*
		 * 
		 * Logica de juego !!!!!!!!!!!!!!
		 * 
		 */
		
		

		/*
		 * 
		 * Logica de juego !!!!!!!!!!!!!!
		 *  RECEPTOR_1 -> A
		 *  RECEPTOR_2 -> B
		 * A mayor recepcion, mayor cercania del emisor
		 */
		 
if(movimiento)
{

		//Se empieza por verificar la cercania del emisor al receptor 
		if(RECEPTOR_1 >= CERCANIA_1_MAX || RECEPTOR_2 >= CERCANIA_2_MAX)
		{
			DISPARO_OUT_PutVal(TRUE);
			MovimientoLineal(0x00,'s');
			movimiento = FALSE;
		}
		else
		{
			DISPARO_OUT_PutVal(FALSE);
			Bit1_PutVal(FALSE);

			if(RECEPTOR_1 > RECEPTOR_2)
			{
				DIFERENCIA = RECEPTOR_1 - RECEPTOR_2;
				direccion = FALSE;
			} 		
			else
			{
				DIFERENCIA = RECEPTOR_2 - RECEPTOR_1;
				direccion = TRUE;
			}
			

			if(DIFERENCIA >= DIFERENCIA_MIN && DIFERENCIA < DIFERENCIA_MAX)
			{
				EXPLORACION = FALSE;
				if(direccion) //RECEPTOR_2 > RECEPTOR_1
				{
					Giro(VEL_MAX_1,VEL_MAX_2,'d');
				}
				else //RECEPTOR_1 > RECEPTOR_2
				{
					Giro(VEL_MAX_1,VEL_MAX_2,'i');
					
				} 
			}
			else// Exploracion
			{
				//EXPLORACION = TRUE;
				//Bit_PutVal(TRUE);
				Bit1_PutVal(TRUE);
				Movimiento2Motores(VEL_MAX_1,VEL_MAX_2,'a');
				//else EXPLORACION = TRUE;
			}
		}
		//MovimientoLineal(0x00,'s');
		//Movimiento2Motores(VEL_MAX_1,VEL_MAX_2,'a');
		
  }else//movimiento = false
  {
	 //if(objeto_cerca) MovimientoLineal(0x00,'s');
  }
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
