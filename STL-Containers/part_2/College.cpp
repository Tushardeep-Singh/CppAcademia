// Author: Tushardeep Singh
// Seneca College Alumni

#include "College.h"

namespace seneca
{
  College &College::operator+=(Person *thePerson)
  {
    // Adding the address of param "thePerson" to vector m_persons
    m_persons.push_back(thePerson);
    return *this;
  }

  void College::display(std::ostream &out) const
  {
    out << "------------------------------------------------------------------------------------------------------------------------\n";
    out << "|                                        Test #1 Persons in the college!                                               |\n";
    out << "------------------------------------------------------------------------------------------------------------------------\n";

    std::vector<Person *>::const_iterator it = (m_persons.begin());
    for (; it != m_persons.end(); ++it)
    {
      (*it)->display(std::cout);
      out << '\n';
    }

    out << "------------------------------------------------------------------------------------------------------------------------\n";
    out << "|                                        Test #2 Persons in the college!                                               |\n";
    out << "------------------------------------------------------------------------------------------------------------------------\n";

    std::vector<Person *>::const_iterator it2 = m_persons.begin();
    for (; it2 != m_persons.end(); ++it2)
    {
      out << "| ";
      out << std::setw(10) << std::left << (*it2)->status();
      out << "| ";
      out << std::setw(10) << std::left << (*it2)->id();
      out << "| ";
      out << std::setw(20) << std::left << (*it2)->name();
      out << " | ";
      out << std::setw(3) << std::left << (*it2)->age();
      out << " |\n";
    }
    out << "------------------------------------------------------------------------------------------------------------------------\n";
  }

  College::College()
  {
    m_persons = {};
  }

  // Destructor
  College::~College()
  {
    for (int i = 0; i < m_persons.size(); ++i)
    {
      delete m_persons[i];
      m_persons[i] = nullptr;
    }
    m_persons = {};
  }
}