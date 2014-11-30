// PrintTupleSimplified.cpp
#include <iostream>
#include <string>
#include <tuple> 

using namespace std;

template<int n, typename TupleType>
class tuple_print_helper
{
	public:
		tuple_print_helper(TupleType t) {
			tuple_print_helper<n-1, TupleType> tp(t);
			cout << get<n-1>(t) << endl;
		}
};
template<typename TupleType>
class tuple_print_helper<0, TupleType>
{
	public:
		tuple_print_helper(TupleType t) {}
};

template<typename T>
void tuple_print(T t)
{
	tuple_print_helper<tuple_size<T>::value, T> tph(t);
}

int main()
{
	auto t1 = make_tuple(167, "Testing", false, 2.3);
	tuple_print(t1);

	return 0;
}
