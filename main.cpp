// This is for testing
// main.cpp

#include <string>
#include "Transaction.h"
#include "EndOfDayBalance.h"
#include "Account.h"

int main(){

    // THis code tests Transaction

    Transaction testTrany1;
    Transaction testTrany2;
    testTrany1.setAmount(44.44);
    testTrany2.setAmount(77.43);
    Transaction testTrany3{20};
    Transaction testTrany4{ 33.33 };



    std::cout << testTrany1.getAmount() << " : " << testTrany1.getID() << std::endl;
    std::cout << testTrany2.getAmount() << " : " << testTrany2.getID() << std::endl;
    std::cout << testTrany3.getAmount() << " : " << testTrany3.getID() << std::endl;

    time_t printTemp (testTrany4.getTimeStamp());
    std::string readableDate;
    readableDate = ctime (&printTemp);
    std::cout << testTrany4.getAmount() << " : " << readableDate << std::endl;

    ////

    // The following code test Account

    Account testAcc1 {};
    Account testAcc2 { "Test Account 2" };
    std::cout << "This is the testAcc1 ID : " << testAcc1.getAccountID() << std::endl;
    std::cout << "This is the testAcc2 ID : " << testAcc2.getAccountID() << std::endl;

    testAcc1.addEODDay(1,1);
    testAcc1.addEODDay(1,1);
    
}