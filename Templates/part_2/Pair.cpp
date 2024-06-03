// Author: Tushardeep Singh
// Seneca College Alumni

#include "Pair.h"

namespace seneca
{
  bool Pair::operator==(const Pair &pair) const
  {
    return m_key == pair.m_key;
  }

  std::ostream& operator<<(std::ostream& output, const Pair& outputPair)
  {
    output << std::setw(20) << std::right << outputPair.getKey();
    output << ": ";
    output << outputPair.getValue();
    return output;
  }
}