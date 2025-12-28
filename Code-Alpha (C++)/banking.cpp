#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    Transaction(string t, double a) : type(t), amount(a) {}
};

class Account {
public:
    int id;
    double balance;
    vector<Transaction> history;
    Account(int i) : id(i), balance(0.0) {}

    void deposit(double amt) {
        balance += amt;
        history.push_back(Transaction("Deposit", amt));
    }

    bool withdraw(double amt) {
        if (amt > balance) return false;
        balance -= amt;
        history.push_back(Transaction("Withdraw", amt));
        return true;
    }

    bool transfer(Account& to, double amt) {
        if (!withdraw(amt)) return false;
        to.deposit(amt);
        history.push_back(Transaction("Transfer Out", amt));
        to.history.push_back(Transaction("Transfer In", amt));
        return true;
    }

    void showHistory() {
        for (auto& t : history) {
            cout << t.type << ": " << t.amount << endl;
        }
    }
};

class Customer {
public:
    string name;
    int id;
    Account* account;
    Customer(string n, int i, Account* a) : name(n), id(i), account(a) {}
};

int main() {
    Account acc1(1);
    Account acc2(2);
    Customer cust1("Simaab", 1, &acc1);
    Customer cust2("Friend", 2, &acc2);

    acc1.deposit(1000);
    acc1.transfer(acc2, 200);
    acc1.withdraw(100);

    cout << "Customer: " << cust1.name << "\nBalance: " << acc1.balance << endl;
    cout << "Transaction History:\n";
    acc1.showHistory();

    cout << "\nCustomer: " << cust2.name << "\nBalance: " << acc2.balance << endl;
    cout << "Transaction History:\n";
    acc2.showHistory();

    return 0;
}