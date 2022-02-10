#include<iostream>
#include<stdlib.h>															
using namespace std;
#define ll long long int													//defining long long int as ll

class balance;																//forward declaration of class balance
class transaction															//class transaction holds all important function 
{
		ll acc_num;
		int date;
		ll ammount;
		char tran_type;
		
		public:

			bool check_bal(balance& );															//function to check balance

			void transaction_data_and_procedure(ll  ,int ,ll  ,char ,balance &);				//function to transaction and update balance also
					
};

class balance{																					//balance class that holds all main information
		ll acc_num;																				//account number
		ll bal;																					//balance
		int update_date;																		//last updated date
		
		public:
		int ren_acc_num();																		//return account number
		balance(ll ac=0,ll b=0, int date=0)														//constructor
		{
			acc_num=ac;
			bal=b;
			update_date=date;			
		}
		friend bool transaction::check_bal(balance &);											//friend member function
		friend void transaction::transaction_data_and_procedure(ll ,int ,ll ,char ,balance & );	//friend member function
		void check_bal();																		//function to check(show) balance
		void get_bal(ll ,ll , int );															//function to take details of balance obj as input

};

int balance::ren_acc_num()																		
{
	return acc_num;	
}

void balance::check_bal()
{
	cout<<"current ammount = "<<bal<<endl;
	cout<<"last updated = "<<update_date/1000000<<'/'<<(update_date/10000)%100<<'/'<<update_date%10000<<endl;
	cout<<"\nHave a nice day \n";
}

void balance::get_bal(ll ac,ll b, int date)														//return account number
{
		acc_num=ac;
		bal=b;
		update_date=date;
}
		
		
bool transaction::check_bal(balance& t)															//transaction member function to check balance
			{
				if(ammount<=t.bal)
				return true;
				else return false;
				
			}

			
void transaction::transaction_data_and_procedure(ll ac,int d,ll amo,char type,balance &t){		//function to transaction and update balance also
		
				acc_num=ac;
				date=d;
				ammount=amo;
				tran_type=type;
				if(tran_type=='W')																//takes the transaction type as given condition
				{
					if(check_bal(t))
					{
						cout<<"your transaction(withdrawl) successfull \nHave a nice day \n";
						t.bal=t.bal-ammount;
						t.update_date=date;
						cout<<"current ammount = "<<t.bal<<endl;
					}
					else 
					{
						cout<<"sorry, you don't have sufficient money \nHave a nice day "<<endl;
						t.update_date=date;
						cout<<"current ammount = "<<t.bal<<endl;
					}
				}
				else if(tran_type=='D')
				{
						cout<<"your transaction(deposite) successfull \nHave a nice day \n";
						t.bal=t.bal+ammount;
						t.update_date=date;
						cout<<"current ammount = "<<t.bal<<endl;
				}
				
			}
			
bool check_account_num(ll arr[],int acc_num,int limit)												//global function to check account number if it is used before
{
	for(int i=0;i<limit;i++)
	{
		if(arr[i]==acc_num)
		return true;
	}
	return false;
}

int ren_position_of_acc_no(ll arr[],int acc_num,int limit)											//global function that returns the position of account number in account number list
{
	for(int i=0;i<limit;i++)
	{
		if(arr[i]==acc_num)
		return i;
	}
	return 0;
}


int main()
{
		int i=0;
		int j=0;
		ll acc_no_list[1000];																		//account number list as an array
		balance b[1000];																			//balance obj as array(same size as account number list)
		transaction tr[50000];																		//transaction obj as array
		
		while(1)
		{
			/*using switch case to use those class function according to input*/
			cout<<"\nenter 1. to create an account \nenter 2. for transaction \nenter 3. to see your account information \nenter 0. for exit\nyour choice  ";
			char ch;
			fflush(stdin);
			cin>>ch;
			switch(ch)
			{
				case '1':{
					do{
					acc_no_list[i]=rand();
					}
					while(i>0&&check_account_num(acc_no_list,acc_no_list[i],i));
					cout<<"your account number is "<<acc_no_list[i]<<endl;
				int dd,mm,yyyy,date;
				do{
				cout<<"\nenter date of when your account is made\nenter valid day(in dd format) - ";
				cin>>dd;}
				while(dd>31||dd<1);
					
				do{
				cout<<"enter valid month(in mm format) - ";
				cin>>mm;}
				while(mm>12||mm<1);
		
				do{
				cout<<"enter valid year(in yyyy format) - ";
				cin>>yyyy;}
				while(yyyy>2020||yyyy<1995);
		
				date=dd*1000000+mm*10000+yyyy;
		
				b[i].get_bal(acc_no_list[i],0,date);
			
				i++;
				break;
				}
				
				case '2':{
					char t;
					cout<<"enter 1. for withdraw your money\nenter 2. for deposite money  ";
					int choice;
					cin>>choice;
					if(choice==1)
					t='W';
					else if(choice==2)
					t='D';
					else
					{
						cout<<"wrong input ";
						return 1;
					}
					
						ll ac;
						do{
						cout<<"enter account number ";
						cin>>ac;
						}
					while(check_account_num(acc_no_list,ac,i)!=true)	;
					
						
						ll am;
						cout<<"enter the amount of money you want to withdraw ";
						cin>>am;
					
						
					int dd,mm,yyyy,date;
					do{
					cout<<"\nenter today's date\n\n'enter valid day(in dd format) - ";
					cin>>dd;}
					while(dd>31||dd<1);
					
					do{
					cout<<"enter valid month(in mm format) - ";
					cin>>mm;}
					while(mm>12||mm<1);
		
					do{
					cout<<"enter valid year(in yyyy format) - ";
					cin>>yyyy;}
					while(yyyy>2020||yyyy<1995);
		
					date=dd*1000000+mm*10000+yyyy;					

					tr[j++].transaction_data_and_procedure(ac,date,am,t,b[ren_position_of_acc_no(acc_no_list,ac,i)]);
					break;
				}
			
			case '3':{
						ll ac;
						do{
						cout<<"enter account number ";
						cin>>ac;
						}
						while(check_account_num(acc_no_list,ac,i)!=true);
						b[ren_position_of_acc_no(acc_no_list,ac,i)].check_bal();
				break;
			}	
			case '0':{
				cout<<"\n\nHAVE A NICE DAY \n\n";
				return 0;
			}
			default:{
				cout<<"entered input is wrong \n";
				return 1;
				break;
			}
			}
		}
}


