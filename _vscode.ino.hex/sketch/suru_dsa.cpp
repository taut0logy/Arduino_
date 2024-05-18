#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\suru_dsa.cpp"
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class circular
{
public:
    node *head;
    int l;

    circular()
    {
        head = NULL;
        l = 0;
    }

    int size()
    {
        return l;
    }

    void traversal()
    {
        if (head == NULL)
        {
            cout << "empty" << endl;
            return;
        }

        node *ptr = head;
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != head);
        cout << endl;
    }

    void insert_begin(int n)
    {
        node *ptr = new node(n);

        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
            head = ptr;
        }
        l++;
    }

    void insert_last(int n)
    {
        node *ptr = new node(n);

        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
        l++;
    }

    void del_beg()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            node *delNode = head;
            temp->next = head->next;
            head = head->next;
            delete delNode;
        }
        l--;
    }

    void de_last()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        else if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            node *temp = head;
            while (temp->next->next != head)
            {
                temp = temp->next;
            }
            node *delNode = temp->next;
            temp->next = head;
            delete delNode;
        }
        l--;
    }
};

int main()
{
    circular myList;

    // Insert elements at the beginning
    myList.insert_begin(10);
    myList.insert_begin(20);
    myList.insert_begin(30);

    // Insert elements at the end
    myList.insert_last(40);
    myList.insert_last(50);
    myList.insert_last(60);

    // Display the circular linked list
    myList.traversal();

    // Delete the first node
    myList.del_beg();

    // Delete the last node
    myList.de_last();

    // Display the updated circular linked list
    myList.traversal();

    return 0;
}