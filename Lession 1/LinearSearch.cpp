#include <iostream>
#include <vector>
using namespace std;
int LinearSearch(vector<int> arr, int x)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int x;
    cout << "Enter x: ";
    cin >> x;
    int index = LinearSearch(arr, x);
    if (index == -1)
    {
        cout << "Not found";
    }
    else
    {
        cout << "Found at index: " << index;
    }
    return 0;
}