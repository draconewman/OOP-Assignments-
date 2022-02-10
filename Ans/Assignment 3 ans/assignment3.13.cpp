#include<iostream>
using namespace std;

class LL
{
	public:
	    int data;
	    LL *next;
};

class NODE : public LL
{
	private:
	    LL *head,*tail;
	public:
	    NODE()
	    {
	        head = NULL;
	        tail = NULL;
	    }
	    
	    void add(int n)
	    {
	        LL *tmp = new LL;
	        tmp->data = n;
	        tmp->next = NULL;
	
	        if(head == NULL)
	        {
	            head = tmp;
	            tail = tmp;
	        }
	        else
	        {
	            tail->next = tmp;
	            tail = tail->next;
	        }
	    }
	    
	    LL* gethead()
    {
        return head;
    }

    static void display(LL *head)
    {
        if(head == NULL)
        {
            cout<<"NULL"<<endl;
        }
        else
        {
            cout<< head->data <<endl;
            display(head->next);
        }
    }
    
    static void concatenate(LL *a,LL *b)
    {
        if(a!=NULL && b!=NULL)
        {
            if(a->next == NULL)
                a->next = b;
            else
                concatenate(a->next,b);
        }
        else
        {
            cout<<"Either a or b is NULL\n";
        }
    }
    
    void front(int n)
    {
        LL *tmp = new LL;
        tmp -> data = n;
        tmp -> next = head;
        head = tmp;
    }

    void after(LL *a, int value)
    {
        LL* p = new LL;
        p->data = value;
        p->next = a->next;
        a->next = p;
    }
    
    void del (LL *before_del)
	{
	    LL* temp;
	    temp = before_del->next;
	    before_del->next = temp->next;
	    delete temp;
	}

};

int main()
{
    NODE a;
    a.add(1);
    a.add(2);
    a.front(3);
    a.add(4);
    a.add(5);
    a.after(a.gethead()->next->next, 6);
    a.del(a.gethead()->next);
    cout<<"The linked list is: "<<endl;
    NODE::display(a.gethead());
    return 0;
}
