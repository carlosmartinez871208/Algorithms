/*
** Encapsulation in C++
** Encapsulation is one of the fundamental principles of object-oriented programming (OOP) 
** that bundles data (attributes) and methods (functions) that operate on the data into a 
** single unit called a class, while restricting direct access to some of the object's components.
**
** Key Aspects of Encapsulation in C++
** Data Hiding: Making class members private to prevent direct external access
** Controlled Access: Providing public methods to interact with private data
** Implementation Hiding: Keeping internal workings hidden from users of the class
*/

#include <iostream>
#include <string.h>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

class BankAccount
{
    private:
        std::string accountHolder;
        double balance;
    public:
        BankAccount(const std::string&holder,double initialBalance):accountHolder(holder),balance(initialBalance){}
        void deposit(double amount)
        {
            if(amount>0)
            {
                balance+=amount;
                std::cout<<"Deposited $"<<amount<<std::endl;
            }
        }
        bool withdraw(double amount)
        {
            if((amount>0)&&(balance>=amount))
            {
                balance-=amount;
                std::cout<<"Withdrew $"<<amount<<std::endl;
                return true;
            }
            std::cout<<"Withdrawal failed"<<std::endl;
            return false;
        }
        double getBalance() const
        {
            return balance;
        }
        std::string getAccountHolder() const
        {
            return accountHolder;
        }
        void setAccountHolder(const std::string& holder)
        {
            if(!holder.empty())
            {
                accountHolder=holder;
            }
        }
};

int main (int argc, char** argv)
{
    BankAccount account("Ninmah Martinez",10000.00);
    account.deposit(4000.0);
    if(!account.withdraw(15000.0))
    {
        std::cout<<"Insufficient funds for withdraw."<<std::endl;
    }
    account.withdraw(350.0);
    std::cout<<"Current balance: $"<<account.getBalance()<<std::endl;
    account.setAccountHolder("Ninmah Martinez Rubio");
    return EXIT_SUCCESS;
}