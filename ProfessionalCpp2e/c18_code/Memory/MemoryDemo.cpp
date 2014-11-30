#include "MemoryDemo.h"
#include <iostream>
using namespace std;

void* MemoryDemo::operator new(size_t size)
{
	cout << "operator new" << endl;
	return ::operator new(size);
}
/*
void MemoryDemo::operator delete(void* ptr, size_t size) noexcept
{
	cout << "operator delete with size" << endl;
	::operator delete(ptr);
}
*/

void MemoryDemo::operator delete(void* ptr) noexcept
{
	cout << "operator delete" << endl;
	::operator delete(ptr);
}


void* MemoryDemo::operator new[](size_t size)
{
	cout << "operator new[]" << endl;
	return ::operator new[](size);
}

void MemoryDemo::operator delete[](void* ptr) noexcept
{
	cout << "operator delete[]" << endl;
	::operator delete[](ptr);
}

void* MemoryDemo::operator new(size_t size, const nothrow_t&) noexcept
{
	cout << "operator new nothrow" << endl;
	return ::operator new(size, nothrow);
}

void MemoryDemo::operator delete(void* ptr, const nothrow_t&) noexcept
{
	cout << "operator delete nothrow" << endl;
	::operator delete[](ptr, nothrow);
}

void* MemoryDemo::operator new[](size_t size, const nothrow_t&) noexcept
{
	cout << "operator new[] nothrow" << endl;
	return ::operator new[](size, nothrow);
}

void MemoryDemo::operator delete[](void* ptr, const nothrow_t&) noexcept
{
	cout << "operator delete[] nothrow" << endl;
	::operator delete[](ptr, nothrow);
}

void* MemoryDemo::operator new(size_t size, int extra)
{
	cout << "operator new with extra int arg" << endl;
	return ::operator new(size);
}

void MemoryDemo::operator delete(void* ptr, int extra) noexcept
{
	cout << "operator delete with extra int arg" << endl;
	return ::operator delete(ptr);
}
