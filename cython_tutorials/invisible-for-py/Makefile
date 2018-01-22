#filename: Makefile
all: cython_invisible

cython:
	cython invisible.pyx

cython_invisible: cython
	gcc invisible.c -fPIC -c
	gcc -shared -lpython2.7 -o invisible.so invisible.o

clean:
	rm -rf invisible.o invisible.c
