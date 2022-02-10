#include<iostream>
#include<fstream>
using namespace std;

int bookcount=0;
int arr[100000];
int k=0;
class book
{
    public:
    int id;
    int serialno;
    string title;
    string author;
   
    int getserialno(){
        return serialno;
    }
    void setbookdetails()
    {
        cout<<"ENTER THE BOOK ID\nSERIAL NUMBER\nTITLE\nAUTHOR\n";
        cin>>id;
        arr[k++]=id;
        cin>>serialno;
        cin.ignore();
        getline(cin,title);
        getline(cin,author);
    }
    void show()
	{
            cout<<"BOOK ID:"<<"\t"<<id<<"\t"<<"SERIAL NUMBER\t"<<serialno<<"\t"<<"TITLE\t"<<title<<"\t"<<"AUTHOR\t"<<author<<"\n";
    }    
};

class member
{
    public:
    string name;
    string mail;
    void setdetails()
    {
        cout<<"\tENTER NAME AND EMAIL\n";
        cin.ignore();
        getline(cin,name);
        getline(cin,mail);
    }
    void showst()
    {
        cout<<"NAME:\t"<<name<<"\t"<<"EMAIL ID\t"<<mail<<"\n";
    }
};

class student:member
{
    public:
    void studentdata()
    {
        setdetails();
    }
    void showdatastudent()
    {
        showst();
    }
    void studentfile();
};

class faculty:member{
    public:
    void facultydetails()
    {
        setdetails();
    }
     void showdatafaculty()
    {
        showst();
    }
    void facultyfile();
};
book b[10000];
book bp2[1000];
student stu[1000];
faculty fu[1000];
int de=0; 
int fcou=0;

class bookfunc:book
{
    public:
    
    void addbook()
    {
        setbookdetails();
       
        bookcount++;
    }
    void showbook()
    {
        show();
    }
    bool checkbook(int b)
    {
        for(int i=0;i<bookcount;i++)
        {
            if(arr[k]==b)
            {
                return true;
            }
        }
        return false;
    }
    int bookdetfiles();
};
student s[1000];
faculty f[1000];
student sp;
bookfunc bfunc[100000];
bookfunc bat;
int n=0,fac=0;
void arrange(int i)
{
    
    int temp2=arr[i];
     bat=bfunc[i];
     sp=s[i];
                  while(i<bookcount-1)
                  {
                      bfunc[i]=bfunc[i+1];
                      arr[i]=arr[i+1];
                    s[i]=s[i+1];
                      i++;
                  }
                  bfunc[i]=bat;
                  arr[i]=temp2;
                bookcount--;
                k--;                
}
void removebook()
{
    int i;
         bool flag =0;
         int ide;
         cout<<"ENTER BOOK ID\n";
         cin>>ide;
         for( i=0;i<bookcount;i++)
         {
             if(arr[i]==ide)
             {
                 cout<<"BOOK REMOVED\n";
                 arrange(i);
                 return;
            }
         }
         cout<<"BOOK NOT AVAILABLE\n";
}
void issuebook()
{
    int id,flag=0,flag2=0;
    string memid;
    cout<<"ENTER MEMBER ID S FOR STUDENT AND T FOR FACULTY\n";
    cin.ignore();
    getline(cin,memid);
    if(memid=="S"||memid=="s"){
    cout<<"ENTER THE BOOK ID TO ISSUE FOR STUDENT\n";
    cin>>id;
    if(n<2){
    for(int i=0;i<bookcount;i++)
    {
        if(arr[i]==id)
        {
            cout<<"BOOK AVAILABLE AND ISSUED\n";
          
        
            stu[de++].studentdata();
        
        
        
            removebook();
            flag=1;
            n++;
        }
    }
    if(flag==0){
    cout<<"BOOK NOT AVALIABLE\n";
    }
    }
    else{
        cout<<"YOU HAVE REACHED THE LIMIT\nRETURN BOOK FIRST\n";
    }
    }
    if(memid=="T"||memid=="t")
    {
         cout<<"ENTER THE BOOK ID TO ISSUE FOR TEACHER\n";
    cin>>id;
    if(fac<10){
    for(int i=0;i<bookcount;i++)
    {
        if(arr[i]==id)
        {
            cout<<"BOOK AVAILABLE AND ISSUED\n";
             
            fu[fcou++].facultydetails();
        
        
            removebook();
            flag2=1;
            fac++;
            flag2=0;
        }
    }
    if(flag2==0){
    cout<<"BOOK NOT AVALIABLE\n";
    }
    }
    else{
        cout<<"YOU HAVE REACHED THE LIMIT\nRETURN BOOK FIRST\n";
    }
    }
}
void returnboook()
{
    cout<<"ENTER MEMBER ID S FOR STUDENT AND T FOR FACULTY\n";
    string m;
    cin.ignore();
    getline(cin,m);
    if(m=="s"||m=="S")
    {
    int i=0;
    bfunc[i++].addbook();
    cout<<"BOOK RETURNED SUCCESSFULLY\n";
    n--;
    }
    else if(m=="t"||m=="T")
    {
        int i=0;
    bfunc[i++].addbook();
    cout<<"BOOK RETURNED SUCCESSFULLY\n";
        fac--;
    }
}
int bookfunc::bookdetfiles()
{
    if(id==0&&serialno==0)
    {
        cout<<"NO BOOK IS INITIALIZED\n";
        return 0;
    }
    else{
        ofstream f;
        f.open("book.txt",ios::app|ios::binary);
        f.write((char*)this,sizeof(*this));
        f.close();
        return 1;
    }

}
void student::studentfile()
{
    ofstream fi;
    fi.open("student.txt",ios::app|ios::binary);
    fi.write((char*)this,sizeof(*this));
    fi.close();
}
void faculty::facultyfile()
{
 ofstream fi;
    fi.open("faculty.txt",ios::app|ios::binary);
    fi.write((char*)this,sizeof(*this));
    fi.close();   
}
//main*************************************************************************************************************
book bkof[1000];
int j=0;

