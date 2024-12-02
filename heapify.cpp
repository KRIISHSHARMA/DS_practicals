#include <iostream>
#include <vector>
using namespace std;

// template <typename T>
// struct Node 
// {
//     T data;
//     Node* left;
//     Node* right;

//     Node(T val)
//     {
//         data = val;
//         left = right = nullptr;
//     }
// };

template <typename T>
class MinHeap
{
   private:
   vector<T> heap;
   
   void bubbleup(int index)
   {
      while (index > 0)
      {
         int parentIndex = (index - 1)/2;
         if (heap[index] < heap[parentIndex])
         {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
         }
         else break;
      }
   }

   public : 

   void insert(T val)
   {
     heap.push_back(val);
     bubbleup(heap.size()-1);
   }

   void display()
   {
        printf("Heap elements: ");
        for (T val : heap) {
            cout << val << " ";
        }
        printf("\n");
   }


};


int main()
{
    MinHeap<int> h;
    h.insert(10);
    h.insert(5);
    h.insert(15);
    h.insert(12);
    h.insert(17);
    h.insert(13);
    h.insert(18);
    h.display();
}