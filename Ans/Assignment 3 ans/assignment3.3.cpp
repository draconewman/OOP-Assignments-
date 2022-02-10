#include<iostream>
using namespace std;
void swap(int &x,int &y)
{
	int t;
	t=x;
	x=y;
	y=t;
}

int main()
{
	int a,b;
	cout<<"Enter two numbers:\n"<<endl;
	cin>>a>>b;
	cout<<"Before swap a="<<a<<"\t"<<"b="<<b<<endl;
	swap(a,b);
	cout<<"After swap a="<<a<<"\t"<<"b="<<b<<endl;
	return 0;
}
