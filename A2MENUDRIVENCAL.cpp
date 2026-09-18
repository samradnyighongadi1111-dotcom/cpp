#include <iostream>
using namespace std;

int main() {
    int choice;
    int a, b;

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5) {
            cout << "Enter two numbers: ";
            cin >> a >> b;
        }

        switch (choice) {
            case 1:
                cout << "Addition = " << a + b << endl;
                break;

            case 2:
                cout << "Subtraction = " << a - b << endl;
                break;

            case 3:
                cout << "Multiplication = " << a * b << endl;
                break;

            case 4:
                if (b != 0)
                    cout << "Division = " << (double)a / b << endl;
                else
                    cout << "Cannot divide by zero." << endl;
                break;

            case 5:
                if (b != 0)
                    cout << "Modulus = " << a % b << endl;
                else
                    cout << "Cannot divide by zero." << endl;
                break;

            case 6:
                cout << "Program exited." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}


