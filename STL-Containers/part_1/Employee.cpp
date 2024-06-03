// Author: Tushardeep Singh
// Seneca College Alumni

#include "Employee.h"

namespace seneca
{
  Employee::Employee()
  {
    // Assigning the member variables to default values
    m_name = "";
    m_age = 0;
    m_id = "";
  }

  Employee::~Employee()
  {
    m_name = "";
    m_age = 0;
    m_id = "";
  }

  void removeLeadTrailWhitespace(std::string &str)
  {
    // Removing leading and trailing whitespaces from patam "str"
    int idx1, idx2;
    for (int i = 0; i < str.length(); ++i)
      if (str[i] != ' ')
      {
        idx1 = i;
        break;
      }

    for (int i = str.length() - 1; i >= 0; --i)
      if (str[i] != ' ')
      {
        idx2 = i;
        break;
      }

    str = str.substr(idx1, idx2 - idx1 + 1);
  }

  Employee::Employee(std::istream &stream)
  {
    std::string line;
    std::getline(stream, line);
    int idx1 = line.find_first_of(',');
    int idx2 = line.find_first_of(',', idx1 + 1);
    m_name = line.substr(idx1 + 1, idx2 - idx1 - 1);
    removeLeadTrailWhitespace(m_name);

    int idx3 = line.find_first_of(',', idx2 + 1);
    std::string ageUtils = line.substr(idx2 + 1, idx3 - idx2 - 1);
    removeLeadTrailWhitespace(ageUtils);
    for (int i = 0; i < ageUtils.length(); ++i)
      if (!std::isdigit(ageUtils[i]))
        throw std::runtime_error(m_name + "++Invalid record!");
    m_age = std::stoi(ageUtils);

    m_id = line.substr(idx3 + 1);
    removeLeadTrailWhitespace(m_id);
    if (m_id[0] != 'E')
      throw std::runtime_error(m_name + "++Invalid record!");
  }

  std::string Employee::status() const
  {
    return "Employee";
  }

  std::string Employee::name() const
  {
    return m_name;
  }

  std::string Employee::id() const
  {
    return m_id;
  }

  std::string Employee::age() const
  {
    return std::to_string(m_age);
  }

  void Employee::display(std::ostream &out) const
  {
    out << "| ";
    out << std::setw(10) << std::left << "Employee";
    out << "| ";
    out << std::setw(10) << std::left << id();
    out << "| ";
    out << std::setw(20) << std::left << name();
    out << " | ";
    out << std::setw(3) << std::left << age();
    out << " |";
  }

  Employee::Employee(const Employee &copyFromEmployee)
  {
    m_name = copyFromEmployee.name();
    m_age = std::stoi(copyFromEmployee.age());
    m_id = copyFromEmployee.id();
  }

  Employee &Employee::operator=(const Employee &copyFromEmployee)
  {
    m_name = copyFromEmployee.name();
    m_age = std::stoi(copyFromEmployee.age());
    m_id = copyFromEmployee.id();
    return *this;
  }
}