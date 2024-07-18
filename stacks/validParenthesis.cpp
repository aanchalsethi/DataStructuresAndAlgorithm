#include <iostream>
#include <stack>
using namespace std;

bool matches(char top, char ch)
{
    if (top == '(' && ch == ')')
        return true;
    else if (top == '{' && ch == '}')
        return true;
    else if (top == '[' && ch == ']')
        return true;
    else
        return false;
}

bool isValidParenthesis(string exp)
{
    stack<char> st;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // if opening bracket stack push
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        } // if closing bracket, stack top check and pop
        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if (matches(top, ch))
                    st.pop();
                else
                    return false;
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "{([))}";
    if (isValidParenthesis(s))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
