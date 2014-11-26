/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Encoder_2_t.c
**     Project     : MCU_PIII
**     Processor   : MC9S08QE128CLK
**     Component   : FreeCntr16
**     Version     : Component 02.078, Driver 01.22, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-10-13, 16:44, # CodeGen: 40
**     Abstract    :
**         This device "FreeCntr16" implements 16-bit Free Running Counter
**     Settings    :
**         Timer name                  : TPM3 (16-bit)
**         Compare name                : TPM32
**         Counter shared              : Yes
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 16384 Hz
**           Resolution of timer
**             Xtal ticks              : 131070
**             microseconds            : 3999939
**             milliseconds            : 4000
**             seconds                 : 4
**             seconds (real)          : 3.999938964844
**
**         Initialization:
**              Timer                  : Enabled
**
**         Timer registers
**              Counter                : TPM3CNT   [$0061]
**              Mode                   : TPM3SC    [$0060]
**              Run                    : TPM3SC    [$0060]
**              Prescaler              : TPM3SC    [$0060]
**
**         Compare registers
**              Compare                : TPM3C2V   [$006C]
**     Contents    :
**         Enable      - byte Encoder_2_t_Enable(void);
**         Disable     - byte Encoder_2_t_Disable(void);
**         Reset       - byte Encoder_2_t_Reset(void);
**         GetTicks16  - byte Encoder_2_t_GetTicks16(word *Ticks);
**         GetTimeUS   - byte Encoder_2_t_GetTimeUS(word *Time);
**         GetTimeMS   - byte Encoder_2_t_GetTimeMS(word *Time);
**         GetTimeSec  - byte Encoder_2_t_GetTimeSec(word *Time);
**         GetTimeReal - byte Encoder_2_t_GetTimeReal(float *Time);
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
** @file Encoder_2_t.c
** @version 01.22
** @brief
**         This device "FreeCntr16" implements 16-bit Free Running Counter
*/         
/*!
**  @addtogroup Encoder_2_t_module Encoder_2_t module documentation
**  @{
*/         


/* MODULE Encoder_2_t. */

#include "PE_Error.h"
#include "Encoder_2_t.h"

#pragma MESSAGE DISABLE C4002          /* Disable warning C4002 "Result not used" */


static bool EnUser;                    /* Enable/Disable device by user */
static word TTicks;                    /* Counter of timer ticks */
static word LTicks;                    /* Working copy of variable TTicks */
static bool TOvf;                      /* Counter overflow flag */
static bool LOvf;                      /* Working copy of variable TOvf */
static word CmpVal;                    /* Value added to compare register in ISR */

/*** Internal macros and method prototypes ***/

/*
** ===================================================================
**     Method      :  SetCV (component FreeCntr16)
**
**     Description :
**         The method computes and sets compare eventually modulo value 
**         for time measuring.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define Encoder_2_t_SetCV(_Val) ( \
  TPM3C2V = (CmpVal = (word)(_Val)) )

/*
** ===================================================================
**     Method      :  LoadTicks (component FreeCntr16)
**
**     Description :
**         The method loads actual number of timer ticks and actual state 
**         of overflow flag.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void LoadTicks(void);
/*
** ===================================================================
**     Method      :  HWEnDi (component FreeCntr16)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void);

/*** End of Internal methods declarations ***/

/*
** ===================================================================
**     Method      :  LoadTicks (component FreeCntr16)
**
**     Description :
**         The method loads actual number of timer ticks and actual state 
**         of overflow flag.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void LoadTicks(void)
{
  EnterCritical();                     /* Save the PS register */
  LTicks = TTicks;                     /* Loading actual number of timer ticks */
  LOvf = TOvf;                         /* Loading actual state of "overflow flag" */
  ExitCritical();                      /* Restore the PS register */
}

/*
** ===================================================================
**     Method      :  HWEnDi (component FreeCntr16)
**
**     Description :
**         Enables or disables the peripheral(s) associated with the 
**         component. The method is called automatically as a part of the 
**         Enable and Disable methods and several internal methods.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
static void HWEnDi(void)
{
  word TmpCmpVal;                      /* Temporary variable for new compare value */

  if (EnUser) {
    TmpCmpVal = (word)(TPM3CNT + CmpVal); /* Count current value for the compare register */
    TPM3C2V = TmpCmpVal;               /* Set compare register */
    while (TPM3C2V != TmpCmpVal) {}    /* Wait for register update (because of Latching mechanism) */
    /* TPM3C2SC: CH2F=0 */
    clrReg8Bits(TPM3C2SC, 0x80U);      /* Reset request flag */ 
    /* TPM3C2SC: CH2IE=1 */
    setReg8Bits(TPM3C2SC, 0x40U);      /* Enable compare interrupt */ 
  } else {
    /* TPM3C2SC: CH2IE=0 */
    clrReg8Bits(TPM3C2SC, 0x40U);      /* Disable Compare interrupt */ 
  }
}

