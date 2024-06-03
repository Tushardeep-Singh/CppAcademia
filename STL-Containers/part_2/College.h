// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H

#include <vector>
#include "Person.h"
#include <iomanip>
#include <list>

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
    // Adds Person object from m_persons vector into linked list param "persons" if 1st param "test" comes out to be true
    template <typename T>
    void select(const T &test, std::list<const Person *> &persons);
  };

  template <typename T>
  void College::select(const T &test, std::list<const Person *> &persons)
  {
    for (int i = 0; i < m_persons.size(); ++i)
      if (test(m_persons[i]))
        persons.push_back(m_persons[i]);
  }
}

#endif