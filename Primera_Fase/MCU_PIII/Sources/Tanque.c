/*
 * Tanque.c
 *
 *  Created on: Oct 3, 2014
 *      Author: Danilo
 */

#include "Cpu.h"
#include "Events.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Tanque.h"


#define TIPO 0
#define DATA1 1
#define DATA2 2
#define FLAG 3
#define SIZE_DATA 5



//Variables
typedef union{
			byte Val_Byte[2];
			word Val_Word;
		}DATA;


/*
 *       FUNCIONES
 */


//Convierte al formato del protocolo de comunicaciones.
//word Dato: Dato a convertir.
//byte *data_salida Apuntador a un arreglo de bytes de tama�o TAMANO
void Convertir_Dato_Serial(word Dato,byte data_salida[]);

//Devuelve el byte de informacion, *Dato es la variable que va a contener la informacion y data_entrada es el arreglo
//recibido por serial.
byte Convertir_Serial_Dato(word *Dato, byte data_entrada[]);


//Convierte al formato del protocolo de comunicaciones.
//word Dato: Dato a convertir.
//byte *data_salida Apuntador a un arreglo de bytes
void Convertir_Dato_Serial(word Dato, byte data_salida[])
{
	
	
	DATA dato;
	
	dato.Val_Word = Dato;
	

	
			  if(dato.Val_Byte[0] != 0xFF)
			  {
				  data_salida[DATA1] = dato.Val_Byte[0];
				  data_salida[FLAG] = 0x00; //No hay 0xFF
				  
				  
			  }
			  else
			  {
				  data_salida[DATA1] = 0xFE;
				  data_salida[FLAG] = 0x01; //Hay 0xFF
				  
			  }
			  
			  
			  //******************
			  
			  
			  if(dato.Val_Byte[1] != 0xFF)
			  {
				  data_salida[DATA2] = dato.Val_Byte[1];
			  }
			  else
			  {
					  data_salida[DATA2] = 0xFE;
					  data_salida[FLAG] = data_salida[FLAG]+0x02; //Hay 0xFF	  
			  }
			  
			
			  
			  
}



//Devuelve el byte de informacion, *Dato es la variable que va a contener la informacion y data_entrada es el arreglo
//recibido por serial.
byte Convertir_Serial_Dato(word *Dato, byte data_entrada[])
{

	
	DATA Salida;
	Salida.Val_Byte[0] = data_entrada[DATA1];
	Salida.Val_Byte[1] = data_entrada[DATA2];
	
	*Dato = Salida.Val_Word;
	
	return data_entrada[TIPO];
	
}

