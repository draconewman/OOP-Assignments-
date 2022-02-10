#include<stdio.h>
#include<stdlib.h>
int main()
{
		int *p,n,i;
		printf("Enter the size of array : ");
		scanf("%d",&n);
		
		p=(int*)malloc(n*sizeof(int));
		for(i=0;i<n;i++)
		{
			printf("Enter the elements of the array : ");
			scanf("%d",&p[i]);
		}
		
		printf("The elements of the array are : ");
		for(i=0;i<n;i++)
		{
			printf("\n");
			printf("%d",p[i]);
		}
		
		free(p);
		return 0;
}
