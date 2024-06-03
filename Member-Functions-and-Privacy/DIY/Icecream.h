// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H

#include <iostream>
#include <iomanip>
#include <cstring>

namespace seneca
{
  // Struct to store each iceCream order
  struct data
  {
    std::string flavour;
    double nScoops;
    bool vanillaWaferCone;
  };

  class Icecream
  {
  private:
    // Number of iceCream orders
    static int numIceCreams;
    // Array to store each iceCream order data
    static data icecreamData[10];

  public:
    // Prints the iceCream picture to the console
    static void printIceCream();
    // Gets user order
    static void takeOrdersUtils();
    // Prints iceCream Menu
    static void printMenu();
    // Prints all iceCream orders
    static void printOrder();
  };
}

#endif