// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <string>
#include <iostream>
#include <iomanip>

namespace seneca
{
  class Pair
  {
    // Key in key-value pair
    std::string m_key{};
    // Value in key-value pair
    std::string m_value{};

  public:
    // Default Constructor
    Pair(){};
    // Getter: return key in key-value pair
    const std::string &getKey() const { return m_key; }
    // Getter: return value in key-value pair
    const std::string &getValue() const { return m_value; }
    // 2-arg constructor
    Pair(const std::string &key, const std::string &value) : m_key{key}, m_value{value} {};
    // Overloading the comparison operator
    bool operator==(const Pair &pair) const;
  };
  // Overloading the '<<' operator
  std::ostream &operator<<(std::ostream &output, const Pair &outputPair);
}

#endif