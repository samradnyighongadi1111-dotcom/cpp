#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productID;
    string productName;
    int quantity;
    double unitPrice;

public:
    void inputDetails() {
        cout << "Enter Product ID: ";
        cin >> productID;

        cout << "Enter Product Name: ";
        cin >> ws;
        getline(cin, productName);

        cout << "Enter Quantity: ";
        cin >> quantity;

        cout << "Enter Unit Price: ";
        cin >> unitPrice;
    }

    double totalCost() {
        return quantity * unitPrice;
    }

    void displayDetails() {
        cout << "\n----- Product Details -----" << endl;
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Unit Price: " << unitPrice << endl;
        cout << "Total Cost: " << totalCost() << endl;
    }
};

int main() {
    Product p;

    p.inputDetails();
    p.displayDetails();

    return 0;
}