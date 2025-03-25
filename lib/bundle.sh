as write.s -o write.o
gcc -shared -o my_asm.so -fPIC -I/usr/include/python3.11 python.c write.o