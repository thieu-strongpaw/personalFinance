// Component class of the Account class
// stores the end of day balance for the account

#pragma once
#include <vector>
#include <time.h>
#include "Transaction.h"

class EndOfDayBalance{
    private:
        double m_eodAmount;
        std::time_t m_date;
        std::vector<Transaction> m_vectorOfTransaction;
        
    public:
        EndOfDayBalance()  = delete;
        EndOfDayBalance(int month, int day);
        double getEODAmount() ;
        void listTransactions() const;
        void addTransaction(Transaction);
        time_t getDate() const;
        [[nodiscard]] bool operator==(const EndOfDayBalance &rhs) const;

};


