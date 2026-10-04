#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// Create Node
Node *createNode(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// Create Linked List
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
void insertAtPosition(Node *&head, int value, int position)
{
    if (position <= 0)
    {
        cout << "Invalid position";
        return;
    }

    // Position 1 means beginning
    if (position == 1)
    {
        Node *newNode = createNode(value);
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *temp = head;

    // Reach node before required position
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "Invalid position";
            return;
        }

        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Invalid position";
        return;
    }

    Node *newNode = createNode(value);

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display
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

    insertAtPosition(head, 25, 3);

    cout << "\n\nAfter insertion:\n";
    display(head);

    return 0;
}
