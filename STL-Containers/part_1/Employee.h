// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H

#include "Person.h"
#include <stdexcept>
#include <iomanip>

namespace seneca
{
  // Global function that removes leading and trailing whitespaces from param str
  void removeLeadTrailWhitespace(std::string &str);
  class Employee : public Person
  {
  private:
    // Name of the employee
    std::string m_name;
    // Age of the employee
    int m_age;
    // I'd of the employee
    std::string m_id;

  public:
    // Default constructor
    Employee();
    // 1-arg constructor that populates the member variables of Employee
    Employee(std::istream &stream);
    // Getter: returns string "Employee"
    std::string status() const override;
    // Getter: returns name of the employee (m_name)
    std::string name() const override;
    // Getter: returns id of the employee (m_id)
    std::string id() const override;
    // Getter: returns age of the employee (m_age)
    std::string age() const override;
    // Outputs information about the employee
    void display(std::ostream &out) const override;
    // Destructor
    ~Employee() override;
    // Copy constructor
    Employee(const Employee &copyFromEmployee);
    // Copy assignment operator
    Employee &operator=(const Employee &copyFromEmployee);
  };
}

#endif