#include <iostream>
using namespace std;
class Student{
 int roll; char name[25];
 public:
 void getdata(){cout<<"\nEnter Roll No : ";cin>>roll;cout<<"\nEnter Name : ";cin>>name;}
 void putdata(){cout<<"\nRoll No : "<<roll<<"\nName : "<<name<<endl;}
};
class StudentExam : public Student{
 public: int sub1,sub2,sub3,sub4,sub5,sub6; float per;
 void accept_data(){getdata();cout<<"\nEnter 6 sub marks : ";cin>>sub1>>sub2>>sub3>>sub4>>sub5>>sub6;}
 void display_data(){putdata();cout<<"\nMarks : "<<sub1<<" "<<sub2<<" "<<sub3<<" "<<sub4<<" "<<sub5<<" "<<sub6;}
};
class StudentResult : public StudentExam{
 public:
  void calculate(){per=(sub1+sub2+sub3+sub4+sub5+sub6)/6.0;cout<<"\nPercentage : "<<per<<endl;}
};
int main(){StudentResult s; s.accept_data(); s.display_data(); s.calculate(); return 0;}
