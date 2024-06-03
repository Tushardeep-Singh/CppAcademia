// Author: Tushardeep Singh
// Seneca College Alumni

#include "Child.h"

namespace seneca
{
  Child::Child()
  {
    m_childName = "";
    m_childAge = 0;
    m_childToysArr = nullptr;
    m_numOfToys = 0;
  }

  Child::Child(std::string name, int age, const Toy *toys[], size_t count)
  {
    m_childName = name;
    m_childAge = age;
    m_numOfToys = count;
    m_childToysArr = new const Toy *[m_numOfToys];
    // Child will have it's own instances of Toys
    for (int i = 0; i < m_numOfToys; ++i)
      m_childToysArr[i] = new Toy(*toys[i]);
  }

  size_t Child::size() const
  {
    return m_numOfToys;
  }

  Child::~Child()
  {
    m_childName = "";
    m_childAge = 0;
    if (m_childToysArr != nullptr)
    {
      for (int i = 0; i < m_numOfToys; ++i)
      {
        delete m_childToysArr[i];
        m_childToysArr[i] = nullptr;
      }
      delete[] m_childToysArr;
      m_childToysArr = nullptr;
    }
    m_numOfToys = 0;
  }

  std::string Child::getChildName() const
  {
    return m_childName;
  }

  int Child::getChildAge() const
  {
    return m_childAge;
  }

  int Child::getNumOfToys() const
  {
    return m_numOfToys;
  }

  const Toy *Child::operator[](const int &index) const
  {
    return m_childToysArr[index];
  }

  Child::Child(const Child &copyFromChild)
  {
    m_childName = copyFromChild.getChildName();
    m_childAge = copyFromChild.getChildAge();
    m_numOfToys = copyFromChild.getNumOfToys();
    m_childToysArr = (new const Toy *[m_numOfToys]);
    for (int i = 0; i < m_numOfToys; ++i)
      m_childToysArr[i] = new Toy(*copyFromChild[i]);
  }

  void Child::emptyToysArr()
  {
    for (int i = 0; i < m_numOfToys; ++i)
    {
      delete m_childToysArr[i];
      m_childToysArr[i] = nullptr;
    }
    delete[] m_childToysArr;
    m_childToysArr = nullptr;
  }

  Child &Child::operator=(const Child &copyFromChild)
  {
    if (this == &copyFromChild)
      return *this;

    emptyToysArr();
    m_numOfToys = 0;
    m_childAge = 0;
    m_childName = "";

    m_childName = copyFromChild.getChildName();
    m_childAge = copyFromChild.getChildAge();
    m_numOfToys = copyFromChild.getNumOfToys();
    m_childToysArr = new const Toy *[m_numOfToys];
    for (int i = 0; i < m_numOfToys; ++i)
      m_childToysArr[i] = new Toy(*copyFromChild[i]);

    return *this;
  }

  const Toy **Child::getChildToysArr() const
  {
    return m_childToysArr;
  }

  void Child::setChildToysArrToNullptr()
  {
    m_childToysArr = nullptr;
  }

  void Child::setChildName(const std::string &name)
  {
    m_childName = name;
  }

  void Child::setChildAge(const int &age)
  {
    m_childAge = age;
  }

  void Child::setNumOfToys(const int &numOfToys)
  {
    m_numOfToys = numOfToys;
  }

  Child::Child(Child &&moveFromChild)
  {
    m_childAge = moveFromChild.getChildAge();
    m_childName = moveFromChild.getChildName();
    m_numOfToys = moveFromChild.getNumOfToys();

    m_childToysArr = moveFromChild.getChildToysArr();
    moveFromChild.setChildToysArrToNullptr();
    moveFromChild.setChildAge(0);
    moveFromChild.setChildName("");
    moveFromChild.setNumOfToys(0);
  }

  Child &Child::operator=(Child &&moveFromChild)
  {
    if (this == &moveFromChild)
      return *this;
    m_childAge = moveFromChild.getChildAge();
    m_childName = moveFromChild.getChildName();
    emptyToysArr();
    m_numOfToys = moveFromChild.getNumOfToys();
    m_childToysArr = moveFromChild.getChildToysArr();
    moveFromChild.setChildToysArrToNullptr();
    moveFromChild.setChildAge(0);
    moveFromChild.setChildName("");
    moveFromChild.setNumOfToys(0);

    return *this;
  }

  std::ostream &operator<<(std::ostream &output, const Child &outputChild)
  {
    static int count = 1;
    output << "--------------------------\n";
    output << "Child " << count++ << ": ";
    output << outputChild.getChildName() << ' ';
    output << outputChild.getChildAge() << " years old:\n";
    output << "--------------------------\n";
    if (outputChild.getNumOfToys() == 0)
    {
      output << "This child has no toys!\n";
      output << "--------------------------\n";
      return output;
    }
    for (int i = 0; i < outputChild.getNumOfToys(); ++i)
      output << *outputChild[i];
    output << "--------------------------\n";
    return output;
  }
}