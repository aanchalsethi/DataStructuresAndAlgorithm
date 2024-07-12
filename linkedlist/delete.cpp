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

void DeleteAtHead(Node *&head)
{
    Node *temp = head;
    head = head->next;

    free(temp);
}

void DeleteAtTail(Node *&head)
{
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next->next);
    temp->next = NULL;
}

void DeleteAtPosition(Node *&head, int pos)
{

    if (pos == 1)
    {
        DeleteAtHead(head);
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        int cn = 1;

        while (cn < pos)
        {
            prev = curr;
            curr = curr->next;
            cn++;
        }

        prev->next = curr->next;
        free(curr);
    }
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
    Node *node1 = new Node(10);
    Node *head = node1;
    InsertAtTail(head, 12);
    InsertAtTail(head, 15);
    InsertAtTail(head, 20);
    Print(head);

    // DeleteAtHead(head);
    // Print(head);

    // DeleteAtTail(head);
    // Print(head);

    DeleteAtPosition(head, 4);
    Print(head);

    return 0;
}