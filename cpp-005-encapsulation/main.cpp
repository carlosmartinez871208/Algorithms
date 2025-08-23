/*
** Encapsulation in C++
** Encapsulation is one of the fundamental principles of object-oriented programming (OOP) that bundles 
** data (attributes) and methods (functions) that operate on that data into a single unit called a class, 
** while restricting direct access to some of the object's components.
** 
** Key Aspects of Encapsulation in C++
** Data Hiding: Making class members private to prevent direct external access
** Controlled Access: Providing public methods to interact with private data
** Implementation Hiding: Keeping internal workings hidden from users of the class
** 
** Benefits of Encapsulation
** Increased Security: Prevents unauthorized access and modification of data
** Maintainability: Internal implementation can change without affecting code that uses the class
** Flexibility: Allows adding validation or logging when accessing/modifying data
** Modularity: Classes become self-contained units with clear interfaces
** Encapsulation helps create more robust and maintainable code by preventing direct manipulation of an object's 
** internal state and ensuring all interactions go through controlled channels.
*/
#include <iostream>
#include <string>

#ifndef EXIT_SUCCESS
 #define EXIT_SUCCESS 0u
#endif

class BankAccount
{
    private:
        double balance;
        std::string accountNumber;
    public:
        BankAccount(std::string AccNum, double initBalance)
        {
            accountNumber = AccNum;
            balance       = initBalance;
        }
        void deposit(double amount)
        {
            if(0<amount)
            {
                balance += amount;
            }
            else{/*Do nothing*/}
        }
        bool withdraw(double amount)
        {
            if((0 < amount) && (balance >= amount))
            {
                balance -= amount;
                return true;
            }
            else{/*Do nothing*/}
            return false;
        }
        double getBalance() const
        {
            return balance;
        }
        std::string getAccountNumber() const
        {
            return accountNumber;
        }
};

int main (int argc, char** argv)
{
    BankAccount Carlos = BankAccount("ABCH7812",5000000);
    std::cout<<"Carlos Account Number: "<< Carlos.getAccountNumber()<<std::endl;
    std::cout<<"Carlos Account Balance: "<< Carlos.getBalance()<<std::endl;
    return EXIT_SUCCESS;
}