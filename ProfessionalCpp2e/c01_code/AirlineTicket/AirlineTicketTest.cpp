// AirlineTicketTest.cpp

#include <iostream>
#include <memory>
#include "AirlineTicket.h"

using namespace std;

int main()
{
  AirlineTicket myTicket;  // stack-based AirlineTicket
    
  myTicket.setPassengerName("Sherman T. Socketwrench");
  myTicket.setNumberOfMiles(700);
  int cost = myTicket.calculatePriceInDollars();
  cout << "This ticket will cost $" << cost << endl;

  // heap-based AirlineTicket with smart pointer
  shared_ptr<AirlineTicket> myTicket2(new AirlineTicket());
  myTicket2->setPassengerName("Laudimore M. Hallidue");
  myTicket2->setNumberOfMiles(2000);
  myTicket2->setHasEliteSuperRewardsStatus(true);
  int cost2 = myTicket2->calculatePriceInDollars();
  cout << "This other ticket will cost $" << cost2 << endl;
  // No need to delete myTicket2, happens automatically

  // heap-based AirlineTicket without smart pointer
  AirlineTicket* myTicket3 = new AirlineTicket();
  // ... Use ticket 3
  delete myTicket3;  // delete the heap object

  return 0;
} 
