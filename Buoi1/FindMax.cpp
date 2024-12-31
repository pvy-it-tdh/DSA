#include <iostream>
#include <vector>
int FindMax(std::vector<int> arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int max = FindMax(arr);
    cout << "Max: " << max;
    return 0;
}