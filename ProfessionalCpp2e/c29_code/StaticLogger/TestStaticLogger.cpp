#include "Logger.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
	Logger::log("test message", Logger::kLogLevelDebug);
	vector<string> items = {"item1", "item2"};
	Logger::log(items, Logger::kLogLevelError);
	Logger::teardown();
	
	return 0;
}
