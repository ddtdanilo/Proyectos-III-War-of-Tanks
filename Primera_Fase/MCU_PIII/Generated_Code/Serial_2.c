/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Serial_2.c
**     Project     : MCU_PIII
**     Processor   : MC9S08QE128CLK
**     Component   : AsynchroSerial
**     Version     : Component 02.611, Driver 01.33, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2014-10-03, 09:54, # CodeGen: 6
**     Abstract    :
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
**     Settings    :
**         Serial channel              : SCI2
**
**         Protocol
**             Init baud rate          : 3200baud
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**             Input buffer size       : 0
**             Output buffer size      : 0
**
**         Registers
**             Input buffer            : SCI2D     [$1877]
**             Output buffer           : SCI2D     [$1877]
**             Control register        : SCI2C1    [$1872]
**             Mode register           : SCI2C2    [$1873]
**             Baud setting reg.       : SCI2BD    [$1870]
**             Special register        : SCI2S1    [$1874]
**
**         Input interrupt
**             Vector name             : Vsci2rx
**             Priority                : 
**
**         Output interrupt
**             Vector name             : Vsci2tx
**             Priority                : 
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Input   |     64               |  PTC6_RxD2_ACMP2PLUS
**            Output  |     63               |  PTC7_TxD2_ACMP2MINUS
**         ----------------------------------------------------------
**
**
**
**     Contents    :
**         RecvChar        - byte Serial_2_RecvChar(Serial_2_TComData *Chr);
**         SendChar        - byte Serial_2_SendChar(Serial_2_TComData Chr);
**         GetCharsInRxBuf - word Serial_2_GetCharsInRxBuf(void);
**         GetCharsInTxBuf - word Serial_2_GetCharsInTxBuf(void);
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
** @file Serial_2.c
** @version 01.33
** @brief
**         This component "AsynchroSerial" implements an asynchronous serial
**         communication. The component supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The component requires one on-chip asynchronous serial channel.
*/         
/*!
**  @addtogroup Serial_2_module Serial_2 module documentation
**  @{
*/         


/* MODULE Serial_2. */

#pragma MESSAGE DISABLE C4002 /* WARNING C4002: Result not used is ignored */

#include "Serial_2.h"
#include "Events.h"



/* SerFlag bits */
#define OVERRUN_ERR      0x01U         /* Overrun error flag bit   */
#define COMMON_ERR       0x02U         /* Common error of RX       */
#define CHAR_IN_RX       0x04U         /* Char is in RX buffer     */
#define FULL_TX          0x08U         /* Full transmit buffer     */

static volatile byte SerFlag;          /* Flags for serial communication */
                                       /* Bit 0 - Overrun error */
                                       /* Bit 1 - Common error of RX */
                                       /* Bit 2 - Char in RX buffer */
                                       /* Bit 3 - Full TX buffer */
static Serial_2_TComData BufferRead;   /* Input char for SCI commmunication */

/*
** ===================================================================
**     Method      :  Serial_2_RecvChar (component AsynchroSerial)
**     Description :
**         If any data is received, this method returns one character,
**         otherwise it returns an error code (it does not wait for
**         data). This method is enabled only if the receiver property
**         is enabled.
**         [Note:] Because the preferred method to handle error and
**         break exception in the interrupt mode is to use events
**         <OnError> and <OnBreak> the return value ERR_RXEMPTY has
**         higher priority than other error codes. As a consequence the
**         information about an exception in interrupt mode is returned
**         only if there is a valid character ready to be read.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to a received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_BREAK - Break character is detected
**                           (only when the <Interrupt service> property
**                           is disabled and the <Break signal> property
**                           is enabled)
**                           ERR_COMMON - common error occurred (the
**                           <GetError> method can be used for error
**                           specification)
** ===================================================================
*/
byte Serial_2_RecvChar(Serial_2_TComData *Chr)
{
  byte Result = ERR_OK;                /* Prepare default error code */

  if ((SerFlag & CHAR_IN_RX) == 0U) {  /* Is any char in RX buffer? */
    return ERR_RXEMPTY;                /* If no then error */
  }
  EnterCritical();                     /* Save the PS register */
  *Chr = BufferRead;                   /* Received char */
  Result = (byte)((SerFlag & (OVERRUN_ERR|COMMON_ERR)) ? ERR_COMMON : ERR_OK);
  SerFlag &= (byte)(~(byte)(OVERRUN_ERR|COMMON_ERR|CHAR_IN_RX)); /* Clear all errors in the status variable */
  ExitCritical();                      /* Restore the PS register */
  return Result;                       /* Return error code */
}

/*
** ===================================================================
**     Method      :  Serial_2_SendChar (component AsynchroSerial)
**     Description :
**         Sends one character to the channel. If the component is
**         temporarily disabled (Disable method) SendChar method only
**         stores data into an output buffer. In case of a zero output
**         buffer size, only one character can be stored. Enabling the
**         component (Enable method) starts the transmission of the
**         stored data. This method is available only if the
**         transmitter property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/
byte Serial_2_SendChar(Serial_2_TComData Chr)
{
  if (SerFlag & FULL_TX) {             /* Is any char in TX buffer? */
    return ERR_TXFULL;                 /* If yes then error */
  }
  EnterCritical();                     /* Save the PS register */
  (void)SCI2S1;                        /* Reset interrupt request flag */
  SCI2D = (byte)Chr;                   /* Store char to the transmitter register */
  SCI2C2_TIE = 0x01U;                  /* Enable transmit interrupt */
  SerFlag |= FULL_TX;                  /* Set the flag "full TX buffer" */
  ExitCritical();                      /* Restore the PS register */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  Serial_2_GetCharsInRxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the input buffer. This
