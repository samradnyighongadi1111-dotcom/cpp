#include<iostream>
using namespace std;
class Distance{
    public:
    int feet ,inch;
    //constructor to initialize the objects value
    Distance(int f,int i)
    {
        this->feet=f;
        this->inch=i;
    }
    //overloading(-) operator to perform decrement operation of distant object 
    void operator ()
{
 feet --;
 inch--;
 cout<<"\nFeet & Inches(Decrement):"<<
 feet <<""<<inch;

}
};

int main()
{
    Distance d1(8,9);
    -d1; 
    return 0;
}