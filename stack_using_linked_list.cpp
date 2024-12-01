#include <iostream>
using namespace std;
#define MAX 10

struct Node 
{
   int data;
   Node* next;
};

class Stack
{
    private : 
    
    Node* top;

    public :
    Stack() : top(nullptr) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
    
    void push(int data)
    {
       Node * newbie = (Node *)malloc(sizeof(Node)); //new Node()
       newbie->data = data;
       newbie->next = top;
       top = newbie;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, nothing to pop!!!" << endl;
        }
        Node* temp = top;
        top = top->next; 
        delete temp;  
    }


    int peek()
    {
        if (!isEmpty())
        {
            return top->data;
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
            Node * temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
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
    s.push(100);

    cout << "Stack after push operations: ";
    s.display();

    cout << "Top element (peek): " << s.peek() << endl;

    s.pop(); // Pop the top element
    cout << "Stack after pop operation: ";
    s.display();

    s.pop(); // Pop another element
    cout << "Stack after another pop operation: ";
    s.display();

    cout << "Top element (peek) after pops: " << s.peek() << endl;

    s.pop(); // Pop the last element
    cout << "Stack after popping last element: ";
    s.display();
}
