// Author: Tushardeep Singh
// Seneca College Alumni

#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

namespace seneca
{
	// Default Constructor with default arguments
	bankAccount::bankAccount(const char *name, bool checking)
	{
		m_userName[0] = '\0'; // Empty string implies is account is not open
		setup(name, checking);
	}

	// Open bank account: setup can only be done once!
	bool bankAccount::setup(const char *name, bool checking)
	{
		if (isOpen())
			return false;
		if (name == nullptr)
			return false;

		strcpy(m_userName, name);
		m_monthlyTransactions = 0;
		m_checking = checking;
		m_funds = 0;
		return true;
	}

	// Account is open if user name string is not empty
	bool bankAccount::isOpen() const
	{
		return (m_userName[0] != '\0');
	}

	// Operator to see if account is open
	bankAccount::operator bool() const
	{
		return isOpen();
	}

	// Operator to get account funds
	bankAccount::operator double() const
	{
		return m_funds;
	}

	// Calculates interest and adds it to existing funds in the account
	bankAccount &bankAccount::operator++()
	{
		if (m_funds >= 0 && isOpen())
		{
			double interest;
			interest = m_checking ? (m_checkingInterestRate * m_funds) : (m_savingInterestRate * m_funds);
			m_funds += (interest / 100);
		}
		return *this;
	}

	// Calculates fees and subtracts it from existing funds in the account
	bankAccount &bankAccount::operator--()
	{
		if (isOpen())
		{
			double fees;
			fees = m_checking ? (m_checkingTransactionFee * m_monthlyTransactions) : (m_savingTransactionFee * m_monthlyTransactions);
			m_funds -= fees;
		}
		return *this;
	}

	// Deposits specified value by adding it to existing funds and increments the number of transactions
	bool bankAccount::operator+=(double deposit)
	{
		if (isOpen())
		{
			m_funds += deposit;
			++m_monthlyTransactions;
			std::cout << "Deposit $";
			std::cout << std::setprecision(2) << std::fixed << deposit;
			std::cout << " for " << m_userName << '\n';
			return true;
		}
		return false;
	}

	// Withdraws specified value by subtracting it from existing funds and increments the number of transactions
	bool bankAccount::operator-=(double withdraw)
	{
		if (isOpen())
		{
			m_funds -= withdraw;
			++m_monthlyTransactions;
			std::cout << "Withdraw $";
			std::cout << std::setprecision(2) << std::fixed << withdraw;
			std::cout << " for " << m_userName << '\n';
			return true;
		}
		return false;
	}

	// Checks if the specified bank account has the same user name, funds and type as this
	bool bankAccount::operator==(const bankAccount &otherBankAcc) const
	{
		return !strcmp(this->m_userName, otherBankAcc.m_userName) && fabs(this->m_funds - otherBankAcc.m_funds) < 0.001 && (this->m_checking == otherBankAcc.m_checking);
	}

	// Returns true if funds in this account > specified value
	bool bankAccount::operator>(double value) const
	{
		if (isOpen())
			return this->m_funds > value;
		return false;
	}

	// Returns true if funds in this account <= specified value
	bool bankAccount::operator<=(double value) const
	{
		if (isOpen())
			return this->m_funds <= value;
		return false;
	}

	// Transfer all funds from the otherBankAcc account to this account
	bool bankAccount::operator<<(bankAccount &otherBankAcc)
	{
		if (isOpen() && otherBankAcc.isOpen() && otherBankAcc.m_funds >= 0)
		{
			std::cout << "Transfer $";
			std::cout << std::setprecision(2) << std::fixed << otherBankAcc.m_funds;
			std::cout << " from " << otherBankAcc.m_userName << " to " << this->m_userName << '\n';
			*this += otherBankAcc.m_funds;
			otherBankAcc -= otherBankAcc.m_funds;
			return true;
		}
		return false;
	}

	// Displays the account details
	void bankAccount::display(void) const
	{
		if (isOpen())
		{
			std::cout << "Display Account -> User:";
			std::cout << std::setfill('-') << std::setw(16) << std::right << this->m_userName;
			std::cout << std::setfill(' ') << " | ";
			std::cout << std::setw(8) << std::right << (this->m_checking ? "Checking" : "Savings");
			std::cout << " | Balance: $";
			std::cout << std::setw(8) << std::right << std::setprecision(2) << std::fixed << this->m_funds;
			std::cout << " | Transactions:";
			std::cout << std::setfill('0') << std::setw(3) << std::right << this->m_monthlyTransactions;
			std::cout << std::setfill(' ') << '\n';
			return;
		}
		std::cout << "Display Account -> User:------- NOT OPEN\n";
	}

	// Global helper operators to support the case where the lhs is not a class and therefore not capable of having a method
	bool operator>(double lhs, const bankAccount &rhs)
	{
		return lhs > (double)rhs;
	}

	bool operator<=(double lhs, const bankAccount &rhs)
	{
		return lhs <= (double)rhs;
	}

}
