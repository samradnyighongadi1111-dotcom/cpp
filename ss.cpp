#include <iostream>
using namespace std;

class Student
{
    int roll;
    char name[25];
public:
    void getdata()
    {
        cout << "\n -----------------------------------------";
        cout << "\n Enter Roll No. : ";
        cin >> roll;
        cout << "\n Enter Student Name : ";
        cin >> name;
    }
    void putdata()
    {
        cout << "\n -----------------------------------------";
        cout << "\n ********** Student Marklist **********";
        cout << "\n -----------------------------------------";
        cout << "\n Roll No. : " << roll;
        cout << "\n Student Name : " << name << endl;
    }
};

class StudentExam : public Student
{
    public:


    int sub1, sub2, sub3, sub4, sub5, sub6;
    float per;
    void accept_data()
    {
        getdata();
        cout << "\n Enter Marks for Subject 1 : "; cin >> sub1;
        cout << "\n Enter Marks for Subject 2 : "; cin >> sub2;
        cout << "\n Enter Marks for Subject 3 : "; cin >> sub3;
        cout << "\n Enter Marks for Subject 4 : "; cin >> sub4;
        cout << "\n Enter Marks for Subject 5 : "; cin >> sub5;
        cout << "\n Enter Marks for Subject 6 : "; cin >> sub6;
    }
    void display_data()
    {
        putdata();
        cout << "\n Marks of Subject 1 : " << sub1;
        cout << "\n Marks of Subject 2 : " << sub2;
        cout << "\n Marks of Subject 3 : " << sub3;
        cout << "\n Marks of Subject 4 : " << sub4;
        cout << "\n Marks of Subject 5 : " << sub5;
        cout << "\n Marks of Subject 6 : " << sub6;
    }
};

class StudentResult : public StudentExam
{
public:
    void calculate()
    {
        per = (sub1 + sub2 + sub3 + sub4 + sub5 + sub6) / 6.0;
        cout << "\n\n Total Percentage : " << per;
        cout << "\n ----------------------------------------- \n";
    }
};

int main()
{
    StudentResult str;
    int cnt;
    cout << "\n Enter No. of Students You Want? : ";
    cin >> cnt;
    for(int i=0;i<cnt;i++)
    {
        str.accept_data();
        str.display_data();
        str.calculate();
    }
 
    return 0;
}

// ===== INHERITANCE ACCESS - 9 COMBINATIONs=====


//
//--- 1. BASE = public ---
//a) class Child : public Base
   // public -> public
   // Inside child: YES (as public)
   // From main() d.mem: YES

//b) class Child : protected Base
   // public -> protected
   // Inside child: YES (as protected)
   // From main() d.mem: NO (becomes protected)

//c) class Child : private Base
   // public -> private
   // Inside child: YES (as private)
   // From main() d.mem: NO (becomes private)

//--- 2. BASE = protected ---

//d) class Child : public Base
   // protected -> protected
   // Inside child: YES (as protected)
   // From main() d.mem: NO (protected never from main)

//e) class Child : protected Base
   // protected -> protected
   // Inside child: YES (as protected)
   // From main() d.mem: NO

//f) class Child : private Base
   // protected -> private
   // Inside child: YES (as private)
   // From main() d.mem: NO

//--- 3. BASE = private ---
//g) class Child : public Base
   // private -> NOT ACCESSIBLE
   // Inside child: NO
   // From main() d.mem: NO

//h) class Child : protected Base
   // private -> NOT ACCESSIBLE
   // Inside child: NO
   // From main() d.mem: NO

//i) class Child : private Base
   // private -> NOT ACCESSIBLE
   // Inside child: NO
   // From main() d.mem: NO
