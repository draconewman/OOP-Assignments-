/*
	3.	Design an ARRAY class with the following features:
a.	Array object may be declared for a specific size and a value for initializing all the elements. If this it is to be assumed as a 0.
b.	An array object may be declared and initialized with another object.
c.	An array object may be declared and initialized with another array (not the object, standard array as in C language).

Let a and b are two objects:
i.	a+b will add corresponding elements.
ii.	a=b will do the assignment.
iii.	a[I] will return the ith element of the object.
iv.	a*5 or 5*a will multiply the element with 5.

*/
#include<iostream>
using namespace std;

class array{
	int size;
	int *p;
	public:
		array(int s=0,int value=0)							//constructor... here we are taking dynamic array
		{
			if(s!=0)
			{
			size=s;
			p=new int[s];
			for(int i=0;i<size;i++)	
			p[i]=value;			
			}
			else p='\0';
		}
		
		void getdata(int s=0)				//takes data bt here we can chose elements of array
		{
			delete[] p;
			if(s!=0)
			{
			size=s;
			p=new int[s];
			for(int i=0;i<size;i++)	
			{
				cout<<"enter "<<i+1<<"th element of the array  ";
				cin>>p[i];	}		
			}
			else p='\0';
		}
		
		~array(){											//destructor... to free the space of dynamic array ,after abj lifetime is over
			if(p!='\0')
			delete[] p;										//delete whole array
		}
		
		array(const array& t)								//copy constructor.., here also we use dynamic allocation so that new array created points to new array dynamically
		{
			size=t.size;
			if(t.size!=0)
			{
				
				p=new int[size];
				for(int i=0;i<size;i++)
				{
					p[i]=t.p[i];
				}
				
			}
			else p='\0';
		
		}
		
		array(int a[],int n=0)								//taking static array as input as well as its size
		{
			size=n;
			if(n!=0)
			{
				
				for(int i=0;i<n;i++)
				{
					p[i]=a[i];
				}
			}
			else p='\0';
		}
		
		array operator+(const array& t)						//using + operator to add two array element by element
		{
			array plus;										//taking a temp array obj
			plus.size=(t.size>size)?t.size:size;			//taking max size of two array obj and store it in size of plus obj
			int min_size=(t.size<size)?t.size:size;			//taking minimum size among two array object
			int k=(t.size>size)?1:0;						//taking 1 if t obj has max value or taking 0 if *this obj has max value
			if(plus.size!=0)								//if size is 0 means both has 0 size
			{
				plus.p=new int[plus.size];					//allocating plus obj dynamically
				int i;										//index taking for loop
				for(i=0;i<min_size;i++)						//using loop to add element till min_size
				{
					plus.p[i]=p[i]+t.p[i];					
				}
				for(int j=i;j<plus.size;j++)				//taking rest of the element in plus obj
				{
					if(k==1)
					plus.p[j]=t.p[j];
					else if(k==0)
					plus.p[j]=p[j];
				}
			}
			else plus.p='\0';
			return plus;									//return plus
		}
		
		array operator=(const array& t)						//assign using =operator
		{
			array equal;
			equal.size=t.size;
			if(t.size!=0)
			{
				if(p='\0')
				delete[] p;
				
				{
					p=new int[t.size];
					for(int i=0;i<t.size;i++)
					{
						equal.p[i]=t.p[i];
					}
				}
	
			}
			else p='\0';
			return equal;									//return equal obj
		}
		
		int operator[](int i)								//using [] operator to indicate obj.p[i] as obj[i]
		{
			return p[i];
		}
		
		
		array& operator*(int k)								//using *operator to indicate obj*int
		{
			for(int i=0;i<size;i++)
			p[i]=p[i]*k;
			return *this;									//using this pointer to indicate the same object
		}
		
		friend array& operator*(int ,array &);				//friend function
};

array& operator*(int k,array &t)							//using *operator to indicate int*obj
{
		for(int i=0;i<t.size;i++)
		t.p[i]*=k;
		return t;											//returning t
	}


int main()
{
		cout<<"\na1(2,4)---\n";
		array a1(2,4);										//array object having two element dynamically and all elements has value of 4
		cout<<"\na2-----\n";	
		array a2;											//array object
		cout<<"\na2.getdata(3)-----\n";
		a2.getdata(3);										//take input of array element
		cout<<"a3=a1+a2----\n";
		array a3=a1+a2;										//using +operator overloading and then using copy constructor
		cout<<"\na3*5-----\n";
		a3*5;												//a*5 as given in q
		cout<<"\ntaking values of array a3 using a3[i]----\n";
		for(int i=0;i<3;i++)								//using loop to print value of a3
		cout<<a3[i]<<endl;
		cout<<"\n5*a3----\n";
		5*a3;												//5*a as given in q
		cout<<"\nprinting values of a3 using a[i]----\n";	
		for(int i=0;i<3;i++)								//using loop to print values of a3
		cout<<a3[i]<<endl;
		
		return 0;
			
}






