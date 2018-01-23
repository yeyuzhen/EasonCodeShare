#file: cython_person_info.pyx
from libc.stdlib cimport malloc, free
cdef extern from "person_info.h":
    struct person_info_t:
        int age
        char *gender
    ctypedef person_info_t person_info

    void print_person_info(char *name, person_info *info)

def cyprint_person_info(name, person_info_wrap info):
    print_person_info(name, info.ptr)


cdef class person_info_wrap(object):
    cdef person_info *ptr
    
    def __init__(self):
        self.ptr = <person_info *>malloc(sizeof(person_info))
    
    def __del__(self):
        free(self.ptr)
    
    @property
    def age(self):
        return self.ptr.age
    @age.setter
    def age(self, value):
        self.ptr.age = value
    
    @property
    def gender(self):
        return self.ptr.gender
    @gender.setter
    def gender(self, value):
        self.ptr.gender = value
