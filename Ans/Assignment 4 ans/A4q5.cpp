/*
5.	Modify the STRING class so that assigning/initializing a string by another will not copy it physically but will keep a reference count, which will be incremented.
 Reference value 0 means the space can be released.
*/

#include<iostream>
#include<string.h>
using namespace std;
#define ui unsigned int
class _string{
	ui size;
	char *c;
	int* count;
	public:
		_string()													//default constructor
		{
			size=0;
			c=new char('\0');
			count=new int(0);
		}
		
		
		_string(ui s)												//constructor...argument= size of string
		{
			size=s;													//taking extra size for null
			if(size!=0)
			{
				cout<<"enter string of "<<size<<" size  ";				
				c=new char[size+1];
				fflush(stdin);
				int i=0;
				while(i<size)										
				{
					cin>>c[i];										//taking value of string one by one
					i++;
				}
			
				c[i]='\0';
				i++;
			}
			else c=new char('\0');
			count=new int(0);
		}
		
	
		_string(const char* ch)										//constructor.... argument character pointer
		{
				size=strlen(ch);
				c=new char[strlen(ch)+1];
				strcpy(c,ch);
				cout<<"\nyour string is----   "<<c<<endl;
			
				count=new int(0);
		}
		
		~_string(){														
			
			if(c!='\0')
			(*count)--;
			if((*count)==0)
			{
			delete[] c;	
			cout<<"destruction is called"<<endl;}
				
		}
		_string(const _string& t)											//copy constructor
		{		
				size=t.size;
				c=t.c;												
				cout<<"\nyour string is----   "<<c<<endl;
			
			count=t.count;
			(*count)++;
		}
		
		void operator=(const _string &t)									//assigning
		{
			if(c!='\0')
			(*count)--;
			if((*count)==0)
			delete[] c;
				
				size=t.size;
				c=t.c;												
				cout<<"\nyour string is----   "<<c<<endl;
			
			count=t.count;
			(*count)++;	
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
					is>>t.c[i];											
					i++;
				}			
		//*t.count++;														//actually with cin i am using the previous location.... and previous object so no need of count++
	return is;
}
int main()
{

	_string a(10);
	_string b("hello world");

	_string c(a);														//coping
	_string d;

	d=b;																//assigning
	
	cout<<"a-----   "<<a<<endl;
	cout<<"b-----   "<<b<<endl;
	cout<<"c-----   "<<c<<endl;
	cout<<"d-----   "<<d<<endl;
	
	cout<<"\n\nif we take another value of c then value of a must change  \nenter c -----  ";
	cin>>c;
	cout<<"c-----   "<<c<<endl;
	cout<<"a-----   "<<a<<endl;
	return 0;
	
}
