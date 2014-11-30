#include <vector>
using namespace std;

class Element
{
public:
  Element() {}
  virtual ~Element() {}
};

int main()
{
  vector<Element>* elementVector = new vector<Element>(10);
  delete elementVector;
  return 0;
}
