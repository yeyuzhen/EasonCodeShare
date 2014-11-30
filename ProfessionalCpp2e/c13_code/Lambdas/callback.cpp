#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

void testCallback(const vector<int>& vec, const function<bool(int)>& callback)
{
	// Using range-based for loop
    for (auto i : vec) {
        // Call callback. If it returns false, stop iteration.
        if (!callback(i))
            break;
        // Callback did not stop iteration, so print value
        cout << i << " ";
    }

	// Using normal for loop
	//for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter) {
    //    // Call callback. If it returns false, stop iteration.
    //    if (!callback(*iter))
    //        break;
    //    // Callback did not stop iteration, so print value
    //    cout << *iter << " ";
    //}

    cout << endl;
}

int main()
{
    vector<int> vec(10);
    int index = 0;
    generate(vec.begin(), vec.end(), [&index]{return ++index;});
    for_each(vec.begin(), vec.end(), [](int i){cout << i << " ";});
    cout << endl;
    testCallback(vec, [](int i){return i<6;});
    return 0;
}
