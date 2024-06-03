// Author: Tushardeep Singh
// Seneca College Alumni

#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_

#include <iomanip>
#include <cmath>

namespace seneca
{
   const int ACCT_MAXLEN_USER = 16; // Max Length of user name

   // Class Definition
   class bankAccount
   {
   private:
      // Data Members
      char m_userName[ACCT_MAXLEN_USER];
      double m_funds;
      bool m_checking;
      int m_monthlyTransactions;
      // Transaction fees
      const double m_checkingTransactionFee = 1.25;
      const double m_savingTransactionFee = 3.50;
      // Interest rate
      const double m_checkingInterestRate = 0.5;
      const double m_savingInterestRate = 2.5;

      bool isOpen() const;

   public:
      // Constructor
      bankAccount(const char *name = nullptr, bool checking = false);
      bool setup(const char *name, bool checking);
      // Explicit to prevent implicit calls, cast operators
      explicit operator bool() const;
      explicit operator double() const;
      // Unary operators
      bankAccount& operator++();
      bankAccount& operator--();
      // Binary operators
      bool operator+= (double deposit);
      bool operator-= (double withdraw);
      bool operator== (const bankAccount& otherBankAcc) const;
      bool operator> (double value) const;
      bool operator<= (double value) const;
      bool operator<<(bankAccount& otherBankAcc);
      // Display the account details
      void display (void) const;
   };
   // Global helpers
   bool operator> (double lhs, const bankAccount& rhs);
   bool operator<= (double lhs, const bankAccount& rhs);
}
#endif
