#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &st, int count, int size)
{
    // base  case
    if (count == size / 2)
    {
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();
    deleteMiddle(st, count + 1, size);
    st.push(num);
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

    deleteMiddle(st, 0, st.size());

    printStack(st);
    return 0;
}