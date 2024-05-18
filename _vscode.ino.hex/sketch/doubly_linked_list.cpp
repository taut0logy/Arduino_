#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\doubly_linked_list.cpp"
#include <iostream>

struct node
{
    int data;
    node *prev;
    node *next;
    node(){prev=next=nullptr;}
};

class DoublyLinkedList
{
    node *head;
    node *tail;
public:
    DoublyLinkedList() { head = NULL; }

    void insertAtEnd(int value)
    {
        node *newnode = new node();
        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL)
        {
            newnode->prev = NULL;
            head = newnode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    void insertAtStart(int value)
    {
        node *newnode = new node();
        newnode->data = value;
        newnode->prev = NULL;

        if (head == NULL)
        {
            newnode->next = NULL;
            head = newnode;
        }
        else
        {
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
    }

    void insertBeforeElement(int value, int element)
    {
        node *newnode = new node();
        newnode->data = value;

        if (head == NULL)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        if (head->data == element)
        {
            head->prev = newnode;
            newnode->next = head;
            newnode->prev = NULL;
            head = newnode;
            return;
        }

        node *temp = head;
        while (temp->next != NULL && temp->next->data != element)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            std::cout << "Element not found in the linked list." << std::endl;
        }
        else
        {
            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
        }
    }

    void insertAfterElement(int value, int element)
    {
        node *newnode = new node();
        newnode->data = value;

        if (head == NULL)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        node *temp = head;
        while (temp != NULL && temp->data != element)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            std::cout << "Element not found in the linked list." << std::endl;
        }
        else
        {
            newnode->prev = temp;
            newnode->next = temp->next;

            if (temp->next != NULL)
            {
                temp->next->prev = newnode;
            }

            temp->next = newnode;
        }
    }

    void deleteElement(int value)
    {
        if (head == NULL)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        if (head->data == value)
        {
            node *temp = head;
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
            return;
        }

        node *temp = head;
        while (temp != NULL && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            std::cout << "Element not found in the linked list." << std::endl;
        }
        else
        {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }
    void deleteFirst()
    {
        if (head == NULL)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteLast()
    {
        if (head == NULL)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    void deleteBeforeElement(int element)
    {
        if (head == NULL)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        if (head->data == element)
        {
            std::cout << "No element found before the first element." << std::endl;
            return;
        }

        if (head->next != NULL && head->next->data == element)
        {
            node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            return;
        }

        node *temp = head;
        while (temp != NULL && temp->next != NULL && temp->next->data != element)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            std::cout << "Element not found in the linked list." << std::endl;
        }
        else
        {
            node *temp2 = temp->prev;
            temp->prev = temp2->prev;
            temp2->prev->next = temp;
            delete temp2;
        }
    }

    void deleteAfterElement(int element)
    {
        if (head == NULL)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        node *temp = head;
        while (temp != NULL && temp->data != element)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            std::cout << "Element not found in the linked list." << std::endl;
        }
        else if (temp->next == NULL)
        {
            std::cout << "No element found after the last element." << std::endl;
        }
        else
        {
            node *temp2 = temp->next;
            temp->next = temp2->next;
            if (temp2->next != NULL)
            {
                temp2->next->prev = temp;
            }
            delete temp2;
        }
    }

    void traverse()
    {
        if (head == NULL)
        {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        node *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    bool palindrome()
    {
        if (head == NULL)
        {
            std::cout << "Linked list is empty." << std::endl;
            return false;
        }

        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        node *temp2 = head;
        while (temp2 != temp && temp2->next != temp)
        {
            if (temp2->data != temp->data)
            {
                return false;
            }
            temp2 = temp2->next;
            temp = temp->prev;
        }
        return true;
    }
};
