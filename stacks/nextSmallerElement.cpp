#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// move in the array from right to left, if the element at the top is smaller than the curr element then store it as the ans else keep popping until you find the ans
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() > curr)
        {
            st.pop();
        }
        // ans is stack ka top
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
    cout << endl;
}

int main()
{
    int arr_data[] = {1, 3, 2};
    vector<int> arr(arr_data, arr_data + 3);
    vector<int> ans = nextSmallerElement(arr, 3);
    print(ans);
    return 0;
}