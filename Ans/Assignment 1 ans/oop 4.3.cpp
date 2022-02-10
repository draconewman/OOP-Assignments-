#include<stdio.h>
#include<stdlib.h>

int dimension(int *r,int *c)
{
    printf("Enter the number of ROW & COLUMN of the array : ");
    scanf("%d %d",r,c);
}
void allocation(int *p[],int r,int c)
{
   int i;
   for(i=0;i<r;i++)
    {
        p[i]=(int*)malloc(c*sizeof(int));
    }

}
void input(int *p[],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("Enter an element : ");
			scanf("%d",&p[i][j]);
        }
    }
}
void print(int *p[],int r,int c)
{
    int i,j;
    printf("\nThe 2d array : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int r,c,i;
    dimension(&r,&c);
    int *a[r];
    allocation(a,r,c);
    input(a,r,c);
    print(a,r,c);
    for(i=0;i<r;i++)
    {
        free(a[i]);
    }
    return 0;
}
