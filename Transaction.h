// Matt Garcia
// Personal Finance App
// Transaction.h
// Header file for Transaction class
// this class will hold the individual transactions for an Account

#pragma once

#include <iostream>
#include <memory>
#include <ctime>

class Transaction
{
private:
    static int nextID;
    const int m_transactionID;
    double m_transactionAmount {};
    std::time_t m_transactionTimeStamp; 

public:
    Transaction();
    Transaction(double);
    Transaction(double, int, int);
    void setAmount(double);
    int getID() const;
    double getAmount() const;
    const std::time_t getTimeStamp() const;
    Transaction operator+(const Transaction& trans);
};
/* 
Transaction operator+(const Transaction& lhs, const Transaction& rhs){
    return Transaction { lhs.getAmount() + rhs.getAmount() };
} */




/*
- m_transactionID: intjj
- m_transactionAmount: double
- m_transactionTimeStamp: date/time

+ getAmount(): double
+ getID(): int
+ getTimeStamp(): date/time
+ setAmount(double): void
- setTime/Stamp: void
- setID: void
*/