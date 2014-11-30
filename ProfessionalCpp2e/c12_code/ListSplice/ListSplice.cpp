#include <list>
#include <string>
#include <iostream>
using namespace std;

int main()
{
  list<string> dictionary, bWords;

  // Add the a words
  dictionary.push_back("aardvark");
  dictionary.push_back("ambulance");

  // Add the c words
  dictionary.push_back("canticle");
  dictionary.push_back("consumerism");

  // create another list of the b words
  bWords.push_back("bathos");
  bWords.push_back("balderdash");

  // splice the b words into the main dictionary.
  if (bWords.size() > 0) {
    // Get an iterator to the last b word.
    auto iterLastB = --(bWords.cend());
    // Iterate up to the spot where we want to insert bs.
    list<string>::iterator it;
    for (it = dictionary.begin(); it != dictionary.end(); ++it) {
      if (*it > *iterLastB)
          break;
    }

    // Add in the bwords. This action removes the elements from bWords.
    dictionary.splice(it, bWords);
  }

  // print out the dictionary
  for (auto it = dictionary.cbegin(); it != dictionary.cend(); ++it) {
    cout << *it << endl;
  }

  return 0;
}
