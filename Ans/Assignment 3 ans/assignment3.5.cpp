#include<iostream>
using namespace std;
int tax(int income,int rate)
{
	int amount;
	amount=(income*rate)/100;
	return amount;
}

main()
{
	int i,r;
	char y;
	cout<<"Enter income: "<<endl;
	cin>>i;
	cout<<"Do you want to enter tax rate?(Y/N)"<<endl;
	cin>>y;
	if(y=='y'||y=='Y')
		{
			cout<<"Enter tax rate: "<<endl;
			cin>>r;	
		}
	else
		{
			cout<<"Default tax rate is 10%"<<endl;
			r=10;
		}
		
	cout<<"Your tax is: "<<tax(i,r)<<endl;
	return 0;		
}
