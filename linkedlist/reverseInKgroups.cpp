// input:
// 1->2->3->4->5->6
// k=2

// output:
// 2->1->4->3->6->5

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

Node *KReverse(Node *head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }

    // reverse k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    int cnt = 0;

    while (curr != NULL && cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

        cnt++;
    }

    // recursion
    if (next != NULL)
    {
        head->next = KReverse(next, k);
    }

    return prev;
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
    InsertAtTail(head, 6);
    Print(head);

    Node *rev = KReverse(head, 2);
    Print(rev);

    return 0;
}