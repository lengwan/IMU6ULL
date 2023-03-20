#include <bsp_led.h>


//LED 初始化 引脚GPIO1_I0O3
void Led_Gpio_Init()
{
	//初始化pad的复用功能
	IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03,0);
	//初始化pad的电气特性 配置为 不使用施密特触发器、22K上拉   11110000 1010 0000
	IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03,0xf0A0);
	//设置引脚模式为输出功能 1为输出
	GPIO1->GDIR|=(0x01)<<3;
	//默认初始化为关闭
	GPIO1->DR|=(0x01)<<3;
}

