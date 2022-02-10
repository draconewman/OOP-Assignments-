#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<utility>
using namespace std;

class Student
{
	static int c;
	char name[100];
	int roll;
	int score;
	public:
		//Accessor function to return the score of a student 
		//to save as key of the map.
		int	ret_roll() const
		{
			return roll;
		}
		
		void initialise(const char*,int);	//To initialise a student
		void display();   //To display the student details.
};

int Student::c = 1;
//The roll numbers of the students is auto-generated using the static variable.

void Student::initialise(const char* n,int s)
{
	roll = c;
	c++;
	strcpy(name,n);
	score=s;
}

void Student::display()
{
	cout<<"Roll: "<<roll<<"\n";
	cout<<"Name: "<<name<<"\n";
	cout<<"Score: "<<score<<"\n";
}

int main()
{
	queue<int> roll_numbers;
	pair<int,Student> p;
	int n,k;
	Student s;
	map<int, Student> students;
	map<int, Student> :: iterator it;
	
	s.initialise("Ajay Ray",450);
	p= make_pair(s.ret_roll(),s);
	students.insert(p);
	
	s.initialise("Bimal Ghosh",439);
	p= make_pair(s.ret_roll(),s);
	students.insert(p);
	
	s.initialise("Chirantan Das",458);
	p= make_pair(s.ret_roll(),s);
	students.insert(p);
	
	s.initialise("Debjit Sarkar",468);
	p= make_pair(s.ret_roll(),s);
	students.insert(p);
	
	s.initialise("Gitan Bose",432);
	p= make_pair(s.ret_roll(),s);
	students.insert(p);
	
	s.initialise("Manoj Kumar",488);
	p= make_pair(s.ret_roll(),s);
	students.insert(p);
	
	//Assumed that the roll numbers entered are valid.			
	cout<<"Enter roll numbers: \n";
	for(int i=0;i<6;i++)
	{
		cin>>n;
		roll_numbers.push(n);
	}
	
	//Queue
	while(!roll_numbers.empty())
	{
		k = roll_numbers.front();
		roll_numbers.pop();
		students[k].display();
	}
	return 0;
}
