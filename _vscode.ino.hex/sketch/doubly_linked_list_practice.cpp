#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\doubly_linked_list_practice.cpp"
#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* pre;
    node* next;
    node(int n=0)
    {
        data=n;
        next=NULL;
        pre=NULL;
    }
};
class dll
{
    node* head;
    node* tail;
    int l;
public:
    dll(){head=NULL;tail=NULL;l=0;}
    void traverse()
    {
        node* tmp=head;
        while(tmp)
        {
            cout<<tmp->data<<' ';
            tmp=tmp->next;
        }
        cout<<endl;
    }
    void create(int n)
    {
        node* p=new node(n);
        if(!head)
        {
            head=tail=p;
            l++;
            return;
        }
        node* tmp=head;
        while(tmp->next)
        {
            tmp=tmp->next;
        }
        tmp->next=p;
        p->pre=tmp;
        l++;
        tail=p;
    }
    void add_begin(int n)
    {
        node *p=new node(n);
        if(!head)
        {
            head=tail=p;
            l++;
            return;
        }
        p->next=head;
        if(head)
        {
            head->pre=p;
        }
        head=p;
        l++;
    }
    void add_before(int n,int x)
    {
        if(!head->next && head->data!=n)
        {
            cout<<"not found\n";
            return;
        }
        node* p=new node(n);
        if(head->data==x)
        {
            p->next=head;
            head->pre=p;
            head=p;
            l++;
            return;
        }
        node* tmp=head;
        while(tmp->next && tmp->next->data!=x)
        {
            tmp=tmp->next;
        }
        if(!tmp->next)
        {
            cout<<"not found\n";
            return;
        }
        p->next=tmp->next;
        tmp->next->pre=p;
        p->pre=tmp;
        tmp->next=p;
        l++;
    }
    void add_after(int n,int x)
    {
        if(!head || (!head->next && head->data!=n))
        {
            cout<<"not found\n";
            return;
        }
        node* p=new node(n);
        node* tmp=head;
        while(tmp && tmp->data!=n) tmp=tmp->next;
        if(!tmp)
        {
            cout<<"not found\n";
            return;
        }
        p->next=tmp->next;
        if(tmp->next) tmp->next->pre=p;
        p->pre=tmp;
        tmp->next=p;
        l++;
    }
    void delete_begin()
    {
        if(!head)
        {
            cout<<"empty\n";
            return;
        }
        node* tmp=head;
        head=head->next;
        if(head) head->pre=NULL;
        delete tmp;
        l--;
    }
    void delete_end()
    {
        if(!head)
        {
            cout<<"empty\n";
            return;
        }
        node* tmp=tail;
        tail=tail->pre;
        if(tail) tail->next=NULL;
        delete tmp;
        l--;
    }
    void delete_node(int n)
    {
        if(!head)
        {
            cout<<"empty\n";
            return;
        }
        if(head->data==n)
        {
            node* tmp=head;
            head=head->next;
            if(head) head->pre=NULL;
            delete tmp;
            l--;
            return;
        }
        node* tmp=head;
        while(tmp->next && tmp->next->data!=n)
        {
            tmp=tmp->next;
        }
        if(!tmp->next)
        {
            cout<<"not found\n";
            return;
        }
        node* tmp2=tmp->next;
        tmp->next=tmp->next->next;
        if(tmp->next) tmp->next->pre=tmp;
        delete tmp2;
        l--;
    }
    void delete_index(int n)
    {
        if(!head)
        {
            cout<<"empty\n";
            return;
        }
        if(n==0)
        {
            node* tmp=head;
            head=head->next;
            if(head) head->pre=NULL;
            delete tmp;
            l--;
            return;
        }
        node* tmp=head;
        for(int i=0;i<n-1;i++)
        {
            if(!tmp)
            {
                cout<<"not found\n";
                return;
            }
            tmp=tmp->next;
        }
        if(!tmp->next)
        {
            cout<<"not found\n";
            return;
        }
        node* tmp2=tmp->next;
        tmp->next=tmp->next->next;
        if(tmp->next) tmp->next->pre=tmp;
        delete tmp2;
        l--;
    }
    void reverse()
    {
        if(!head) return;
        node* tmp=head;
        while(tmp)
        {
            node* tmp2=tmp->next;
            tmp->next=tmp->pre;
            tmp->pre=tmp2;
            tmp=tmp2;
        }
        tmp=head;
        head=tail;
        tail=tmp;
    }
    bool palindrome()
    {
        if(!head) return false;
        node *b=head,*e=tail;
        while(b!=e && b->next!=e)
        {
            if(b->data!=e->data) return false;
            b=b->next;
            e=e->pre;
        }
        return true;
    }
    friend dll sort_merge(dll a,dll b);
};

dll sort_merge(dll a,dll b)
{
    dll c;
    node *x=a.head,*y=b.head;
    while(x || y)
    {
        if(x && y)
        {
            if(x->data>y->data)
            {
                c.create(x->data);
                x=x->next;
            }
            else
            {
                c.create(y->data);
                y=y->next;
            }
        }
        else if(!x)
        {
            c.create(y->data);
            y=y->next;
        }
        else
        {
            c.create(x->data);
            x=x->next;
        }
    }
    return c;
}
