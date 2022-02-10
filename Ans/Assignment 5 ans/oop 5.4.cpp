#include <iostream>
using namespace std;

class player
{
    char name[30],dob[8];
public:
    player()

    {
        cout<<"Enter Name of the player\n";
        cin>>name;
        cout<<"Enter date of birth(ddmmyyyy) of the player\n";
        cin>>dob;
    }
    void display()
    {
        cout<<"Name:"<<name<<"\tDate of Birth:";
        int j;
        for(j=0;j<8;j++)
        {
            if((j==2)||(j==4))
                cout<<"/";
            cout<<dob[j];
        }
        cout<<"\n";
    }
};

class bowler:virtual public player
{
    int wicket;float economy;
public:
    bowler()
        {
        cout<<"Enter number of wickets taken by the player\n";
        cin>>wicket;
        cout<<"Enter average economy of the player\n";
        cin>>economy;
        }
        void display()
            {
                cout<<"wickets:";
                cout<<wicket<<"\n";
                cout<<"Average economy:";
                cout<<economy<<"\n";
            }
};

class batsman:virtual public player
{
    int run;float avg;
public:
    batsman()
    {
        cout<<"Enter total runs scored by the player\n";
        cin>>run;
        cout<<"Enter average score of the player\n";
        cin>>avg;
    }
   void display()
            {
                cout<<"Runs:";
                cout<<run<<"\n";
                cout<<"Average run:";
                cout<<avg<<"\n";
            }
};

class allrounder:public bowler,public batsman
{
public:
    void display()
    {
        batsman::display();
        bowler::display();
    }
};

class PAIR
{
    batsman bat;
    bowler bwl;
public:
    void display()
    {
    bat.player::display();
    bat.display();
    bwl.player::display();
    bwl.display();
    }
};
int main()
{
    while(1)
    {
        cout<<"(1)Enter details of a bats man\n(2)Enter details of a bowler\n(3)Enter details of an allrounder\n(4)Enter a pair\n(5)Exit\n";
        int i;cin>>i;
        switch(i)
        {
        case(1):
            {
                batsman b;
                b.player::display();
                b.display();break;
            }
            case(2):
            {
                bowler b;
                b.player::display();
                b.display();break;
            }
            case(3):
            {
                allrounder c;
                c.player::display();
                c.display();break;
            }
            case(4):
            {
                PAIR p;
                p.display();break;
            }
            case(5):
                return(0);
        }
    }
    return 0;
}
