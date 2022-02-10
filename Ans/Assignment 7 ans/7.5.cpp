#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

/*The key value of the map is the roll number and value field is that of score.
By default, the values of the map is stored in ascending order of the keys & 
duplicate key values are not overwritten.*/

int main()
{
	map<int,float> list;
	int roll,score,ch;
	map<int,float>::iterator it;
	
	while(1)
	{system("cls");
		cout<<"\nEnter choice:\n1.Initialise a student\n2.Display the students :";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter roll: ";
				cin>>roll;
				cout<<"Enter score: ";
				cin>>score;
				list.insert(pair<int, float>(roll, score));
				break;
			case 2:
				cout<<"Enter the roll to be searched: ";
				cin>>roll;
				it = list.find(roll);
				if(it!=list.end())
				{
					cout<<"Roll number: "<<roll<<", Score: "<<(*it).second<<"\n";
				}
				else
				{
					cout<<"Not found in the list\n";
				}
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
