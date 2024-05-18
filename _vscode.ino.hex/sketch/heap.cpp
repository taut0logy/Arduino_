#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\heap.cpp"
#include <iostream>
using namespace std;

class maxheap
{
public:
    int arr[100];
    int size = 0;

    void insert(int d)
    {
        int index = size++;
        arr[index] = d;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletion()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        arr[0] = arr[--size];
        int i = 0;
        while (i < size)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class minheap
{
public:
    int arr[100];
    int size = 0;

    void insert(int d)
    {
        int index = size++;
        arr[index] = d;
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletion()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        arr[0] = arr[--size];
        int i = 0;
        while (i < size)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < size && arr[i] > arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < size && arr[i] > arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    int i = n - 1;
    while (i > 0)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        i--;
    }
}

int main()
{
    minheap x;
    x.insert(10);
    x.insert(20);
    x.insert(30);
    x.insert(40);
    x.insert(50);
    x.insert(70);
    x.insert(570);
    x.print();
    x.deletion();
    x.print();

    int arr[5] = {54, 53, 55, 52, 50};
    int n = 5;
    

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
