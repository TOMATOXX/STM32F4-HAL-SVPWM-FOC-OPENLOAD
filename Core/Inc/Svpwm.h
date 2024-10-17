//############################################################
// FILE:  Svpwm.h
//############################################################

#ifndef __SVPWM_H__
#define __SVPWM_H__

#ifdef __cplusplus
extern "C"{
#endif

#define _sqrt3_2        0.8660254037844f
#define _1_2			0.5f
#define Ts				1

void svpwm(float Ualpha,float Ubeta);

#ifdef __cplusplus
}
#endif
#endif /*__SVPWM_H__*/



