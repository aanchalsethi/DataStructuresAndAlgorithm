// in each place the smallest value in the right place
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int n)
{
}

int main()
{
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(1);
    arr.push_back(3);

    cout << "Before sorting" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }
    cout << "After sorting" << endl;
    insertionSort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}