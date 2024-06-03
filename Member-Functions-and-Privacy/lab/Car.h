// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_CAR_H
#define SENECA_CAR_H

#include <iostream>
#include <iomanip>
#include <cstring>

namespace seneca
{
  class Car
  {
  private:
    char m_licencePlate[8];
    char *m_makeModel;
    char *m_serviceDesc;
    double m_cost;

  public:
    // To check if the object is in a safe recognizable empty state.
    bool isEmpty() const;
    // Sets the object in a safe recognizable empty state.
    void setEmpty();
    void deallocateMemory();
    // Set's car information and service details
    void set(const char plateNo[], const char *carMakeModel, const char *serviceDesc, double serviceCost);
    void display() const;
  };
}

#endif