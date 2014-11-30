#include <new>

class MyClass
{
public:
    void* operator new(std::size_t size) = delete;
    void* operator new[](std::size_t size) = delete;
};

int main()
{
    MyClass* p1 = new MyClass;
    MyClass* pArray = new MyClass[2];

	return 0;
}
