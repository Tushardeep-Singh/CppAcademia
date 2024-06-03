// Author: Tushardeep Singh
// Seneca College Alumni

#include "Utilities.h"

namespace seneca
{
  Person *buildInstance(std::istream &in)
  {
    std::string line;
    // Stores the current position of stream indicator before advancing the indicator using std::getline()
    std::streampos startPosition = in.tellg();
    std::getline(in, line);

    if (line.length() == 0)
      return nullptr;
    removeLeadTrailWhitespace(line);
    if (line[0] != 'e' && line[0] != 'E')
      return nullptr;

    // Re-positioning the indicator to it's position before calling std::getline()
    in.seekg(startPosition);
    Employee *newEmployee = new Employee(in);
    // Returning Person pointer to Employee
    return newEmployee;
  }
}