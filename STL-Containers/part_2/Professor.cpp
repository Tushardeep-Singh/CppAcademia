#include "Professor.h"

namespace seneca
{
  // Default constructor
  Professor::Professor()
  {
    m_department = "";
  }

  // 1-arg constructor
  Professor::Professor(std::istream &in) : Employee(in) // Initialise the sub-object Employee
  {
    std::string line;
    std::getline(in, line);
    removeLeadTrailWhitespace(line);
    m_department = line;
  }

  void Professor::display(std::ostream &out) const
  {
    Employee::display(out);
    out << m_department << "| Professor";
  }

  std::string Professor::status() const
  {
    return "Professor";
  }

  std::string Professor::department() const
  {
    return m_department;
  }
}