**         method is available only if the receiver property is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the input
**                           buffer.
** ===================================================================
*/
word Serial_2_GetCharsInRxBuf(void)
{
  return ((SerFlag & CHAR_IN_RX) ? (word)1U : (word)0U); /* Return number of chars in the receive buffer */
}

/*
** ===================================================================
**     Method      :  Serial_2_GetCharsInTxBuf (component AsynchroSerial)
**     Description :
**         Returns the number of characters in the output buffer. This
**         method is available only if the transmitter property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the output
**                           buffer.
** ===================================================================
*/
word Serial_2_GetCharsInTxBuf(void)
{
  return ((SerFlag & FULL_TX) ? (word)1U : (word)0U); /* Return number of chars in the transmitter buffer */
}

/*
** ===================================================================
**     Method      :  Serial_2_InterruptRx (component AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the component's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define ON_ERROR        0x01U
#define ON_FULL_RX      0x02U
#define ON_RX_CHAR      0x04U
#define ON_IDLE_CHAR    0x08U
#define ON_RX_CHAR_EXT  0x10U
ISR(Serial_2_InterruptRx)
{
  byte OnFlags = 0x00U;                /* Temporary variable for flags */
  byte StatReg = SCI2S1;               /* Temporary variable for status flags */
  Serial_2_TComData Data = SCI2D;      /* Read data from the receiver into temporary variable for data */

  if (SerFlag & CHAR_IN_RX) {          /* Is any char already present in the receive buffer? */
    SerFlag |= OVERRUN_ERR;            /* If yes then set flag OVERRUN_ERR */
    OnFlags |= ON_ERROR;               /* Set flag "OnError" */
  } else {
    BufferRead = Data;                 /* Copy data into global buffer variable */
    SerFlag |= CHAR_IN_RX;             /* Set flag "char in RX buffer" */
    OnFlags |= ON_RX_CHAR;             /* Set flag "OnRxChar" */
  }
  if (OnFlags & ON_ERROR) {            /* Is OnError flag set? */
    Serial_2_OnError();                /* If yes then invoke user event */
  }
  else {
    if (OnFlags & ON_RX_CHAR) {        /* Is OnRxChar flag set? */
      Serial_2_OnRxChar();             /* If yes then invoke user event */
    }
  }
}

/*
** ===================================================================
**     Method      :  Serial_2_InterruptTx (component AsynchroSerial)
**
**     Description :
**         The method services the transmit interrupt of the selected 
**         peripheral(s) and eventually invokes the component's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define ON_FREE_TX  0x01U
#define ON_TX_CHAR  0x02U
ISR(Serial_2_InterruptTx)
{
  byte OnFlags = 0x00U;                /* Temporary variable for flags */

  if (SerFlag & FULL_TX) {             /* Is a char already present in the transmit buffer? */
    OnFlags |= ON_TX_CHAR;             /* Set flag "OnTxChar" */
  }
  SerFlag &= (byte)(~(byte)FULL_TX);   /* Reset flag "full TX buffer" */
  SCI2C2_TIE = 0x00U;                  /* Disable transmit interrupt */
  if (OnFlags & ON_TX_CHAR) {          /* Is flag "OnTxChar" set? */
    Serial_2_OnTxChar();               /* If yes then invoke user event */
  }
}

/*
** ===================================================================
**     Method      :  Serial_2_InterruptError (component AsynchroSerial)
**
**     Description :
**         The method services the error interrupt of the selected 
**         peripheral(s) and eventually invokes the component's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Serial_2_InterruptError)
{
  byte StatReg = getReg(SCI2S1);

  (void)SCI2D;                         /* Dummy read of data register - clear error bits */
  SerFlag |= COMMON_ERR;               /* If yes then set an internal flag */
  Serial_2_OnError();                  /* Invoke user event */
}

/*
** ===================================================================
**     Method      :  Serial_2_Init (component AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and the component's 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void Serial_2_Init(void)
{
  SerFlag = 0x00U;                     /* Reset flags */
  /* SCI2C1: LOOPS=0,SCISWAI=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  setReg8(SCI2C1, 0x00U);              /* Configure the SCI */ 
  /* SCI2C3: R8=0,T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
  setReg8(SCI2C3, 0x00U);              /* Disable error interrupts */ 
  /* SCI2C2: TIE=0,TCIE=0,RIE=0,ILIE=0,TE=0,RE=0,RWU=0,SBK=0 */
  setReg8(SCI2C2, 0x00U);              /* Disable all interrupts */ 
  /* SCI2S2: LBKDIF=0,RXEDGIF=0,??=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
  setReg8(SCI2S2, 0x00U);               
  SCI2BDH = 0x01U;                     /* Set high divisor register (enable device) */
  SCI2BDL = 0xECU;                     /* Set low divisor register (enable device) */
      /* SCI2C3: ORIE=1,NEIE=1,FEIE=1,PEIE=1 */
  SCI2C3 |= 0x0FU;                     /* Enable error interrupts */
  SCI2C2 |= (SCI2C2_TE_MASK | SCI2C2_RE_MASK | SCI2C2_RIE_MASK); /*  Enable transmitter, Enable receiver, Enable receiver interrupt */
}



/* END Serial_2. */


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
