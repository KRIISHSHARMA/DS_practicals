#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class MinHeap 
{
private:
    vector<T> heap;

    void bubbleup(int index) 
    {
        while (index > 0) 
        {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) 
            {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } 
            else 
            {
                break;
            }
        }
    }

    void heapify(int index) 
    {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] < heap[smallest])  smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest]) smallest = right;

        if (smallest != index) 
        {
            swap(heap[index], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    void insert(T val) {
        heap.push_back(val);
        bubbleup(heap.size() - 1);
    }

    T extractMin() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        T minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapify(0);
        }
        return minVal;
    }

    vector<T> heapSort() {
        vector<T> sorted;
        while (!heap.empty()) {
            sorted.push_back(extractMin());
        }
        return sorted;
    }

    void display() {
        cout << "Heap elements: ";
        for (const T &val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap<int> h;
    h.insert(10);
    h.insert(5);
    h.insert(15);
    h.insert(12);
    h.insert(17);
    h.insert(13);
    h.insert(18);

    h.display();

    vector<int> sorted = h.heapSort();
    cout << "Sorted elements: ";
    for (const int &val : sorted) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
