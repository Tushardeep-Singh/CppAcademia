// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_GUEST_H
#define SENECA_GUEST_H

#include <iostream>
#include <cstring>

namespace seneca
{
  // Guest details
  struct Guest
  {
    char *m_firstName;
    char *m_lastName;
    bool m_adult;
  };

  // sets the Guest variables and sets the m_adult flag to true if the age is greater than or equal to 18
  void set(Guest &guest, const char *first, const char *last, int age);
  // Prints the guest name
  void print(const Guest &guest);
  // books the guest information from the console
  void book(Guest &guest);
  // vacates the guest by dallocating its memory
  void vacate(Guest &guest);
  // Sets the dynamic guest variables to nullptr
  void setToDefault(Guest &guest);
}

#endif