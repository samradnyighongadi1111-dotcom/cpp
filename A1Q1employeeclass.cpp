#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int employeeID;
    string employeeName;
    string department;
    double basicSalary;

public:
    void inputDetails() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;

        cout << "Enter Employee Name: ";
        cin >> ws;
        getline(cin, employeeName);

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
    }

    double annualSalary() {
        return basicSalary * 12;
    }

    void displayDetails() {
        cout << "\n----- Employee Details -----" << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Employee Name: " << employeeName << endl;
        cout << "Department: " << department << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Annual Salary: " << annualSalary() << endl;
    }
};

int main() {
    Employee e;

    e.inputDetails();
    e.displayDetails();

    return 0;
}
