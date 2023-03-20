#include "bsp_delay.h"

void delay_us(int i)
{
	int j,k=0;
	for(j=0;j<i;j++)
	{
		for(k=0;k<200;k++)
		{

		}
	}
}

void delay_ms(int i)
{
	int j=0;
	for(j=0;j<i;j++)
		delay_us(1000);
}