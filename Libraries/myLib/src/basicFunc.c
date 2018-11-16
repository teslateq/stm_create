#include <stm32f4xx.h>
#include "basicFunc.h"

__IO uint32_t TimmingDelayMs;
__IO uint32_t TimmingDelayUs;

void delay_ms(__IO uint32_t nCount) {
	TimmingDelayMs = nCount*1000;
	while(TimmingDelayMs != 0);
}

void delay_us(__IO uint32_t nCount) {
	TimmingDelayUs = nCount;
	while(TimmingDelayUs != 0);
}

void SysTick_Handler(void) {
	if(TimmingDelayUs != 0)
		TimmingDelayUs--;
	if(TimmingDelayMs != 0)
		TimmingDelayMs--;
}

float transfloat(uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4){
	union u_tag {
		uint8_t b[4]; 
		float fval;
	} u;
	u.b[0]=b4;
	u.b[1]=b3;
	u.b[2]=b2;
	u.b[3]=b1;
	return u.fval;
}

void float2Byte(float numFloat, uint8_t *data) {
	union dataUnion {
			float f;  
			char fBuff[sizeof(float)];  
	}  dataUnion; 
	dataUnion.f = numFloat;
	data[0]=dataUnion.fBuff[3];
	data[1]=dataUnion.fBuff[2];
	data[2]=dataUnion.fBuff[1];
	data[3]=dataUnion.fBuff[0];
}

uint8_t toAscii(uint8_t ch){
	uint8_t ch1;
	switch(ch){
		case 0:{ch1 = '0'; break;}
		case 1:{ch1 = '1'; break;}
		case 2:{ch1 = '2'; break;}
		case 3:{ch1 = '3'; break;}
		case 4:{ch1 = '4'; break;}
		case 5:{ch1 = '5'; break;}
		case 6:{ch1 = '6'; break;}
		case 7:{ch1 = '7'; break;}
		case 8:{ch1 = '8'; break;}
		case 9:{ch1 = '9'; break;}
		default:{ch1 = 'X'; break;}
	}
	return ch1;
}
uint8_t AsciiToInt(uint8_t ch){
	uint8_t ch1;
	switch(ch){
		case '0':{ch1 = 0; break;}
		case '1':{ch1 = 1; break;}
		case '2':{ch1 = 2; break;}
		case '3':{ch1 = 3; break;}
		case '4':{ch1 = 4; break;}
		case '5':{ch1 = 5; break;}
		case '6':{ch1 = 6; break;}
		case '7':{ch1 = 7; break;}
		case '8':{ch1 = 8; break;}
		case '9':{ch1 = 9; break;}
		case 'A':{ch1 = 10; break;}
		case 'B':{ch1 = 11; break;}
		case 'C':{ch1 = 12; break;}
		case 'D':{ch1 = 13; break;}
		case 'E':{ch1 = 14; break;}
		case 'F':{ch1 = 15; break;}
		case 'a':{ch1 = 10; break;}
		case 'b':{ch1 = 11; break;}
		case 'c':{ch1 = 12; break;}
		case 'd':{ch1 = 13; break;}
		case 'e':{ch1 = 14; break;}
		case 'f':{ch1 = 15; break;}
		default:{ch1 = 88; break;}	//'X'
	}
	return ch1;
}
