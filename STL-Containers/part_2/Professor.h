#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include "Employee.h"

namespace seneca
{
  // Inherits Employee, Professor is a Employee
  class Professor : public Employee
  {
  private:
    // Stores the working department of professor
    std::string m_department;

  public:
    // Default constructor
    Professor();
    // 1-arg constructor that populates the professor
    Professor(std::istream &in);
    // Displays the contents of Professor object
    void display(std::ostream &out) const;
    // Getter: returns the string "Professor"
    std::string status() const;
    // Getter: returns the department of professor (m_department)
    std::string department() const;
  };
}

#endif