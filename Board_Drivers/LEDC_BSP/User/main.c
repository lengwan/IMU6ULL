#include "main.h"


//函数入口
int main()
{
	clk_enable();
	Led_Gpio_Init();
	while(1)
	{
		//开灯
		LED_ON;
		delay_ms(300);
		LED_OFF;
		delay_ms(300);
	}
	
}