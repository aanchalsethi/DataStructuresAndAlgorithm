#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
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

vector<int> prevSmallerElement(vector<int> &arr, int n)
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

int largestRectangularArea(vector<int> &height)
{
    int n = height.size();
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

int main()
{
    int arr_data[] = {2, 1, 5, 6, 2, 3};
    vector<int> arr(arr_data, arr_data + 6);
    cout << largestRectangularArea(arr) << endl;
    return 0;
}