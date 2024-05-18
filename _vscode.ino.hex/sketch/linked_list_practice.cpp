#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\linked_list_practice.cpp"
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int n = 0)
    {
        this->data = n;
        next = NULL;
    }
};
class ll
{
    node *head;
    int l;

public:
    ll()
    {
        head = NULL;
        l = 0;
    }
    void traverse()
    {
        node *tmp = head;
        while (tmp)
        {
            cout << tmp->data << ' ';
            tmp = tmp->next;
        }
        cout << endl;
    }
    void create(int n)
    {
        node *p = new node(n);
        if (!head)
        {
            head = p;
            l++;
            return;
        }
        node *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = p;
        l++;
    }
    void add_begin(int n)
    {
        node *p = new node(n);
        if (!head)
        {
            head = p;
            l++;
            return;
        }
        p->next = head;
        head = p;
        l++;
    }
    void add_index(int n, int x)
    {
        if (x > l + 1)
        {
            cout << "error\n";
            return;
        }
        node *p = new node(n);
        if (x == 1)
        {
            p->next = head;
            head = p;
            l++;
            return;
        }
        if (x == l + 1)
        {
            create(n);
            return;
        }
        node *tmp = head;
        for (int i = 1; i < x - 1; i++)
        {
            tmp = tmp->next;
        }
        p->next = tmp->next;
        tmp->next = p;
        l++;
    }
    void del_first()
    {
        if (!head)
        {
            cout << "error\n";
            return;
        }
        node *tmp = head;
        head = head->next;
        delete tmp;
        l--;
    }
    void del_last()
    {
        if (!head)
        {
            cout << "error\n";
            return;
        }
        if (!head->next)
        {
            node *tmp = head;
            head = NULL;
            delete tmp;
            l--;
            return;
        }
        node *tmp = head;
        while (tmp->next->next)
        {
            tmp = tmp->next;
        }
        node *del = tmp->next;
        tmp->next = NULL;
        delete del;
        l--;
    }
    void del_index(int x)
    {
        if (x == 1)
        {
            del_first();
            return;
        }
        if (x == l)
        {
            del_last();
            return;
        }
        node *tmp = head;
        for (int i = 0; i < x - 2; i++)
        {
            tmp = tmp->next;
        }
        node *del = tmp->next;
        tmp->next = tmp->next->next;
        delete del;
        l--;
    }
    void reverse()
    {
        node *pre = NULL, *curr = head, *next = NULL;
        while (curr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        head = pre;
    }
    friend void conc(ll a, ll b);
    friend void merge(ll a, ll b);
    void removedup()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        node *temp = head;
        node *dup;
        while (temp != NULL)
        {
            node *p = temp;
            while (p->next != NULL)
            {
                if (temp->data == p->next->data)
                {
                    dup = p->next;
                    p->next = p->next->next;
                    delete dup;
                    l--;
                }
                else
                {
                    p = p->next;
                }
            }
            temp = temp->next;
        }
    }
};
void conc(ll a, ll b)
{
    node *tmp = a.head;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = b.head;
    a.l += b.l;
}
void merge(ll a, ll b)
{
    node *x = a.head, *y = b.head;
    while (x && y)
    {
        node *p = new node(y->data);
        p->next = x->next;
        x->next = p;
        x = x->next;
        x = x->next;
        y = y->next;
        a.l++;
    }
}
int main()
{
    ll a, b;
    a.create(6);
    a.create(5);
    a.add_begin(3);
    a.add_index(3, 2);
    a.create(3);
    a.create(6);
    a.create(6);
    a.traverse();
    a.removedup();
    a.traverse();
    // a.del_last();
    // a.reverse();
    // a.traverse();
    /* b.create(100);
    b.create(200);
    b.create(300);
    b.traverse();
    merge(a,b);
    a.traverse();
    b.traverse(); */
    return 0;
}