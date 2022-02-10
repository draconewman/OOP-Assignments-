#include<stdio.h>

int main()
{
		int a, *p, **pp;
		printf("enter the value of a : ");
		scanf("%d",&a);
		p=&a;
		printf("Value of a using p is : %d\n",*p);
		pp=&p;
		printf("Value of a using pp is : %d\n",**pp);
		return 0;
}
