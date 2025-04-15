as write.s -o write.o
python3 setup.py build
python3 setup.py install
#gcc -shared -o my_asm.so -fPIC -I/usr/include/python3.11 python.c write.o