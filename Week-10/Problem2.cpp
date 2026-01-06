#include <iostream>
using namespace std;

class EWallet {
private:
    string walletID;
    string userName;
    double balance;

public:

    EWallet() {
        walletID = "";
        userName = "";
        balance = 0;
        cout << "Default wallet created with zero balance." << endl;
    }

    EWallet(string name, string id) {
        userName = name;
        walletID = id;
        balance = 0;
        cout << "Wallet created for user " << name 
             << " with no initial balance." << endl;
    }

    EWallet(string name, string id, double bal) {
        userName = name;
        walletID = id;

        if (bal < 0) {
            balance = 0;
            cout << "Invalid initial amount! Balance set to 0." << endl;
        } else {
            balance = bal;
            cout << "Wallet created with initial balance for user " 
                 << name << "." << endl;
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!" << endl;
            return;
        }
        balance += amount;
        cout << "Amount deposited successfully!" << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
            return;
        }
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        }
    }

    void showDetails() const {
        cout << "User Name: " << userName << endl;
        cout << "Wallet ID: " << walletID << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    EWallet A;
    EWallet B("Ali", "W1001");
    EWallet C("Abaid", "W2001", 500);
    C.deposit(200);
    B.withdraw(50);

    A.showDetails();
    B.showDetails();
    C.showDetails();

    return 0;
}