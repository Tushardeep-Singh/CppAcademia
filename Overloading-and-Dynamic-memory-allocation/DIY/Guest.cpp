// Author: Tushardeep Singh
// Seneca College Alumni

#include "./Guest.h"

namespace seneca
{
  void set(Guest &guest, const char *first, const char *last, int age)
  {
    // only set dynamic variables if params are valid
    if (first && last && strlen(first) && strlen(last))
    {
      guest.m_firstName = new char[strlen(first) + 1];
      strcpy(guest.m_firstName, first);

      guest.m_lastName = new char[strlen(last) + 1];
      strcpy(guest.m_lastName, last);

      guest.m_adult = (age >= 18) ? true : false;
      return;
    }
    guest.m_firstName = nullptr;
    guest.m_lastName = nullptr;
  }

  void print(const Guest &guest)
  {
    if (guest.m_firstName == nullptr || guest.m_lastName == nullptr)
    {
      std::cout << "Vacated!\n";
      return;
    }

    std::cout << guest.m_firstName << ' ' << guest.m_lastName;
    if (!guest.m_adult)
    {
      std::cout << "(Child)\n";
      return;
    }
    std::cout << '\n';
  }

  void book(Guest &guest)
  {
    char fName[50];
    char lName[50];
    char age[4];  

    // Get the input from the console
    std::cout << "Name: ";
    std::cin >> fName;
    std::cout << "Lastname: ";
    std::cin >> lName;
    std::cout << "Age: ";
    std::cin >> age;

    // Allocate the memory and copy into struct variable
    guest.m_firstName = new char[strlen(fName) + 1];
    strcpy(guest.m_firstName, fName);

    guest.m_lastName = new char[strlen(lName) + 1];
    strcpy(guest.m_lastName, lName);

    guest.m_adult = (std::stoi(age) >= 18) ? true : false;
  }

  // Release the memory and point to nullptr
  void vacate(Guest &guest)
  {
    delete[] guest.m_firstName;
    delete[] guest.m_lastName;
    guest.m_firstName = nullptr;
    guest.m_lastName = nullptr;
  }

  // Set the struct dynamic varibales to nullptr
  void setToDefault(Guest &guest)
  {
    guest.m_firstName = nullptr;
    guest.m_lastName = nullptr;
  }
}