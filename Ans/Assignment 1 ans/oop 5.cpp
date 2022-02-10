#include<stdio.h>
#include<string.h>

void arrange(char name[][51],int age[],int n)
{
   int i,j,temp=0;
   char t[51];
     for(i=0;i<n-1;i++)
     {
       for(j=i+1;j<n;j++)
       {
          if(age[i]>age[j])
          {
             temp=age[i];
             age[i]=age[j];
             age[j]=temp;
             strcpy(t,name[i]);
             strcpy(name[i],name[j]);
             strcpy(name[j],t);
          }
       }
     }
}

void display(char name[][51],int age[],int n)
{
  int i,j;
  printf("********************\n");
  printf("Age%sName\n"," ");
  printf("********************\n");
    for(i=0;i<n;i++)
    printf("%d%s%s\n",age[i]," ",name[i]);
}

int main()
{
   int n,i;
   printf("Enter the number of names: ");
   scanf("%d",&n);
   int age[n];
   char name[n][51];
     for(i=0;i<n;i++)
     {
        printf("Enter name: ");
        scanf("%s",name[i]);
        printf("Enter age: ");
        scanf("%d",&age[i]);
     }
     arrange(name,age,n);
     display(name,age,n);
     
     return 0;
}

