// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

#include <string>
#include <fstream>
#include <iostream>

namespace seneca
{
  class StringSet
  {
  private:
    // Array to store strings
    std::string *m_stringArr{nullptr};
    // Number of strings currently stored in m_stringArr
    int m_stringArrSize{0};

  public:
    // Default constructor
    StringSet();
    // 1-argument constructor that populates the current object
    StringSet(const char *fileName);
    // Getter: returns the number of strings stored in the current object (strings stored in m_stringArr)
    size_t size();
    // Returns a copy of the string at the index
    std::string operator[](size_t index);
    // Rule of 3
    // Copy constructor
    StringSet(const StringSet &other);
    // Copy assignment operator
    StringSet &operator=(const StringSet &other);
    // Destructor
    ~StringSet();
  };
}

#endif