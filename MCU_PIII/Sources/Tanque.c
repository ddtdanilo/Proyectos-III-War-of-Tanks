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
#include "Math.h"


#define TIPO 0
#define DATA1 1
#define DATA2 2
#define FLAG 3
#define SIZE_DATA 5




/*
 *       FUNCIONES
 */

/*
 * Re-maps a number from one range to another. That is, a value of fromLow would get mapped to toLow, a value of fromHigh to toHigh, values in-between to values in-between, etc.
Does not constrain values to within the range, because out-of-range values are sometimes intended and useful. The constrain() function may be used either before or after this function, if limits to the ranges are desired.
Note that the "lower bounds" of either range may be larger or smaller than the "upper bounds" so the map() function may be used to reverse a range of numbers, for example
y = map(x, 1, 50, 50, 1);
The function also handles negative numbers well, so that this example
y = map(x, 1, 50, 50, -100);
is also valid and works well.
The map() function uses integer math so will not generate fractions, when the math might indicate that it should do so. Fractional remainders are truncated, and are not rounded or averaged.
 */

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float MapF(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//Devuelve el tamano del paquete
byte SizeData(void){
	return (byte)SIZE_DATA;
}

//Convierte al formato del protocolo de comunicaciones.
//word Dato: Dato a convertir.
//byte *data_salida Apuntador a un arreglo de bytes de tamaño TAMANO
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

void MovimientoLineal(byte velocidad,char direccion)
{
	if(direccion == 'a')
	{
	M1_P_PutVal(TRUE);
    (void)M_1_SetRatio8(velocidad);
    M2_P_PutVal(TRUE);
    (void)M_2_SetRatio8(velocidad);
	}
	
	if(direccion == 'r')
	{
	M1_P_PutVal(FALSE);
	(void)M_1_SetRatio8(0xFF-velocidad);
	M2_P_PutVal(FALSE);
	(void)M_2_SetRatio8(0xFF-velocidad);
	}
	if(direccion == 's')
	{
	M1_P_PutVal(FALSE);
	(void)M_1_SetRatio8(0xFF-0x00);
	M2_P_PutVal(FALSE);
	(void)M_2_SetRatio8(0xFF-0x00);
	}
}


void Movimiento2Motores(byte velocidad1,byte velocidad2,char direccion)
{
	if(direccion == 'a')
	{
	M1_P_PutVal(TRUE);
    (void)M_1_SetRatio8(velocidad1);
    M2_P_PutVal(TRUE);
    (void)M_2_SetRatio8(velocidad2);
	}
	
	if(direccion == 'r')
	{
	M1_P_PutVal(FALSE);
	(void)M_1_SetRatio8(0xFF-velocidad1);
	M2_P_PutVal(FALSE);
	(void)M_2_SetRatio8(0xFF-velocidad2);
	}
	if(direccion == 's')
	{
	M1_P_PutVal(TRUE);
	(void)M_1_SetRatio8(0xFF-0x00);
	M2_P_PutVal(TRUE);
	(void)M_2_SetRatio8(0xFF-0x00);
	}
}

//Permite manejar la velocidad de los motores de manera individual
void MovimientoDual(byte velocidad1,byte velocidad2,bool STOP)
{

	if(STOP)
	{
	M1_P_PutVal(TRUE);
	(void)M_1_SetRatio8(0xFF-0x00);
	M2_P_PutVal(TRUE);
	(void)M_2_SetRatio8(0xFF-0x00);
	}
	else{
		
		M1_P_PutVal(FALSE);
		(void)M_1_SetRatio8(0xFF-velocidad1);
		M2_P_PutVal(FALSE);
		(void)M_2_SetRatio8(velocidad2);
	}
}




void Giro(byte velocidad1,byte velocidad2,char direccion)
{
	if(direccion == 'd')
	{
	M1_P_PutVal(TRUE);
    (void)M_1_SetRatio8(velocidad1);
    M2_P_PutVal(FALSE);
    (void)M_2_SetRatio8(0xFF-velocidad2);
	}
	
	if(direccion == 'i')
	{
	M1_P_PutVal(FALSE);
	(void)M_1_SetRatio8(0xFF-velocidad1);
	M2_P_PutVal(TRUE);
	(void)M_2_SetRatio8(velocidad2);
	}
	if(direccion == 's')
	{
	M1_P_PutVal(TRUE);
	(void)M_1_SetRatio8(0xFF-0x00);
	M2_P_PutVal(TRUE);
	(void)M_2_SetRatio8(0xFF-0x00);
	}
}
