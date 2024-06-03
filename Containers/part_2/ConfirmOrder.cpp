// Author: Tushardeep Singh
// Seneca College Alumni

#include "ConfirmOrder.h"

namespace seneca
{
  ConfirmOrder::ConfirmOrder()
  {
    m_toysArr = nullptr;
    m_numOfToys = 0;
  }

  int ConfirmOrder::getNumOfToys() const
  {
    return m_numOfToys;
  }

  void ConfirmOrder::setNumOfToys(const int &num)
  {
    m_numOfToys = num;
  }

  bool ConfirmOrder::lookForToy(const Toy &toy) const
  {
    for (int i = 0; i < getNumOfToys(); ++i)
      if (m_toysArr[i] == &toy)
        return true;

    return false;
  }

  ConfirmOrder &ConfirmOrder::operator+=(const Toy &toy)
  {
    if (lookForToy(toy))
      return *this;

    if (getNumOfToys() == 0)
    {
      m_toysArr = new const Toy *[getNumOfToys() + 1];
      m_toysArr[getNumOfToys()] = &toy;
      setNumOfToys(getNumOfToys() + 1);
      return *this;
    }
    const Toy *(*tempToysArr) = new const Toy *[getNumOfToys() + 1];
    for (int i = 0; i < getNumOfToys() + 1; ++i)
      tempToysArr[i] = m_toysArr[i];
    tempToysArr[getNumOfToys()] = &toy;

    for (int i = 0; i < getNumOfToys(); ++i)
      m_toysArr[i] = nullptr;
    delete[] m_toysArr;
    m_toysArr = nullptr;

    m_toysArr = new const Toy *[getNumOfToys() + 1];
    for (int i = 0; i < getNumOfToys() + 1; ++i)
      m_toysArr[i] = tempToysArr[i];
    setNumOfToys(getNumOfToys() + 1);

    for (int i = 0; i < getNumOfToys(); ++i)
      tempToysArr[i] = nullptr;
    delete[] tempToysArr;
    tempToysArr = nullptr;

    return *this;
  }

  ConfirmOrder &ConfirmOrder::operator-=(const Toy &toy)
  {
    if (!lookForToy(toy))
      return *this;

    const Toy *(*tempToysArr) = new const Toy *[getNumOfToys() - 1];
    int idx = 0;
    for (int i = 0; i < getNumOfToys(); ++i)
    {
      if (m_toysArr[i] == &toy)
      {
        m_toysArr[i] = nullptr;
        continue;
      }
      tempToysArr[idx++] = m_toysArr[i];
    }

    for (int i = 0; i < getNumOfToys(); ++i)
      m_toysArr[i] = nullptr;
    delete[] m_toysArr;
    m_toysArr = nullptr;

    m_toysArr = new const Toy *[getNumOfToys() - 1];
    for (int i = 0; i < getNumOfToys() - 1; ++i)
      m_toysArr[i] = tempToysArr[i];

    for (int i = 0; i < getNumOfToys() - 1; ++i)
      tempToysArr[i] = nullptr;
    delete[] tempToysArr;
    tempToysArr = nullptr;

    setNumOfToys(getNumOfToys() - 1);
    return *this;
  }

  const Toy *ConfirmOrder::operator[](const int &index) const
  {
    return m_toysArr[index];
  }

  std::ostream &operator<<(std::ostream &output, const ConfirmOrder &outputOrder)
  {
    output << "--------------------------\n";
    output << "Confirmations to Send\n";
    output << "--------------------------\n";

    if (outputOrder.getNumOfToys() == 0)
    {
      output << "There are no confirmations to send!\n";
      output << "--------------------------\n";
      return output;
    }

    for (int i = 0; i < outputOrder.getNumOfToys(); ++i)
      output << *outputOrder[i];
    output << "--------------------------\n";

    return output;
  }

  ConfirmOrder::~ConfirmOrder()
  {
    if (m_toysArr != nullptr)
    {
      for (int i = 0; i < getNumOfToys(); ++i)
        m_toysArr[i] = nullptr;
      delete[] m_toysArr;
      m_toysArr = nullptr;
    }
    setNumOfToys(0);
  }

  ConfirmOrder::ConfirmOrder(const ConfirmOrder &copyFromConfirmOrder)
  {
    m_toysArr = new const Toy *[copyFromConfirmOrder.getNumOfToys()];
    m_numOfToys = copyFromConfirmOrder.getNumOfToys();
    for (int i = 0; i < m_numOfToys; ++i)
      m_toysArr[i] = copyFromConfirmOrder[i];
  }

  ConfirmOrder::ConfirmOrder(ConfirmOrder &&moveFromConfirmOrder)
  {
    m_numOfToys = moveFromConfirmOrder.getNumOfToys();
    m_toysArr = moveFromConfirmOrder.m_toysArr;

    moveFromConfirmOrder.m_toysArr = nullptr;
    moveFromConfirmOrder.setNumOfToys(0);
  }

  ConfirmOrder &ConfirmOrder::operator=(ConfirmOrder &&moveFromConfirmOrder)
  {
    if (this == &moveFromConfirmOrder)
      return *this;

    for (int i = 0; i < getNumOfToys(); ++i)
      m_toysArr[i] = nullptr;
    delete[] m_toysArr;
    m_toysArr = nullptr;
    setNumOfToys(0);

    m_toysArr = moveFromConfirmOrder.m_toysArr;
    m_numOfToys = moveFromConfirmOrder.getNumOfToys();

    moveFromConfirmOrder.m_toysArr = nullptr;
    moveFromConfirmOrder.setNumOfToys(0);
    return *this;
  }

  ConfirmOrder &ConfirmOrder::operator=(const ConfirmOrder &copyFromConfirmOrder)
  {
    if (const_cast<const ConfirmOrder *>(this) == &copyFromConfirmOrder)
      return *this;

    for (int i = 0; i < getNumOfToys(); ++i)
      m_toysArr[i] = nullptr;
    delete[] m_toysArr;
    m_toysArr = nullptr;

    m_numOfToys = copyFromConfirmOrder.getNumOfToys();
    m_toysArr = new const Toy *[m_numOfToys];
    for (int i = 0; i < m_numOfToys; ++i)
      m_toysArr[i] = copyFromConfirmOrder[i];

    return *this;
  }
}