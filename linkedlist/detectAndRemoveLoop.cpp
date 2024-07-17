// 1. detect if there's a loop.
// 2. remove if there's a loop or flatten a linkedlist.
// 3. return the beginning/start element of the loop.

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

Node *FloydDetectLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
            return slow;
    }
    return NULL;
}

Node *GettingStartingNode(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *intersection = FloydDetectLoop(head);
    if (intersection != NULL)
        return NULL;

    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node *RemoveLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *startOfLoop = GettingStartingNode(head);

    if (startOfLoop == NULL)
        return head;

    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}

void insertNode(Node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        Node *curr = tail;

        do
        {
            if (curr->data == element)
            {
                Node *temp = new Node(d);
                temp->next = curr->next;
                curr->next = temp;

                // Update tail if we're inserting after the current tail
                if (curr == tail)
                {
                    tail = temp;
                }
                return;
            }
            curr = curr->next;
        } while (curr != tail);
    }
}

void print(Node *tail)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    Node *temp = tail->next; // Start from the node after tail

    do
    {
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != tail->next); // loop until we come back to the first node

    cout << endl;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 1, 1);
    insertNode(tail, 1, 2);
    insertNode(tail, 2, 3);
    insertNode(tail, 3, 4);
    insertNode(tail, 4, 5);
    print(tail);

    cout << FloydDetectLoop(tail) << endl;

    Node *loop = GettingStartingNode(tail);
    cout << loop->data << endl;

    return 0;
}
