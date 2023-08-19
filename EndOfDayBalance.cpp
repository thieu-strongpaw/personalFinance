#include "EndOfDayBalance.h"

EndOfDayBalance::EndOfDayBalance(int month, int day)
    : m_date {}
{
    m_date.tm_mon = month;
    m_date.tm_mday = day;
}

double EndOfDayBalance::getEODAmount() 
{
    m_eodAmount = 0;
    for(auto t : m_vectorOfTransaction){
        m_eodAmount += t.getAmount();
    }
    return m_eodAmount;
}

void EndOfDayBalance::addTransaction(Transaction newTransaction)
{
    m_vectorOfTransaction.push_back(newTransaction);
}

tm EndOfDayBalance::getDate()
{
    return m_date;
}
