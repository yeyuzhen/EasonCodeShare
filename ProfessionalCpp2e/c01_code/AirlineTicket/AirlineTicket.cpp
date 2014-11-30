// AirlineTicket.cpp

#include <iostream>
#include "AirlineTicket.h"

using namespace std;

AirlineTicket::AirlineTicket()
{
  // initialize data members
  bHasEliteSuperRewardsStatus = false; 
  mPassengerName = "Unknown Passenger";
  mNumberOfMiles = 0;
}

AirlineTicket::~AirlineTicket()
{
  // nothing much to do in terms of cleanup
}

int AirlineTicket::calculatePriceInDollars() const
{
  if (getHasEliteSuperRewardsStatus()) {
    // Elite Super Rewards customers fly for free!
    return 0;
  }
 
  // The cost of the ticket is the number of miles times
  // 0.1. Real airlines probably have a more complicated formula!
  return static_cast<int>((getNumberOfMiles() * 0.1));
}

string AirlineTicket::getPassengerName() const
{
  return mPassengerName;
}

void AirlineTicket::setPassengerName(string inName)
{
  mPassengerName = inName;
}

int AirlineTicket::getNumberOfMiles() const
{
  return mNumberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int inMiles)
{
  mNumberOfMiles = inMiles;
}

bool AirlineTicket::getHasEliteSuperRewardsStatus() const
{
  return bHasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool inStatus)
{
  bHasEliteSuperRewardsStatus = inStatus;
}
