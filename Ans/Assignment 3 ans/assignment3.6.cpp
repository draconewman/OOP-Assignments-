#include<iostream>
using namespace std;

void f(int)
{
	cout<<"inside f(int)"<<endl;
}

void f(float)
{
	cout<<"inside f(float)"<<endl;
}

main()
{
	int a;
	char b;
	float c;
	double d;
	f(a);
	f(b);
	f(c);
	return 0;	
}
