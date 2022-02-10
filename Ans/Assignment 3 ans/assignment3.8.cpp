#include<iostream>
using namespace std;

struct student
{
	int roll;
	int score;	
};

void input(struct student **a,struct student **temp)
{
	struct student *t;
	cout<<"Enter roll\n"<<endl;
	cin>>((*temp)->roll));
	cout<<"Enter score\n"<<endl;
	cin>>((*temp)->score));
	(*temp)->next=NULL;
	
	if(*a==NULL)
	{
		*a=*temp;
		return;
	}
	
	else
	{
		t=*a;
	}
	
	while(t->next!=NULL)
	{
		t=t->next;
	}
	cout<<"\n"<<endl;
	t->next=*temp;
}

void show(struct student *a)
{
	if(a==NULL)
	{
		cout<<"List is empty!!\n"<<endl;
		return;	
	}
	
	while(a!=NULL)
	{	
		cout<<(a->roll)<<endl;
		cout<<(a->score)<<endl;
		a=a->next;		
	}	
}

void modify()
{
	int i,u=0;
		cout<<"Press 1 to insert element\nPress 2 to delete last element\nPress 3 to display\nPress 4 to exit\n"<<endl;
		cin>>i;
		switch(i)
		{
			case(1):
			{
				temp=(struct student*)malloc(sizeof(struct student));
				input(&start,&temp);
				break;
		    }
		    case(2):
		    {
		    	del(&start);
		    	break;
			}
			case(3):
			{
				show(start);
				break;
			}
			case(4):
			{
				u++;
				while(start!=NULL)
				{
					d=start;
					start=start->next;
					free(d);
				}
				break;
			}
			default: cout<<"Wrong input!!"<<endl;
		}
		if(u==1)  break;
	}
}

main()
{
	struct student *start,*temp,*d;
	start=NULL;
	
}













