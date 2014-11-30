// shared_ptr_malloc_int.cpp
#include <memory>

using namespace std;

int* malloc_int(int value)
{
    int* p = (int*)malloc(sizeof(int));
    *p = value;
    return p;
}

int main()
{
    shared_ptr<int> myIntSmartPtr(malloc_int(42), free);
    return 0;
}
