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
};

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

//Function object to check for a given roll number.
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

/*This is simply a boolean function used in merging two vetcors
The system does not know how to merge two user-defined vectors, so this comparator function is used
If true is returned, second list + first list
If fasle is returned , as below, first list + second list*/
bool comp_stu(const Student s1,const Student s2)
{
	return false;
}

//Compare the roll number to sort the vector in descending order of roll numbers.
bool compare_student(const Student s1,const Student s2)
{
	return (s1.ret_roll()>s2.ret_roll());
}

int main()
{
	vector<Student> v1,v2,v3;
	Student s;
	string str;
	vector<Student>::iterator it;
	int ch,r;
	while(1)
	{	system("cls");
		cout<<"\nChoice:\n1.Enter a student\n2.Display entire List\n3.Enter a roll Number to delete\n4.Enter a roll Number to display\n5.Display the first list in descending order of roll numbers.\n6.Merge two lists :";
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
				for(it= v1.begin(); it!=v1.end(); ++it)
					it->display();
				getchar();
				getchar();
				break;
			case 3:
				cout<<"Enter roll to be deleted: ";
				cin>>r;
				it = find_if(v1.begin(),v1.end(),is_roll(r));
				if(it!= v1.end())
					v1.erase(it);
				else
					cout<<"Roll not found.\n";
				getchar();
				getchar();
				break;
			case 4:
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
			case 5:
				cout<<"The list in descending order of roll numbers:\n";
				sort(v1.begin(),v1.end(),compare_student);
				for(it= v1.begin();it!=v1.end();++it)
					it->display();
				getchar();
				break;
			case 6:
				v3.resize(v1.size()+v2.size());
				merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin(),comp_stu);
				for(it= v3.begin();it!=v3.end();++it)
					it->display();
				getchar();
				getchar();	
				break;
		}
	}
return 0;
}
