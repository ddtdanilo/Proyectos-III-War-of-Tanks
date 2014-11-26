/* ###################################################################
**     Filename    : Events.h
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
** @file Events.h
** @version 01.02
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
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


void M_1_OnEnd(void);
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

void In_OnInterrupt(void);
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

void Serial_2_OnRxChar(void);
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

void Serial_1_OnError(void);
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

void Serial_1_OnRxChar(void);
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

void Serial_1_OnTxChar(void);
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

void In_IRQ(void);
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

void Enconder_Int_2_OnInterrupt(void);
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

void Enconder_Int_1_OnInterrupt(void);
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

void ADC_OnEnd(void);
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

void Serial_2_OnFullRxBuf(void);
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

void LED_OUT_1K(void);
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

void Serial_1_OnFreeTxBuf(void);
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

void Cap1_OnCapture(void);
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

/* END Events */
#endif /* __Events_H*/

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
