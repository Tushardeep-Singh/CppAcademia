// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H

#include "Toy.h"

namespace seneca
{
  class Child
  {
  private:
    // Name of the child
    std::string m_childName{""};
    // Age of the child
    int m_childAge{0};
    // Array storing pointers to Toy objects
    const Toy *(*m_childToysArr){nullptr};
    // Number of toys stored in m_childToysArr
    int m_numOfToys{0};

  public:
    // Default constructor
    Child();
    // 4-arg constructor
    Child(std::string name, int age, const Toy *toys[], size_t count);
    // Getter: returns m_numOfToys
    size_t size() const;
    // Destructor
    ~Child();
    // Copy constructor
    Child(const Child &copyFromChild);
    // Copy assignment operator
    Child &operator=(const Child &copyFromChild);
    // Move constructor
    Child(Child &&moveFromChild);
    // Move assignment operator
    Child &operator=(Child &&moveFromChild);
    // Getter: returns child name(m_childName)
    std::string getChildName() const;
    // Getter: returns child age(m_childAge)
    int getChildAge() const;
    // Getter: returns number of toys in m_childToysArr(m_numOfToys)
    int getNumOfToys() const;
    // returns m_childToysArr[index]
    const Toy *operator[](const int &index) const;
    // Empties m_childToysArr
    void emptyToysArr();
    // Returns m_childToysArr
    const Toy **getChildToysArr() const;
    // Sets m_childToysArr to nullptr
    void setChildToysArrToNullptr();
    // Setter: sets m_childName to param name
    void setChildName(const std::string &name);
    // Setter: sets m_childAge to param age
    void setChildAge(const int &age);
    // Setter: sets m_numOfToys to param numOfToys
    void setNumOfToys(const int &numOfToys);
  };
  // Overloading the insertion operator
  std::ostream &operator<<(std::ostream &output, const Child &outputChild);
}

#endif