#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    int patientID;
    string name;
    int age;
    double consultationCharge;

public:
    void registerPatient() {
        cout << "Enter Patient ID: ";
        cin >> patientID;

        cout << "Enter Patient Name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Consultation Charge: ";
        cin >> consultationCharge;
    }

    void display() {
        cout << "\n----- Patient Details -----" << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Consultation Charge: "
             << consultationCharge << endl;
    }
};

int main() {
    Patient p;

    p.registerPatient();
    p.display();

    return 0;
}