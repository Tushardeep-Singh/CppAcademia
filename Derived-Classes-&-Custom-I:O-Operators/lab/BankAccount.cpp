// Author: Tushardeep Singh
// Seneca College Alumni

#include "BankAccount.h"

namespace seneca
{
  // Getter
  double BankAccount::getBalance() const
  {
    return m_balance;
  }

  // Setter
  void BankAccount::setBalance(double balance)
  {
    m_balance = balance;
  }

  void BankAccount::writeCurrency(std::ostream &out, double amount) const
  {
    out << '$' << std::setprecision(2) << std::fixed << amount;
  }

  // Default constructor
  BankAccount::BankAccount()
  {
    strcpy(m_name, " ");
    m_balance = 0.0;
  }

  // Constructor
  BankAccount::BankAccount(const char *name, Date openDate, DepositInfo depInfo, double balance)
  {
    strcpy(m_name, name);
    m_openDate = openDate;
    m_depInfo = depInfo;
    m_balance = balance;
  }

  std::ostream &BankAccount::write(std::ostream &out) const
  {
    out << ">> " << m_name << " | ";
    std::cout << '$' << std::setprecision(2) << std::fixed << getBalance();
    std::cout << " | " << m_openDate.getYear() << '-';
    std::cout << std::setw(2) << std::setfill('0') << std::right << m_openDate.getMonth();
    std::cout << std::setfill(' ') << '-';
    std::cout << std::setw(2) << std::right << std::setfill('0') << m_openDate.getDay() << std::setfill(' ');
    std::cout << " | " << m_depInfo.getTransit() << ',' << m_depInfo.getInstitution() << ',' << m_depInfo.getAccount();

    return out;
  }

  std::istream &BankAccount::read(std::istream &in)
  {
    char tempLName[50];
    std::cout << "Name: ";
    in >> m_name >> tempLName;
    std::strcpy(m_name, std::strcat(std::strcat(m_name, " "), tempLName));
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Opening Balance: ";
    in >> m_balance;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Date Opened ";
    m_openDate.read(in);

    m_depInfo.read(in);
    return in;
  }

  std::istream &operator>>(std::istream &in, BankAccount &acct)
  {
    acct.read(in);
    return in;
  }

  std::ostream &operator<<(std::ostream &out, const BankAccount &acct)
  {
    acct.write(out);
    return out;
  }
}