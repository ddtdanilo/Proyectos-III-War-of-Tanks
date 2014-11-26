/* ###################################################################
**     Filename    : Events.c
**     Project     : MCU_PIII
**     Processor   : MC9S08QE128CLK
**     Component   : Events
**     Version     : Driver 01.02
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-09-30, 07:20, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.02
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */


#include "Cpu.h"
#include "Events.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "PE_Types.h"
#include "PE_Error.h"
#include "Tanque.h"

#define SIZE_DATA_S1 5
#define SIZE_DATA_S2 3
//Indica el comienzo del pulso (M1)
bool PULSO1_START = TRUE;

//Indica el comienzo del pulso (M2)
bool PULSO2_START = TRUE;


float fN = 20;
float fRADIO = 3;
float fTIEMPO_1 = 0;
float fTIEMPO_2 = 0;
word wTIEMPO_2 = 0;
float PI = 3.1415;
float fPERIMETRO;
float fVEL_1;
float fVEL_2;
byte N = 35; //Numero de rendijas
byte N_Interrupcion = 0x00;
byte DIFERENCIA = 0x00;
byte error_capture;
DATA tiempo_d;
bool tiempo_ok = TRUE;

//extern unsigned int tiempo; //Tiempo de ultrasonido
//extern unsigned int distancia;

//fData = envio;
DATA envio;

bool test = TRUE;
byte giro = 0x00;


//SERIAL
byte enviado;
Serial_1_TComData dataOut1[SIZE_DATA_S1];
Serial_2_TComData dataOut2[SIZE_DATA_S2];
Serial_2_TComData a = 0x00;
byte COMANDO_ENTRANTE;

//byte DUTY_CYCLE = 0x00;

/*
** ===================================================================
**     Event       :  M_1_OnEnd (module Events)
**
**     Component   :  M_1 [PWM]
**     Description :
**         This event is called when the specified number of cycles has
**         been generated. (Only when the component is enabled -
**         <Enable> and the events are enabled - <EnableEvent>). The
**         event is available only when the <Interrupt service/event>
**         property is enabled and selected peripheral supports
**         appropriate interrupt.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void M_1_OnEnd(void)
{
  /* Write your code here ... */
	
	if(EXPLORACION)
	{
		if(giro == 0x00)
		{
			Giro(VEL_MAX_1,VEL_MAX_2,'i');
			giro++;
		}
		if(giro == 0x01)
		{
			Giro(VEL_MAX_1,VEL_MAX_2,'i');
			giro++;
		}
		if(giro == 0x02)
		{
			Giro(VEL_MAX_1,VEL_MAX_2,'i');
			giro = 0x00;
		}
		
	}
}


/*
** ===================================================================
**     Event       :  In_OnInterrupt (module Events)
**
**     Component   :  In [KBI]
**     Description :
**         This event is called when the active signal edge/level
**         occurs. This event is enabled only if <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void In_OnInterrupt(void)
{
  /* Write your code here ... */
	LED_1_NegVal();
}

/*
** ===================================================================
**     Event       :  Serial_2_OnRxChar (module Events)
**
**     Component   :  Serial_2 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void  Serial_2_OnRxChar(void)
{
  /* Write your code here ... */
	/*
	Bit1_NegVal();
	Serial_2_RecvChar(&a);
	(void)Serial_2_ClearRxBuf();
    (void)Serial_1_SendBlock(&a,1,&enviado);
    
   */
    //(void)Serial_1_ClearTxBuf();Bit1_ClrVal();
    
}

/*
** ===================================================================
**     Event       :  Serial_1_OnError (module Events)
**
**     Component   :  Serial_1 [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void  Serial_1_OnError(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Serial_1_OnRxChar (module Events)
**
**     Component   :  Serial_1 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void  Serial_1_OnRxChar(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Serial_1_OnTxChar (module Events)
**
**     Component   :  Serial_1 [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void  Serial_1_OnTxChar(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  In_IRQ (module Events)
**
**     Component   :  B_1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void In_IRQ(void)
{
  /* place your B_1 interrupt procedure body here*/
	LED_1_NegVal();
	dataOut1[0] = 0x00;
	dataOut1[1] = 0xF0;
	DIFERENCIA = 0x00;
	if(RECEPTOR_1 > RECEPTOR_2) DIFERENCIA = RECEPTOR_1 - RECEPTOR_2;
	else DIFERENCIA = RECEPTOR_2 - RECEPTOR_1;
	
	(void)Serial_1_SendChar(0xFE);
	//(void)Serial_1_ClearTxBuf();
	(void)Serial_1_SendChar(DIFERENCIA);
	(void)Serial_1_SendChar(RECEPTOR_1);
	(void)Serial_1_SendChar(RECEPTOR_2);
	(void)Serial_1_SendChar(0xFF);
	//(void)Serial_1_ClearTxBuf();
	//(void)Serial_1_SendChar(RECEPTOR_1);
	//(void)Serial_1_SendChar(RECEPTOR_2);
	//(void)Serial_1_SendChar(0xFF);
	//(void)Serial_1_SendBlock(&ENVIO_S,4,&enviado);
	//(void)Serial_1_ClearTxBuf();
	//(void)Serial_1_SendChar(0x01);
	/*	
	if(test){
	M1_P_PutVal(TRUE);
    (void)M_1_SetRatio8(0xFF);
	}else{
		M1_P_PutVal(FALSE);
	(void)M_1_SetRatio8(0xFF);
	}
	test = !test;
	*/
	
	/*
	(void)Serial_1_SendBlock(&dataOut1,SIZE_DATA_S1,&enviado);
	
	(void)M_1_SetRatio8(DUTY_CYCLE);
    (void)M_2_SetRatio8(DUTY_CYCLE);
	if(PULSO1_START){
		  (void)Encoder_1_t_Reset();
		  PULSO1_START = FALSE;
	  }
	  else{
		  (void)Encoder_1_t_GetTimeReal(&fTIEMPO_1);
		  fVEL_1 = fPERIMETRO/fTIEMPO_1;
		  PULSO1_START = TRUE;
	  }
	DUTY_CYCLE = DUTY_CYCLE + 10;
	
	
	*/
	
	//MovimientoLineal(DUTY_CYCLE,'a');
}

