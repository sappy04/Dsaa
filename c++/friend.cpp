#include<iostream>
using namespace std;
class BankAccount
{
private:
    int balance;

public:
    // Other member functions and constructors

    friend class BankManager;
};

class BankManager
{
public:
    int changeInterestRate(BankAccount &account, double newRate)
    {
        // Access the private member 'balance' of the BankAccount class
        account.balance += 1000; // Example operation
        cout<<account.balance<<endl;
        // Other operations related to changing the interest rate
    }

    int generateMonthlyStatement(const BankAccount &account)
    {
        // Access the private member 'balance' of the BankAccount class
        double currentBalance = account.balance;
        cout<<currentBalance<<endl;
        // Generate the monthly statement
    }
};
int main()
{
    BankManager b;
    b.changeInterestRate(12);
    b.generateMonthlyStatement(100);
}