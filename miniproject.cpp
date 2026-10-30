#include <iostream>
using namespace std;

class Food {
protected:
    string name;
    int price;

public:
    Food(string n, int p) {
        name = n;
        price = p;
    }

    virtual void display() {
        cout << name << " Rs." << price << endl;
    }

    virtual ~Food() {}
};

class VegFood : public Food {
public:
    VegFood(string n, int p) : Food(n, p) {}

    void display() override {
        cout << "Veg ";
        Food::display();
    }
};

class NonVegFood : public Food {
public:
    NonVegFood(string n, int p) : Food(n, p) {}

    void display() override {
        cout << "Non-Veg ";
        Food::display();
    }
};

class Restaurant {
public:
    virtual void menu() = 0;
};

class Order : public Restaurant {
private:
    int total = 0;

public:
    void menu() override {
        cout << "\n1. Burger - Rs.100";
        cout << "\n2. Pizza - Rs.200";
        cout << "\n3. Sandwich - Rs.80";
        cout << "\n4. Chicken Burger - Rs.150\n";
    }

    void add(int p) {
        total += p;
    }

    void add(int p, int q) {
        total += p * q;
    }

    void bill() {
        cout << "\nTotal Bill: Rs." << total;

        if (total >= 500) {
            cout << "\nDiscount: Rs." << total * 10 / 100;
            total -= total * 10 / 100;
        }

        cout << "\nFinal Bill: Rs." << total << endl;
    }
};

int main() {
    Order o;
    VegFood v("Burger", 100);
    NonVegFood n("Chicken Burger", 150);

    v.display();
    n.display();
    o.menu();

    int choice, quantity, price;

    while (true) {
        cout << "\nEnter choice (0 to finish): ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice == 1) price = 100;
        else if (choice == 2) price = 200;
        else if (choice == 3) price = 80;
        else if (choice == 4) price = 150;
        else {
            cout << "Invalid choice!\n";
            continue;
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        if (quantity <= 0) {
            cout << "Invalid quantity!\n";
            continue;
        }

        o.add(price, quantity);
    }

    o.bill();
    return 0;
}