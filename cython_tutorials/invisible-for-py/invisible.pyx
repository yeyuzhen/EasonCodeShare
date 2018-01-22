#file: invisible.pyx
cdef inline cdef_function():
    print('cdef_function')

def def_function():
    print('def_function')

cdef int cdef_value

def_value = 999

cdef class cdef_class:
    def __init__(self):
        self.value = 1

class def_class:
    def __init__(self):
        self.value = 1
