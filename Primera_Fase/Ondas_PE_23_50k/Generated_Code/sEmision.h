/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : sEmision.h
**     Project     : Ondas_PE_23_50k
**     Processor   : MC9S08QE128CLK
**     Component   : KBI
**     Version     : Component 01.096, Driver 01.25, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-09-17, 22:00, # CodeGen: 1
**     Abstract    :
**         This component "KBI" implements the Freescale Keyboard 
**         Interrupt Module (KBI/KBD) which allows to catch events 
**         on selected external pins. These pins share one KBI/KBD 
**         interrupt which can be caused by events on the pins.
**     Settings    :
**         Keyboard                    : KBI1 
**         Used pins           
**         Pin 0                       : PTA2_KBI1P2_SDA1_ADP2
**         Pull resistor               : off
**         Generate interrupt on       : falling
**         Interrupt service           : Enabled
**         Interrupt                   : Vkeyboard
**         Interrupt Priority          : 
**         Enable in init. code        : Yes
**         Events enabled in init.     : Yes
**     Contents    :
**         Enable       - void sEmision_Enable(void);
**         Disable      - void sEmision_Disable(void);
**         EnableEvent  - void sEmision_EnableEvent(void);
**         DisableEvent - void sEmision_DisableEvent(void);
**         GetVal       - byte sEmision_GetVal(void);
**         SetEdge      - byte sEmision_SetEdge(byte edge);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file sEmision.h
** @version 01.25
** @brief
**         This component "KBI" implements the Freescale Keyboard 
**         Interrupt Module (KBI/KBD) which allows to catch events 
**         on selected external pins. These pins share one KBI/KBD 
**         interrupt which can be caused by events on the pins.
*/         
/*!
**  @addtogroup sEmision_module sEmision module documentation
**  @{
*/         

#ifndef __sEmision
#define __sEmision

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* MODULE sEmision. */

#include "Cpu.h"

/* PUBLISHED CONSTANTS for using together with GetVal method  */
#define sEmision_NUM_PIN0     0x01U /* Mask of Pin0 */

/* PUBLISHED CONSTANTS for enabled pins */
#define sEmision_PIN_SIGNAL0  0x04U  /* Mask of Pin0*/

/* Deprecated */
#define PinSignal0            0x01U

extern volatile bool sEmision_EnEvent; /* Enable/Disable events */

void sEmision_Init(void);
/*
** ===================================================================
**     Method      :  sEmision_Init (component KBI)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* KBI1PE: KBIPE2=1 */
#define sEmision_Enable() \
  (((KBI1PE |= 0x04U), (KBI1SC_KBACK = 1U)), (KBI1SC_KBIE = 1U))

/*
** ===================================================================
**     Method      :  sEmision_Enable (component KBI)
**     Description :
**         Enables the component - the external events are accepted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* KBI1PE: KBIPE2=0 */
#define sEmision_Disable() \
  ((KBI1PE &= (byte)(~(byte)0x04U)), (KBI1SC_KBIE = 0U))

/*
** ===================================================================
**     Method      :  sEmision_Disable (component KBI)
**     Description :
**         Disables the component - the external events are not accepted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

__interrupt void sEmision_Interrupt(void);
/*
** ===================================================================
**     Method      :  sEmision_Interrupt (component KBI)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#define sEmision_GetVal() \
  ((byte)((PTAD & 0x04U) >> 2))

/*
** ===================================================================
**     Method      :  sEmision_GetVal (component KBI)
**     Description :
**         Returns the value of pins
**     Parameters  : None
**     Returns     :
**         ---             - The value of associated pins (bits ordered
**                           according to the component list of pins)
** ===================================================================
*/

#define sEmision_EnableEvent() \
  (sEmision_EnEvent = TRUE)
/*
** ===================================================================
**     Method      :  sEmision_EnableEvent (component KBI)
**     Description :
**         Enables on interrupts event. This method is available only
**         if <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define   sEmision_DisableEvent() \
  (sEmision_EnEvent = FALSE)
/*
** ===================================================================
**     Method      :  sEmision_DisableEvent (component KBI)
**     Description :
**         Disables on interrupts event. This method is available only
**         if <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

byte sEmision_SetEdge(byte edge);
/*
** ===================================================================
**     Method      :  sEmision_SetEdge (component KBI)
**     Description :
**         Sets the sensitive edge. If all selected pins don't have the
**         same edge setting possibility, the method allows to set only
**         those edges that are common (possible to set for all
**         selected pins).
**     Parameters  :
**         NAME            - DESCRIPTION
**         edge            - Edge type:
**                           0 - falling edge
**                           1 - rising edge
**                           2 - both edges
**                           3 - low level
**                           4 - high level
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_RANGE - Value is out of range
** ===================================================================
*/


/* END sEmision. */

#endif /* ifndef __sEmision */
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