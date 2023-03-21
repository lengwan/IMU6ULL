#标准化编译
USE_COMPILE :=arm-linux-gnueabihf-
TARGET :=BSP_LED

ARM_GCC :=$(USE_COMPILE)gcc #确定值
ARM_LD :=$(USE_COMPILE)ld #链接
ARM_COPY :=$(USE_COMPILE)objcopy #换文件格式
ARM_DUMP :=$(USE_COMPILE)objdump #反向汇编编译

#编译头文件地址 -I
INC_PATH := Bsp/CLCOK   \
			Bsp/DELAY   \
			Bsp/LED     \
			SDK_LIB/inc \
			SDK_LIB     \
			User
#资源文件路径
SRC_PATH := Bsp/CLCOK   \
			Bsp/DELAY   \
			Bsp/LED     \
			SDK_LIB/src \
			User
OUT_PATH := Output

INCLUDE :=$(patsubst %,-I %,$(INC_PATH))
#遍历所有文件夹查找所有的c文件
CFILES :=$(foreach dir,$(SRC_PATH),$(wildcard ./$(dir)/*.c))
#遍历所有文件夹查找所有的s文件
SFILES :=$(foreach dir,$(SRC_PATH),$(wildcard ./$(dir)/*.s))

#将路径去掉
SFILENDIR		:= $(notdir  $(SFILES))
CFILENDIR		:= $(notdir  $(CFILES))
#获取输出文件.o
COBJ :=$(patsubst %.c,$(OUT_PATH)/%.o,$(CFILENDIR))
SOBJ :=$(patsubst %.s,$(OUT_PATH)/%.o,$(SFILENDIR))
OBJS :=$(COBJ) $(SOBJ)

#依赖文件搜索路径
VPATH :=$(SRC_PATH)
.PHONY: clean

$(TARGET).bin:$(OBJS)#需要.o
	$(ARM_LD) -T imx6ul.lds  -o $(OUT_PATH)/$(TARGET).elf $^
	$(ARM_COPY) -O binary -S -g $(OUT_PATH)/$(TARGET).elf $(OUT_PATH)/$@
	$(ARM_DUMP) -D -m arm  $(OUT_PATH)/$(TARGET).elf >  $(OUT_PATH)/$(TARGET).dis




$(COBJ):$(OUT_PATH)/%.o:%.c
	$(ARM_GCC) -Wall -nostdlib  -c -O2 $(INCLUDE) $^ -o $@ 
$(SOBJ):$(OUT_PATH)/%.o:%.s
	$(ARM_GCC) -Wall -nostdlib  -c -O2 $(INCLUDE) $^ -o $@


download:$(TARGET).bin
	chmod 777 imxdownload
	./imxdownload $(OUT_PATH)/$(TARGET).bin /dev/sdb
clean:
	rm -rf $(OUT_PATH)/*.o $(OUT_PATH)/*.bin $(OUT_PATH)/*.elf $(OUT_PATH)/*.dis