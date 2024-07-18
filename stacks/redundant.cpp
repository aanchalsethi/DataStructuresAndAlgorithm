#include <iostream>
#include <stack>
using namespace std;

bool isRedundant(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            bool isRedundant = true;
            while (st.top() != '(')
            {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                {
                    isRedundant = false;
                }
                st.pop();
            }
            if (isRedundant)
                return isRedundant;
            st.pop();
        }
    }
    return false;
}

int main()
{
    string s = "((b*c))";

    if (isRedundant(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}