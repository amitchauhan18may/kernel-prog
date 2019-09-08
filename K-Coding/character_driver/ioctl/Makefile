obj-m += mymodule.o
mymodule-objs := chardev.o procfs.o
all:
	make -C /lib/modules/${shell uname -r}/build M=${PWD}
module_install:
#	make -C /lib/modules/${shell uname -r}/build M=./my_module modules_install
clean:
	make -C /lib/modules/${shell uname -r}/build M=${PWD} clean
