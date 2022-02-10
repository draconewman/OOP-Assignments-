#include<iostream>
using namespace std;
class complex{
	int a;
	int b;
	public:
		complex(int v1=0,int v2=0):a(v1),b(v2){ 	}							//constructor
		complex operator+(complex );											//+operator overloading
		complex operator-(complex );											//-operator overloading
		friend ostream &operator<<(ostream& ,complex );							//<<operator overloading and using cout to take input for obj
		friend istream &operator>>(istream &,complex & );						//>>operator overloading and using cin to take input for obj
};
complex complex::operator+(complex t)											//+operator overloading									
{
	complex p;																	//declaring another temporaray obj
	p.a=a+t.a;
	p.b=b+t.b;
	return p;
}

complex complex::operator-(complex t)											//-operator overloading
{
	complex m;																	//declaring another temporaray obj
	m.a=a-t.a;
	m.b=b-t.b;
	return m;
}

ostream &operator<<(ostream &os,complex t)										//<<operator overloading and using cout to take input for obj
{
	os<<"value of a= "<<t.a<<endl;
	os<<"value of b= "<<t.b<<endl;
	return os;																	//returning os
}

istream &operator>>(istream &is,complex& t)										//>>operator overloading and using cin to take input for obj
{
	cout<<"  a= ";
	is>>t.a;
	cout<<"  b= ";
	is>>t.b;
	return is;																	//returning is
}

int main()
{
	complex c1,c2,c3;															//declaring three complex object
	cout<<"enter first complex object values ";									
	cin>>c1;																	//scanning using >>operator overloading
	cout<<"enter second complex object values ";
	cin>>c2;																	//scanning using >>operator overloading
	cout<<"enter third complex object values ";
	cin>>c3;																	//scanning using >>operator overloading
	complex c4=c1+c2-c3;														//here + and - both operator is being overloaded
	cout<<"now value of c3 is \n";	
	cout<<c4;																	//printing c4 by <<operator overloading
	return 0;
}
