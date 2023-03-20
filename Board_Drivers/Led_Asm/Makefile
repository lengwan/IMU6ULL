#伪目标 一直重新执行，不检查依赖
.PHONY: clean
objc=$(patsubst %.c,%.o,$(wildcard *.c))
objs=$(patsubst %.s,%.o,$(wildcard *.s))
ARM_GCC=arm-linux-gnueabihf-gcc
ARM_LD=arm-linux-gnueabihf-ld
ARM_COPY=arm-linux-gnueabihf-objcopy
target=led.bin
$(target):$(objs) $(objc)
	$(ARM_LD) -Ttext 0X87800000 $^ -o $(patsubst %.o,%.elf,$^)
	$(ARM_COPY) -O binary -S -g $(patsubst %.o,%.elf,$^) $(patsubst %.o,%.bin,$^)
	arm-linux-gnueabihf-objdump -D $(patsubst %.o,%.elf,$^) > led.dis
.o:%.c
	$(ARM_GCC) -g -c $^ -o $@
%.o:%.s
	$(ARM_GCC) -g -c $^ -o $@

download:$(target)
	chmod 777 imxdownload
	./imxdownload $(target) /dev/sdb

clean:
	rm -rf *.o *.bin *.elf *.dis

