#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
node *create_node(int value)
{
    node *new_node = new node;
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}
node *linked_list()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    node *head = NULL;
    node *temp = NULL;
    cout << "Enter the value of each node: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        node *new_node = create_node(value);
        if (head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }

    return head;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << "| " << temp->data << "  ";
        temp = temp->next;
        cout<<temp<<" | ";
    }
}
int main()
{
    node *head;

    head = linked_list();

    display(head);

    return 0;
}
