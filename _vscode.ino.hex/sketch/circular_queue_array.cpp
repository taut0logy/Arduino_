#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\circular_queue_array.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class circular
{
    private:
        int *arr;
        int front;
        int rear;
        int MAX;
    public:
        circular()
        {
            arr = new int[MAX];
            front = -1;
            rear = -1;
        }
        circular(int n)
        {
            MAX = n;
            arr = new int[MAX];
            front = -1;
            rear = -1;
        }
        bool isempty()
        {
            if (front == -1 && rear == -1)
            {
                return true;
            }
            return false;
        }
        bool isfull() {
            if ((rear + 1) % MAX == front)
            {
                return true;
            }
            return false;
        }
        void enqueue(int data)
        {
            if (isfull())
            {
                cout<<"Queue full"<<endl;
                return;
            }
            else if (isempty())
            {
                front = 0;
                rear = 0;
                arr[rear] = data;
            }
            else
            {
                rear = (rear + 1) % MAX;
                arr[rear] = data;
            }
        }
        void dequeue()
        {
            if (isempty())
            {
                cout<<"Queue empty"<<endl;
                return;
            }
            else if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % MAX;
            }
        }
        int peek()
        {
            if (isempty())
            {
                cout<<"Queue empty"<<endl;
                return -1;
            }
            return arr[front];
        }
};

int main()
{
    circular q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.isempty() << endl;
    return 0;
}