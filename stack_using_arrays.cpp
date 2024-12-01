#include <iostream>
using namespace std;
#define MAX 10

class Stack
{
    private : 
    int arr[MAX];
    int top;

    public :
    Stack() : top(-1) {}

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX-1;
    }
    
    bool push(int data)
    {
        if (!isFull())
        {
          arr[++top] = data;
          return true;
        }

        else
        { 
           printf("Stack full lil bro\n");
           return false;
        }
    }

    bool pop()
    {
        if (!isEmpty())
        {
            top--;
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
            return arr[top];
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
            for (int i = 0; i <= top; i++) 
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }

};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);

    s.pop();
    s.push(30);
    printf("peek : %d\n",s.peek());
    s.display();
}
