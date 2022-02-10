#include<stdio.h>
#include<stdlib.h>
int size()
{
    int d;
    printf("Enter size of the array: ");
    scanf("%d",&d);
    return d;
}

int* allocation(int d)
{
    int* p=(int*)malloc(d*sizeof(int));
    return p;
}

void accept(int* p,int d)
{
    for(int i=0;i<d;i++)
	{
    	printf("Enter an element : ");
    	scanf("%d",&(*(p+i)));
	}
}

void print(int* p,int d)
{
	printf("\nYour array : \n");
    for(int i=0;i<d;i++)
	{
        printf("%d\t",*(p+i));
	}
}

int main()
{
    int *ptr;
    int n;
    n=size();
    ptr=allocation(n);
    accept(ptr,n);
    print(ptr,n);
    return 0;
}

