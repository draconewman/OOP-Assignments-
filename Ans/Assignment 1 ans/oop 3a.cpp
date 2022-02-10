//Pointer to an array//
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b;
	printf("Enter row: ");
	scanf("%d",&a);
	printf("Enter column: ");
	scanf("%d",&b);
	
	int *(*ptr) [a], *arr[a], i,j;
	for(i=0;i<a;i++)
	{
		arr[i]= (int *)(malloc(sizeof(int)*b));
	}
	ptr=&arr;
	
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("Enter the elements: ");
			scanf("%d",(*((*ptr)+i)+j));
		}
	}
	printf("The elements are: ");
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
		{
			printf("\n");
			printf("%d\t",*(*((*ptr)+i)+j));
		}
	}
	free(arr[i]);
	return 0;
}
