// Author: Tushardeep Singh
// Seneca College Alumni

#include "./SavingsAccount.h"

namespace seneca
{
  SavingsAccount::SavingsAccount(double initialAccBal, double interestRate) : Account(initialAccBal)
  {
    m_interestRate = (interestRate >= 0.0) ? interestRate * 100 : 0.0;
  }

  void SavingsAccount::monthEnd()
  {
    double interestEarned = Account::balance() * m_interestRate / 100;
    Account::credit(interestEarned);
  }

  void SavingsAccount::display(std::ostream& output) const
  {
    output << "Account type: Savings\n";
    output << "Balance: $";
    output << std::setprecision(2) << std::fixed << Account::balance();
    output << '\n';
    output << "Interest Rate (%): ";
    output << std::setprecision(2) << std::fixed << m_interestRate;
    output << '\n';
  } 

  SavingsAccount::~SavingsAccount() {}
}