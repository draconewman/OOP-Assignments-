#include <iostream>
#define MAXIMUM 100
using namespace std;

class student
{
	private:
    	int roll;
		char name[30],
		course[50];
		int marks[5],date[8];
	public:
	    static int number;
	    void admission();
	    void receivemarks();
	    void preparemarksheet();
	    student()
		    {
		        int j;
		        for(j=0;j<5;j++)
		        marks[j]=-1;
		        roll=-1;
		    }
};

int student::number;
void student::admission()
{
    int j;
	roll=number+1;
    cout<<"Enter name\n";
    cin>>name;
    cout<<"Enter Course Name\n";
    cin>>course;
    cout<<"Your roll is "<<roll<<endl;
    cout<<"Enter admission Date(ddmmyyyy)\n";
    for(j=0;j<8;j++)
	{
		cin>>date[j];
	}
	number++;
	cout<<"\n\n";
}

void student::receivemarks()
{
    int j;
	if(roll==-1)
	{
		cout<<"Not a valid roll\n"<<endl;
		return;
	}
	cout<<"Enter marks\n";
	for(j=0;j<5;j++) 	cin>>marks[j];
}

void student::preparemarksheet()
{
    int total=marks[0]+marks[1]+marks[2]+marks[3]+marks[4];
	if(total<0)
	{
		cout<<"Candidate with roll "<<roll<<" has not given exams yet\n"<<endl;
		return;
	}
    cout<<"Roll: "<<roll<<endl;
	cout<<"Department: "<<course<<endl;
	cout<<"NAME: "<<name<<endl;
    
	int j;
    for(j=0;j<5;j++)
    {
        cout<<"subject "<<j+1<<endl;
		cout<<": "<<marks[j]<<endl;
    }
    cout<<"\n";
    for(j=0;j<100;j++)
        cout<<"-";
    cout<<"\n";
    cout<<"Total "<<total<<endl;
}

student arr[MAXIMUM];
int main()
{
    while(1)
    {
        cout<<"(1)admission\n(2)number of stdents\n(3)receive marks\n(4)prepare marksheet\n(5)Exit\n"<<endl;
        int i,u=0;
		cin>>i;
        switch(i)
        {
            case(1):
            {
               arr[student::number].admission();
			   continue;
            }
            case(2):
            {
                cout<<"There are "<<(student::number)<<" student(s)\n"<<endl;
				continue;
            }
            case(3):
            {
                cout<<"Enter roll of the student\n"<<endl;
				int i;
				cin>>i;
                arr[i-1].receivemarks();
				continue;
            }
            case(4):
            {
               cout<<"Enter roll of the student\n"<<endl;
			   int i;
			   cin>>i;
               arr[i-1].preparemarksheet();
			   continue;
            }
            case(5):
            {
            	u++;
               break;
            }
        }
            if(u==1)
                break;
    }
    return 0;
}
