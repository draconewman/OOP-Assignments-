#include<iostream>
#include<string.h>
using namespace std;

class applicant
{
	static int last_id;
	int score;
	int id;
	char name[31];
	public:
		applicant()
		{
			score=0;
			id=0;
			
		}
		applicant(int s,char n[31])
		{
			applicant::last_id++;
			id=applicant::last_id;
			score=s;
			strcpy(name,n);
					//getdata(int s,char n[31]);
		}
		void getdata(int s,char n[31]);   //take score and name and stores the values in score and name
		void showdetails();    //print id, name, score
		static void show_no_of_applicant();    //print number of applicants
};

int applicant::last_id=0;    //initialising static int variable id......here id is independent of objects

//take score and name and stores the values in score and name
void applicant::getdata(int s,char n[31])
{
	applicant::last_id++;
	id=applicant::last_id;
	score=s;
	strcpy(name,n);
	cout<<"Your id is  "<<applicant::last_id;
}

//print num. of applicant
void applicant::show_no_of_applicant()
{
	cout<<"Total number of Applicants : "<<applicant::last_id++;
	return;
}

//print out id num. name score
void applicant::showdetails()
{
	cout<<"id = "<<id<<endl<<"Name = "<<name<<endl<<"Score = "<<score<<endl;
}

int main()
{
	applicant a[100];
	int i=0;
	while(1)
	{
		cout<<"\n\nEnter 0. to exit \nEnter 1. to input data \nEnter 2. to show details \nEnter 3. to know the number of applicants   :\nYour choice    ";
		char ch;
		cin>>ch;
		switch(ch)
		{
			case '0':return 0;
			case '1': {
				char name[31];
				int score;
				cout<<"Enter the details of the applicant----------\nEnter name----";
				fflush(stdin);
				cin>>name;
				cout<<"\nEnter score-------";
				cin>>score;
				a[i].getdata(score,name);
				i++;
				break;
			}
			case '2':{
				cout<<"Enter the id for details   ";
				int id;
				cin>>id;
				a[id-1].showdetails();
				break;
			}
			case '3':{
				applicant::show_no_of_applicant();
				break;}
			
			default: cout<<"Wrong input!!";
					return 1;
			
		}
	}

	return 0;
}
