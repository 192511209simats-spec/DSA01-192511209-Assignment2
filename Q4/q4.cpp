#include <iostream>
using namespace std;

class SavingsAccount {
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;

    void addTransaction(double amount) {
        if (count < 10) {
            transactions[count] = amount;
            ++count;
        } else {
            // Discard the oldest transaction by shifting the remaining entries.
            for (int i = 0; i < 9; ++i) {
                transactions[i] = transactions[i + 1];
            }
            transactions[9] = amount;
        }
    }

public:
    SavingsAccount(int accountNo, double initialBalance)
        : accountNumber(accountNo), balance(initialBalance), count(0) {}

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount\n";
            return;
        }
        balance += amount;
        addTransaction(amount);
        cout << "Deposited: " << amount << '\n';
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            cout << "Invalid withdrawal\n";
            return;
        }
        balance -= amount;
        addTransaction(-amount);
        cout << "Withdrawn: " << amount << '\n';
    }

    void miniStatement() const;
};

void SavingsAccount::miniStatement() const {
    cout << "\nACCOUNT NUMBER: " << accountNumber << '\n';
    cout << "BALANCE: " << balance << '\n';
    cout << "\nLAST TRANSACTIONS:\n";

    for (int i = 0; i < count; ++i) {
        if (transactions[i] > 0) {
            cout << "Deposit: " << transactions[i] << '\n';
        } else {
            cout << "Withdrawal: " << transactions[i] << '\n';
        }
    }
}

int main() {
    SavingsAccount account(1001, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);
    account.miniStatement();

    cout << "\nTEST: MORE THAN 10 TRANSACTIONS\n";
    SavingsAccount testAccount(1002, 10000);
    for (int i = 1; i <= 12; ++i) {
        testAccount.deposit(i * 100);
    }
    testAccount.miniStatement();

    return 0;
}
