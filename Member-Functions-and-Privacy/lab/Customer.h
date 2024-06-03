// Author: Tushardeep Singh
// Seneca Collge Alumni

#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H

#include "./Car.h"

namespace seneca
{
  class Customer
  {
  private:
    int m_id;
    char *m_name;
    const Car *m_car;

  public:
    // Checks if the object is in a safe empty state.
    bool isEmpty() const;
    // Sets the customer to a safe empty state by setting the pointers to null and the id to 0.
    void setEmpty();
    // Deallocates the dynamically allocated memory
    void deallocateMemory();
    void set(int customerId, const char *name, const Car *car);
    void display() const;
    // Returns the car object pointed to by m_car pointer by dereferencing it.
    const Car &car() const;
  };
}

#endif