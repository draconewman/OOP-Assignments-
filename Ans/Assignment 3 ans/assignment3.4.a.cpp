#include<iostream>
using namespace std;
int max(int a,int b)
{
	int x;
		if(a>b) 
		{
			x=a;
		}
		else
		{
			x=b;
		}
	return x;
}

main()
{
	int a,b;
	cout<<"Enter two integers:\n"<<endl;
	cin>>a>>b;
	cout<<"Max is:\n"<<max(a,b);
	return 0;
}

