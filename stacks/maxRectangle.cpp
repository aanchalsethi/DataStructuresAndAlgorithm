// max rectangle in binary matrix with all 1's

// Approach:-
// compute max area for first row
// for every remaining row add elements from the above row and then find the max area
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(int *arr, int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] > curr)
        {
            st.pop();
        }
        // ans is stack ka top
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(int *arr, int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] > curr)
        {
            st.pop();
        }
        // ans is stack ka top
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangularArea(int *height, int n)
{
    vector<int> next(n);
    next = nextSmallerElement(height, n);

    vector<int> prev(n);
    prev = prevSmallerElement(height, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = height[i];
        if (next[i] == -1)
            next[i] = n;
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int maxArea(int M[4][4], int n, int m)
{
    // compute max area for first row
    int area = largestRectangularArea(M[0], m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // row updated by adding previous values
            if (M[i][j] != 0)
                M[i][j] += M[i - 1][j];
            else
                M[i][j] = 0;
        }
        area = max(area, largestRectangularArea(M[i], m));
    }
    return area;
}

int main()
{
    int n = 4;
    int m = 4;

    // Initialize a 2D array with specific values
    int M[4][4] = {{0, 1, 1, 0},
                   {1, 1, 1, 1},
                   {1, 1, 1, 1},
                   {1, 1, 0, 0}};
    cout << maxArea(M, n, m) << endl;
}