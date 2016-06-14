/*
 * helpincludes.h
 *
 *  Created on: Jun 12, 2016
 *      Author: andres
 */


#ifndef SOURCES_HELPINCLUDES_H_
#define SOURCES_HELPINCLUDES_H_
#define MPU_addr 0x68
#define memaddr1 0x06B
#define MPU6050_ACCEL_XOUT_H       0x3B   // R
#define MPU6050_ACCEL_XOUT_L       0x3C   // R
#define MPU6050_ACCEL_YOUT_H       0x3D   // R
#define MPU6050_ACCEL_YOUT_L       (0x3E)   // R
#define MPU6050_ACCEL_ZOUT_H       (0x3F)   // R
#define MPU6050_ACCEL_ZOUT_L       (0x40)   // R
#define MPU6050_TEMP_OUT_H         (0x41)   // R
#define MPU6050_TEMP_OUT_L         (0x42)   // R
#define MPU6050_GYRO_XOUT_H        0x43   // R
#define MPU6050_GYRO_XOUT_L        0x44   // R
#define MPU6050_GYRO_YOUT_H        0x45   // R
#define MPU6050_GYRO_YOUT_L        0x46   // R
#define MPU6050_GYRO_ZOUT_H        0x47   // R
#define MPU6050_GYRO_ZOUT_L        0x48   // R
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
  char datareceived[64];
  char test;
  mySerial_TComData inString[64],data;
  //mySerial_TComData data;
  //char *inString;

  word rx;
#endif /* SOURCES_HELPINCLUDES_H_ */
