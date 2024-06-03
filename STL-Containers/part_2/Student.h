#ifndef SENECA_STUDENT_H
#define SENECA_STUDENT_H

#include "Person.h"
#include <vector>
#include <iomanip>

namespace seneca
{
  // Inherit Person
  class Student : public Person
  {
  private:
    // Name of the student
    std::string m_name;
    // Age of the student
    int m_age;
    // Id of the student
    std::string m_id;
    // Vector containing courses taken by the student
    std::vector<std::string> m_courses;
    // Count of courses taken by the student
    int m_count;

  public:
    // Default constructor
    Student();
    // 1-arg constructor
    Student(std::istream &stream);
    // Getter: Returns the string "Student"
    std::string status() const override;
    // Getter: Returns the name of the student (m_name)
    std::string name() const override;
    // Getter: Returns the age of the student (m_age)
    std::string age() const override;
    // Getter: Returns the id of the student (m_id)
    std::string id() const override;
    // Deleting the copy constructor
    Student(const Student &) = delete;
    // Deleting the copy assignment operator
    Student &operator=(const Student &) = delete;
    // Displays the contents of the Student object
    void display(std::ostream &out) const override;
    // Removes leading and trailing whitespaces from the param string "str"
    void removeLeadTrailWhitespace(std::string &str);
    // Destructor
    ~Student() override;
  };
}

#endif