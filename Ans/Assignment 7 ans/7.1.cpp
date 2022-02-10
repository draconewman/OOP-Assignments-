#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class Student
{
	static int c;
	string name;
	int roll;
	float score;
	public:
		int ret_roll() const
		{
			return roll;
		}
		int ret_score() const
		{
			return score;
		}
		void initialise();// To create a new Student.
		void display(); //To display the student details.
		friend class get_stu; //Function object to check if a given substring is present in the name.
		friend class not_get_stu; //Function object to check if a given substring is not present in the name.
};

//A vector of Student Objects is created in main.
int Student::c = 1;
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

//Function object to display student details of a given roll number.
class is_roll
{
	int r;
	public:
		is_roll(int k)
		{
			r=k;
		}
		bool operator()(Student s) const
		{
			return (s.ret_roll() ==r);
		}
};

//Boolean function to compare the scores of two students.
bool is_max(const Student s1,const Student s2) 
{
	return (s1.ret_score()<s2.ret_score());
}

//Checks if a given substring is present in the Name of the student.
//Friend class of Student.
class get_stu
{
	string s;
	public:
		get_stu(string l)
		{
			s=l;
		}
		void operator()(Student s1) const 
		{
			if(s1.name.find(s)!= string::npos)
				s1.display();
		}
};

//Checks if a given substring is present in the Name of the student.
//Friend class of Student.
class not_get_stu
{
	string s;
	public:
		not_get_stu(string l)
		{
			s=l;
		}
		void operator()(Student s1) const 
		{
			if(s1.name.find(s)== string::npos)
				s1.display();
		}
};

int main()
{
	vector<Student> v1,v2,v3;
	Student s;
	string str;
	vector<Student>::iterator it;
	int ch,r;
	while(1)
	{
		system("cls");
		cout<<"\nChoice:\n1.Enter a student\n2.Display entire List\n3.Enter a roll Number to display\n4.Display Student with Highest Score\n5.Check for Substring in the names :";
		cin>>ch;
		switch(ch)
		{
			case 1:
				s.initialise();
				v1.push_back(s);
				v2.push_back(s);
				break;
			case 2:
				cout<<"Students are:\n";
				for(it= v1.begin();it!=v1.end();++it)
					it->display();
				getchar();
				getchar();
				break;
			case 3:
				cout<<"Enter roll to be displayed: ";
				cin>>r;
				it = find_if(v1.begin(),v1.end(),is_roll(r));
				if(it!= v1.end())
					it->display();
				else
					cout<<"Roll not found.\n";
				getchar();
				getchar();
				break;
			case 4:
				cout<<"The student with highest score \n";
				it =  max_element(v1.begin(),v1.end(),is_max);
				it->display();
				getchar();
				getchar();
				break;	
			case 5 :
				cout<<"Enter the substring to be found: ";
				getchar();
				getline(cin,str);
				cout<<"Student with the given substring in their names\n ";
				for_each(v1.begin(),v1.end(),get_stu(str));
				cout<<"Student not having the given substring in their names\n ";
				for_each(v1.begin(),v1.end(),not_get_stu(str));
				getchar();
				break;
			default:
				cout<<"Ending...";
				exit(0);
		}
	}
	return 0;
}
	
