// AirlineTicket.h

#include <string>

class AirlineTicket
{
 public:
  AirlineTicket();
  ~AirlineTicket();

  int     calculatePriceInDollars() const;

  std::string  getPassengerName() const;
  void         setPassengerName(std::string inName);
  int          getNumberOfMiles() const;
  void         setNumberOfMiles(int inMiles);
  bool         getHasEliteSuperRewardsStatus() const;
  void         setHasEliteSuperRewardsStatus(bool inStatus);

 protected:
  std::string  mPassengerName;
  int          mNumberOfMiles;
  bool         bHasEliteSuperRewardsStatus;
}; 
