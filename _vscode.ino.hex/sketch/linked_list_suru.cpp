#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\linked_list_suru.cpp"
#include<bits/stdc++.h>
#include<stack>
using namespace std;
typedef long long ll;
struct node
{
   int data;
   struct node *next;
};
class l_list
{
   public:
   node *head;
   int l;
   l_list()
   {
      head=NULL;
      l=0;
   }
   node *access()
   {
     return head;
   }
   void null()
   {
    head=nullptr;
    l=0;
   }
   l_size()
   {
    return l;
   }
   void traverse()
   {
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
   }
   void insertion_begin(int n)
   {
    node *ptr=new node();
    ptr->next=head;
    ptr->data=n;
    head=ptr;
    l++;
   }
   void reverse()
   {
    stack<struct node*>s;
    node *temp=head;
    while(temp!=NULL)
    {
        s.push(temp);
        temp=temp->next;
    }
    head=s.top();
    temp=head;
    s.pop();
    while(!s.empty())
    {
        temp->next=s.top();
        temp=s.top();
        s.pop();
    }
    temp->next=NULL;
   }
};
int main()
{
    l_list a;
    a.insertion_begin(40);
    a.insertion_begin(30);
    a.insertion_begin(20);
    a.insertion_begin(10);
    a.traverse();
    cout<<endl;
    a.reverse();
    a.traverse();
    cout<<endl;
    return 0;
}