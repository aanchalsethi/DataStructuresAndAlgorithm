#include <iostream>
using namespace std;

int pivotElement(int arr[], int n)
{
    int s = 0, e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int searchInRotatedArray(int arr[], int n, int key)
{
    int pivot = pivotElement(arr, n);
    int s, e;
    if (key >= arr[pivot] && key <= arr[n - 1])
    {
        s = pivot;
        e = n - 1;
    }
    else
    {
        s = 0;
        e = pivot - 1;
    }

    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    int arr[5] = {7, 9, 1, 2, 3};
    cout << searchInRotatedArray(arr, 5, 2) << endl;
    return 0;
}