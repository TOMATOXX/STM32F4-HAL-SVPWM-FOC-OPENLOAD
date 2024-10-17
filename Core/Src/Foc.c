//############################################################
// FILE:  Foc.c
//############################################################
#include "foc.h"
#include "math.h"
#include "Svpwm.h"
#include "stm32f4xx_hal.h"
#include "tim.h"
#include "main.h"
float Ualpha;
float Ubeta;
//限幅函数
float my_limit(float *limit,float limit_max,float limit_min)
{
	if(*limit > limit_max)
	{
		*limit = limit_max;
	}
	if(*limit < limit_min)
	{
		*limit = limit_min;
	}
	return *limit;

}
	
//归一化函数,为了将角度限制在[0,2PI]
float normalizeAngle(float angle)
{
	float a;
	a=fmod(angle,2*PI);
	return a>=0?a:(a+2*PI);
	
}

//Park逆变换
void back_park(float Uq, float Ud,float eAngle)
{
	normalizeAngle(eAngle);
	
	Ualpha = Ud*cos(eAngle)-Uq*sin(eAngle);
	Ubeta  = Ud*sin(eAngle)+Uq*cos(eAngle);
	
	svpwm(Ualpha,Ubeta);
	
	__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, Tc*5600);
	__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_2, Tb*5600);
	__HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_3, Ta*5600);
	
//	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
	
}
void motor_init(void)
{
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);
	HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_2);
	HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_3);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1,0);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2,0);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3,0);
	HAL_GPIO_WritePin(SHUTDOWN_GPIO_Port, SHUTDOWN_Pin, GPIO_PIN_SET);

}


