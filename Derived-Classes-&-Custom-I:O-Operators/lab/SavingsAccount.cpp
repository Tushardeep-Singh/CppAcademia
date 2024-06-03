// Author: Tushardeep Singh
// Seneca College Alumni

#include "SavingsAccount.h"

namespace seneca
{
  void SavingsAccount::writeInterest(std::ostream &out) const
  {
    out << std::setprecision(3) << std::fixed << m_interest;
    out << "%";
  }

  SavingsAccount::SavingsAccount(const char *name, Date openDate, DepositInfo depInfo, double balance, double interest, Date interestDate) : BankAccount(name, openDate, depInfo, balance)
  {
    m_interest = interest;
    m_interestDate = interestDate;
  }

  void SavingsAccount::applyInterest(Date &dt)
  {
    std::cout << "   " << '$';
    std::cout << std::setprecision(2) << std::fixed << getBalance();
    std::cout << " + ";
    writeCurrency(std::cout, static_cast<double>(getBalance() * m_interest));
    std::cout << " (";
    writeInterest(std::cout);
    std::cout << ") = $";
    setBalance(static_cast<double>((getBalance() * m_interest) + getBalance()));
    std::cout << std::setprecision(2) << std::fixed << getBalance();
    std::cout << " | ";
    m_interestDate.write(std::cout);
    std::cout << " => ";
    m_interestDate = dt;
    dt.write(std::cout);
    std::cout << '\n';
  }

  std::ostream &SavingsAccount::write(std::ostream &out) const
  {
    BankAccount::write(std::cout);
    std::cout << " | ";
    writeInterest(out);
    std::cout << " | ";
    std::cout << m_interestDate;

    return out;
  }

  std::ostream &operator<<(std::ostream &out, const SavingsAccount &acct)
  {
    acct.write(out);
    return out;
  }

  std::istream &operator>>(std::istream &in, SavingsAccount &acct)
  {
    acct.read(in);
    return in;
  }

  std::istream &SavingsAccount::read(std::istream &in)
  {
    BankAccount::read(in);
    std::cout << "Interest Date ";
    m_interestDate.read(in);
    std::cout << "Interest Rate: ";
    std::cin >> m_interest;
    return in;
  }
}