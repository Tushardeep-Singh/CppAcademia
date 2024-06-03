// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_I_ACCOUNT_H
#define SENECA_I_ACCOUNT_H

#include <iostream>

namespace seneca
{
  class iAccount
  {
  public:
    // Pure virtual public member functions
    // Adds a positive amount to the account balance
    virtual bool credit(double) = 0;
    // Subtracts a positive amount from the account balance
    virtual bool debit(double) = 0;
    // Applies month-end transactions to the account
    virtual void monthEnd() = 0;
    // Inserts account information into an ostream object
    virtual void display(std::ostream &) const = 0;
    // Empty virtual destructor
    virtual ~iAccount(){};
  };
  // Creates the account with the starting balance and returns its address
  iAccount *CreateAccount(const char *, double);
}

#endif