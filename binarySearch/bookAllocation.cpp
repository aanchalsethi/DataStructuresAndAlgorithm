#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
    if (m > n)
        return -1; // More students than books
    int s = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        s = max(s, arr[i]); // Starting point should be the maximum number of pages in a single book
    }
    int e = sum;
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);

    int n = arr.size();
    int m = 2;

    int ans = allocateBooks(arr, n, m);

    cout << ans << endl;
    return 0;
}
