# define extra cflags needed to build this module
EXTRA_CFLAGS := -I.

# define modules to be built
obj-m := module-one.o module-two.o

# define variables needed to be used in rules
KERNDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNDIR) M=$(PWD) clean
