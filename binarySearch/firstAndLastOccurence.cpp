#include <iostream>
using namespace std;

int firstOccurence(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key)
        { // left
            e = mid - 1;
        }
        else if (arr[mid] < key)
        { // right
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOccurence(int arr[], int n, int key)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > key)
        { // left
            e = mid - 1;
        }
        else if (arr[mid] < key)
        { // right
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

// find total occurence
int totalOccurence(int arr[], int n, int key)
{
    return (lastOccurence(arr, n, key) - firstOccurence(arr, n, key)) + 1;
}

int main()
{
    int arr[5] = {0,
                  1,
                  1,
                  1,
                  3};
    cout << firstOccurence(arr, 5, 1) << endl;
    cout << lastOccurence(arr, 5, 2) << endl;
    cout << totalOccurence(arr, 5, 1) << endl;
    return 0;
}