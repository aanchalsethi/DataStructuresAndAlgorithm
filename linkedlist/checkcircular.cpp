#include <iostream>
#include <map>
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

// using map
bool detectLoop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp] == true)
            return true;

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

bool isCircularList(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
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

    cout << isCircularList(tail) << endl;

    cout << detectLoop(tail) << endl;

    return 0;
}
