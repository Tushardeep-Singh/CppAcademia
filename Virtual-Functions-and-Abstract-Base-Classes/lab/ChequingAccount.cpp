// Author: Tushardeep Singh
// Seneca College Alumni

#include "./ChequingAccount.h"

namespace seneca
{
  ChequingAccount::ChequingAccount(double initialAccBal, double transactionFee, double monthEndFee) : Account(initialAccBal)
  {
    m_transactionFee = (transactionFee >= 0.0) ? transactionFee : 0.0;
    m_monthlyFee = (monthEndFee >= 0.0) ? monthEndFee : 0.0;
  }

  bool ChequingAccount::credit(double receivedAmt)
  {
    if (Account::credit(receivedAmt))
    {
      Account::debit(m_transactionFee);
      return true;
    }
    return false;
  }

  bool ChequingAccount::debit(double receivedAmt)
  {
    if (Account::debit(receivedAmt))
    {
      Account::debit(m_transactionFee);
      return true;
    }
    return false;
  }

  void ChequingAccount::monthEnd()
  {
    Account::debit(m_monthlyFee);
  }

  void ChequingAccount::display(std::ostream& output) const
  {
    output << "Account type: Chequing\n";
    output << "Balance: $";
    output << std::setprecision(2) << std::fixed << Account::balance();
    output << "\nPer Transaction Fee: ";
    output << std::setprecision(2) << std::fixed << m_transactionFee;
    output << "\nMonthly Fee: ";
    output << std::setprecision(2) << std::fixed << m_monthlyFee;
    output << '\n';
  }
}