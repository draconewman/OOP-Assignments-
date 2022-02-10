/*
	1.	Design the class(es) for the following. Each account has account number and balance amount. 
	A list of account is to be maintained where one can add and find account, display information of all accounts.
	 While adding, account number must be unique. Withdraw object has account number (must exist) and amount (will not exceed balance amount of corresponding account). 
	 Withdraw object will update the balance of corresponding account in the list.
	 Implement your design. Use friend function wherever required and again, modify your implementation to avoid friend function.
*/
#include<iostream>
using namespace std;
#define ll long long int 

bool check_account_num(ll arr[],int acc_num,int limit)							//says position of ana account in account list
{
	for(int i=0;i<limit;i++)
	{
		if(arr[i]==acc_num)
		return true;
	}
	return false;
}
int account_pos(ll arr[],int acc_num,int limit)						//to check the acc number is present or not
{
	for(int i=0;i<limit;i++)
	{
		if(arr[i]==acc_num)
		return i;
	}
}
class account{																//account class that contains account number and balance
	ll acc_no;
	ll bal;
	public:
		void getacc(ll );													//take account number
		void getbal(ll );													//take balance 
		ll ren_acc_no();													//return account number
		ll ren_bal();														//return balance
};
void account::getacc(ll a)													//defining getacc .... it takes account number from user
{ 
	acc_no=a;
}
void account::getbal(ll b)													//defining getbal.... it takes balance
{
	bal=b;
}
ll account::ren_acc_no()													//returns account number
{
	return acc_no;
}
ll account::ren_bal()														//returns balance
{
	return bal;
}

class account_list															//account list that contains 10000 account object
{
	account a[10000];
	ll acc_no_list[10000];
	public:
		static int count;													//it counts total number of accounts
		void add_account();													//add accounts in account list 
		bool find_account();												//to find account from account list
		void display();														//display all account data
		friend class withdrawl;
};

int account_list::count=0;													//initializing static int count

void account_list::add_account()											//add accounts in account list
{
	ll ac;
	do{
	cout<<"enter the account number  :";
	cin>>ac;}
	while(account_list::count>0&&check_account_num(acc_no_list,ac,account_list::count));	//check wheather the acount present in the account list
	acc_no_list[account_list::count]=ac;
	cout<<"enter the balance of that account  :";
	ll b;
	cin>>b;
	a[account_list::count].getacc(ac);
	a[account_list::count].getbal(b);
	account_list::count++;
	return;
}

bool account_list::find_account()														//function to find account number
{
	ll ac;
	cout<<"enter the account number ";
	cin>>ac;
	if(check_account_num(acc_no_list,ac,account_list::count))
	{cout<<"your account is found "<<endl;
	 cout<<"your current balance is "<<a[account_pos(acc_no_list,ac,account_list::count)].ren_bal();
	 return true;
	}
	else
	{
		cout<<"your account is not found "<<endl;
		return false;
	}
}
void account_list::display()																//function to show data
{
	cout<<"the all accounts present in this system  "<<endl;
	cout<<"account number"<<"\t\t"<<"balance available in that account "<<endl;
	for (int i=0;i<account_list::count;i++)
	{
		cout<<a[i].ren_acc_no()<<"\t\t\t\t"<<a[i].ren_bal()<<endl;
	}
	
}
class withdrawl{
	ll acc_number;
	ll amount;
	public:
		void getwithdrawl(account_list &);
};
void withdrawl::getwithdrawl(account_list & t)
{
	ll ac, a;
	cout<<"enter account number ";
	cin>>ac;
	cout<<"enter amount of money you yant to withdraw  ";
	cin>>a;
	if(check_account_num(t.acc_no_list,ac,account_list::count))
	{
		int k=account_pos(t.acc_no_list,ac,account_list::count);
		if(t.a[k].ren_bal()>=a)
		{
			acc_number=ac;
			amount=a;
			cout<<"transaction successfull \n";
			t.a[k].getbal(t.a[k].ren_bal()-amount);
			cout<<"your current balance is  "<<t.a[k].ren_bal();
		}
		else cout<<"sorry, you don't have sufficient balance \nhave a nice day"<<endl;
	}
	else cout<<"sorry, you have entered a wrong account number \nhave a nice day "<<endl;
	
}

int main()
{
	account_list al;
	cout<<"add new account  \n";
	al.add_account();
	cout<<"add new account  \n";
	al.add_account();
	cout<<"\nto find your account  \n";
	al.find_account();
	cout<<"\ndisplaying your all account datas \n";
	al.display();
	
	withdrawl w;
	cout<<"\n to withdraw money \n";
	w.getwithdrawl(al);
	return 0;
}














