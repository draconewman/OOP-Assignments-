/*
4.	Design a STRING class, which will have the initialization facility similar to array class. Provide support for 
"	Assigning one object for another, 
"	Two string can be concatenated using + operator, 
"	Two strings can be compared using the relational operators.

*/

#include<iostream>
#include<string.h>
using namespace std;
#define ui unsigned int
class _string{
	ui size;							//size of the string 
	char *c;
	public:
		void showstring()											//print string....used for back up
		{
			int i=0;
			while(c[i]!='\0')
			{
				cout<<c[i];
				i++;
			}
		}
		_string()													//default constructor
		{
			size=0;
			c=new char('\0');	
		}
		_string(ui s)												//constructor...argument= size of string
		{
			size=s;													//taking extra size for null
			if(size!=1)
			{
				cout<<"enter string of "<<size<<" size  ";				
				c=new char[size+1];
				fflush(stdin);
				int i=0;
				while(i<size)										//take char untill the escape line is placed
				{
					cin>>c[i];										//taking value of string one by one
					i++;
				}
			
				c[i]='\0';
				i++;
			}
			else c=new char('\0');
		}
		_string(const char* ch)										//constructor.... argument character pointer
		{
			if(ch=='\0')
			{
				c=new char('\0');
			}
			else
			{
				size=strlen(ch);
				c=new char[strlen(ch)+1];
				strcpy(c,ch);
				cout<<"\nyour string is----   "<<c<<endl;
			}
		}
		
			~_string(){														//destructor
				if(c!='\0')
				delete[] c;
			}
		_string(const _string& t)											//copy constructor
		{
			if(c!='\0')
			delete[] c;
			
			if(t.c=='\0')
			c=new char('\0');												
			else
				{
				size=t.size;
				c=new char[size+1];												
				strcpy(c,t.c);												
				cout<<"\nyour string is----   "<<c<<endl;
				}
		}
		
		void operator=(const _string& t)									//assignment operator overloas=ding
		{
			
			if(c!='\0')
			delete[] c;
			
			if(t.c=='\0')
			c=new char('\0');												//setting c=null if passed string char pointer has null value
			else
				{
				size=t.size;
				c=new char[t.size+1];												
				strcpy(c,t.c);												//coping string
				cout<<"\nyour assigned string is----   "<<c<<endl;
				}
			
		}
		
		_string operator+(const _string& t)									//+operator overloading
		{

			_string p;
			
			p.size=size+t.size;	
			if(p.size=='\0')
			p.c=new char('\0');												//setting c=null if passed string char pointer has null value
			else
				{
				p.c=new char[p.size+1];	
				int i=0;											
				while(c[i]!='\0')
				{
					p.c[i]=c[i];
					i++;
				}
				int j=0;
				while(t.c[j]!='\0')
				{
					p.c[i+j]=t.c[j];
					j++;
				}
				p.c[i+j]='\0';
				}
				cout<<"addition done"<<endl;
			return p;
			
		}
		
		bool operator==(const _string& t)								//==operator overloading
		{
			if(strcmp(c,t.c)==0)
			return true;
			else return false;
		}
		
		bool operator!=(const _string& t)								//!=operator overloading
		{
			if(strcmp(c,t.c)!=0)
			return true;
			else return false;
		}
		
		bool operator>(const _string& t)								//>operator overloading
		{
			if(strcmp(c,t.c)>0)
			return true;
			else return false;
		}
		
		bool operator>=(const _string& t)								//>=operator overloading
		{
			if(strcmp(c,t.c)>=0)
			return true;
			else return false;
		}
		bool operator<(const _string& t)								//<operator overloading
		{
			if(strcmp(c,t.c)<0)
			return true;
			else return false;
		}
		bool operator<=(const _string& t)								//<=operator overloading
		{
			if(strcmp(c,t.c)<=0)
			return true;
			else return false;
		}
		
		friend ostream& operator<<(ostream& ,_string& );				//friend function of <<operator overloading
		friend istream& operator>>(istream& ,_string& );				//friend function of >>operator overloading
};

ostream& operator<<(ostream& o,_string& t)								//<<operator overloading for print
{
	o<<t.c;
	return o;
}
istream& operator>>(istream& is,_string& t)								//>>operator overloading for scan
{	
		
			
				cout<<"\nenter string of "<<t.size<<" size  ";
				fflush(stdin);
				int i=0;
				while(i<t.size)											
				{
					is>>t.c[i];											//taking value of string one by one
					i++;
				}			
		
	return is;
}
int main()
{
	cout<<"a-----"<<endl;											
	_string a(10);														//_string obj a having size 10												
	cout<<"b-----"<<endl;
	_string b;															//_string b
	b=a;																//b becomes a 
	
	cout<<"string b is  ";
	cout<<b<<endl;														//b printed
	
	cout<<"c-----"<<endl;
	_string c("hello world");											//constructor with char pointer is called here
	
	cout<<"d-----"<<endl;
	_string d=b+c;														//using addition then copping
	
	cout<<"string a is  ";
	cout<<a<<endl;						
	cout<<"new b-------"<<endl;
	cin>>b;																//new value of b is entered
	cout<<"new b is   ";
	cout<<b<<endl;
	
	cout<<"string c is  ";
	cout<<c<<endl;
	
	cout<<"string d is  ";
	cout<<d<<endl;

	/*comparing using relational opera*/
	if(a>b)
	cout<<"a>b"<<endl;
	if(a<b)
	cout<<"a<b"<<endl;
	if(a==b)
	cout<<"a==b"<<endl;
	if(a!=b)
	cout<<"a!=b"<<endl;
	if(a>=b)
	cout<<"a>=b"<<endl;
	if(a<=b)
	cout<<"a<=b";	
	
		
	
}
