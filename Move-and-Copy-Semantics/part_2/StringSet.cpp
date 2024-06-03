// Author: Tushardeep Singh
// Seneca College Alumni

#include "StringSet.h"

namespace seneca
{
  // Default constructor
  StringSet::StringSet()
  {
    m_stringArr = nullptr;
    m_stringArrSize = 0;
  }

  // 1-argument constructor that populates the current object
  StringSet::StringSet(const char *fileName)
  {
    std::ifstream file(fileName);

    if (!file.is_open())
    {
      std::cerr << "ERROR! File not opened!\n";
      return;
    }

    std::string word;
    while (std::getline(file, word, ' '))
    {
      ++m_stringArrSize;
    }
    m_stringArr = new std::string[m_stringArrSize];

    int index = 0;
    file.clear();
    file.seekg(0, std::ios::beg);
    while (std::getline(file, word, ' '))
    {
      m_stringArr[index++] = word;
    }
  }

  // Getter: returns the number of strings stored in the current object (strings stored in m_stringArr)
  size_t StringSet::size()
  {
    return m_stringArrSize;
  }

  // Returns a copy of the string at the index
  std::string StringSet::operator[](size_t index)
  {
    if (index >= 0 && index < m_stringArrSize)
      return m_stringArr[index];
    return static_cast<std::string>("");
  }

  // Copy constructor
  StringSet::StringSet(const StringSet &other)
  {
    // self assignment check
    if (this == &other)
      return;
    m_stringArrSize = other.m_stringArrSize;
    m_stringArr = new std::string[other.m_stringArrSize];
    for (int i = 0; i < m_stringArrSize; ++i)
      m_stringArr[i] = other.m_stringArr[i];
  }

  // Copy assignment operator
  StringSet &StringSet::operator=(const StringSet &other)
  {
    // self assignment check
    if (this == &other)
      return *this;

    if (m_stringArr != nullptr)
    {
      delete[] m_stringArr;
      m_stringArr = nullptr;
    }
    m_stringArrSize = other.m_stringArrSize;
    m_stringArr = new std::string[m_stringArrSize];
    for (int i = 0; i < m_stringArrSize; ++i)
      m_stringArr[i] = other.m_stringArr[i];

    return *this;
  }

  // Destructor
  StringSet::~StringSet()
  {
    if (m_stringArr != nullptr)
    {
      delete[] m_stringArr;
      m_stringArr = nullptr;
    }
    m_stringArrSize = 0;
  }

  // Move constructor
  StringSet::StringSet(StringSet &&other) noexcept
  {
    if (this == &other)
      return;

    m_stringArrSize = other.m_stringArrSize;
    // Make m_stringArr point to other.m_stringArr
    m_stringArr = other.m_stringArr;

    // Make other.m_stringArr nullptr
    other.m_stringArr = nullptr;
    other.m_stringArrSize = 0;
  }

  // Move assignment operator
  StringSet &StringSet::operator=(StringSet &&other) noexcept
  {
    if (this == &other)
      return *this;

    // Release the resources of this
    delete[] m_stringArr;
    m_stringArr = nullptr;
    m_stringArrSize = other.m_stringArrSize;
    // Make m_stringArr point to memory of other.m_stringArr
    m_stringArr = other.m_stringArr;

    // Make other.m_stringArr nullptr
    other.m_stringArr = nullptr;
    other.m_stringArrSize = 0;

    return *this;
  }
}