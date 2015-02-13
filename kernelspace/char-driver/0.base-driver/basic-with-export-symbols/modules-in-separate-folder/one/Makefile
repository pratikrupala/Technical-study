EXTRA_CFLAGS += -I$(PWD)/../inc
KBUILD_EXTRA_SYMBOLS := $(PWD)/../two/Module.symvers
ifneq ($(KERNELRELEASE),)
	obj-m += src/module-one.o
else
	KERNDIR := /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNDIR) M=$(PWD) clean
endif
