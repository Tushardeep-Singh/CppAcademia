// Author: Tushardeep Singh
// Seneca College Alumni

#include "./Account.h"

namespace seneca
{
  Account::Account(double receivedBal)
  {
    m_currBalance = (receivedBal <= 0.0) ? 0.0 : receivedBal;
  }

  bool Account::credit(double receivedAmt)
  {
    m_currBalance += (receivedAmt >= 0.0) ? receivedAmt : 0;
    return receivedAmt >= 0;
  }

  bool Account::debit(double receivedAmt)
  {
    m_currBalance -= (receivedAmt >= 0.0) ? receivedAmt : 0;
    return receivedAmt >= 0.0;
  }

  double Account::balance() const
  {
    return m_currBalance;
  }

  Account::~Account() {}
}