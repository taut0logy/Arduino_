#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\linked_list.cpp"
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* link;
    Node(int x)
    {
        this->data=x;
        link=nullptr;
    }
};
class linkedList
{
private:
    Node* head;
    int l;
public:
    linkedList()
    {
        head=nullptr;
    }
    int size()
    {
        return l;
    }
    Node* begin()
    {
        return head;
    }
    void create(int x)
    {
        Node *p=new Node(x);
        if(head==nullptr)
        {
            head=p;
            l++;
            return;
        }
        Node *tmp=head;
        while(tmp->link!=nullptr)
            tmp=tmp->link;
        tmp->link=p;
        l++;
    }
    void insert_begin(int x)
    {
        Node *p=new Node(x);
        p->link=head;
        head=p;
        l++;
    }
    void insert_after(int y,int x)
    {
        Node *p=new Node(x);
        Node *tmp=head;
        while(tmp!=nullptr && tmp->data!=y)
            tmp=tmp->link;
        if(tmp==nullptr) 
        {
            cout<<"Not found"<<endl;
            return;
        }
        p->link=tmp->link;
        tmp->link=p;
        l++;
    }
    void insert_before(int y,int x)
    {
        Node *p=new Node(x);
        Node *tmp=head;
        if(tmp->data==y)
        {
            p->link=head;
            head=p;
            l++;
            return;
        }
        if(tmp==nullptr)
        {
            cout<<"Not found"<<endl;
            return;
        }
        while(tmp->link!=nullptr && tmp->link->data!=y)
            tmp=tmp->link;
        if(tmp->link==nullptr)
        {
            cout<<"Not found"<<endl;
            return;
        }
        p->link=tmp->link;
        tmp->link=p;
        l++;
    }
    void insert_last(int x)
    {
        Node *p=new Node(x);
        if(head==nullptr)
        {
            head=p;
            l++;
            return;
        }
        Node *tmp=head;
        while(tmp->link!=nullptr)
            tmp=tmp->link;
        tmp->link=p;
        l++;
    }
    void delete_begin()
    {
        if(head==nullptr)
        {
            cout<<"Empty"<<endl;
            return;
        }
        Node *tmp=head;
        head=head->link;
        delete tmp;
        l--;
    }
    void delete_after(int y)
    {
        Node *tmp=head;
        while(tmp!=nullptr && tmp->data!=y)
            tmp=tmp->link;
        if(tmp==nullptr)
        {
            cout<<"Not found"<<endl;
            return;
        }
        if(tmp->link==nullptr)
        {
            cout<<"Not found"<<endl;
            return;
        }
        Node *p=tmp->link;
        tmp->link=tmp->link->link;
        delete p;
        l--;
    }
    void delete_before(int y)
    {
        Node *tmp=head;
        if(tmp->data==y)
        {
            cout<<"Not found"<<endl;
            return;
        }
        if(tmp==nullptr)
        {
            cout<<"Not found"<<endl;
            return;
        }
        while(tmp->link!=nullptr && tmp->link->data!=y)
            tmp=tmp->link;
        if(tmp->link==nullptr)
        {
            cout<<"Not found"<<endl;
            return;
        }
        Node *p=tmp->link;
        tmp->link=tmp->link->link;
        delete p;
        l--;
    }
    void delete_last()
    {
        if(head==nullptr)
        {
            cout<<"Empty"<<endl;
            return;
        }
        Node *tmp=head;
        while(tmp->link->link!=nullptr)
            tmp=tmp->link;
        Node *p=tmp->link;
        tmp->link=nullptr;
        delete p;
        l--;
    }
    void delete_index(int x)
    {
        if(x==1)
        {
            Node *tmp=head;
            head=head->link;
            delete tmp;
            l--;
            return;
        }
        Node *tmp=head;
        for(int i=1;i<x-1;i++)
            tmp=tmp->link;
        Node *p=tmp->link;
        tmp->link=tmp->link->link;
        delete p;
        l--;
    }
    void delete_key(int x)
    {
        Node *tmp=head;
        if(tmp->data==x)
        {
            head=head->link;
            delete tmp;
            l--;
            return;
        }
        while(tmp->link!=nullptr && tmp->link->data!=x)
            tmp=tmp->link;
        if(tmp->link==nullptr)
        {
            cout<<"Not found"<<endl;
            return;
        }
        Node *p=tmp->link;
        tmp->link=tmp->link->link;
        delete p;
        l--;
    }
    void display()
    {
        Node *tmp=head;
        while(tmp!=nullptr)
        {
            cout<<tmp->data<<" ";
            tmp=tmp->link;
        }
        cout<<endl;
    }
    void reverse()
    {
        Node *prev=nullptr,*curr=head,*next=nullptr;
        while(curr!=nullptr)
        {
            next=curr->link;
            curr->link=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
    void sort()
    {
        Node *tmp=head;
        while(tmp!=nullptr)
        {
            Node *p=tmp->link;
            while(p!=nullptr)
            {
                if(tmp->data>p->data)
                {
                    int t=tmp->data;
                    tmp->data=p->data;
                    p->data=t;
                }
                p=p->link;
            }
            tmp=tmp->link;
        }
    }
    void remove_duplicate()
    {
        Node *tmp=head;
        while(tmp!=nullptr)
        {
            Node *p=tmp->link;
            while(p!=nullptr && p->data==tmp->data)
            {
                Node *q=p;
                tmp->link=p->link;
                p=p->link;
                delete q;
                l--;
            }
            tmp=tmp->link;
        }
    }
};
void conc(linkedList l1,linkedList l2)
{
    Node *h1=l1.begin(),*h2=l2.begin();
    while(h1->link!=nullptr) h1=h1->link;
    h1->link=h2;
}
void merge(linkedList l1,linkedList l2)
{
    Node *h1=l1.begin(),*h2=l2.begin();
    while(h2!=nullptr)
    {
        Node* p=new Node(h2->data);
        p->link=h1->link;
        h1->link=p;
        h1=h1->link;
        h1=h1->link;
        h2=h2->link;
    }
}
int main()
{
    linkedList l1,l2;
    l1.create(30);
    l1.insert_begin(20);
    l1.insert_before(20,10);
    l1.insert_last(40);
    l1.insert_after(40,50);
    l2.create(80);
    l2.insert_begin(70);
    l2.insert_before(70,60);
    l2.insert_last(90);
    l1.display();
    l2.display();
    //conc(l1,l2);
    merge(l1,l2);
    l1.display();
    return 0;
}