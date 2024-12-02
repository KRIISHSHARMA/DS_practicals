#include <iostream>
using namespace std;
#define MAX 10

class queue
{
    private : 
    int arr[MAX];
    int front;
    int rear;
    int size;
    
    public :
    queue() : front(0) , rear(-1) , size(0) {}

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == MAX;
    }
    
    bool enqueue(int data)
    {
        if (!isFull())
        {
           rear = (rear + 1) % MAX;
           arr[rear] = data;
           size++;
           return true;
        }

        else
        { 
           printf("queue full lil bro\n");
           return false;
        }
    }

    bool dequeue()
    {
        if (!isEmpty())
        {
            front = (front + 1) % MAX;
            size--;
            return true;
        }
        else 
        {
            printf("stack is empty\n");
            return false;
        }
    }


    int peek()
    {
        if (!isEmpty())
        {
            return arr[front];
        }
        else return -1;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            printf("Stack is empty\n");
        } 
        else 
        {
            for (int i = 0; i <= size-1; i++) 
            {
                printf("%d ", arr[(front + i) % MAX]);
            }
            printf("\n");
        }
    }

};

int main()
{
    queue s;

    s.enqueue(10);
    s.enqueue(20);

    s.dequeue();
    s.enqueue(30);
    printf("peek : %d\n",s.peek());
    s.display();
}
