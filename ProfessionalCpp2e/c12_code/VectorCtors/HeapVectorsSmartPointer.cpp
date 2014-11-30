#include <vector>
#include <memory>
using namespace std;

class Element
{
public:
  Element() {}
  virtual ~Element() {}
};

int main()
{
  shared_ptr<vector<Element>> elementVector(new vector<Element>(10));

  return 0;
}
