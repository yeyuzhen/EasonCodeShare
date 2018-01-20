#filename: Makefile
all: hello_world cython_hello_world

hello_world:
	gcc hello_world.c -c hello_world.c
	gcc hello_world.o -o hello_world 

cython:
	cython cython_hello_world.pyx

cython_hello_world: cython
	gcc cython_hello_world.c -fPIC -c
	gcc -shared -lpython2.7 -o cython_hello_world.so hello_world.o cython_hello_world.o

clean:
	rm -rf hello_world hello_world.o cython_hello_world.so cython_hello_world.c cython_hello_world.o
