#include <iostream>
using namespace std;

template<class T>
class Array
{
    T a[10];
public:
    Array()
    {
        cout<<"Enter elements\n";
        int j;
        for(j=0;j<10;j++)
        {
            cin>>a[j];
        }
    }
    void Max();
    void Sum();
};
template<class T>
void Array<T>::Sum()
{
    int j;
    T sum=0;
    for(j=0;j<10;j++)
        sum+=a[j];
    cout<<"Sum is: "<<sum<<"\n";
}
template<class T>
void Array<T>::Max()
{
    int j;
    T m=a[0];
    for(j=0;j<10;j++)
        {
            if(m<a[j])
                m=a[j];
        }
    cout<<"Maximum is: "<<m<<"\n";
}

int main()
{
    while(1)
    {
    	int i;
        cout<<"\nChoose data type\n(1)Float\n(2)Integer\n(3)Exit\n"<<endl;		
		cin>>i;
        switch(i)
        {
        case(1):
            {
                Array<float> f;
                f.Max();
				f.Sum();
				break;
            }
        case(2):
            {
                Array<int> i;
                i.Max();
				i.Sum();
				break;
            }
        case(3):
            {
                return(0);
            }
        }
    }
    return 0;
}
