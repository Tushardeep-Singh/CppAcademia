#include "Student.h"

namespace seneca
{

  void Student::removeLeadTrailWhitespace(std::string &str)
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

  // Default constructor
  Student::Student()
  {
    m_name = "";
    m_age = 0;
    m_id = "";
    m_courses = {};
    m_count = 0;
  }

  // 1-arg constructor
  Student::Student(std::istream &stream)
  {
    std::string line;
    std::getline(stream, line);

    int idx1 = line.find_first_of(',', 0);
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

    int idx4 = line.find_first_of(',', idx3 + 1);
    m_id = line.substr(idx3 + 1, idx4 - idx3 - 1);
    removeLeadTrailWhitespace(m_id);
    if (m_id[0] != 'S')
      throw std::runtime_error(m_name + "++Invalid record!");

    int idx5 = line.find_first_of(',', idx4 + 1);
    std::string numCoursesUtils = line.substr(idx4 + 1, idx5 - idx4 - 1);
    removeLeadTrailWhitespace(numCoursesUtils);
    for (int i = 0; i < numCoursesUtils.length(); ++i)
      if (!std::isdigit(numCoursesUtils[i]))
        throw(m_name + "++Invalid record!");
    m_count = std::stoi(numCoursesUtils);

    std::string listOfCourses = line.substr(idx5 + 1);
    for (int i = 0; i < m_count; ++i)
    {
      if (i == m_count - 1)
      {
        std::string course = line.substr(idx5 + 1);
        removeLeadTrailWhitespace(course);
        m_courses.push_back(course);
        return;
      }
      int idx6 = line.find_first_of(',', idx5 + 1);
      std::string course = line.substr(idx5 + 1, idx6 - idx5 - 1);
      removeLeadTrailWhitespace(course);
      m_courses.push_back(course);
      idx5 = idx6;
    }
  }

  std::string Student::status() const
  {
    return "Student";
  }

  std::string Student::name() const
  {
    return m_name;
  }

  void Student::display(std::ostream &out) const
  {
    out << "| ";
    out << std::setw(10) << std::left << "Student";
    out << "| ";
    out << std::setw(10) << std::left << id();
    out << "| ";
    out << std::setw(20) << std::left << name();
    out << " | ";
    out << std::setw(3) << std::left << age();
    out << " |";
    for (int i = 0; i < m_courses.size() - 1; ++i)
      std::cout << m_courses[i] << ", ";
    std::cout << m_courses[m_courses.size() - 1];
  }

  std::string Student::age() const
  {
    return std::to_string(m_age);
  }

  std::string Student::id() const
  {
    return m_id;
  }

  // Destructor
  Student::~Student()
  {
    m_name = "";
    m_age = 0;
    m_id = "";
    m_courses = {};
    m_count = 0;
  }
}