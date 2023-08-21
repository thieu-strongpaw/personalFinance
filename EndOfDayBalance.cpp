#include "EndOfDayBalance.h"

EndOfDayBalance::EndOfDayBalance(int month, int day)
    : m_date {}
{
    // make tm to hold month and day
    struct tm tempTime {};
    tempTime.tm_mon = month;
    tempTime.tm_mday = day;

    //convert tm to time_t
    m_date = mktime(&tempTime);
}

double EndOfDayBalance::getEODAmount() 
{
    m_eodAmount = 0;
    for(auto t : m_vectorOfTransaction){
        m_eodAmount += t.getAmount();
    }
    return m_eodAmount;
}

void EndOfDayBalance::listTransactions() const
{
    for (auto record : m_vectorOfTransaction){
        std::cout << "Record : " << record.getID() << " has " << record.getAmount() << std::endl;
    }
}

void EndOfDayBalance::addTransaction(Transaction newTransaction)
{
    m_vectorOfTransaction.push_back(newTransaction);
}

time_t EndOfDayBalance::getDate() const
{
    return m_date;
}

bool EndOfDayBalance::operator==(const EndOfDayBalance &rhs) const
{
    return (m_date == rhs.m_date);
}
