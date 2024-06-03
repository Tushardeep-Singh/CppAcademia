// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_TOY_H
#define SENECA_TOY_H

#include <string>
#include <iostream>
#include <iomanip>

namespace seneca
{
  class Toy
  {
  private:
    int m_toyOrderId;
    std::string m_toyName;
    // Number of orders for this particular toy
    int m_toyOrders;
    double m_toyPrice;
    double m_toySalesTax;

  public:
    // Default Constructor
    Toy();
    // Updates the m_toyOrders member variable
    void update(const int &numItems);
    // 1-arg constructor
    Toy(const std::string &toy);
    // Removes leading and trailing spaces from the string
    void removeLeadTrailSpaces(std::string &str);
    // Getters
    int getToyId() const;
    std::string getToyName() const;
    int getToyOrders() const;
    double getToyPrice() const;
    double getSubTotal() const;
    double getTaxPaid() const;
    double getTotalPrice() const;
  };
  // Overloading the insertion operator
  std::ostream &operator<<(std::ostream &output, const Toy &outputToy);
}

#endif