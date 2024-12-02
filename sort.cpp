#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

template <typename T>
class Sorting
{
   private :
   vector<T> arr;

   void bubblesort()
   {
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size() - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
   }

   void selectionsort()
   {
        for(int i = 0; i < arr.size(); i++)
        {
            int min = i;
            for(int j = i + 1; j < arr.size(); j++)
            {
                if(arr[j] < arr[min])
                {
                    min = j;
                }
    
            }
            swap(arr[i], arr[min]);
        }
   }

    void insertionSort() 
    {
        int n = arr.size();
        for (int i = 1; i < n; ++i) 
        {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) 
            {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }



    public: 
    Sorting(const vector<T>& inputArr) : arr(inputArr) {}

    void sortList(const string& algorithm) {
        auto start = chrono::high_resolution_clock::now();
        if (algorithm == "bubble") {
            bubblesort();
        } else if (algorithm == "insertion") {
            insertionSort();
        } else if (algorithm == "selection") {
            selectionsort();
        } else {
            cout << "Unknown algorithm!" << endl;
            return;
        }

        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

        cout << "Time taken by " << algorithm << " sort: "<< duration.count() << " microseconds." << endl;
    }

    void printList() const 
    {
        for (const T& element : arr) 
        {
            cout << element << " ";
        }
        cout << endl;
    }

};


int main()
{

    vector<int> arr;

    for (int i = 0 ; i < 10000 ; i++)
    {
        arr.push_back(rand() % 10000);
    }

    // Create an object of the Sorting class
    Sorting<int> Sorting(arr);

    cout << "Choose sorting algorithm (bubble, insertion, merge): ";
    string algorithm;
    cin >> algorithm;

    cout << "Original array: ";
    Sorting.printList();

    Sorting.sortList(algorithm);

    cout << "Sorted array: ";
    Sorting.printList();
    
    return 0;
}