int main()
{
    int l=0;
    cout<<"WELCOME TO MY LIBRARY\n";
    cout<<"*********************\n\n";
    while(1)
    {
        cout<<"ENTER YOUR CHOICE\n";
        cout<<"1. ADD BOOK TO THE LIBRARY\n";
        cout<<"2. REMOVE BOOK FROM LIBRARY\n";
        cout<<"3. SHOW ALL BOOKS\n";
        cout<<"4. DISPLAYING ALL THE STUDENT WHO HAVE ISSUED BOOKS\n";
        cout<<"5. DISPLAYING ALL THE FACULTIES WHO HAVE ISSUED BOOKS\n";
        cout<<"6. RETURN BOOK\n";
        cout<<"7. ISSUE A BOOK\n";
        cout<<"********************************************************\n";
        int ch;
        cin>>ch;
        switch(ch)
        {
            case 0:
            cout<<"THANK YOU\n\n";
            exit(0);
            break;
            case 1:
            cout<<"ADD BOOK\n";
            cout<<"**********\n";
            
            bfunc[l++].addbook();
            bfunc[j++].bookdetfiles();
            cout<<"RECORD INSERTED\n\n";
            break;
            case 2:
             removebook();
             break;
             case 3:
               
                for(int i=0;i<bookcount;i++)
                {
                    bfunc[i].showbook();
                }
                break;
                case 4:
                cout<<"DISPLAYING ALL THE STUDENTS WHO HAVE ISSUED BOOKS \n\n";
                 for(int i=0;i<de;i++)
                {
                    stu[i].showdatastudent();
                }
                stu[0].studentfile();
                break;
                case 5:
                cout<<"DISPLAYING ALL THE FACULTIES WHO HAVE ISSUED BOOKS \n\n";
                 for(int i=0;i<fcou;i++)
                {
                    fu[i].showdatafaculty();
                }
                fu[0].facultyfile();
                break;
                case 6:
                returnboook();
                break;
                case 7:
                issuebook();
                break;
        }
    }
    return 0;
}
