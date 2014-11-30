// Typedefs.cpp

#include <vector>
#include <string>

using namespace std;

//void processVector(const std::vector<std::string>& vec)
//{
//    // Body omitted
//}

typedef std::vector<std::string> StringVector;

void processVector(const StringVector & vec)
{
    // Body omitted
}

int main()
{
    //std::vector<std::string> myVector;
    StringVector myVector;
    // Rest of the program ...
    return 0;
}
