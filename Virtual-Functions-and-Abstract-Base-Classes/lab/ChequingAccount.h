// Author: Tushardeep Singh
// Seneca College Alumni

#ifndef SENECA_CHEQUING_ACCOUNT_H
#define SENECA_CHEQUING_ACCOUNT_H

#include "./Account.h"
#include <iomanip>

namespace seneca
{
  class ChequingAccount : public Account
  {
  private:
    double m_transactionFee;
    double m_monthlyFee;

  public:
    // Constructor
    ChequingAccount(double initialAccBal, double transactionFee, double monthEndFee);
    // Credits the balance by the amount received
    bool credit(double receivedAmt);
    // Debits the balance by the amount received
    bool debit(double receivedAmt);
    // Debits the monthly fee from the balance
    void monthEnd();
    void display(std::ostream &output) const;
  };
}

#endif