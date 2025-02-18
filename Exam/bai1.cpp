#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> num_list{3, 4, 5, 1, -44, 5, 10, 12, 33, 1};
    int k = 3;
    vector<int> result;

    for (int i = 0; i <= num_list.size() - k; i++)
    {
        vector<int> sub_list(num_list.begin() + i, num_list.begin() + i + k);
        result.push_back(*max_element(sub_list.begin(), sub_list.end()));
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
