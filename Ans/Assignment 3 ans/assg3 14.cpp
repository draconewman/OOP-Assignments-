#include<iostream>
#include<string.h>
using namespace std;


int pos_item(char arr[][50],char it_code[50],int limit)						//function to get position of item in list 
{
		for(int i=0;i<limit;i++)
	{
		if(strcmp(arr[i],it_code)==0)
		{
			return i;														//return position if code is found
		}
	}
	return -1;                     											//return -1 if code is found
}
bool search_item(char arr[][50],char it_code[50],int limit)					//function to check wheater code is available before or not
{
	for(int i=0;i<limit;i++)
	{
		if(strcmp(arr[i],it_code)==0)
		{
			return true;													//return true if code found
		}
	}
	return false;															//return false if code is not found
}
class item{									//item class
	char code[50];							//item code
	char name[50];							//name of the item
	float rate;								//rate given by customers
	int quan;    							//quantity of the item
	float price;							//price of the item
	public:	
		friend class item_list;    			//friend class
	
};
class item_list{                           //item_list class
	char i_code_list[1000][50];
	item it[1000];
	static int count;						//static variable
	
	
	
	
	public:
		void add_item();					//function to add item
		void rate();						//function to rate item
		void issue_item();					//function to issue or recieve item
		void item_details();				//prints the details of the item using code
		
};
int item_list::count=0;						//initializing static variable count
void item_list::add_item()					//function to add new item in item_list
{
	char c[50];																					//item code
	do{
		cout<<"enter the item code you want to add  ";
		fflush(stdin);
		cin>>c;
		if(item_list::count>0 && search_item(i_code_list,c,item_list::count))					//condition to exit or try more times
		{
			cout<<"code invalid  ";
			cout<<"if you want to try more enter any positive intiger value... or enter 0 to return in main menu \nyour choice  ";
			int z;																				//temp
			cin>>z;
			if(z==0)
			return;																				
			
		}
	}
	while(item_list::count>0 && search_item(i_code_list,c,item_list::count));   				//condition of this loop repeat
	strcpy(i_code_list[item_list::count],c);													//coping code in item code list
	cout<<"enter name of the item  ";
	char n[50];																					//name of the item
	fflush(stdin);
	cin>>n;																						//takes name input
	
	cout<<"enter quantity available of the item  ";
	int q;																						//quantity available
	cin>>q;																						//takes quantity
	
	cout<<"enter the price of the item  ";
	float p;																					//price of the item
	cin>>p;																						//takes price as input
	
	strcpy(it[item_list::count].code,c);														//assigning values in item obj
	strcpy(it[item_list::count].name,n);
	it[item_list::count].quan=q;
	it[item_list::count].price=p;		
	it[item_list::count].rate=0;																//while adding items rating is taken 0 and it will be changed later
	item_list::count++;																			//increamenting the count by 1
	
}

void item_list::rate()																			//function to rate items
{
	char c[50];																			//item code																		
	do{
		cout<<"enter the item code you want to rate  ";
		fflush(stdin);
		cin>>c;
		if(item_list::count>0 && (search_item(i_code_list,c,item_list::count)!=true))			//condition checking to get out of loop or try more times
		{
			cout<<"code invalid  ";
			cout<<"\nif you want to try more enter any positive intiger value... or enter 0 to return in main menu \nyour choice  ";
			int z;																		//temp
			cin>>z;
			if(z==0)
			return;
			
		}
	}
	while(item_list::count>0 && (search_item(i_code_list,c,item_list::count)!=true));			//repeat this if code is invalid
	float r;																			//rating
	cout<<"enter the rating of this item  ";
	cin>>r;
	it[pos_item(i_code_list,c,item_list::count)].rate=r;     							//assigning rating
	return;
}

void item_list::issue_item()																		//function to issue or recieve item
{
	char c[50];																						//item code
	do{
		cout<<"enter the item code you want to issue or recieve  ";
		fflush(stdin);
		cin>>c;
		if(item_list::count>0 && (search_item(i_code_list,c,item_list::count)!=true))						//condition checking to get out of loop or try more times
		{
			cout<<"code invalid  ";
			cout<<"if you want to try more enter any positive intiger value... or enter 0 to return in main menu \nyour choice  ";
			int z;
			cin>>z;
			if(z==0)
			return;
			
		}
	}
	while(item_list::count>0 && (search_item(i_code_list,c,item_list::count)!=true));						//repeat this if code is invalid
	
	if(it[pos_item(i_code_list,c,item_list::count)].quan<=0)										//checking if the item is available or not
	{
		cout<<"not available ........try after some days  \n";
		return;
	}
	else
	{
		int no_i;
		cout<<"enter number of item you want  ";
		cin>>no_i;
		if(it[pos_item(i_code_list,c,item_list::count)].quan-no_i<=0)								//checking avilability of items for one or or more items
		{
		cout<<"too much items... not available ........try after some days  \n";
		return;}
		else
		{
			cout<<"your order is successfull  \n";
			it[pos_item(i_code_list,c,item_list::count)].quan=it[pos_item(i_code_list,c,item_list::count)].quan-no_i;			//update item after issue successfull
			return;
			
		}
	}

}

void item_list::item_details()														//function to show item details
{
		char c[50];																	//item code
	do{
		cout<<"enter the item code of which you want to see details  ";
		fflush(stdin);
		cin>>c;
		if(item_list::count>0 && (search_item(i_code_list,c,item_list::count)!=true))		//condition checking to get out of loop or try more times
		{
			cout<<"code invalid  ";
			cout<<"if you want to try more times enter any positive intiger value... or enter 0 to return in main menu \nyour choice  ";
			int z;																	//temp
			cin>>z;
			if(z==0)
			return;
			
		}
	}
	while(item_list::count>0 && (search_item(i_code_list,c,item_list::count)!=true));		//repeat this if code is invalid
	cout<<"\n\t\t\tITEM DETAILS\n";																	//prints item name, rating, price and number of item availabe
	cout<<"name of the item---  "<<it[pos_item(i_code_list,c,item_list::count)].name<<endl;
	cout<<"rating of the item---  "<<it[pos_item(i_code_list,c,item_list::count)].rate<<endl;
	cout<<"price of the item---  "<<it[pos_item(i_code_list,c,item_list::count)].price<<endl;
	cout<<"number of item available---  "<<it[pos_item(i_code_list,c,item_list::count)].quan<<endl;
	return;
	
}

int main()
{
		item_list itlist;								//item list object
		
		/* there is some function call according to user  */
		while(1)
		{
			cout<<"\nenter 1. to add item\nenter 2. to rate item\nenter 3. to issue item or recieve item\nenter 4. to see details of the item\nenter 0. to exit\nyour choice ";
			char ch;
			cin>>ch;
			switch(ch)
			{
				case '1':{
					itlist.add_item();	
					break;
				}
				case '2':{
					itlist.rate();
					break;
				}
				case '3':{
					itlist.issue_item();
					break;
				}
				case '4':{
					itlist.item_details();
					break;
				}
				case '0':{
					return 0;
				}
				default: return 1;
			}
		}				
}
