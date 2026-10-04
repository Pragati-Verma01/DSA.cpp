#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

// 1. Create a new node
Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 2. Create linked list
Node *linkedList()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node *head = NULL;
    Node *temp = NULL;
    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        Node *newNode = createNode(value);
        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

// 3. Insert at end
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = createNode(value);
  
    // If list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;

    // Go to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Connect last node to new node
    temp->next = newNode;
}

// 4. Display
void display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }

    cout << "NULL";
}

int main()
{
    Node *head = linkedList();
    cout << "\nOriginal Linked List:\n";
    display(head);
    int value;
    cout << "\n\nEnter value to insert at end: ";
    cin >> value;
    insertAtEnd(head, value);
    cout << "\nAfter insertion at end:\n";
    display(head);
    return 0;
}
