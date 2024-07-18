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

    printStack(st);

    insertAtBottom(st, 0);

    printStack(st);

    return 0;
}