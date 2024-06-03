// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include "Employee.h"

namespace seneca
{
  // Creates a new Employee and returns a Person pointer to Employee
  Person *buildInstance(std::istream &in);
}

#endif