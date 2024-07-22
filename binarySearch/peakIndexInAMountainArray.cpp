#include <iostream>
using namespace std;

int indexOfPeak(int arr[], int n)
{
    int s = 0, e = n - 1;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] > arr[mid - 1])
        {
            s = mid + 1;
        }
        else if (arr[mid] < arr[mid - 1])
        {
            e = mid - 1;
        }
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            ans = mid;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[7] = {-2, -1, 0, 1, 2, 1, 0};
    cout << indexOfPeak(arr, 7) << endl;
    return 0;
}