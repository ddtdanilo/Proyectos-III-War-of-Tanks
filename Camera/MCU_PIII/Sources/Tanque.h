/*
 * Tanque.h
 *
 *  Created on: Oct 3, 2014
 *      Author: Danilo
 */

#ifndef TANQUE_H_
#define TANQUE_H_



extern float fN;
extern float fRADIO;
extern float fTIEMPO_1;
extern float fTIEMPO_2;
extern float PI;
extern float fPERIMETRO;
extern float fVEL_1;
extern float fVEL_2;
extern Serial_1_TComData dataOut1[5];
extern Serial_1_TComData dataOut2[3];
extern byte COMANDO_ENTRANTE;
extern byte DUTY_CYCLE;
extern byte RECEPTOR_1;
extern byte RECEPTOR_2;
extern byte VEL_MAX_1;
extern byte VEL_MAX_2;
extern byte DIFERENCIA;
extern bool EXPLORACION;
extern byte error_capture;
extern unsigned int tiempo; //Tiempo de ultrasonido
extern int distancia;
extern bool objeto_cerca;
extern bool movimiento;



typedef union{
			byte Val_Byte[2];
			word Val_Word;
		}DATA;
		
typedef union{
				byte Val_Byte[2];
				float Val_Float;
				}fDATA;

//Convierte al formato del protocolo de comunicaciones.
//word Dato: Dato a convertir.
//byte *data_salida Apuntador a un arreglo de bytes de tamaño TAMANO
void Convertir_Dato_Serial(word Dato,byte data_salida[]);

		//Devuelve el byte de informacion, *Dato es la variable que va a contener la informacion y data_entrada es el arreglo
		//recibido por serial.
		byte Convertir_Serial_Dato(word *Dato, byte data_entrada[]);

//Devuelve el tamano del paquete
byte SizeData(void);


//velocidad -> PWM don duty cycle 
//direccion: 'r' -> retroceso, 'a'-> avanza, 's'-> stop
void MovimientoLineal(byte velocidad,char direccion);

//velocidad -> PWM don duty cycle 
//direccion: 'r' -> retroceso, 'a'-> avanza, 's'-> stop
void MovimientoLineal(byte velocidad,char direccion);

void MovimientoProporcional(byte velocidad,char direccion);

//Permite manejar la velocidad de los motores de manera individual
void MovimientoDual(byte velocidad1,byte velocidad2,bool STOP);
void Movimiento2Motores(byte velocidad1,byte velocida2,char direccion);
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
long map(long x, long in_min, long in_max, long out_min, long out_max);

float MapF(float x, float in_min, float in_max, float out_min, float out_max);

void Giro(byte velocidad1,byte velocidad2,char direccion);

#endif /* TANQUE_H_ */
