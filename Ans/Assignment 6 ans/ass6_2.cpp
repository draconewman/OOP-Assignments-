/*2.	Consider a class Student with roll, name and score as attributes. Support to take and display data is also there.  
One wants to works with array of Student objects. May collect data for array elements, display those. 
In case index goes out of bounds, exception is to be raised with suitable message.
*/

#include<iostream>
using namespace std;
int Student=0;
class student{
    public:
    string name;
    int roll;
    int score;
    void get_student_details()
    {
        cin.ignore();
        getline(cin,name);
        cin>>roll;
        cin>>score;
        Student++;
    }
    void show_students()
    {
        cout<<"NAME:\t"<<name<<"\t"<<"ROLL NUMBER:\t"<<roll<<"SCORE:\t"<<score<<"\n";
    }
};
student s[10000];

int main()
{
    int i=0;
    while(1)
    {
        int ch;
        cout<<"ENTER YOUR CHOICE:\n(0) Exit\n(1) Add number of student\n(2) Add student details\n(3) Show Student details\n(4) Enter index of a student\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"ENTER THE NUMBER OF STUDENT YOU WANT TO STORE\n";
            int n;
            cin>>n;
            cout<<"RECORDED\n";
            break;
            case 2:
            while(n!=0)
            {
                cout<<"ENTER THE DETAILS OF THE STUDENT\nNAME\nROLL\nSCORE\n";
                s[i].get_student_details();
                i++;
                n--;
            }
            break;
            case 3:
            cout<<"DETAILS OF"<<i<<"STUDENTS"<<"\n";
            for(int j=0;j<i;j++)
            {
                s[j].show_students();
            }
            break;
            case 4:
            cout<<"ENTER THE INDEX YOU WANT TO SEE FOR THE DETAILS OF A STUDENT\n";
            int a;
            cin>>a;
            if(a>=i)
            {
                cout<<"THIS NUMBER OF STUDENTS IS PRESENT\nSORRY TRY AGAIN\n";
                break;
            }
            else{
                s[a].show_students();
            }
            break;
            case 0:
            cout<<"THANK YOU\n\n\n";
            exit(0);
            break;
        }
    }
}
