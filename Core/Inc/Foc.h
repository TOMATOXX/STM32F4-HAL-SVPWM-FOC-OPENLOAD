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
//�޷�����
float my_limit(float *limit,float limit_max,float limit_min);
//��һ������
float normalizeAngle(float angle);
	//Park��任
void back_park(float Uq, float Ud,float eAngle);
void motor_init(void);
#ifdef __cplusplus
}
#endif
#endif /*__FOC_H__*/




