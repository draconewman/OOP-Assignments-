#include<stdio.h>
#include<stdlib.h>
struct student
{
	int roll;
	char name[40];
	int score;	
	struct student* next;
};

void input(struct student **a,struct student **temp)
{
	struct student *t;
	printf("Enter roll\n");
	scanf("%d",&((*temp)->roll));
	printf("Enter name\n");
	scanf("%s",&((*temp)->name));
	printf("Enter score\n");
	scanf("%d",&((*temp)->score));
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
	printf("\n");
	t->next=*temp;
}

void del(struct student **a)
{
	struct student *t,**d;
	t=*a;
	
	if(*a==NULL)
	{
		printf("Nothing to delete!!\n");
		return;
	}
	
	if(((*a)->next)==NULL)
	{
		*a=NULL;
		free(t);
		return;
	}
	
	while(t->next->next!=NULL)
	{
		t=t->next;
	}
	
	*d=(t->next);
	(t->next)=NULL;
	free(*d);
}

void display(struct student *a)
{
	if(a==NULL)
	{
		printf("List is empty!!\n");
		return;	
	}
	
	while(a!=NULL)
	{	
		printf("%d\t",a->roll);
		printf("%s\t",a->name);
		printf("%d\n",a->score);
		a=a->next;		
	}	
}

int main()
{
	struct student *start,*temp,*d;
	start=NULL;
	while(1)
	{
		int i,u=0;
		printf("Press 1 to insert element\nPress 2 to delete last element\nPress 3 to display\nPress 4 to exit\n");
		scanf("%d",&i);
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
				display(start);
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
			default: printf("Wrong input!!");
		}
		if(u==1)  break;
	}
	return 0;	
}
