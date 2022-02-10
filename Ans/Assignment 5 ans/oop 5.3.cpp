#include <iostream>
using namespace std;

class Employee
{
protected: 
    int id;float basicpay;
    char name[31],designation[50];
public:
    Employee()
    {
        getdata();
    }
    virtual calculatesalary()=0;
	void getdata();
    float getbasicpay();
};

void Employee:: getdata()
{
    cout<<"Enter employee id:\n";cin>>id;
    cout<<"Enter employee basicpay:\n";cin>>basicpay;
    cout<<"Enter employee name:\n";cin>>name;
    cout<<"Enter employee designation:\n";cin>>designation;
}

float Employee:: getbasicpay()
{
    return(basicpay);
}

class Parmanent:public Employee
{
public:
    calculatesalary()
    {
        float x;x=getbasicpay();
        cout<<" Salary of parmanent employee is:"<<x+(3*x/10)+(8*x/10)<<"\n";
    }
};

class Contractual:public Employee
{
	protected:
    float a;
public:
    Contractual()
        {
            cout<<"Enter allowance\n";cin>>a;
        }
    calculatesalary()
    {
        float x;x=getbasicpay();
        cout<<" Salary of contractual employee is:"<<x+a<<"\n";
    }
};

int main()
{
    while(1)
    {
        cout<<"(1)Calculate salary of parmanent employee\n(2)Calculate salary of contractual employee\n(3)Exit\n";
        int i;cin>>i;
        switch(i)
        {
            case(1):
                {
                    Employee *b;Parmanent p;
                    b=&p;
                    b->calculatesalary();break;
                }
            case(2):
                {
                    Employee *b;Contractual t;
                    b=&t;
                    b->calculatesalary();break;
                }
            case(3):
                {
                    return(0);
                }

        }
    }

    return 0;
}
