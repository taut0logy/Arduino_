#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\ll02.cpp"
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
public:
    Node* head;
    linkedList()
    {
        head=nullptr;
    }
    void create(int x)
    {
        Node *p=new Node(x);
        if(head==nullptr)
        {
            head=p;
            return;
        }
        Node *tmp=head;
        while(tmp->link!=nullptr)
            tmp=tmp->link;
        tmp->link=p;
    }
    void insert_begin(int x)
    {
        Node *p=new Node(x);
        p->link=head;
        head=p;
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
    int length()
    {
        Node *tmp=head;
        int l=0;
        while(tmp!=nullptr)
        {
            l++;
            tmp=tmp->link;
        }
        return l;
    }
};
void merge(linkedList l1,linkedList l2)
{
    Node *h1=l1.head,*h2=l2.head;
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
    l1.create(1);
    l1.create(2);
    l1.create(3);
    l2.create(4);
    l2.create(5);
    l2.create(6);
    l1.display();
    l2.display();
    merge(l1,l2);
    l1.display();
    cout<<l1.length()<<endl;
    return 0;
}