#include <iostream>
using namespace std;

class student
{
    int roll,score;char name[40];
public:
    student(){score=-1;}
    void get_data()
    {
        cout<<"Enter roll:\n";cin>>roll;
        cout<<"Enter name:\n";cin>>name;
        cout<<"Enter score:\n";cin>>score;
    }
    void display()
    {
        cout<<"Name:"<<name<<"\n";cout<<"Roll:"<<roll<<"\n";cout<<"Score:"<<score<<"\n";
    }
    int check(int r)
    {
        if(r==roll)
            return(1);
        return(0);
    }
};

class studentlist
{
    student a[5];
    static int no_of_students;
public:
    void addstudent()  //::throw(char *)
    {
        if(no_of_students>=5)
            throw("List is full. No further elements can be inserted.\n");
        else
            a[no_of_students++].get_data();
    }
    void display()  //:throw(char *)
    {
        int r;
        cout<<"Enter roll number:\n";cin>>r;
        int j=0;
        while(j<no_of_students)
        {
            if(a[j].check(r))
            {
                a[j].display();
				return;
            }
            j++;
        }
        throw("Roll does not exist\n");
    }
}l;

int studentlist::no_of_students;
int main()
{
    while(1)
    {
        cout<<"(1)Insert students\n(2)Display information\n(3)Exit\n";
        int i;cin>>i;
        switch(i)
        {
        case(1):
            {
                try
                {
                    l.addstudent();
                }
                catch(char const * s)
                {
                    cout<<s;
                }
                break;
            }
        case(2):
            {
                try
                {
                    l.display();
                }
                catch(char const * s)
                {
                    cout<<s;
                }
                break;
            }
        case(3):
            return(0);
        }
    }
    return 0;
}
