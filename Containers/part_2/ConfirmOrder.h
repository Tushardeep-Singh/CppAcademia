// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_CONFIRM_ORDER_H
#define SENECA_CONFIRM_ORDER_H

#include "Toy.h"

namespace seneca
{
  class ConfirmOrder
  {
  private:
    // Array storing address of Toys
    const Toy *(*m_toysArr){nullptr};
    // Number of toys stored in m_toysArr
    int m_numOfToys{0};

  public:
    // Default constructor
    ConfirmOrder();
    // Overloading '+=' : adds the toy `toy` to the array by adding its address.
    ConfirmOrder &operator+=(const Toy &toy);
    // Getter: returns m_numOfToys
    int getNumOfToys() const;
    // Setter: sets m_numOfToys to param num
    void setNumOfToys(const int &num);
    // Searches if param toy exists in array m_toysArr
    bool lookForToy(const Toy &toy) const;
    // Overloading '-=' : removes the toy `toy` from the array by removing its address
    ConfirmOrder &operator-=(const Toy &toy);
    // Returns m_toysArr[index]
    const Toy *operator[](const int &index) const;
    // Destructor
    ~ConfirmOrder();
    // Copy constructor
    ConfirmOrder(const ConfirmOrder &copyFromConfirmOrder);
    // Copy assignment operator
    ConfirmOrder &operator=(const ConfirmOrder &copyFromConfirmOrder);
    // Move constructor
    ConfirmOrder(ConfirmOrder &&moveFromConfirmOrder);
    // Move assignment operator
    ConfirmOrder &operator=(ConfirmOrder &&moveFromConfirmOrder);
  };
  // Overloading the insertion operator
  std::ostream &operator<<(std::ostream &output, const ConfirmOrder &outputOrder);
}

#endif