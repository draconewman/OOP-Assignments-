#include <iostream>
#include <fstream>
using namespace std;

class book
{
    char author[100],publisher[100],title[100];
    int bookid;
    int Copy;
    float price;
public:
    book(int x)
    {
        bookid=x;
    }
    book()
    {
        cout<<"Enter title:";cin>>title;
        cout<<"Enter author:";cin>>author;
        cout<<"Enter publisher:";cin>>publisher;
        cout<<"Enter bookid:";cin>>bookid;
        cout<<"Enter price:";cin>>price;
        Copy=1;
    }
    int operator==(book b)
    {
        cout<<b.bookid<<"*"<<bookid<<"\n";
        if(b.bookid==bookid)
            return(1);
        else
            return(0);
    }
    void increasecount()
    {
        Copy++;
		cout<<"Copy number increased successfully\n";
    }
    int check()
    {
        if(Copy>0)
            Copy--;
        return(Copy+1);
    }
    int increasebookcount(int id)
    {
        if(id==bookid)
        {
            Copy++;
            return(1);
        }
        else
            return(0);
    }
};

class booklist
{
public:
    int Unique(book b)
    {
        int i=0;
        ifstream f;
        f.open("booklist",ios::binary|ios::in);
        while(!f.eof())
        {
            cout<<"!\n";
            i++;
            book c(0);
            f.read((char *)&c,sizeof(book));
            if(c==b)
            {
                f.close();
				return(i);
            }
        }
        return(0);
    }
    void addbook()
    {
        book b;
        int x=Unique(b);
		cout<<x;
        if(x)
        {
            book c(0);
            fstream f;
            f.open("booklist",ios::ate|ios::in|ios::binary);
            f.seekg((x-1)*sizeof(book),ios::beg);
            f.read((char *)&c,sizeof(book));
            c.increasecount();
            f.clear();
            f.seekp((x-1)*sizeof(book),ios::beg);
            f.write((char *)&c,sizeof(book));
            f.close();
        }
        else
        {
            fstream f;
            f.open("booklist",ios::app|ios::out|ios::binary);
            f.write((char *)&b,sizeof(book));
            f.close();
        }
    }
    int bookavailability(int id)
    {
            book b(id);
            int i=0;
        fstream f;
        f.open("booklist",ios::binary|ios::in);
        while(!f.eof())
        {
            cout<<"!\n";
            i++;
            book c(0);
            f.read((char *)&c,sizeof(book));
            if(c==b)
            {
               int z=b.check();
               f.seekp((i-1)*sizeof(book),ios::beg);
               f.write((char *)&b,sizeof(book));
               f.close();return(z);
            }
        }
        return(0);
    }
    void keepthebookback(int id)
    {
        int i=0;
        book c(0);
        fstream f;
        f.open("booklist",ios::binary|ios::in|ios::out|ios::ate);
        while(!f.eof())
        {
            i++;
            if(c.increasebookcount(id))
            {
                f.seekp((i-1)*sizeof(book),ios::beg);
                f.write((char *)&c,sizeof(book));
                f.close();
                return;
            }
        }
        f.close();
    }
}bl;

class member
{
   int  memberid;
   char email[100],name[40];
   int flag;
   int available;
   public:
       member(int x)
       {
           memberid=x;
       }
    member()
    {
        cout<<"Enter memberid:";cin>>memberid;
        cout<<"Enter emailid:";cin>>email;
        cout<<"Enter name:";cin>>name;
        cout<<"Enter (1)faculty (2)student:";cin>>flag;
        if(flag==1)
            available=10;
        else
            available=2;
    }
    int operator==(member b)
    {
        cout<<b.memberid<<"+"<<memberid<<"\n";
        if(b.memberid==memberid)
            return(1);
        else
            return(0);
    }
    int Available()
    {
        cout<<"%"<<available<<"\n"<<name<<"\n";
        if(available>0)
            return(1);
        else
            return(0);
    }
};

class memberlist
{
    public:
    int Unique(member &b)
    {
        int i=0;
        ifstream f;
        f.open("memberlist",ios::binary|ios::in);
        while(!f.eof())
        {
            cout<<"!"<<i<<"\n";
            i++;
            member c(0);
            f.read((char *)&c,sizeof(member));
            if(c==b)
            {
                printf("*\n");
                f.close();return(i);
            }
        }
        f.close();
        return(0);
    }
    void addmember()
    {
        member b;
        int x=Unique(b);cout<<x;
        if(x)
        {
            cout<<"Id is not unique\n";
        }
        else
        {
            fstream f;
            f.open("memberlist",ios::app|ios::out|ios::binary);
            f.write((char *)&b,sizeof(member));
            f.close();
            cout<<"successfully added to the system";
        }
    }
    int booksavailable(int x)
    {
        member c(0);
        fstream f;f.open("memberlist",ios::in|ios::out|ios::ate|ios::binary);f.seekp((x-1)*sizeof(book),ios::beg);f.seekg((x-1)*sizeof(book),ios::beg);
        f.read((char *)&c,sizeof(member));
        f.close();
        if(c.Available()){return(1);}else return(0);
    }
}ml;

