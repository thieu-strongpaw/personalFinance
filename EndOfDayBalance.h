// Component class of the Account class
// stores the end of day balance for the account

#pragma once
#include <vector>
#include <time.h>
#include "Transaction.h"

class EndOfDayBalance{
    private:
        double m_eodAmount;
        struct tm m_date;
        std::vector<Transaction> m_vectorOfTransaction;
        
    public:
        EndOfDayBalance()  = delete;
        EndOfDayBalance(int month, int day);
        double getEODAmount() ;
        void addTransaction(Transaction);
        struct tm getDate();

};



/*
- m_eodAmount: double
- m_eodTimeStamp: date/time

+ getEODAmount(): double
+ getEODTimeStamp(): date/time
*/