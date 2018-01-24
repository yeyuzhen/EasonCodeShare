/*file: person_info.h */
typedef struct person_info_t
{
    int age;
    char gender[16];
}person_info;

void print_person_info(char *name, person_info *info);
