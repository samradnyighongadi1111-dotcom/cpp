#include <iostream>
using namespace std;

class Time
{
    int hours, minutes, seconds;

public:
    void getTime()
    {
        cout << "Enter hours, minutes and seconds: ";
        cin >> hours >> minutes >> seconds;
    }

    Time add(Time t2)
    {
        Time t3;

        t3.seconds = seconds + t2.seconds;
        t3.minutes = minutes + t2.minutes;
        t3.hours = hours + t2.hours;

        if (t3.seconds >= 60)
        {
            t3.seconds = t3.seconds - 60;
            t3.minutes++;
        }

        if (t3.minutes >= 60)
        {
            t3.minutes = t3.minutes - 60;
            t3.hours++;
        }

        return t3;
    }

    void display()
    {
        cout << "Time = " << hours << " hours "
             << minutes << " minutes "
             << seconds << " seconds";
    }
};

int main()
{
    Time t1, t2, t3;

    t1.getTime();
    t2.getTime();

    t3 = t1.add(t2);

    t3.display();

    return 0;
}