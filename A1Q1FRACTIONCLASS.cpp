#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
    }

public:
    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;

        cout << "Enter denominator: ";
        cin >> denominator;
    }

    Fraction add(Fraction f) {
        Fraction result;

        result.numerator =
            numerator * f.denominator +
            f.numerator * denominator;

        result.denominator =
            denominator * f.denominator;

        result.simplify();
        return result;
    }

    Fraction subtract(Fraction f) {
        Fraction result;

        result.numerator =
            numerator * f.denominator -
            f.numerator * denominator;

        result.denominator =
            denominator * f.denominator;

        result.simplify();
        return result;
    }

    void display() {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1, f2, sum, difference;

    cout << "Enter first fraction:" << endl;
    f1.input();

    cout << "\nEnter second fraction:" << endl;
    f2.input();

    sum = f1.add(f2);
    difference = f1.subtract(f2);

    cout << "\nAddition = ";
    sum.display();

    cout << "Subtraction = ";
    difference.display();

    return 0;
}