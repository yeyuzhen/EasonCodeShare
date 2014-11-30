#include <string>
#include <iostream>

using namespace std;

int main()
{
    []{cout << "Hello from Lambda" << endl;}();
    
    string result = [](const string& str) -> string {return "Hello from " + str;}("second Lambda");
    cout << "Result: " << result << endl;

    result = [](const string& str){return "Hello from " + str;}("second Lambda");
    cout << "Result: " << result << endl;

    return 0;
}
