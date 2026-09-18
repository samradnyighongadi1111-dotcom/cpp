#include <iostream>
#include <string>
using namespace std;

class MobileRecharge {
private:
    string mobileNumber;
    double balance;

public:
    MobileRecharge(string number, double initialBalance) {
        mobileNumber = number;
        balance = initialBalance;
    }

    void recharge(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Recharge successful: Rs. "
                 << amount << endl;
        }
    }

    void deductBalance(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount deducted: Rs. "
                 << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display() {
        cout << "\n----- Mobile Details -----" << endl;
        cout << "Mobile Number: " << mobileNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};

int main() {
    MobileRecharge m("9876543210", 100);

    m.display();
    m.recharge(200);
    m.deductBalance(50);
    m.display();

    return 0;
}