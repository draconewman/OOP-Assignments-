#include<iostream>
#define SIZE 10
using namespace std;
 
class STACK
{
    private:
        int num[SIZE];
        int top;
    public:
        STACK();    		//defualt constructor
        int push(int);
        int pop();
        int Empty();
        int Full();
        void display();
};

STACK::STACK()
{
    top=-1;
}
 
int STACK::Empty()
{
    if(top==-1)
        return 1;
    else
        return 0;   
}
 
int STACK::Full()
{
    if(top==(SIZE-1))
        return 1;
    else
    return 0;
}
 
int STACK::push(int n)
{
    if(Full())			//check stack is full or not
	{
        return 0;
    }
    ++top;
    num[top]=n;
    return n;
}
 
int STACK::pop()
{
    int temp;			//to store and print which number is deleted
    if(Empty())			//check for empty
        return 0;
    temp=num[top];
    --top;
    return temp;
     
}
 
void STACK::display()
{
    int i; 
	if(Empty())	
	{
			cout<<"Empty STACK"<<endl;
	}					
    
	for(i=(top); i>=0; i--)				//for loop
        cout<<num[i]<<" ";
    cout<<endl;
}
 
int main()
{
    STACK stk;							//declare object
    int choice, n,temp;
    
	while(choice!=0)
    {
        cout<<endl;
        cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item."<<endl;
        cout<<"2 - Pop Item."<<endl;
        cout<<"3 - Display Items."<<endl;
         
        cout<<"Enter your choice: ";
        cin>>choice;
         
        switch(choice){
            case 0: break;
             
            case 1:
                cout<<"Enter item to insert: ";
                cin>>n;
                temp=stk.push(n);
                if(temp==0)
                    cout<<"STACK Overflow"<<endl;
                else
                    cout<<temp<<" inserted"<<endl;
                break;
                 
            case 2:
                temp=stk.pop();
                if(temp==0)
                    cout<<"STACK Underflow"<<endl;
                else
                    cout<<temp<<"Item removed"<<endl;
            break;
             
            case 3:
                stk.display();
                break;
             
            default:
                cout<<"Invalid choice!!"<<endl;
        }   
    }
	return 0;
} 
                    
                    
                    
                    
                    
