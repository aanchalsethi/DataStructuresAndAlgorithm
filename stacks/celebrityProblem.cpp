// everyone knows celebrity
// celebrity knows no one

// Brute force:-
// celebrity row will only have zero
// celebrity column will only have 1's exceot diagonal element

// Optimized approach:-
// put all elements inside stack
// stack size!=1 -> A-> s.top()-> s.pop()
//               -> B-> s.top()-> s.pop()
// if A knows B discard A push B back in the stack or vice versa
// the element left in the stack is 'potential celebrity'
// confirm by verifying
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int celebrity(vector<vector<int>> &M, int n)
{
    // push all the elements in the stack
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }

    // stack size!=1 -> A-> s.top()-> s.pop()
    //               -> B-> s.top()-> s.pop()
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        // if A knows B discard A push B back in the stack or vice versa
        if (M[a][b] == 1)
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }

    // potential candidate
    int ans = st.top();

    // Check row of ans
    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] != 0 && i != ans)
        {
            return -1;
        }
    }

    // Check column of ans
    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] != 1 && i != ans)
        {
            return -1;
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }

        cout << celebrity(M, n) << endl;
    }
}
