#include <iostream>
using namespace std;

class Distance {
public:
    int feet, inch;

    // Constructor to initialize value
    Distance(int f, int i)
    {
        this->feet = f;
        this->inch = i;
    }

    // Overloading (-) unary operator to decrement
    void operator-()
    {
        feet--;
        inch--;
        cout << "\nFeet & Inches(Decrement): " << feet << "'" << inch;
    }
};

int main()
{
    Distance d1(8, 9);
    
    // Use (-) unary operator
    -d1;
    
    return 0;
}