#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
/*A map is used as the container.
The key of the map is the score of the student and the value is a student object.
map<int, Student,greater<int> > ; greater<int> has been used as it helps in storing the student details 
in descending order of the keys, i.e, the score of the student.*/

class Student
{
	static int c;
	string name;
	int roll;
	int score;
	public:
		//Accessor function to return the score of a student 
		//to save as key of the map.
		int	ret_score() const
		{
			return score;
		}
		
		void initialise();	//To initialise a student
		void display(); //To display the student details.
};

int Student::c = 1;
//The roll numbers of the students is auto-generated using the static variable.


void Student::initialise()
{
	roll = c;
	c++;
	getchar();
	cout<<"Enter Name: ";
	getline(cin,name);
	cout<<"Enter Score: ";
	cin>>score;
	getchar();
}

void Student::display()
{
	cout<<"Roll: "<<roll<<"\n";
	cout<<"Name: "<<name<<"\n";
	cout<<"Score: "<<score<<"\n";
}

int main()
{
	int ch;
	pair<int,Student> p;
	Student s;
	map<int, Student, greater<int> > students;
	map<int,Student> :: iterator it;
	while(1)
	{	system("cls");
		cout<<"\nChoice:\n1.Initialise a student\n2.Display the students : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				s.initialise();
				p= make_pair(s.ret_score(),s);
				students.insert(p);
				break;
			case 2:
				for(it=students.begin(); it!=students.end(); ++it)
					it->second.display();
				getchar();
				getchar();
				break;
			default:
				cout<<"Ending...";
				exit(0);
		}
	}
	return 0;
}
