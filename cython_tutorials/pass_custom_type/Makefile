#filename: Makefile
all: person_info cython_person_info

person_info:
	gcc person_info.c -c
	gcc person_info.o -o person_info 

cython:
	cython cython_person_info.pyx

cython_person_info: cython
	gcc cython_person_info.c -fPIC -c
	gcc -shared -lpython2.7 -o cython_person_info.so person_info.o cython_person_info.o

clean:
	rm -rf person_info.o person_info cython_person_info.c cython_person_info.o cython_person_info.so
