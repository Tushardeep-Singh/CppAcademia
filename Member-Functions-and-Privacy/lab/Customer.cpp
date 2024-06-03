// Author: Tushardeep Singh
// Seneca College Alumni

#include "./Customer.h"

namespace seneca
{
  // Obj is empty if any of the conditions is true
  bool Customer::isEmpty() const
  {
    return m_name == nullptr || !strlen(m_name) || m_car == nullptr;
  }

  void Customer::setEmpty()
  {
    m_id = 0;
    m_name = nullptr;
    m_car = nullptr;
  }

  void Customer::deallocateMemory()
  {
    m_id = 0;
    delete[] m_name;
    m_name = nullptr;
    m_car = nullptr;
  }

  void Customer::set(int customerId, const char *name, const Car *car)
  {
    setEmpty();
    deallocateMemory();

    if (name != nullptr && strlen(name) && car != nullptr)
    {
      m_id = customerId;
      // Allocate memory before copying from param
      m_name = new char[strlen(name) + 1];
      strcpy(m_name, name);
      m_car = car;
    }
  }

  void Customer::display() const
  {
    std::cout << std::setw(15) << std::left << "Customer ID:";
    std::cout << std::setw(20) << std::right << m_id;
    std::cout << '\n';
    std::cout << std::setw(15) << std::left << "First Name:";
    std::cout << std::setw(20) << std::right << m_name;
    std::cout << '\n';
    m_car->display();
  }

  const Car &Customer::car() const
  {
    // return the Car obj pointer after dereferencing
    return *m_car;
  }
}