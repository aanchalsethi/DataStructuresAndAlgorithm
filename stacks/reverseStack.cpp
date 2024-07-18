#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int num)
{
    // base case
    if (st.empty())
    {
        st.push(num);
        return;
    }

    int val = st.top();
    st.pop();
    insertAtBottom(st, num);
    st.push(val);
}

void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int num = st.top();
    st.pop();

    reverse(st);

    insertAtBottom(st, num);
}

void printStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    printStack(st);

    reverse(st);

    printStack(st);

    return 0;
}