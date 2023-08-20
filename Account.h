// file for the Account class
// this is dependent on Transaction.h and EndOfDayBalance.h

#pragma once

#include <string>
#include <vector>
#include <string>
#include "Transaction.h"
#include "EndOfDayBalance.h"

class Account 
{
    private:
        static int nextID;
        const int m_accountID;
        std::string  m_accountName;
        double m_accountBalance;
        std::vector<EndOfDayBalance> m_EODRecord;

    public:
        Account();
        Account(std::string);

        void setAccountName(std::string);
        std::string getAccountName() const;

        void addEODDay(int, int);

        void addTransaction(double amount, int month, int day);
        void listTransactions(); // this is a helper function. not sure how it will fit in
        void alterTransaction(int transactionNumber, double newAmount);

        double getAccountBalance() const;

        double getEODBalance(int month, int day);

        int getAccountID() const;


};

/*


+ makeEOD(): EndOfDayBalance
+ setAccountName(string): void
+ addTransaction(Transaction): void
+ getAccountName(): string
+ getAccountBalance(): double
+ getEOD(date/time): double
+ accessTransactions(???): Transaction
*/