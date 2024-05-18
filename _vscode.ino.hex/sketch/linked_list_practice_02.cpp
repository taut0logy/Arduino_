#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\linked_list_practice_02.cpp"
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
void traverse(node *&head)
{
    node *tmp = head;
    while (tmp)
    {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << endl;
}
void create(node *&head, int &l, int n)
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
void add_begin(node *&head, int &l, int n)
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
void add_index(node *&head, int &l, int n, int x)
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
        create(head, l, n);
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
void del_first(node *&head, int &l)
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
void del_last(node *&head, int &l)
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
void del_index(node *&head, int &l, int x)
{
    if (x == 1)
    {
        del_first(head, l);
        return;
    }
    if (x == l)
    {
        del_last(head, l);
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
void deleteMiddleNode(node *&head)
{
    int l=0;
    node *temp = head;
    while (temp)
    {
        l++;
        temp = temp->next;
    }
    int n = (l + 1)/2;
    node *p = head;
    for (int i = 0; i < n - 2; i++)
    {
        p = p->next;
    }
    node *del = p->next;
    p->next = p->next->next;
    delete del;
}
void deletemid(node *&head)
{
    node *slow = head, *fast = head, *prev = NULL;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
}
void reverse(node *&head)
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
void removedup(node *&head, int &l)
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
            }
            else
            {
                p = p->next;
            }
        }
        temp = temp->next;
    }
}
node *split_in_two(node *&head, int &l)
{
    node *temp = head;
    int n = ceil(l / 2);
    for (int i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    node *head2 = temp->next;
    temp->next = NULL;
    return head2;
    l -= n;
}
void removeDuplicates(node *&head,int &l)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            // Duplicate element found, remove next node
            node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            l--;
        }
        else
        {
            // Element not a duplicate, move to next node
            curr = curr->next;
        }
    }
}
void merge_alternate(node *&x, node *&y)
{
    while (x && y)
    {
        node *p = new node(y->data);
        p->next = x->next;
        x->next = p;
        x = x->next;
        x = x->next;
        y = y->next;
    }
    if (y)
    {
        x->next = y;
    }
    y = NULL;
}
void sort(node *&head)
{
    node *temp = head;
    while (temp)
    {
        node *p = temp->next;
        while (p)
        {
            if (temp->data > p->data)
            {
                int t = temp->data;
                temp->data = p->data;
                p->data = t;
            }
            p = p->next;
        }
        temp = temp->next;
    }
}
void swapnode(node* &x,node* &y)
{
    node* temp = x;
    x = y;
    y = temp;
}
int main()
{
    node *head = NULL;
    int l = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        create(head, l, x);
    }
    traverse(head);
    removedup(head, l);
    traverse(head);
    sort(head);
    traverse(head);

    // cout<<sizeof(head->next->next)<<endl;
    /* node *head2 = split_in_two(head, l);
    int l2 = l / 2;
    traverse(head);
    traverse(head2);
    merge_alternate(head, head2);
    traverse(head);
    traverse(head2); */
    /* add_begin(head, l, 5);
    traverse(head);
    add_index(head, l, 10, 3);
    traverse(head);
    del_first(head, l);
    traverse(head);
    del_last(head, l);
    traverse(head);
    del_index(head, l, 2);
    traverse(head);
    reverse(head);
    traverse(head); */
    return 0;
}