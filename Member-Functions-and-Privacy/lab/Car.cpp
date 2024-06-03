// Author: Tushardeep Singh
// Seneca College Alumni

#include "./Car.h"

namespace seneca
{
  // Car is considered empty if any one condition is true
  bool Car::isEmpty() const
  {
    return m_makeModel == nullptr || m_serviceDesc == nullptr || !strlen(m_makeModel) || !strlen(m_serviceDesc);
  }

  // Set's the Car class member variables to empty state.
  void Car::setEmpty()
  {
    const char *emptyStr = "";
    strcpy(m_licencePlate, emptyStr);
    m_makeModel = nullptr;
    m_serviceDesc = nullptr;
    m_cost = 0.0;
  }

  // Deallocates the dynamically allocated memory
  void Car::deallocateMemory()
  {
    delete[] m_makeModel;
    delete[] m_serviceDesc;
    m_makeModel = nullptr;
    m_serviceDesc = nullptr;
  }

  // Set's the Car variables to params
  void Car::set(const char plateNo[], const char *carMakeModel, const char *serviceDesc, double serviceCost)
  {
    deallocateMemory();
    setEmpty();

    if (strlen(plateNo) && carMakeModel != nullptr && serviceDesc != nullptr && strlen(carMakeModel) && strlen(serviceDesc))
    {
      strcpy(m_licencePlate, plateNo);
      // Allocate memory dynamically before copying param into var
      m_makeModel = new char[strlen(carMakeModel) + 1];
      strcpy(m_makeModel, carMakeModel);
      m_serviceDesc = new char[strlen(serviceDesc) + 1];
      strcpy(m_serviceDesc, serviceDesc);
      m_cost = serviceCost;
    }
  }

  void Car::display() const
  {
    if (!isEmpty())
    {
      std::cout << std::setw(15) << std::left << "License Plate:";
      std::cout << std::setw(20) << std::right << m_licencePlate;
      std::cout << '\n';
      std::cout << std::setw(15) << std::left << "Model:";
      std::cout << std::setw(20) << std::right << m_makeModel;
      std::cout << '\n';
      std::cout << std::setw(15) << std::left << "Service Name:";
      std::cout << std::setw(20) << std::right << m_serviceDesc;
      std::cout << '\n';
      std::cout << std::setw(15) << std::left << "Service Cost:";
      std::cout << std::setw(20) << std::right << std::fixed << std::setprecision(2) << m_cost << '\n';
    }
  }
}