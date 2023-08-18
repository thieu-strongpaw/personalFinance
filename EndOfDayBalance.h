// Component class of the Account class
// stores the end of day balance for the account

#pragma once

#include <time.h>

class EndOfDayBalance{
    private:
        double m_eodAmount;
        time_t m_date;
    public:
        EndOfDayBalance() = delete;
        EndOfDayBalance(double);
        double getEODAmount() const;
        void updateEOD(double);

};



/*
- m_eodAmount: double
- m_eodTimeStamp: date/time

+ getEODAmount(): double
+ getEODTimeStamp(): date/time
*/