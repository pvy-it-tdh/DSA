#include <iostream>
using namespace std;
void QuickSort(int a[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int pivot = a[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j)
    {
        while (a[i] < pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    QuickSort(a, left, j);
    QuickSort(a, i, right);
}
int main()
{
    int a[] = {5, 2, 6, 1, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}