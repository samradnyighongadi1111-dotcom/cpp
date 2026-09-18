#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    void input() {
        cout << "Enter hours minutes seconds: ";
        cin >> hours >> minutes >> seconds;
    }

    Time add(Time t) {
        Time result;

        result.seconds = seconds + t.seconds;
        result.minutes = minutes + t.minutes;
        result.hours = hours + t.hours;

        if (result.seconds >= 60) {
            result.seconds -= 60;
            result.minutes++;
        }

        if (result.minutes >= 60) {
            result.minutes -= 60;
            result.hours++;
        }

        return result;
    }

    void display() {
        cout << setfill('0')
             << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds << endl;
    }
};

int main() {
    Time t1, t2, result;

    cout << "Enter first time:" << endl;
    t1.input();

    cout << "Enter second time:" << endl;
    t2.input();

    result = t1.add(t2);

    cout << "\nResultant Time = ";
    result.display();

    return 0;
}