class transaction
{
    char date[8];
    int bookid;
    int memberid;
    int serialnumber;
    int returned;
    int r;
    int fail;
public:
    transaction(int x){}
    transaction()
    {
        cout<<"Enter date of transaction(ddmmyyyy):";cin>>date;
        cout<<"Enter memberid:";cin>>memberid;
        cout<<"Enter bookid:";cin>>bookid;
        cout<<"Is it (0)return slip or (1)issue slip?";cin>>r;
        if(r)
        {
            returned=0;
        }
        else
        {
            cout<<"Enter serialnumber:";cin>>serialnumber;
        }
    }
    int returntype()
    {
        return(r);
    }
    int returnmemberid()
    {
        return(memberid);
    }
    void successfulissue(int x)
    {
        fail=0;
        serialnumber=x;
    }
    void failedissue()
    {
        fail=1;
    }
    int returnbookid()
    {
        return(bookid);
    }
    int checkreturnslip(transaction &r)
    {
       if( (r.fail==0)&&(r.bookid==bookid)&&(r.serialnumber==serialnumber))
       {
           r.returned=1;return(1);
       }
       return(0);
    }
};

class transactionlist
{
public:
    void searchtransactionlist(transaction & trsn)
    {
        int i=0;
        fstream f;
        f.open("transactionlist",ios::in|ios::out|ios::ate|ios::binary);
        transaction t(0);
        while(!f.eof())
        {i++;
            f.read((char *)&t,sizeof(transaction));

            if(t.checkreturnslip(trsn))
            {
                f.seekp(((i-1)*sizeof(transaction)),ios::beg);
                f.write((char *)&trsn,sizeof(transaction));
                bl.keepthebookback(trsn.returnbookid());
                f.close();return;
            }
        }
        f.close();return;
    }
    addtransaction()
    {
        int z;
        fstream f;
        transaction t;
        //issue slip
        if(t.returntype())
        {
            member m(t.returnmemberid());
            cout<<"@"<<t.returnmemberid()<<"\n";
            z=ml.Unique(m);cout<<"!"<<z;
            //valid member
            if(z)
            {
                int y;
                y=ml.booksavailable(z);
                cout<<"^"<<z<<"\n";cout<<y;
                if(y==1)
                {
                    int p;
                    p=bl.bookavailability(t.returnbookid());cout<<"$"<<p<<"\n";
                    //book available
                    if(p)
                    {
                        cout<<"book available and serial number is:"<<p<<"\n";
                        t.successfulissue(p);
                    }
                    //book not available
                    else
                    {
                        cout<<"Book is not available\n";
                        t.failedissue();
                    }
                }
                else
                    cout<<"You can't take more books\n";
            }
            //not valid member
            else
            {
                cout<<"You are not a valid member";
            }
            fstream f;
            f.open("transactionlist",ios::out|ios::app|ios::binary);
            f.write((char *)&t,sizeof(transaction));
        }
        //return slip
        else
        {
            member m(t.returnmemberid());
            //valid member
            if(!ml.Unique(m))
            {
                searchtransactionlist(t);
            }
            //not valid member
            else
            {
                cout<<"You are not a valid member";
            }
            fstream f;
            f.open("transactionlit",ios::out|ios::app|ios::binary);
            f.write((char *)&t,sizeof(transaction));
        }
    }
}tl;

class library
{
public:
    access()
    {
        while(1)
        {
            cout<<"(1)add book to library\n(2)Add member\n(3)Submit transaction slip\n";
            int i;cin>>i;
            switch(i)
            {
            case(1):
                {
                    bl.addbook();break;
                }
            case(2):
                {
                    ml.addmember();break;
                }
            case(3):
                {
                    tl.addtransaction();break;
                }
            }
        }
    }
}l;

int main()
{
    fstream f,g,h;f.open("booklist",ios::out|ios::binary);
    g.open("memberlist",ios::out|ios::binary);
    h.open("transactionlist",ios::out|ios::binary);
    f.close();
    g.close();
    h.close();
    l.access();
    return 0;
}
