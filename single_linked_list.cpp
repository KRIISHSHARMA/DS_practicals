#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node * next;
};

Node* createNode(int data) 
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == nullptr) 
    {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void displayNode(Node *head) 
{
    if (head == nullptr) 
    {
        cout << "List is empty." << endl;
        return;
    }
    while (head != nullptr) 
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(Node * &head)
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

void insertAtEnd(Node *&head, int data) 
{
    Node *newNode = createNode(data);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void InsertAtBegining(Node * &head , int data)
{
   Node *newNode = createNode(data);
   newNode->next = head;
   head = newNode;
}

void InsertAtGivenPos(Node * &head , int data , int pos)
{
    if (pos <= 0) 
    {
        cout << "Invalid position!" << endl;
        return;
    }
    
    Node *newNode = createNode(data);
    if (pos == 1) 
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    int posNode = 1;
    while (temp != nullptr && posNode < pos - 1) 
    {
        temp = temp->next;
        posNode++;
    }

    if (temp == nullptr) 
    {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void RemoveBeg(Node * &head)
{
    if (head == nullptr) 
    {
        cout << "List is empty!" << endl;
        return;
    }
    
    Node *temp = head;
    head = head->next;
    delete temp;
}

void RemoveAtPos(Node * &head , int pos)
{
    if (head == nullptr) 
    {
        cout << "List is empty!" << endl;
        return;
    }
    if (pos <= 0) 
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node *temp = head;
    int posNode = 1;
    while (temp != nullptr && posNode < pos - 1) 
    {
        temp = temp->next;
        posNode++;
    }

    if (temp == nullptr || temp->next == nullptr) 
    {
        cout << "Position out of range!" << endl;
        return;
    }

    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

Node* Search(Node * head , int data)
{
    if (head == nullptr) 
    {
        cout << "List is empty!" << endl;
        return nullptr;
    }

    while (head != nullptr)
    {
        if(head->data == data)
        {
            cout << "Data is in linked list" << "\n";
            return head;
        }
        head = head->next;
    }
    cout << "Not in linked list" << endl;
    return nullptr;
}

void concatenateLists(Node* &head1, Node* head2) 
{
    if (head1 == nullptr) 
    {
        head1 = head2;
        return;
    }
    if (head2 == nullptr)
    {
        return;
    }

    Node* temp = head1;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    temp->next = head2;
}

int main()
{
    Node *ll = nullptr;
    Node *ll2 = nullptr;
    int size = 0;
    cout << "Enter number of data to be entered: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int data = 0;
        cout << "Enter data " << i << ": ";
        cin >> data;
        insertAtEnd(ll, data);
    }

    displayNode(ll);
    InsertAtBegining(ll, 1010);
    displayNode(ll);
    InsertAtGivenPos(ll, 3030303, 2);
    displayNode(ll);
    RemoveBeg(ll);
    displayNode(ll);
    RemoveAtPos(ll, 2);
    displayNode(ll);
    Search(ll, 1);
    InsertAtBegining(ll2, 999);
    concatenateLists(ll, ll2);
    displayNode(ll);
    freeList(ll);
    cout << "Memory for the linked list has been freed." << endl;
}
