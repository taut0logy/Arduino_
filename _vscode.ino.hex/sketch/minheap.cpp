#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\minheap.cpp"
#include<bits/stdc++.h>
using namespace std;
void swap(int& a, int& b)
{
    a^=b^=a^=b;
}
class MinHeap 
{
private:
    int* heap;
    int capacity;
    int size;

    // Helper function to heapify the subtree rooted at index i
    void heapify(int i)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    // Constructor
    MinHeap(int capacity=100) : capacity(capacity), size(0)
    {
        heap = new int[capacity];
    }

    // Destructor
    ~MinHeap()
    {
        delete[] heap;
    }

    // Insert an element into the heap
    void insert(int key)
    {
        if (size == capacity)
            throw out_of_range("Heap is full");

        int i = size;
        heap[i] = key;
        size++;

        int parent = (i - 1) / 2;

        while (i > 0 && heap[parent] > heap[i])
        {
            swap(heap[parent], heap[i]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    // Remove and return the minimum element from the heap
    int extractMin()
    {
        if (size == 0)
            throw out_of_range("Heap is empty");

        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);

        return root;
    }

    // Get the minimum element from the heap
    int getMin()
    {
        if (size == 0)
            throw out_of_range("Heap is empty");

        return heap[0];
    }

    // Check if the heap is empty
    bool isEmpty()
    {
        return size == 0;
    }
};
class maxheap
{
    int *arr;
    int size;
    int capacity;
public:
    maxheap(int capacity=100):capacity(capacity),size(0)
    {
        arr = new int[capacity];
    }
    ~maxheap()
    {
        delete[] arr;
    }
    void insert(int d)
    {
        if (size == capacity)
            throw out_of_range("Heap is full");
        size++;
        int index = size;
        arr[index] = d;
        while (index > 1)
        {
            int parent = index / 2;
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
            throw out_of_range("Heap is empty");
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;
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
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // Example usage
    MinHeap heap(10);

    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(25);

    while (!heap.isEmpty()) {
        std::cout << heap.extractMin() << " ";
    }

    std::cout << std::endl;

    return 0;
}