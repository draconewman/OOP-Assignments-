#include<stdio.h>
#include<stdlib.h>
struct des
{
	 int age;
	 char name[30];
};

struct des* list(struct des* info,int n)
{
	 info=(struct des*)malloc(n*sizeof(struct des));
	 return info;
}

struct des* input(struct des* info,int n)
{
	 int i;
	 for(i=0;i<n;i++)
	 {  
	  printf("enter the age of the %dth student\t",(i+1));
	  scanf("%d",&info[i].age);
	  getchar();
	  printf("name\t");
	  fgets(info[i].name,30,stdin);
	 }
	return info;
}

struct des* sort(struct des* info,int n)
{
	int i,j;
	 for(i=0;i<n-1;i++)
	 {
	  for(j=0;j<n-i-1;j++)
	  {
	   if(info[j].age>info[j+1].age)
	   {
	    struct des temp;
	    temp=info[j];
	    info[j]=info[j+1];
	    info[j+1]=temp; 
	   }
	  }
	 }
 return info;
}

void output(struct des* info,int n)
{
	 printf("***************************\nage\tname\n****************************\n");
	  int i;
	 for(i=0;i<n;i++)
	 {
	 printf("%d\t",info[i].age);
	 puts(info[i].name);
	 }
}

int main()
{
	 int n;
	 printf("enter the number of students\t");
	 scanf("%d",&n);
	 struct des test={};
	 struct des *info=&test;
	 info=list(info,n);
	 info=input(info,n);
	 info=sort(info,n);
	 output(info,n);
	 return 0;
}
