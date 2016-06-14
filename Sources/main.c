/* ###################################################################
**     Filename    : main.c
**     Project     : Bluetooth GPS
**     Processor   : MK64FN1M0VLL12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-06-12, 16:33, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Pins1.h"
#include "UTIL1.h"
#include "KSDK1.h"
#include "mySerial.h"
#include "ASerialLdd1.h"
#include "myWait.h"
#include "myLCD.h"
#include "RW1.h"
#include "BitIoLdd11.h"
#include "EN1.h"
#include "BitIoLdd1.h"
#include "RS1.h"
#include "BitIoLdd2.h"
#include "DB41.h"
#include "BitIoLdd7.h"
#include "DB51.h"
#include "BitIoLdd8.h"
#include "DB61.h"
#include "BitIoLdd9.h"
#include "DB71.h"
#include "BitIoLdd10.h"
#include "WAIT1.h"
#include "Wire.h"
#include "WAIT2.h"
#include "CI2C1.h"
#include "myInt.h"
#include "ExtIntLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"


volatile bool flag=false;
volatile bool interrupt=false;
/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	  char *latitude="*";
	  char *longitud="%";
	  char *accurancy="@";
	  char *timein="#";
	  char *timeend="#";
	  char valorx[17];
	  char valory[17];
	  char valorz[17];
	  char valorgix[17];
	  char valorgiy[17];
	  char valorgiz[17];
	  char valortemp[17];
	  int lat,longi,ac,tin,tend,i,j,x,y=0,aux,aux1,aux2,pantalla;
	  char val_Lat[50];
	  char val_Long[50];
	  char val_Ac[50];
	  char val_Time[50];
	  char basura[50] = "Prueba";
	  byte  bufferx0;
	  byte bufferx1;
	  int16_t bufferx;
	  byte  buffery0;
	  byte buffery1;
	  int16_t buffery;
	  byte  bufferz0;
	  byte bufferz1;
	  byte  buffert0;
	  byte buffert1;
	  int16_t buffert;
	  int8_t  buffergx0;
	  int8_t buffergx1;
	  int8_t buffergx;
	  int8_t  buffergy0;
	  int8_t buffergy1;
	  int16_t buffergy;
	  int8_t  buffergz0;
	  int8_t buffergz1;
	  int16_t buffergz;


	    int16_t bufferz;
	    uint8_t *data;
	    uint8_t dataSize,res;
	    uint8_t addrSize;
	    int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
	    static const uint8_t addr = memaddr1;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  printf("The program started\n");
  //char inString[128] = "";
  //char firstVal[10], secondVal[10], thirdVal[10], forthVal[10], fifthVal[10], sixthVal[10], seventhVal[10], eighthVal[10];
  myLCD_Clear();
  myLCD_WriteLineStr(1,"Iniciando");


  /* Write your code here */
  /* For example: for(;;) { } */
  for(;;)
  {
	  //mySerial_ClearRxBuf();
	  //myWait_Waitms(100);



	  //myWait_Waitms(100);
	  //printf("The string is: %s\n",inString);
	  //mySerial_RecvChar(&data);
	  //myWait_Waitms(100);
	  //test = data;
	  if(interrupt == false)
	  {
	  if(flag == true)
	  {
		  flag=false;

	  strncpy(datareceived, inString, sizeof(datareceived));

	  //printf("I have received: %c\n",test);
	  printf("I have received a vector: %s\n",datareceived);
	  lat = strcspn(datareceived,latitude);
	  longi = strcspn(datareceived,longitud);
	  ac = strcspn(datareceived,accurancy);
	  tin = strcspn(datareceived,timein);
	  tend = strcspn(datareceived,timeend);
	  //printf(" lat finish at %d\n long finish at: %d\n ac finsih at %d\n tin finish at %d y %d\n",lat,longi,ac,tin,tend);
	  myLCD_Clear();
	  myLCD_WriteLineStr(1,"LAT is: ");
	  myLCD_GotoXY(2,1);
	  printf("The value of lat is: ");
	  //myLCD_GotoXY(2,1);
	  //myLCD_Write(basura[0]);
	  //myLCD_WriteString(&basura[0]);
	  pantalla=0;
	  for(i=1;i<lat;i++)
	  {	  pantalla++;
		  val_Lat[i]=datareceived[i];
		  printf("%c",val_Lat[i]);
		  myLCD_GotoXY(2,pantalla);
		  myLCD_Write(val_Lat[i]);
		  //myLCD_GotoXY(2,i);
		  //myLCD_WriteString(val_Lat[i]);
		  //myLCD_WriteString(val_Lat[i]);
		  //myLCD_WriteLineStr(2,val_Lat[i]);
	  }
	  myWait_Waitms(2000);
	  printf("\n");
	  printf("The value of long is: ");
	  myLCD_Clear();
	  myLCD_WriteLineStr(1,"Long is: ");
	  myLCD_GotoXY(2,1);
	  aux=lat+1;
	  pantalla=0;
	  for(j=aux;j<longi;j++)
	  {
		pantalla++;
	    val_Long[j]=datareceived[j];
	    printf("%c",val_Long[j]);
	    myLCD_GotoXY(2,pantalla);
	    myLCD_Write(val_Long[j]);
	  }
	  myWait_Waitms(2000);
	  printf("\n");
	  printf("The value of Ac is: ");
	  myLCD_Clear();
	  myLCD_WriteLineStr(1,"Ac is: ");
	  myLCD_GotoXY(2,1);
	  pantalla=0;
	  for(x=longi+1;x<ac;x++)
	  {
		pantalla++;
	    val_Ac[x]=datareceived[x];
	    printf("%c",val_Ac[x]);
	    myLCD_GotoXY(2,pantalla);
	    myLCD_Write(val_Ac[x]);
	   }
	  myWait_Waitms(2000);
	  printf("\n");
	  printf("The value of Time is: ");
	  myLCD_Clear();
	  myLCD_WriteLineStr(1,"Time is: ");
	  myLCD_GotoXY(2,1);
	  pantalla=0;
	  for(y=ac+1;y<tin;y++)
	  {
		pantalla++;
	    val_Time[y]=datareceived[y];
	    printf("%c",val_Time[y]);
	    myLCD_GotoXY(2,pantalla);
	    myLCD_Write(val_Time[y]);

	   }
	  myWait_Waitms(2000);
  	  printf("\n");


	  //printf("The value of lat is: %s\n",val_Lat);
	  //mySerial_ClearRxBuf();
	  //myWait_Waitms(100);

	  //printf("lat es igual a :%s",)
	  flag=false;
	  }
	  }
	  else
	  {

		  	  	  myLCD_Clear();
		  	  	  myLCD_WriteLineStr(1,"Interrupt ");
		  	  	  myWait_Waitms(2000);
		  	  	  Wire_Init();
		  	  	  res=Wire_WriteByteAddress8(MPU_addr,addr,0x00);  // PWR_MGMT_1 register

		 	 		printf("%d \n",res);

		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_ACCEL_XOUT_H ,&bufferx0);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_ACCEL_XOUT_L , &bufferx1);
		 	 		bufferx=(int16)((int8)bufferx0<<8|(int8)bufferx1);
		 	 		printf("Accel X is: %d \n",bufferx);
		 	 		myLCD_Clear();
		 	 		myLCD_WriteLineStr(1,"Accel X is: ");
		 	 		UTIL1_Num16uToStr(&valorx, sizeof(valorx), bufferx);
		 	 		//itoa(bufferx,valorx,10);
		 	 		myLCD_WriteLineStr(2,valorx);
		 	 		//printf("%s\n",valorx);
		 	 		myWait_Waitms(2000);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_ACCEL_YOUT_H ,&buffery0);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_ACCEL_YOUT_L , &buffery1);
		 	 		buffery=(int8)buffery0<<8|(int8)buffery1;
		 	 		printf("Accel Y is: %d \n",buffery);
		 	 		myLCD_Clear();
		 	 		myLCD_WriteLineStr(1,"Accel Y is: ");
		 	 		UTIL1_Num16uToStr(&valory, sizeof(valory), buffery);
		 	 		myLCD_WriteLineStr(2,valory);
		 	 		//printf("%s\n",valory);
		 	 		myWait_Waitms(2000);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_ACCEL_ZOUT_H ,&bufferz0);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_ACCEL_ZOUT_L , &bufferz1);
		 	 		bufferz=(int8)bufferz0<<8|(int8)bufferz1;
		 	 		printf("Accel Z is: %d \n",bufferz);
		 	 		myLCD_Clear();
		 	 		myLCD_WriteLineStr(1,"Accel Z is: ");
		 	 		UTIL1_Num16uToStr(&valorz, sizeof(valorz), bufferz);
		 	 		myLCD_WriteLineStr(2,valorz);
		 	 		//printf("%s\n",valorz);
		 	 		myWait_Waitms(2000);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_TEMP_OUT_H ,&buffert0);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_TEMP_OUT_L ,&buffert1);
		 	 		buffert=(int8)buffert0<<8|(int8)buffert1;
		 	 		printf("Temp is: %d \n",buffert/340+37);
		 	 		myLCD_Clear();
		 	 		myLCD_WriteLineStr(1,"Temp is: ");
		 	 		UTIL1_Num16uToStr(&valortemp, sizeof(valortemp), buffert);
		 	 		myLCD_WriteLineStr(2,valortemp);
		 	 		///printf("%s\n",valortemp);
		 	 		myWait_Waitms(2000);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_GYRO_XOUT_H ,&buffergx0);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_GYRO_XOUT_L ,&buffergx1);
		 	 		buffergx=(int8)buffergx0<<8|(int8)buffergx1;
		 	 		printf("Gyros X: %d \n",buffergx);
		 	 		myLCD_Clear();
		 	 		myLCD_WriteLineStr(1,"Gyros X is: ");
		 	 		UTIL1_Num16uToStr(&valorgix, sizeof(valorgix), buffergx);
		 	 		myLCD_WriteLineStr(2,valorgix);
		 	 		//printf("%d\n",valorgix);
		 	 		myWait_Waitms(2000);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_GYRO_YOUT_H ,&buffergy0);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_GYRO_YOUT_L ,&buffergy1);
		 	 		buffergy=(int8)buffergy0<<8|(int8)buffergy1;
		 	 		printf("Gyros Y: %d \n",buffergy);
		 	 		myLCD_Clear();
		 	 		myLCD_WriteLineStr(1,"Gyros Y is: ");
		 	 		UTIL1_Num16uToStr(&valorgiy, sizeof(valorgiy), buffergy);
		 	 		myLCD_WriteLineStr(2,valorgiy);
		 	 		//printf("%s\n",valorgiy);
		 	 		myWait_Waitms(2000);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_GYRO_ZOUT_H ,&buffergz0);
		 	 		Wire_ReadByteAddress8(MPU_addr, (byte)MPU6050_GYRO_ZOUT_L ,&buffergz1);
		 	 		buffergz=(int8)buffergz0<<8|(int8)buffergz1;
		 	 		printf("Gyros Z: %d \n",buffergz);
		 	 		myLCD_Clear();
		 	 		myLCD_WriteLineStr(1,"Gyros Z is: ");
		 	 		UTIL1_Num16uToStr(&valorgiz, sizeof(valorgiz), buffergz);
		 	 		myLCD_WriteLineStr(2,valorgiz);
		 	 		//printf("%s\n",valorgiz);
		 	 		myWait_Waitms(2000);


		 	      WAIT1_Waitms(333);
		 	      interrupt = false;
		 	      flag=true;

	  }

  }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
