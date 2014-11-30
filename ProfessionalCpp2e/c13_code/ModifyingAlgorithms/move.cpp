#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class MyClass
{
public:
	MyClass() {}
	MyClass(const string& str) : mStr(str) {}
	// Move assignment operator
	MyClass& operator=(MyClass&& rhs) {
		if (this == &rhs)
			return *this;
		mStr = std::move(rhs.mStr);
		cout << "Move operator= (mStr=" << mStr << ")" << endl;
		return *this;
	}
	string getString() const {return mStr;}
protected:
	string mStr;
};

int main()
{
	vector<MyClass> vecSrc = {MyClass("a"), MyClass("b"), MyClass("c")};
	vector<MyClass> vecDst(vecSrc.size());
	move(vecSrc.begin(), vecSrc.end(), vecDst.begin());
	for (auto& c : vecDst) cout << c.getString() << " ";

	return 0;
}
