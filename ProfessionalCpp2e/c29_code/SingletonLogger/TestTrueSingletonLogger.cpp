#include "Logger.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
	Logger::instance().log("test message", Logger::kLogLevelDebug);
	vector<string> items = {"item1", "item2"};
	Logger::instance().log(items, Logger::kLogLevelError);

	return 0;
}
