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

    // Return nullptr if the stream is empty
    if (line.length() == 0)
      return nullptr;
    removeLeadTrailWhitespace(line);
    if (line[0] != 'e' && line[0] != 'E' && line[0] != 's' && line[0] != 'S' && line[0] != 'p' && line[0] != 'P')
      return nullptr;

    // Re-positioning the indicator to it's position before calling std::getline()
    in.seekg(startPosition);

    // Return a pointer to student if the stream contains student data
    if (line[0] == 's' || line[0] == 'S')
      return new Student(in);

    // Return a pointer to professor if the stream contains professor data
    if (line[0] == 'p' || line[0] == 'P')
      return new Professor(in);

    Employee *newEmployee = new Employee(in);
    // Returning Person pointer to Employee
    return newEmployee;
  }
}