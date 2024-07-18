#include <iostream>
#include <stack>
using namespace std;

void sorted(stack<int> &st, int num)
{
    // base case
    if (st.empty() || st.top() < num)
    {
        st.push(num);
        return;
    }

    int val = st.top();
    st.pop();
    sorted(st, num);
    st.push(val);
}

void sortStack(stack<int> &st)
{
    // base case
    if (st.empty())
        return;

    int num = st.top();
    st.pop();

    // recursive call
    sortStack(st);

    sorted(st, num);
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
    st.push(10);
    st.push(3);
    st.push(5);
    st.push(14);
    st.push(2);
    printStack(st);

    sortStack(st);
    printStack(st);

    return 0;
}