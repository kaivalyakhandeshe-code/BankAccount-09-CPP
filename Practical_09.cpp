
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class BankAccount
{
    int accountNumber;
    string accountHolder;
    double balance;

public:

    // Parameterized constructor
    BankAccount(int number, string name, double amount)
    {
        accountNumber = number;
        accountHolder = name;
        balance = amount;
    }

    // Move constructor
    BankAccount(BankAccount&& obj)
    {
        accountNumber = obj.accountNumber;
        accountHolder = std::move(obj.accountHolder);
        balance = obj.balance;

        // Reset source object
        obj.accountNumber = 0;
        obj.accountHolder.clear();
        obj.balance = 0;
    }

    // Move assignment operator
    BankAccount& operator=(BankAccount&& obj)
    {
        if (this != &obj)
        {
            accountNumber = obj.accountNumber;
            accountHolder = std::move(obj.accountHolder);
            balance = obj.balance;

            // Reset source object
            obj.accountNumber = 0;
            obj.accountHolder.clear();
            obj.balance = 0;
        }

        return *this;
    }

    // Display account details
    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main()
{
    int choice;
    int number;
    string name;
    double amount;

    do
    {
        cout << "\n===== BANK ACCOUNT MANAGEMENT =====" << endl;
        cout << "1. Demonstrate Move Constructor" << endl;
        cout << "2. Demonstrate Move Assignment" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nEnter source account number: ";
            cin >> number;

            cout << "Enter account holder name: ";
            cin >> name;

            cout << "Enter account balance: ";
            cin >> amount;

            BankAccount source(number, name, amount);

            cout << "\nSource Account Before Move:" << endl;
            source.display();

            // Move constructor
            BankAccount destination(std::move(source));

            cout << "\nDestination Account After Move:" << endl;
            destination.display();

            cout << "\nSource Account After Move:" << endl;
            source.display();
        }
        else if (choice == 2)
        {
            int sourceNumber, destinationNumber;
            string sourceName, destinationName;
            double sourceBalance, destinationBalance;

            cout << "\nEnter source account number: ";
            cin >> sourceNumber;

            cout << "Enter source account holder name: ";
            cin >> sourceName;

            cout << "Enter source account balance: ";
            cin >> sourceBalance;

            cout << "\nEnter destination account number: ";
            cin >> destinationNumber;

            cout << "Enter destination account holder name: ";
            cin >> destinationName;

            cout << "Enter destination account balance: ";
            cin >> destinationBalance;

            BankAccount source(sourceNumber, sourceName, sourceBalance);

            BankAccount destination(destinationNumber,
                                    destinationName,
                                    destinationBalance);

            cout << "\nSource Account Before Move:" << endl;
            source.display();

            cout << "\nDestination Account Before Move:" << endl;
            destination.display();

            // Move assignment operator
            destination = std::move(source);

            cout << "\nDestination Account After Move:" << endl;
            destination.display();

            cout << "\nSource Account After Move:" << endl;
            source.display();
        }
        else if (choice == 3)
        {
            cout << "\nExiting Program..." << endl;
        }
        else
        {
            cout << "\nInvalid Choice! Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}

