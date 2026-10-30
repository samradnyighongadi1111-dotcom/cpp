#include <iostream>
#include <vector>
#include <string>
using namespace std;

// CLASS: VEHICLE - The class is used to store vehicle details
class Vehicle {
private:
    string vehicleNo;
    string ownerName;
    int batteryPer;

public:
    Vehicle() {
        vehicleNo = "";
        ownerName = "";
        batteryPer = 0;
    }
    Vehicle(string vNo, string oName, int bPer) {
        vehicleNo = vNo;
        ownerName = oName;
        batteryPer = bPer;
    }
    void inputVehicle() {
        cout << "Enter Vehicle No: ";
        cin >> vehicleNo;
        cout << "Enter Owner Name: ";
        cin >> ownerName;
        cout << "Enter Battery % : ";
        cin >> batteryPer;
    }
    string getVehicleNo() { return vehicleNo; }
    string getOwnerName() { return ownerName; }
    int getBattery() { return batteryPer; }
    void displayVehicle() {
        cout << "\tVehicle No: " << vehicleNo << " | Owner: " << ownerName << " | Battery: " << batteryPer << "%" << endl;
    }
};

// CLASS: CHARGING SLOT
class ChargingSlot {
private:
    int slotId;
    bool isOccupied;
    Vehicle parkedVehicle;

public:
    ChargingSlot() {
        slotId = 0;
        isOccupied = false;
    }
    ChargingSlot(int id) {
        slotId = id;
        isOccupied = false;
    }
    int getSlotId() { return slotId; }
    bool getStatus() { return isOccupied; }

    void assignVehicle(Vehicle v) {
        if (!isOccupied) {
            parkedVehicle = v;
            isOccupied = true;
            cout << "Vehicle " << v.getVehicleNo() << " assigned to Slot " << slotId << endl;
        } else {
            cout << "Slot " << slotId << " is already occupied!" << endl;
        }
    }
    void releaseSlot() {
        if (isOccupied) {
            cout << "Vehicle " << parkedVehicle.getVehicleNo() << " removed from Slot " << slotId << endl;
            isOccupied = false;
        } else {
            cout << "Slot " << slotId << " is already empty!" << endl;
        }
    }
    void displaySlot() {
        cout << "Slot ID: " << slotId << " | Status: " << (isOccupied ? "Occupied" : "Available");
        if (isOccupied) {
            cout << endl;
            parkedVehicle.displayVehicle();
        } else {
            cout << endl;
        }
    }
};

// CLASS: CHARGING STATION
class ChargingStation {
private:
    string stationName;
    vector<ChargingSlot> slots;
    int totalSlots;

public:
    ChargingStation(string name, int n) {
        stationName = name;
        totalSlots = n;
        for (int i = 1; i <= n; i++) {
            slots.push_back(ChargingSlot(i));
        }
    }
    void showAllSlots() {
        cout << "\n--- " << stationName << " - Slot Status ---" << endl;
        for (int i = 0; i < totalSlots; i++) {
            slots[i].displaySlot();
        }
    }
    void bookSlot() {
        Vehicle v;
        v.inputVehicle();
        for (int i = 0; i < totalSlots; i++) {
            if (!slots[i].getStatus()) {
                slots[i].assignVehicle(v);
                return;
            }
        }
        cout << "All slots are full! Cannot book." << endl;
    }
    void vacateSlot() {
        int id;
        cout << "Enter Slot ID to vacate (1-" << totalSlots << "): ";
        cin >> id;
        if (id >= 1 && id <= totalSlots) {
            slots[id - 1].releaseSlot();
        } else {
            cout << "Invalid Slot ID!" << endl;
        }
    }
};

int main() {
    ChargingStation station("DYP CET EV Station", 5);
    int choice;

    do {
        cout << "\n===== EV Charging Station Management System =====" << endl;
        cout << "1. Show All Slots" << endl;
        cout << "2. Book Slot for Vehicle" << endl;
        cout << "3. Vacate Slot" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: station.showAllSlots(); break;
            case 2: station.bookSlot(); break;
            case 3: station.vacateSlot(); break;
            case 4: cout << "Thank you!" << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}