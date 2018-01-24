#file: test_person_info.py
from cython_person_info import cyprint_person_info, person_info_wrap

if __name__ == '__main__':
    info_wrap = person_info_wrap()
    info_wrap.age = 88
    info_wrap.gender = 'mmmale'
    
    cyprint_person_info('hhhandsome', info_wrap)
