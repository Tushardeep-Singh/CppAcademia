// Author: Tushardeep Singh
// Seneca College Alumni

#include "./Icecream.h"

// Define static members
int seneca::Icecream::numIceCreams = 0;
seneca::data seneca::Icecream::icecreamData[10];

namespace seneca
{
  // Prints iceCream picture
  void Icecream::printIceCream()
  {
    std::cout << std::setw(11) << std::right << '@';
    std::cout << '\n';
    std::cout << std::setw(13) << std::right << "(' .)";
    std::cout << '\n';
    std::cout << std::setw(14) << std::right << "(*.`. )";
    std::cout << '\n';
    std::cout << std::setw(13) << std::right << "\\###/";
    std::cout << '\n';
    std::cout << std::setw(12) << std::right << "\\#/";
    std::cout << '\n';
    std::cout << std::setw(11) << std::right << "V";
    std::cout << '\n';
  }

  // Prints the menu
  void Icecream::printMenu()
  {
    std::cout << "Select flavour:\n";
    std::cout << "----------------\n";
    std::cout << "1: Chocolate\n";
    std::cout << "2: Strawberry\n";
    std::cout << "3: Mango\n";
    std::cout << "4: Tutti fruit\n";
    std::cout << "5: Almond crunch\n";
    std::cout << "----------------\n";
  }

  // Gets the user order
  void Icecream::takeOrdersUtils()
  {
    std::cout << "Seneca Icecream shop\n";
    printIceCream();

    std::cout << "How many Icecreams?\n> ";
    std::cin >> numIceCreams;

    for (int i = 0; i < numIceCreams; ++i)
    {
      std::cout << "Order number " << (i + 1) << ":\n";
      printMenu();

      std::string idx;
      bool loop = false;

      do
      {
        std::cout << "> ";
        std::cin >> idx;

        if (std::isalpha(idx[0]))
        {
          std::cout << "Invalid entry, retry\n";
          loop = true;
        }
        else if (std::stoi(idx) <= 0 || std::stoi(idx) >= 6)
        {
          std::cout << "Invlid value(1<=val<=5)\n";
          loop = true;
        }
        else
          loop = false;
      } while (loop);

      std::string flavour;
      int n = std::stoi(idx);
      if (n == 1)
        flavour = "Chocolate";
      if (n == 2)
        flavour = "Strawberry";
      if (n == 3)
        flavour = "Mango";
      if (n == 4)
        flavour = "Tutti fruit";
      if (n == 5)
        flavour = "Almond crunch";

      std::string nScoopsUtils;
      loop = false;

      std::cout << "Number of Scoops (max 3)\n";
      do
      {
        std::cout << "> ";
        std::cin >> nScoopsUtils;

        if (std::isalpha(nScoopsUtils[0]))
        {
          std::cout << "Invalid entry, retry\n";
          loop = true;
        }
        else if (std::stoi(nScoopsUtils) <= 0 || std::stoi(nScoopsUtils) >= 4)
        {
          std::cout << "Invlid value(1<=val<=3)\n";
          loop = true;
        }
        else
          loop = false;
      } while (loop);

      std::string vanillaWaferConeUtils;
      loop = false;

      std::cout << "Vanilla wafer cone?\n";
      std::cout << "(Y)es/(N)o > ";
      do
      {
        std::cin >> vanillaWaferConeUtils;

        if (vanillaWaferConeUtils != "n" && vanillaWaferConeUtils != "y" && vanillaWaferConeUtils != "Y" && vanillaWaferConeUtils != "N")
        {
          std::cout << "Only Y or N are acceptable:\n> ";
          loop = true;
        }
        else
          loop = false;
      } while (loop);

      // Store each iceCream order data in icecreamData array
      icecreamData[i].flavour = flavour;
      icecreamData[i].nScoops = std::stod(nScoopsUtils);
      icecreamData[i].vanillaWaferCone = (vanillaWaferConeUtils == "n") ? false : true;
    }
  }

  // Print all iceCream orders
  void Icecream::printOrder()
  {
    std::cout << "\n********** Order Summary **********\n";
    double price = 0.0;
    double addPrice = 0.0;
    for (int i = 0; i < numIceCreams; ++i)
    {
      std::cout << "Order No: " << (i + 1) << ":\n";
      std::cout << "Order details:                Price\n";
      std::cout << "-----------------------------------\n";
      std::cout << std::setw(18) << std::left << "Number of scoops, ";
      std::cout << std::setprecision(0) << std::setw(2) << std::left << icecreamData[i].nScoops;
      std::cout << std::setw(10) << std::left << "total:";
      std::cout << std::setw(5) << std::right << std::setprecision(2) << std::fixed << icecreamData[i].nScoops * 5;
      std::cout << '\n';
      if (icecreamData[i].flavour != "Chocolate")
      {
        std::cout << icecreamData[i].flavour << " flavour";
        std::cout << '\n';
      }
      else
      {
        std::cout << icecreamData[i].flavour << std::setw(21) << std::left << " flavour:";
        std::cout << std::setw(5) << std::right << std::setprecision(2) << std::fixed << icecreamData[i].nScoops << '\n';
      }
      std::cout << std::setw(30) << std::left << "Vanilla Wafer:";
      std::cout << std::setw(5) << std::right << std::setprecision(2) << std::fixed << (icecreamData[i].vanillaWaferCone ? static_cast<double>(5) : static_cast<double>(0));
      std::cout << '\n';
      price = (icecreamData[i].nScoops * 5) + (icecreamData[i].flavour == "Chocolate" ? icecreamData[i].nScoops : 0) + (icecreamData[i].vanillaWaferCone ? 5 : 0);
      addPrice += price;
      std::cout << std::setw(30) << std::left << "Price:";
      std::cout << std::setw(5) << std::right << std::setprecision(2) << std::fixed << price;
      std::cout << '\n';
      if (i != numIceCreams - 1)
        std::cout << '\n';
    }
    std::cout << "-----------------------------------\n";
    std::cout << std::setw(30) << std::left << "Price:";
    std::cout << std::setw(5) << std::right << std::setprecision(2) << std::fixed << addPrice;
    std::cout << '\n';
    std::cout << std::setw(30) << std::left << "Tax:";
    std::cout << std::setw(5) << std::right << std::setprecision(2) << std::fixed << static_cast<double>(0.13 * addPrice);
    std::cout << '\n';
    std::cout << std::setw(30) << std::left << "Total Price ($):";
    std::cout << std::setw(5) << std::right << std::setprecision(2) << std::fixed << static_cast<double>(static_cast<double>(0.13 * addPrice) + addPrice);
    std::cout << '\n';
  }
}