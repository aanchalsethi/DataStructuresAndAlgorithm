#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void InsertAtTail(Node *head, int d)
{
    Node *newnode = new Node(d);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void Print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;

    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    Print(head);
    return 0;
}