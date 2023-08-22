#include "Account.h"
#include <utility>
#include <ctime>
#include <algorithm>

int Account::nextID = {};

Account::Account()
    : m_accountID { nextID++ },
      m_accountName {},
      m_accountBalance {}
{
    //
}

Account::Account(std::string name)
    : m_accountID { nextID++ },
      m_accountName { name },
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

void Account::addEODDay(int month, int day)
{
    // make a temp EndOfDayBalance to compare
    EndOfDayBalance EODtoCompare { month, day };
           
    std::cout << "Trying to make a new EOD bal." << std::endl;    
    auto iter = std::find(m_EODRecord.begin(), m_EODRecord.end(), EODtoCompare);
    if (m_EODRecord.end() == m_EODRecord.begin()) { 
        m_EODRecord.push_back(EODtoCompare); 
        std::cout << "Non in list\nEODBalance ID : " << m_accountID << " : was made" << std::endl;
    }else if(iter == m_EODRecord.end()){
        EndOfDayBalance newBalance{ month, day };
        m_EODRecord.push_back( newBalance );
        std::cout << "not found make new\nEODBalance ID : " << m_accountID << " : was made" << std::endl;
    }else{
        std::cout << "-- It did not push to vector." << std::endl;
    }       
    
}

void Account::addTransaction(double amount, int month, int day)
{
    Transaction transToAdd { amount, month, day };
    EndOfDayBalance EODtoCompare { month, day };
    auto iter = std::find(m_EODRecord.begin(), m_EODRecord.end(), EODtoCompare);
    
    if (m_EODRecord.end() == m_EODRecord.begin()) { 
        addEODDay(month, day);
        addTransaction(amount, month, day);
        m_accountBalance += amount;
    }else if(iter != m_EODRecord.end()){
        iter->addTransaction(transToAdd);
        m_accountBalance += amount;
    }else if(iter != m_EODRecord.end()){
    }else{
        std::cout << "-- It did not push the transaciton to EOD." << std::endl;
    }       
}

void Account::listTransactions(int month, int day)
{
    EndOfDayBalance EODtoCompare { month, day };
    auto iter = std::find(m_EODRecord.begin(), m_EODRecord.end(), EODtoCompare);
    if (m_EODRecord.end() == m_EODRecord.begin()) { 
        std::cout << "No records" << std::endl;
    }else if(iter != m_EODRecord.end()){
        iter->listTransactions();
    }else{
        std::cout << "EOD date not found. " << std::endl;
    };
}

double Account::getAccountBalance() const
{
    return m_accountBalance;
}

double Account::getEODBalance(int month, int day)
{
    double bal{};
    EndOfDayBalance EODtoCompare { month, day };
    auto iter = std::find(m_EODRecord.begin(), m_EODRecord.end(), EODtoCompare);
    if (m_EODRecord.end() == m_EODRecord.begin()) { 
        std::cout << "No EOD record empty. " << std::endl;
    }else if(iter != m_EODRecord.end()){
        for(auto record : m_EODRecord){
            bal += record.getEODAmount();
        }
    }else{
        std::cout << "EOD date not found. " << std::endl;
    };
    return bal;
}

int Account::getAccountID() const
{
    return m_accountID;
}
