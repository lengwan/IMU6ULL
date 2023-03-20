#伪目标 一直重新执行，不检查依赖
.PHONY: clean
objc=$(patsubst %.c,%.o,$(wildcard *.c))
objs=$(patsubst %.s,%.o,$(wildcard *.s))
ARM_GCC=arm-linux-gnueabihf-gcc
ARM_LD=arm-linux-gnueabihf-ld
ARM_COPY=arm-linux-gnueabihf-objcopy
target=led.bin
$(target):$(objs) $(objc)
	$(ARM_LD) -T imx6ul.lds  -o $(patsubst %.bin,%.elf,$(target)) 
	$(ARM_COPY) -O binary -S -g $(patsubst %.bin,%.elf,$(target)) $(target)
	arm-linux-gnueabihf-objdump -D $(patsubst %.bin,%.elf,$(target)) > $(patsubst %.bin,%.dis,$(target))


%.o:%.c
	$(ARM_GCC) -Wall -nostdlib -g -c $^ -o $@
%.o:%.s
	$(ARM_GCC) -Wall -nostdlib -g -c $^ -o $@
download:$(target)
	chmod 777 imxdownload
	./imxdownload $(target) /dev/sdb
clean:
	rm -rf *.o *.bin *.elf *.dis