// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H

#include <vector>
#include "Person.h"
#include <iomanip>

namespace seneca
{
  class College
  {
  private:
    // Vector of pointers that stores Person objects
    std::vector<Person *> m_persons{};

  public:
    // Default constructor
    College();
    // Deleting copy constructor
    College(const College &) = delete;
    // Deleting copy assignment operator
    College &operator=(const College &) = delete;
    // Overloading '+=' operator
    College &operator+=(Person *thePerson);
    // Displays Person objects stored in m_persons vector
    void display(std::ostream &out) const;
    // Destructor
    ~College();
  };
}

#endif