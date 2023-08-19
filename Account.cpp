#include "Account.h"
#include <utility>

int Account::nextID = {};

Account::Account()
    : m_accountID { nextID++ },
      m_accountName {},
      m_accountBalance {}
{
    //
}

void Account::setAccountName(std::string name)
{
    m_accountName = name;
}

std::string Account::getAccountName() const
{
    return m_accountName;
}

void Account::addEODDay()
{
    
}

void Account::addTransaction(double amount, int month, int day)
{
    
    
}
