/*汇编编写源代码*/
//全局符号
//led的引脚第一组GPIO3
.global _start
_start:
	//CCCGR1的第 26、27位
	LDR r0,=0x020C406C
	LDR r1,[r0]
	//设置第26、27位为11 |(0x03<<26)
	mov r2,#0x03
	LSL r2,#26
	ORR r2,r2,r1
	STR r2,[r0]
	//配置复用
	LDR r0,=0x020E0068
	//写入0x05
	mov r1,#0x05
	STR r1,[r0]

	//配置输出
    ldr r0, =0X020E02F4	/*寄存器SW_PAD_GPIO1_IO03_BASE */
    ldr r1, =0X10B0
    str r1,[r0]

  	ldr r0, =0X0209C004	/*寄存器GPIO1_GDIR */
    ldr r1, =0X0000008		
    str r1,[r0]
	/* 5、打开LED0
	 * 设置GPIO1_IO03输出低电平
	 */
	ldr r0, =0X0209C000	/*寄存器GPIO1_DR */
	mov r1,#0x0

   	str r1,[r0]

/*
 * 描述：	loop死循环
 */
loop:
	b loop 	

	