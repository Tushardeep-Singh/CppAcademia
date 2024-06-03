// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H

#include "./iAccount.h"

namespace seneca
{
  class Account : public iAccount
  {
  private:
    // Current balance
    double m_currBalance;

  public:
    // Default constructor
    Account(double receivedBal);
    // Receives an amount to be credited to the account balance
    bool credit(double receivedAmt);
    // Receives an amount to be debited from the account balance
    bool debit(double receivedAmt);
    // Empty Destructor
    ~Account();
  protected:
    // Getter: returns the current balance of the account
    double balance() const;
  };
}

#endif