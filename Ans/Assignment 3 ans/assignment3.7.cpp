#include<iostream>
using namespace std;

void f(int,int)
{
	cout<<"inside f(int,int)"<<endl;
}

void f(char,int)
{
	cout<<"inside f(char,int)"<<endl;
}

main()
{
	int a;
	char b;
	float c;
	f(a,b);
	f(b,b);
	return 0;	
}
