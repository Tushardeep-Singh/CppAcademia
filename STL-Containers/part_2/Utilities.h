// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include "Student.h"
#include "Professor.h"

namespace seneca
{
  // Creates a new Employee, student or Professor depending upon the content stored in stream and returns a Person pointer to object
  Person *buildInstance(std::istream &in);
}

#endif