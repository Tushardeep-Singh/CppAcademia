// Author: Tushardeep Singh
// Seneca College Alumni

#include "Toy.h"

namespace seneca
{
  Toy::Toy()
  {
    // Set to default values
    m_toyOrderId = 0;
    m_toyName = "";
    m_toyOrders = 0;
    m_toyPrice = 0.0;
    m_toySalesTax = 0.13;
  }

  void Toy::update(const int &numItems)
  {
    m_toyOrders = numItems;
  }

  void Toy::removeLeadTrailSpaces(std::string &str)
  {
    std::string strCopy = str;
    int start, end;
    for (int i = 0; i < strCopy.length(); ++i)
      if (strCopy[i] != ' ')
      {
        start = i;
        break;
      }

    for (int i = strCopy.length() - 1; i >= 0; --i)
      if (strCopy[i] != ' ' && strCopy[i] != ':')
      {
        end = i;
        break;
      }

    str = strCopy.substr(start, end - start + 1);
  }

  Toy::Toy(const std::string &toy)
  {
    int idx1 = toy.find_first_of(":");
    std::string utils = toy.substr(0, idx1 + 1);
    removeLeadTrailSpaces(utils);
    m_toyOrderId = std::stoi(utils);

    int idx2 = toy.find_first_of(":", idx1 + 1);
    utils = toy.substr(idx1 + 1, idx2 - idx1);
    removeLeadTrailSpaces(utils);
    m_toyName = utils;

    int idx3 = toy.find_first_of(":", idx2 + 1);
    utils = toy.substr(idx2 + 1, idx3 - idx2);
    removeLeadTrailSpaces(utils);
    m_toyOrders = std::stoi(utils);

    utils = toy.substr(idx3 + 1, toy.length() - idx3);
    m_toyPrice = std::stod(utils);

    m_toySalesTax = 0.13;
  }

  int Toy::getToyId() const
  {
    return m_toyOrderId;
  }

  std::string Toy::getToyName() const
  {
    return m_toyName;
  }

  int Toy::getToyOrders() const
  {
    return m_toyOrders;
  }

  double Toy::getToyPrice() const
  {
    return m_toyPrice;
  }

  double Toy::getSubTotal() const
  {
    return m_toyPrice * m_toyOrders;
  }

  double Toy::getTaxPaid() const
  {
    return m_toySalesTax * getSubTotal();
  }

  double Toy::getTotalPrice() const
  {
    return getTaxPaid() + getSubTotal();
  }

  std::ostream &operator<<(std::ostream &output, const Toy &outputToy)
  {
    output << "Toy";
    output << std::setw(8) << outputToy.getToyId();
    output << ':';
    output << std::setw(18) << std::right << outputToy.getToyName();
    output << std::setw(3) << std::right << outputToy.getToyOrders();
    output << " items";
    output << std::setw(8) << std::right << outputToy.getToyPrice();
    output << "/item  subtotal:";
    output << std::setw(7) << std::right << outputToy.getSubTotal();
    output << " tax:";
    output << std::setw(6) << std::right << std::setprecision(2) << std::fixed << outputToy.getTaxPaid();
    output << " total:";
    output << std::setw(7) << std::right << std::setprecision(2) << std::fixed << outputToy.getTotalPrice();
    output << '\n';

    return output;
  }
}