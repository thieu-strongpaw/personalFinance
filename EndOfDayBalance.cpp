#include "EndOfDayBalance.h"

EndOfDayBalance::EndOfDayBalance(double amount)
{
    m_date = time(nullptr);
    m_eodAmount = amount;
}

double EndOfDayBalance::getEODAmount() const
{
    return m_eodAmount;
}

void EndOfDayBalance::updateEOD(double amount)
{
    m_eodAmount += amount;
}
