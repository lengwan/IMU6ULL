#ifndef __BSP__LED_H
#define __BSP__LED_H
#include "imx6ull.h"
#define LED_ON {GPIO1->DR&=(~((0x01)<<3));}
#define LED_OFF {GPIO1->DR|=((0x01)<<3);}
void Led_Gpio_Init(void);






#endif