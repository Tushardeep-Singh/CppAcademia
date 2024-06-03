// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_SAVINGS_ACCOUNT_H
#define SENECA_SAVINGS_ACCOUNT_H

#include "./Account.h"
#include <iomanip>

namespace seneca
{
  class SavingsAccount : public Account
  {
  private:
    // Interest rate that applies to the account
    double m_interestRate;

  public:
    // Constructor
    SavingsAccount(double initialAccBal, double interestRate);
    // Calculates the interest earned on the current balance and credits the account with that interest
    void monthEnd();
    void display(std::ostream &output) const;
    // Empty Destructor
    ~SavingsAccount();
  };
}

#endif