/*
** ===================================================================
**     Method      :  Encoder_2_t_Enable (component FreeCntr16)
*/
/*!
**     @brief
**         This method enables the component - the internal clocks are
**         counted.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
*/
/* ===================================================================*/
byte Encoder_2_t_Enable(void)
{
  if (!EnUser) {                       /* Is the device disabled by user? */
    EnUser = TRUE;                     /* If yes then set the flag "device enabled" */
    HWEnDi();                          /* Enable the device */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Encoder_2_t_Disable (component FreeCntr16)
*/
/*!
**     @brief
**         This method disables the component - the internal clocks are
**         not counted.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
*/
/* ===================================================================*/
byte Encoder_2_t_Disable(void)
{
  if (EnUser) {                        /* Is the device enabled by user? */
    EnUser = FALSE;                    /* If yes then set the flag "device disabled" */
    HWEnDi();                          /* Disable the device */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Encoder_2_t_Reset (component FreeCntr16)
*/
/*!
**     @brief
**         This method clears the counter.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
*/
/* ===================================================================*/
byte Encoder_2_t_Reset(void)
{
  EnterCritical();
  HWEnDi();                            /* Reset compare settings */
  TTicks =  0x00U;                     /* Reset counter of timer ticks */
  TOvf = FALSE;                        /* Reset counter overflow flag */
  ExitCritical();                      /* Restore the PS register */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Encoder_2_t_GetTicks16 (component FreeCntr16)
**     Description :
**         Returns the number (as a 16-bit unsigned integer) of main
**         oscillator ticks since the last reset (usually External osc.,
**         internal osc. if exits and external osc. is disabled).
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ticks           - A pointer to the returned 16-bit value
**                           in main oscillator ticks
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_OVERFLOW - Software counter overflow\
**                           ERR_MATH - Overflow during evaluation
** ===================================================================
*/
byte Encoder_2_t_GetTicks16(word *Ticks)
{
  dlong RtVal;                         /* Result of two 32-bit numbers multiplication */

  LoadTicks();                         /* Load actual state of counter */
  if (LOvf) {                          /* Testing counter overflow */
    return ERR_OVERFLOW;               /* If yes then error */
  }
  PE_Timer_LngMul((dword)LTicks, 0x0001FFFEUL, &RtVal); /* Multiply timer ticks and High speed CPU mode coefficient */
  if (PE_Timer_LngHi0(RtVal[0], RtVal[1], Ticks)) { /* Is the result greater or equal than 65536 ? */
    return ERR_MATH;                   /* If yes then error */
  } else {                             /* Is the result less than 65536 ? */
    return ERR_OK;                     /* If yes then OK */
  }
}

/*
** ===================================================================
**     Method      :  Encoder_2_t_GetTimeUS (component FreeCntr16)
**     Description :
**         Returns the time (as a 16-bit unsigned integer) in microseconds
**         since the last resetting after the last reset.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Time            - A pointer to the returned 16-bit value
**                           in microseconds
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_OVERFLOW - Software counter overflow
**                           ERR_MATH - Overflow during evaluation
** ===================================================================
*/
byte Encoder_2_t_GetTimeUS(word *Time)
{
  dlong RtVal;                         /* Result of two 32-bit numbers multiplication */

  LoadTicks();                         /* Load actual state of counter */
  if (LOvf) {                          /* Testing counter overflow */
    return ERR_OVERFLOW;               /* If yes then error */
  }
  PE_Timer_LngMul((dword)LTicks, 0x3D08C2F7UL, &RtVal); /* Multiply timer ticks and High speed CPU mode coefficient */
  if (PE_Timer_LngHi1(RtVal[0], RtVal[1], Time)) { /* Get result value into word variable */
    return ERR_MATH;                   /* Overflow, value too big */
  } else {
    return ERR_OK;                     /* OK: Value calculated */
  }
}

/*
** ===================================================================
**     Method      :  Encoder_2_t_GetTimeMS (component FreeCntr16)
**     Description :
**         Returns the time (as a 16-bit unsigned integer) in milliseconds
**         since the last resetting after the last reset.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Time            - A pointer to the returned 16-bit value
**                           in milliseconds
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_OVERFLOW - Software counter overflow
**                           ERR_MATH - Overflow during evaluation
** ===================================================================
*/
byte Encoder_2_t_GetTimeMS(word *Time)
{
  dlong RtVal;                         /* Result of two 32-bit numbers multiplication */

  LoadTicks();                         /* Load actual state of counter */
  if (LOvf) {                          /* Testing counter overflow */
    return ERR_OVERFLOW;               /* If yes then error */
  }
  PE_Timer_LngMul((dword)LTicks, 0x0F9FF060UL, &RtVal); /* Multiply timer ticks and High speed CPU mode coefficient */
  if (PE_Timer_LngHi2(RtVal[0], RtVal[1], Time)) { /* Get result value into word variable */
    return ERR_MATH;                   /* Overflow, value too big */
  } else {
    return ERR_OK;                     /* OK: Value calculated */
  }
}

/*
** ===================================================================
**     Method      :  Encoder_2_t_GetTimeSec (component FreeCntr16)
**     Description :
**         Returns the time (as a 16-bit unsigned integer) in seconds
**         since the last resetting after the last reset.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Time            - A pointer to the returned 16-bit value
**                           in seconds
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_OVERFLOW - Software counter overflow
**                           ERR_MATH - Overflow during evaluation
** ===================================================================
*/
byte Encoder_2_t_GetTimeSec(word *Time)
{
  dlong RtVal;                         /* Result of two 32-bit numbers multiplication */

  LoadTicks();                         /* Load actual state of counter */
  if (LOvf) {                          /* Testing counter overflow */
    return ERR_OVERFLOW;               /* If yes then error */
  }
  PE_Timer_LngMul((dword)LTicks, 0x03FFFC00UL, &RtVal); /* Multiply timer ticks and High speed CPU mode coefficient */
  if (PE_Timer_LngHi3(RtVal[0], RtVal[1], Time)) { /* Get result value into word variable */
    return ERR_MATH;                   /* Overflow, value too big */
  } else {
    return ERR_OK;                     /* OK: Value calculated */
  }
}

/*
** ===================================================================
**     Method      :  Encoder_2_t_GetTimeReal (component FreeCntr16)
**     Description :
**         Returns the time in seconds since the last resetting
**         as a real (floating point) number.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Time            - A pointer to the returned floating
**                           point value in seconds
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_OVERFLOW - Software counter overflow
**                           ERR_MATH - Overflow during evaluation
** ===================================================================
*/
byte Encoder_2_t_GetTimeReal(TPE_Float *Time)
{
  LoadTicks();                         /* Load actual state of counter */
  if (LOvf) {                          /* Testing counter overflow */
    return ERR_OVERFLOW;               /* If yes then error */
  }
  *Time = (TPE_Float)LTicks * 3.999938964844F; /* Multiply ticks and High speed CPU mode coefficient */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Encoder_2_t_Init (component FreeCntr16)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Encoder_2_t_Init(void)
{
  /* TPM3C2SC: CH2F=0,CH2IE=0,MS2B=0,MS2A=1,ELS2B=0,ELS2A=0,??=0,??=0 */
  setReg8(TPM3C2SC, 0x10U);            /* Set output compare mode and disable compare interrupt */ 
  EnUser = TRUE;                       /* Enable device */
  TTicks = 0U;                         /* Counter of timer ticks */
  TOvf = FALSE;                        /* Counter overflow flag */
  Encoder_2_t_SetCV(0xFFFFU);          /* Initialize appropriate value to the compare/modulo/reload register */
  HWEnDi();
}

/*
** ===================================================================
**     Method      :  Encoder_2_t_Interrupt (component FreeCntr16)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the component event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Encoder_2_t_Interrupt)
{
  /* TPM3C2SC: CH2F=0 */
  clrReg8Bits(TPM3C2SC, 0x80U);        /* Reset compare interrupt request flag */ 
  TPM3C2V += CmpVal;                   /* Count and save new value to the compare register (counter is shared)*/
  if (++TTicks == 0x00U) {             /* Increment #ticks, check overflow */
    TOvf = TRUE;                       /* If yes then set overflow flag */
  }
}



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