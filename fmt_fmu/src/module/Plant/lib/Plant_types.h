/*
 * File: Plant_types.h
 *
 * Code generated for Simulink model 'Plant'.
 *
 * Model version                  : 1.538
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Sep 27 14:51:58 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Plant_types_h_
#define RTW_HEADER_Plant_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_Control_Out_Bus_
#define DEFINED_TYPEDEF_FOR_Control_Out_Bus_

typedef struct {
  uint32_T timestamp;
  uint16_T actuator_cmd[16];
} Control_Out_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Plant_States_Bus_
#define DEFINED_TYPEDEF_FOR_Plant_States_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T phi;
  real32_T theta;
  real32_T psi;
  real32_T rot_x_B;
  real32_T rot_y_B;
  real32_T rot_z_B;
  real32_T acc_x_O;
  real32_T acc_y_O;
  real32_T acc_z_O;
  real32_T vel_x_O;
  real32_T vel_y_O;
  real32_T vel_z_O;
  real32_T x_R;
  real32_T y_R;
  real32_T h_R;
  real_T lon;
  real_T lat;
  real_T alt;
  real_T lon_ref;
  real_T lat_ref;
  real_T alt_ref;
} Plant_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Extended_States_Bus_
#define DEFINED_TYPEDEF_FOR_Extended_States_Bus_

typedef struct {
  real32_T temprature;
  real32_T prop_vel[8];
  real32_T quat[4];
  real32_T M_BO[9];
  real32_T M_OB[9];
} Extended_States_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Barometer_Bus_
#define DEFINED_TYPEDEF_FOR_Barometer_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T pressure;
  real32_T temperature;
} Barometer_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_
#define DEFINED_TYPEDEF_FOR_GPS_uBlox_Bus_

typedef struct {
  uint32_T timestamp;
  uint32_T iTOW;
  uint16_T year;
  uint8_T month;
  uint8_T day;
  uint8_T hour;
  uint8_T min;
  uint8_T sec;
  uint8_T valid;
  uint32_T tAcc;
  int32_T nano;
  uint8_T fixType;
  uint8_T flags;
  uint8_T reserved1;
  uint8_T numSV;
  int32_T lon;
  int32_T lat;
  int32_T height;
  int32_T hMSL;
  uint32_T hAcc;
  uint32_T vAcc;
  int32_T velN;
  int32_T velE;
  int32_T velD;
  int32_T gSpeed;
  int32_T headMot;
  uint32_T sAcc;
  uint32_T headAcc;
  uint16_T pDOP;
  uint16_T reserved2;
} GPS_uBlox_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_IMU_Bus_
#define DEFINED_TYPEDEF_FOR_IMU_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T gyr_x;
  real32_T gyr_y;
  real32_T gyr_z;
  real32_T acc_x;
  real32_T acc_y;
  real32_T acc_z;
} IMU_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MAG_Bus_
#define DEFINED_TYPEDEF_FOR_MAG_Bus_

typedef struct {
  uint32_T timestamp;
  real32_T mag_x;
  real32_T mag_y;
  real32_T mag_z;
} MAG_Bus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_zjTVXoT1Wcig2PfNqPD1gB_
#define DEFINED_TYPEDEF_FOR_struct_zjTVXoT1Wcig2PfNqPD1gB_

typedef struct {
  uint32_T period;
  int8_T model_info[19];
} struct_zjTVXoT1Wcig2PfNqPD1gB;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_Plant_T RT_MODEL_Plant_T;

#endif                                 /* RTW_HEADER_Plant_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
