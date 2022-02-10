#include<iostream>
#define max(x,y) (((int)((x)<(y)) * (y)) + ((int)((y)<=(x)) * (x)))
using namespace std;

int main()
{
    int a,b;
	cout<<("Enter two integers:\n");
	cin>>a>>b;
    cout<<("Max number is ");
	cout<<max(a,b);
	return 0;
}
