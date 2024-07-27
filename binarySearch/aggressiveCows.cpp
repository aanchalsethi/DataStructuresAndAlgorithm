#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> stalls, int k, int mid)
{
    int cowCount = 1;
    int lastPos = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggresiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;

    for (int i = 0; i < stalls.size(); i++)
    {
        maxi = max(stalls[i], maxi);
    }

    int e = maxi;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(6);
    int k = 2;

    cout << aggresiveCows(arr, k) << endl;
    return 0;
}