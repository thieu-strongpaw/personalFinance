// Matt Garcia
// Personal Finance App
// Transaction.h
// Header file for Transaction class
// this class will hold the individual transactions for an Account

/* 
Last updated on 8/17/23
*/

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
    Transaction(double, int, int); // the two ints are for (month, day)
    void setAmount(double);
    int getID() const;
    double getAmount() const;
    const std::time_t getTimeStamp() const;
    Transaction operator+(const Transaction& trans);
};
