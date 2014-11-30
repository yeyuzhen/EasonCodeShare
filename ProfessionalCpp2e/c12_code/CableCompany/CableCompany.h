#include <bitset>
#include <map>
#include <string>
#include <stdexcept>
using std::map;
using std::bitset;
using std::string;
using std::out_of_range;

const int kNumChannels = 10;

class CableCompany
{
 public:
  CableCompany() {}

  // Adds the package with the specified channels to the database
  void addPackage(const string& packageName,
          const bitset<kNumChannels>& channels);

  // Removes the specified package from the database
  void removePackage(const string& packageName);

  // Adds customer to database with initial channels found in package
  // Throws out_of_range if the package name is invalid.
  void newCustomer(const string& name, const string& package)
    throw(out_of_range);

  // Adds customer to database with initial channels specified
  // in channels
  void newCustomer(const string& name, const bitset<kNumChannels>& channels);

  // Adds the channel to the customers profile
  void addChannel(const string& name, int channel);

  // Removes the channel from the customers profile
  void removeChannel(const string& name, int channel);

  // Adds the specified package to the customers profile
  void addPackageToCustomer(const string& name, const string& package);

  // Removes the specified customer from the database
  void deleteCustomer(const string& name);

  // Retrieves the channels to which this customer subscribes
  // Throws out_of_range if name is not a valid customer
  bitset<kNumChannels>& getCustomerChannels(const string& name)
    throw(out_of_range);

 protected:
  typedef map<string, bitset<kNumChannels> > MapType;
  MapType mPackages, mCustomers;
};
