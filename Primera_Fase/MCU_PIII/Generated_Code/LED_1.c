/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : LED_1.c
**     Project     : MCU_PIII
**     Processor   : MC9S08QE128CLK
**     Component   : BitIO
**     Version     : Component 02.086, Driver 03.27, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-10-03, 10:36, # CodeGen: 7
**     Abstract    :
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings    :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       34            |  PTC0_TPM3CH0
**             ----------------------------------------------------
**
**         Port name                   : PTC
**
**         Bit number (in port)        : 0
**         Bit mask of the port        : $0001
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTCD      [$0004]
**         Port control register       : PTCDD     [$0005]
**
**         Optimization for            : speed
**     Contents    :
**         GetVal - bool LED_1_GetVal(void);
**         PutVal - void LED_1_PutVal(bool Val);
**         ClrVal - void LED_1_ClrVal(void);
**         SetVal - void LED_1_SetVal(void);
**         NegVal - void LED_1_NegVal(void);
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
** @file LED_1.c
** @version 03.27
** @brief
**         This component "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This component is set to work in Output direction only.
**         Methods of this component are mostly implemented as a macros
**         (if supported by target language and compiler).
*/         
/*!
**  @addtogroup LED_1_module LED_1 module documentation
**  @{
*/         

/* MODULE LED_1. */

#include "LED_1.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  LED_1_GetVal (component BitIO)
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This component is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
/*
bool LED_1_GetVal(void)

**  This method is implemented as a macro. See LED_1.h file.  **
*/

/*
** ===================================================================
**     Method      :  LED_1_PutVal (component BitIO)
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void LED_1_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PTCD, 0x01U);          /* PTCD0=0x01U */
  } else { /* !Val */
    clrReg8Bits(PTCD, 0x01U);          /* PTCD0=0x00U */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  LED_1_ClrVal (component BitIO)
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED_1_ClrVal(void)

**  This method is implemented as a macro. See LED_1.h file.  **
*/

/*
** ===================================================================
**     Method      :  LED_1_SetVal (component BitIO)
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED_1_SetVal(void)

**  This method is implemented as a macro. See LED_1.h file.  **
*/

/*
** ===================================================================
**     Method      :  LED_1_NegVal (component BitIO)
**     Description :
**         This method negates (inverts) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LED_1_NegVal(void)

**  This method is implemented as a macro. See LED_1.h file.  **
*/


/* END LED_1. */
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
