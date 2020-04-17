TARGET=hello
KDIR=/usr/src/linux-headers-4.8.0-46-generic
PWD=$(shell pwd)
obj-m:=$(TARGET).o
default:
	make -C $(KDIR) M=$(PWD) modules