/*
** ===================================================================
**     Event       :  Enconder_Int_2_OnInterrupt (module Events)
**
**     Component   :  Enconder_Int_2 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Enconder_Int_2_OnInterrupt(void)
{
		
		
		if(objeto_cerca && N_Interrupcion < N)
		{
					movimiento = FALSE;
					Giro(VEL_MAX_1,VEL_MAX_2,'d');
					N_Interrupcion++;
					//DISPARO_OUT_PutVal(TRUE);
					DISPARO_OUT_PutVal(TRUE);
		}
		else
		 {
		   if(!objeto_cerca)
		   {
			   //N_Interrupcion = 0x00;
			   movimiento = TRUE;
		   }
		   else//objeto_cerca = true && N_Int > N
		   {
			   //MovimientoLineal(0x00,'s');
			   N_Interrupcion = 0x00;
			  
		   }
		   
		 }
		//DISPARO_OUT_NegVal();
		
	
		
}

/*
** ===================================================================
**     Event       :  Enconder_Int_1_OnInterrupt (module Events)
**
**     Component   :  Enconder_Int_1 [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Enconder_Int_1_OnInterrupt(void)
{
  
 // LED_1_NegVal();
	
}

/*
** ===================================================================
**     Event       :  ADC_OnEnd (module Events)
**
**     Component   :  ADC [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void ADC_OnEnd(void)
{
  /* Write your code here ... */
	//LED_1_NegVal();
	
}


/*
** ===================================================================
**     Event       :  Serial_2_OnFullRxBuf (module Events)
**
**     Component   :  Serial_2 [AsynchroSerial]
**     Description :
**         This event is called when the input buffer is full;
**         i.e. after reception of the last character 
**         that was successfully placed into input buffer.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
//Cuando llegan 3 bytes, toma el segundo dato.
void  Serial_2_OnFullRxBuf(void)
{
	DISPARO_OUT_NegVal();
	//Obtengo la data
	(void)Serial_2_RecvBlock(&dataOut2,SIZE_DATA_S2,&enviado);
	(void)Serial_2_ClearRxBuf();
	if(dataOut2[0] == 0xFE) if(dataOut2[2] == 0xFF) COMANDO_ENTRANTE = dataOut2[1];
	
	/*
	 * Este switch debe ser modificado acorde al comando
	 * asignado a cada uno de los tanques.
	*/
	
	switch(COMANDO_ENTRANTE)
	{
		//ACKNOWLEDGE Tanque 1
		case 0x00:
			//Cambia el estado del led.
			
			break;
		//Fuera Pista Derecha Tanque 1
		case 0x01:
			DISPARO_OUT_NegVal();
			break;
		//Fuera Pista Izquierda Tanque 1
		case 0x02:
			break;
		//Fuera Pista Abajo Tanque 1			
		case 0x03:
			break;
		//Fuera Pista Arriba Tanque 1	
		case 0x04:
			break;
		//STOP Tanque 1	
		case 0x05:
			//Cambia el estado del led de disparo.
			DISPARO_OUT_NegVal();
			break;
	}
	
	
}

/*
** ===================================================================
**     Event       :  LED_OUT_1K (module Events)
**
**     Component   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LED_OUT_1K(void)
{
  /* Write your code here ... */
  (void)LED_OUT_1K_SQ_NegVal();
}

/*
** ===================================================================
**     Event       :  Serial_1_OnFreeTxBuf (module Events)
**
**     Component   :  Serial_1 [AsynchroSerial]
**     Description :
**         This event is called after the last character in output
**         buffer is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void  Serial_1_OnFreeTxBuf(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Cap1_OnCapture (module Events)
**
**     Component   :  US [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the component is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Cap1_OnCapture(void)
{
  /* Write your code here ... */
	error_capture = US_GetCaptureValue(&tiempo); //Devuelve error si lo hay
	//En tiempo se guarda cuanto tarda
	error_capture = US_Reset();
	distancia = (tiempo/58); //Para la distancia, tomando la velocidad del sonido en ambiente
	//AS1_SendChar(distancia); 
	tiempo_d.Val_Word = tiempo;
	if(tiempo < 0x0200)
	{
		(void)Serial_1_SendChar(tiempo_d.Val_Byte[0]);
		(void)Serial_1_SendChar(tiempo_d.Val_Byte[1]);
		tiempo_ok = !tiempo_ok;
		objeto_cerca = TRUE;
		
		if(tiempo <= 0x0C)// 10 cm
		{
			objeto_cerca = TRUE;
			//movimiento = FALSE;
			
		}
		else 
		{
			objeto_cerca = FALSE;
			//movimiento = TRUE;
		}
		
	}
	else tiempo_ok = !tiempo_ok; 
	
		
		
	
		
}

/* END Events */

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
