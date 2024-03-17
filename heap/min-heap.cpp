#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
private:
    vector<int> heap;
    int capacity;

public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
    }

    int getLeftChildIndex(int parentIndex) // O(1)
    {
        int leftChildIndex = 2 * parentIndex + 1;
        if (leftChildIndex < capacity)
        {
            return leftChildIndex;
        }
        {
            return leftChildIndex;
        }
        return -1;
    }

    int getRightChildIndex(int parentIndex) // O(1)
    {
        int rightChildIndex = 2 * parentIndex + 2;
        if (rightChildIndex < capacity)
        {
            return rightChildIndex;
        }
        return -1;
    }

    int getParentIndex(int childIndex) // O(1)
    {
        if (childIndex < heap.size() && childIndex > 0)
        {
            return (childIndex - 1) / 2;
        }
        return -1;
    }

    void insert(int value) // insert new value in heap 1. add at end 2. heapify from bottom to top
    {                      // O(logn)
        if (heap.size() == capacity)
        {
            cout << "Heap is full" << endl;
            return;
        }
        heap.push_back(value);
        int index = heap.size() - 1;
        while (index > 0)
        {
            int parentIndex = getParentIndex(index);
            if (heap[parentIndex] <= heap[index])
            {
                break;
            }
            swap(heap[parentIndex], heap[index]);
            index = parentIndex;
        }
    }

    void minHeapify(int index) // one index is out of place 1. find left and right child 2. find smallest of 3 3. swap with smallest 4. call minHeapify on smallest
    {                          // O(logn)
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);
        int smallest = index;
        if (leftChildIndex < heap.size() && heap[leftChildIndex] < heap[smallest])
        {
            smallest = leftChildIndex;
        }
        if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[smallest])
        {
            smallest = rightChildIndex;
        }
        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            minHeapify(smallest);
        }
    }

    int extractMin()
    { // O(logn) steps 1. store min 2. swap min with last 3. pop last 4. call minHeapify on 0
        if (heap.size() == 0)
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        if (heap.size() == 1)
        {
            int minValue = heap[0];
            heap.pop_back();
            return minValue;
        }
        int minValue = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        minHeapify(0);
        return minValue;
    }

    void decreaseKey(int index, int newValue) // O(logn)
    {
        if (index < heap.size())
        {
            heap[index] = newValue;
            while (index > 0)
            {
                int parentIndex = getParentIndex(index);
                if (heap[parentIndex] <= heap[index])
                {
                    break;
                }
                swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            }
        }
    }

    void deleteKey(int index) // O(logn)
    {
        if (index < heap.size())
        {
            swap(heap[index], heap[heap.size() - 1]);
            heap.pop_back();
            minHeapify(index);
        }
    }

    void buildHeap(vector<int> arr) // O(n)
    {
        heap = arr;
        for (int idx = arr.size() / 2 - 1; idx >= 0; idx--)
        {
            minHeapify(idx);
        }
    }

    void printHeap()
    {
        for (int i : heap)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {3, 2, 1, 15, 5, 4, 45};
    MinHeap minHeap(arr.size());
    minHeap.buildHeap(arr);
    minHeap.printHeap();
}