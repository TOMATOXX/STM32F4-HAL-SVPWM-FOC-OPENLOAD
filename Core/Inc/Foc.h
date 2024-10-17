//############################################################
// FILE:  Foc.h
//############################################################
#ifndef __FOC_H__
#define __FOC_H__

#ifdef __cplusplus
extern "C"{
#endif
#include <math.h>
#define PI 3.1415926535
//限幅函数
float my_limit(float *limit,float limit_max,float limit_min);
//归一化函数
float normalizeAngle(float angle);
	//Park逆变换
void back_park(float Uq, float Ud,float eAngle);
void motor_init(void);
#ifdef __cplusplus
}
#endif
#endif /*__FOC_H__*/




