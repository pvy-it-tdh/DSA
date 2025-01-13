#include <iostream>
using namespace std;
int BinarySearch(int a[], int n, int x)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int x;
    cin >> x;
    int result = BinarySearch(a, n, x);
    if (result == -1)
    {
        cout << "Not found";
    }
    else
    {
        cout << "Found at index " << result;
    }
    return 0;
}