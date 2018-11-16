#ifndef _basicFunc_H_
#define _basicFunc_H_
#include "stm32f4xx.h"

extern __IO uint32_t TimmingDelayMs;
extern __IO uint32_t TimmingDelayUs;

//Remember to config SysTick_Config(SystemCoreClock / 1000);
void delay_ms(__IO uint32_t nCount);
void delay_us(__IO uint32_t nCount);

float transfloat(uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4);
void float2Byte(float numFloat, uint8_t *data);
uint8_t toAscii(uint8_t ch);
uint8_t AsciiToInt(uint8_t ch);

#endif   
