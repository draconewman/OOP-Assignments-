/*3.	Employee has unique emp-id, name, designation and basic pay. An employee is either a permanent one or contractual.
 For permanent employee salary is computed as basic pay+ hra (30% of basic pay) + da (80% of basic pay).
  For contractual employee it is basic pay + allowance (it is different for different contractual employee). 
  An employee pointer may point to either of the two categories and accordingly the salary has to be created.
Design the classes and implement.
*/

#include<iostream>
int tempcount=0;
int permcount=0;
int temparr[1000];
int permarr[10000];
int itm=0;
int ipm=0;
using namespace std;
class emplist{
    public:
    int emid;
    double bp;
    string name;

};
class tempemp:public emplist{//using inheritence*****************
    public:
    void get()
    {
        cin>>emid;
        //temparr[itm++]=emid;
        cin>>bp;
        cin.ignore();
        getline(cin,name);
        tempcount++;
    }
    void allowpay()
    {
        double all;
        cout<<"ENETR THE ALLOWENCE\n";
        cin>>all;
        bp=all+bp;
    }
};
class pememp:public emplist{
    public:
    int id=0;
   void getperm()
   {
       cin>>emid;
       cin>>bp;
       cin.ignore();
       getline(cin,name);
        permcount++;
   }
   void finalpay()
   {
       bp=0.8*(bp)+0.3*bp+bp;
   }
};
tempemp temply[10000],checkingtemp[10000];
pememp permaemp[1000],checkingperm[10000];


void show()
{
    if(tempcount==0)
    {
        cout<<"FIRST ADD EMPLOYEE\n\n";
        return;
    }
    else{
        cout<<"DISPLAYING TEMPORARY EMPLOYEE DETAILS\n";
    for(int i=0;i<tempcount;i++)
    {
        cout<<"NAME:\t"<<temply[i].name<<"\t"<<"EMPLOYEE ID\t"<<temply[i].emid<<"\t"<<"SALARY\t"<<temply[i].bp<<endl;
    }
    }
}

void showperma()
{
    if(permcount==0)
    {
        cout<<"FIRST ADD EMPLOYEE\n\n";
        return;
    }
    else{
        cout<<"DISPLAYING PERMANENT EMPLOYEE DETAILS\n";
    for(int i=0;i<permcount;i++)
    {
        cout<<"NAME:\t"<<permaemp[i].name<<"\t"<<"EMPLOYEE ID\t"<<permaemp[i].emid<<"\t"<<"SALARY\t"<<permaemp[i].bp<<"\n";
    }
    }
}
//______________________checking for permanent employee id______________________
bool check_permaid(int input_emid)
{
    for(int i=0;i<permcount;i++)
    {
        if(permarr[i]==input_emid)
        {
            permcount--;
            return false;
        }
    }
    permarr[ipm++]=input_emid;
    return true;
}
//___________checking for temporary employee id__________
bool check_tempaid(int input_emid)
{
    for(int i=0;i<tempcount;i++)
    {
        if(temparr[i]==input_emid)
        {
            tempcount--;
            return false;
        }
    }
    temparr[itm++]=input_emid;
    return true;
}
//______________________________________MAIN PART__________________________
int l=0;
int k=0;
int a=0;
int b=0;
int main()
{
    while(1)
    {
        cout<<"ENTER YOUR CHOICE\n1 TO ADD TEMPORARY EMPLOYEE\n2 TO SHOW TEMPORARY EMPLOYEE DETAILS\n3 TO ADD PERMANENT EMPLOYEE\n4 TO SHOW PERMANENT EMPLOYEE DETAILS\n";
        cout<<"0 TO EXIT\n";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 0:
            cout<<"THANK YOU\n";
            exit(0);
            break;
            case 1:
            cout<<"Enter the details of Temporary Employee\nEMPLOYEE ID\nEMPLOYEE BASIC PAY\nEMPLOYEE NAME\n";
            temply[l].get();

            if(!check_tempaid(temply[l].emid))
            {
                cout<<"EMPLOYEE ID CAN'T BE SAME\nTRY AGAIN\n";
                break;
            }
            checkingtemp[b].emid=temply[l].emid;
            b++;
            temply[l].allowpay();
            l++;
            break;
            case 2:
            
            show();
            break;
            case 3:
            cout<<"Enter the details of Permanent Employee\nEMPLOYEE ID\nEMPLOYEE BASIC PAY\nEMPLOYEE NAME\n";
            permaemp[k].getperm();
            check_permaid(permaemp[k].emid);
             if(!check_permaid(permaemp[k].emid))
             {
                 cout<<"EMPLOYEE ID CAN'T BE SAME\nTRY AGAIN\n";
                break;
             }
            checkingperm[a].id=permaemp[k].emid;
            a++;
            permaemp[k].finalpay();
            k++;
            break;
            case 4:
            
                showperma();
                break;
        }
    }
}
