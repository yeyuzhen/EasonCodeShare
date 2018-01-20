#file: hello_world.pyx

cdef extern from "hello_world.h":
    void print_hello_world()

def cython_print_hello_world():
    print_hello_world()