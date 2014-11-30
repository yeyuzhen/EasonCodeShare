// shared_ptr_return_from_function.cpp
#include <iostream>
#include <memory>

using namespace std;

class Simple 
{
    public:
        Simple() { cout << "Simple constructor called!" << endl; }
        virtual ~Simple() { cout << "Simple destructor called!" << endl; }
};

shared_ptr<Simple> func()
{
    auto ptr = make_shared<Simple>();
    return ptr;
}
int main()
{
    shared_ptr<Simple> mySmartPtr = func();
    return 0;
}
