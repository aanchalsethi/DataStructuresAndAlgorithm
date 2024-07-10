#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node *&head, int d)
{
    // create a new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&head, int d)
{
    // create a new node
    Node *newNode = new Node(d);

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void InsertAtPosition(Node *&head, int pos, int d)
{

    if (pos == 1)
    {
        InsertAtHead(head, d);
    }
    Node *temp = head;
    int cn = 1;

    while (cn < pos - 1)
    {
        temp = temp->next;
        cn++;
    }

    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

void Print(Node *&head)
{
    // create a temp node
    Node *temp = head;

    // traverse through the linkedlist
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // create a node
    Node *node1 = new Node(10);

    // head point to node1
    Node *head = node1;
    Print(head);

    // InsertAtHead(head, 12);
    // Print(head);

    // InsertAtHead(head, 15);
    // Print(head);

    InsertAtTail(head, 12);
    Print(head);

    InsertAtTail(head, 15);
    Print(head);

    InsertAtPosition(head, 2, 22);
    Print(head);
    return 0;
}