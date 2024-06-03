// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_BANK_ACCOUNT_H
#define SENECA_BANK_ACCOUNT_H

#include "DepositUtility.h"
#include <iomanip>

namespace seneca
{
  // Customer name length
  const size_t NAME_LENGTH = 50;

  class BankAccount
  {
  private:
    // Name of the person that owns the account
    char m_name[NAME_LENGTH];
    // Date the account was opened
    Date m_openDate;
    // Direct deposit information
    DepositInfo m_depInfo;
    // Current balance of the account
    double m_balance;

  protected:
    // Returns the current balance of the account
    double getBalance() const;
    // Sets the current balance of the account
    void setBalance(double balance);
    // Inserts into `out` a formatted dollar amount
    void writeCurrency(std::ostream &out, double amount) const;

  public:
    // Default constructor
    BankAccount();
    // Constructor that updates all of the data members of the object
    BankAccount(const char *name, Date openDate, DepositInfo depInfo, double balance);
    // Inserts into `out` the content of the object
    std::ostream &write(std::ostream &out) const;
    // Reads from the stream `in` the data for the current object
    std::istream &read(std::istream &in);
  };
  // Overload the extraction operator to extract a `BankAccount` from a stream
  std::istream &operator>>(std::istream &in, BankAccount &acct);
  // Overload the insertion operator to insert a `BankAccount` into a stream
  std::ostream &operator<<(std::ostream &out, const BankAccount &acct);
}

#endif