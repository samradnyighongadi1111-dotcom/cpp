#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int employeeID;
    string employeeName;
    double basicSalary;
    double HRA;
    double DA;

public:
    Employee() {
        employeeID = 0;
        employeeName = "Unknown";
        basicSalary = 0;
        HRA = 0;
        DA = 0;
    }

    Employee(int id, string name, double basic,
             double hra, double da) {
        employeeID = id;
        employeeName = name;
        basicSalary = basic;
        HRA = hra;
        DA = da;
    }

    double grossSalary() {
        return basicSalary + HRA + DA;
    }

    void display() {
        cout << "\n----- Employee Details -----" << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Employee Name: " << employeeName << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "HRA: " << HRA << endl;
        cout << "DA: " << DA << endl;
        cout << "Gross Salary: " << grossSalary() << endl;
    }

    ~Employee() {
        cout << "Employee object destroyed." << endl;
    }
};

int main() {
    Employee e(101, "Rahul", 30000, 5000, 3000);

    e.display();

    return 0;
}