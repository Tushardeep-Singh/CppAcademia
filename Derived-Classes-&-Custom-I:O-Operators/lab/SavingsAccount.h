// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_SAVINGS_ACCOUNT_H
#define SENECA_SAVINGS_ACCOUNT_H

#include "BankAccount.h"

namespace seneca
{
  class SavingsAccount : public BankAccount
  {
  private:
    // Current interest rate of the account
    double m_interest;
    // Holds the date interest was last applied to the account
    Date m_interestDate;
    // Inserts into `out` interest rate
    void writeInterest(std::ostream &out) const;

  public:
    // Constructor updates all data members of the object
    SavingsAccount(const char *name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate);
    // Increases the account balance by the amount of interest
    void applyInterest(Date &dt);
    // Inserts into `out` the content of the object
    std::ostream &write(std::ostream &out) const;
    // Reads from the stream `in` the data for the current object
    std::istream &read(std::istream &in);
  };
  // Insertion operator overload
  std::ostream &operator<<(std::ostream &out, const SavingsAccount &acct);
  // Extraction operator overload
  std::istream &operator>>(std::istream &in, SavingsAccount &acct);
}

#endif