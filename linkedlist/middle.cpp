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

// Two pointer approach
Node *GetMiddle(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

int GetLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }

    return len;
}

// Iterative approach
Node *Middle(Node *head)
{
    int len = GetLength(head);
    int mid = len / 2;

    Node *temp = head;
    int cnt = 0;
    while (cnt < mid)
    {
        temp = temp->next;
        cnt++;
    }

    return temp;
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

    Node *mid = Middle(head);
    Print(mid);

    Node *mid1 = GetMiddle(head);
    Print(mid1);
    return 0;
}
