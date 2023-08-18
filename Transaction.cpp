// Matt Garcia
// Personal Finance App
// Transaction.h
// Header file for Transaction class

#include "Transaction.h"
#include <time.h>

int Transaction::nextID = {0};

Transaction::Transaction()
    : m_transactionID { nextID++ }, m_transactionTimeStamp { std::time(nullptr)}
{
    // default consturctor
}

Transaction::Transaction(double amount)
    : m_transactionID { nextID++ },
      m_transactionTimeStamp { std::time(nullptr)},
      m_transactionAmount { amount }
{
    //
}

Transaction::Transaction(double amount,int month, int day)
    : m_transactionID { nextID++ },
      m_transactionTimeStamp { std::time(nullptr)},
      m_transactionAmount { amount }
      
{
    // This needs to be cleaned up. Maybe abstracted into a function. 
    
    time_t now;
    struct tm * tempTimeInfo;
    time(&now);
    tempTimeInfo = localtime (&now);
    tempTimeInfo->tm_mon = month - 1; // the minus one is so jan can be entered with a 1 instead of a 0.
    tempTimeInfo->tm_mday = day;
    m_transactionTimeStamp = mktime(tempTimeInfo);
}

void Transaction::setAmount(double amount)
{
    m_transactionAmount = amount;
}

double Transaction::getAmount() const{
    return m_transactionAmount;
}

int Transaction::getID() const{
    return m_transactionID;
}

const std::time_t Transaction::getTimeStamp() const{
    return m_transactionTimeStamp;
}

Transaction Transaction::operator+(const Transaction &trans)
{
    return Transaction { getAmount() + trans.getAmount() };
}
