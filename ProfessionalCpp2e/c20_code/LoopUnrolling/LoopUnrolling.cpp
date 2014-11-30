#include <iostream>
#include <string>
#include <functional>

using namespace std;

template<int i, typename FuncType>
class Loop
{
public:
	static inline void Do(FuncType func) {
		Loop<i-1, FuncType>::Do(func);
		func(i);
	}
};

template<typename FuncType>
class Loop<-1, FuncType>
{
public:
	static inline void Do(FuncType func) { }
};


template<int i, typename FuncType>
void loopFunc(FuncType f)
{
	Loop<i, FuncType>::Do(f);
}


void DoWork(int i)
{
	cout << "DoWork(" << i << ")" << endl;
}

double DoWork2(string str, int i)
{
	cout << "DoWork2(" << str << ", " << i << ")" << endl;
	return 0.0;
}

int main()
{
	Loop<3, function<void(int)>>::Do(DoWork);
	cout << endl;

	Loop<3, decltype(DoWork)>::Do(DoWork);
	cout << endl;

	auto a = bind(DoWork2, "TestStr", placeholders::_1);
	Loop<2, decltype(a)>::Do(a);
	cout << endl;

	loopFunc<2>(bind(DoWork2, "TestStr", placeholders::_1));

	return 0;
}
