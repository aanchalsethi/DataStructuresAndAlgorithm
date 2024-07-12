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

// iteratively
Node *Reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// recursion
void RecursiveReverse(Node *&head, Node *&curr, Node *&prev)
{

    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }

    Node *forward = curr->next;
    RecursiveReverse(head, forward, curr);
    curr->next = prev;
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
    Node *node1 = new Node(1);
    Node *head = node1;

    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    Print(head);

    // Node *node2 = Reverse(head);
    // Print(node2);

    Node *curr = head;
    Node *prev = NULL;
    RecursiveReverse(head, curr, prev);
    Print(head);
    return 0;
}
