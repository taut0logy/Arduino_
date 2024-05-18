#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\circular_linked_list.cpp"
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
class circularLinkedList
{
private:
    Node* head;
    int l;
public:
    circularLinkedList()
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
            return;
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
            insert_begin(x);
            return;
        }
        while(tmp->link!=nullptr && tmp->link->data!=y)
            tmp=tmp->link;
        if(tmp->link==nullptr) 
            return;
        p->link=tmp->link;
        tmp->link=p;
        l++;
    }
    void insert_end(int x)
    {
        Node *p=new Node(x);
        Node *tmp=head;
        while(tmp->link!=nullptr)
            tmp=tmp->link;
        tmp->link=p;
        l++;
    }
    void delete_begin()
    {
        if(head==nullptr) 
            return;
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
        if(tmp==nullptr || tmp->link==nullptr) 
            return;
        Node *p=tmp->link;
        tmp->link=p->link;
        delete p;
        l--;
    }
    void delete_before(int y)
    {
        Node *tmp=head;
        if(tmp->link->data==y)
        {
            delete_begin();
            return;
        }
        while(tmp->link!=nullptr && tmp->link->link->data!=y)
            tmp=tmp->link;
        if(tmp->link==nullptr || tmp->link->link==nullptr)

            return;
        Node *p=tmp->link;
        tmp->link=p->link;
        delete p;
        l--;
    }
    void delete_end()
    {
        Node *tmp=head;
        if(tmp->link==nullptr)
        {
            delete_begin();
            return;
        }
        while(tmp->link->link!=nullptr)
            tmp=tmp->link;
        Node *p=tmp->link;
        tmp->link=nullptr;
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
};
int main()
{
    circularLinkedList l;
    l.create(1);
    l.create(2);
    l.create(3);
    l.create(4);
    l.create(5);
    l.display();
    l.insert_begin(0);
    l.display();
    l.insert_after(2,6);
    l.display();
    l.insert_before(2,7);
    l.display();
    l.insert_end(8);
    l.display();
    l.delete_begin();
    l.display();
    l.delete_after(2);
    l.display();
    l.delete_before(2);
    l.display();
    l.delete_end();
    l.display();
    return 0;
}