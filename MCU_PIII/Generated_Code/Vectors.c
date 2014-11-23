/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Vectors.c
**     Project     : MCU_PIII
**     Processor   : MC9S08QE128CLK
**     Version     : Component 01.003, Driver 01.40, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-11-17, 13:38, # CodeGen: 69
**     Abstract    :
**         This component "MC9S08QE128_80" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
**     Settings    :
**
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
** @file Vectors.c                                                  
** @version 01.40
** @brief
**         This component "MC9S08QE128_80" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
*/         
/*!
**  @addtogroup Vectors_module Vectors module documentation
**  @{
*/         


#include "Cpu.h"
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

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
static void (* near const _vect[])(void) @0xFFC0 = { /* Interrupt vector table */
/*lint -restore Enable MISRA rule (1.1) checking. */
         Encoder_1_t_Interrupt,        /* Int.no. 31 Vtpm3ovf (at FFC0)              Used */
         Cpu_Interrupt,                /* Int.no. 30 Vtpm3ch5 (at FFC2)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 29 Vtpm3ch4 (at FFC4)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 28 Vtpm3ch3 (at FFC6)              Unassigned */
         Encoder_2_t_Interrupt,        /* Int.no. 27 Vtpm3ch2 (at FFC8)              Used */
         Cpu_Interrupt,                /* Int.no. 26 Vtpm3ch1 (at FFCA)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 25 Vtpm3ch0 (at FFCC)              Unassigned */
         TI1_Interrupt,                /* Int.no. 24 Vrtc (at FFCE)                  Used */
         Serial_2_InterruptTx,         /* Int.no. 23 Vsci2tx (at FFD0)               Used */
         Serial_2_InterruptRx,         /* Int.no. 22 Vsci2rx (at FFD2)               Used */
         Serial_2_InterruptError,      /* Int.no. 21 Vsci2err (at FFD4)              Used */
         Cpu_Interrupt,                /* Int.no. 20 Vacmpx (at FFD6)                Unassigned */
         ADC_Interrupt,                /* Int.no. 19 Vadc (at FFD8)                  Used */
         Cpu__ivVkeyboard,             /* Int.no. 18 Vkeyboard (at FFDA)             Used */
         Cpu_Interrupt,                /* Int.no. 17 Viicx (at FFDC)                 Unassigned */
         Serial_1_InterruptTx,         /* Int.no. 16 Vsci1tx (at FFDE)               Used */
         Serial_1_InterruptRx,         /* Int.no. 15 Vsci1rx (at FFE0)               Used */
         Serial_1_InterruptError,      /* Int.no. 14 Vsci1err (at FFE2)              Used */
         Cpu_Interrupt,                /* Int.no. 13 Vspi1 (at FFE4)                 Unassigned */
         Cpu_Interrupt,                /* Int.no. 12 Vspi2 (at FFE6)                 Unassigned */
         Cpu_Interrupt,                /* Int.no. 11 Vtpm2ovf (at FFE8)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 10 Vtpm2ch2 (at FFEA)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  9 Vtpm2ch1 (at FFEC)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  8 Vtpm2ch0 (at FFEE)              Unassigned */
         M_1_Interrupt,                /* Int.no.  7 Vtpm1ovf (at FFF0)              Used */
         Cpu_Interrupt,                /* Int.no.  6 Vtpm1ch2 (at FFF2)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  5 Vtpm1ch1 (at FFF4)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  4 Vtpm1ch0 (at FFF6)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  3 Vlvd (at FFF8)                  Unassigned */
         B_1_Interrupt,                /* Int.no.  2 Virq (at FFFA)                  Used */
         Cpu_Interrupt,                /* Int.no.  1 Vswi (at FFFC)                  Unassigned */
         _EntryPoint                   /* Int.no.  0 Vreset (at FFFE)                Reset vector */
};
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
