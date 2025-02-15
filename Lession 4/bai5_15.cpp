#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Hàm tìm next greater element
vector<int> nextGreater(vector<int> &arr, int n)
{
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop(); // Loại bỏ phần tử nhỏ hơn hoặc bằng arr[i]
        }
        if (!st.empty())
            nge[i] = st.top(); // Phần tử lớn hơn đầu tiên bên phải
        st.push(arr[i]);
    }
    return nge;
}

// Hàm tìm next smaller element
vector<int> nextSmaller(vector<int> &arr, int n)
{
    vector<int> nse(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop(); // Loại bỏ phần tử lớn hơn hoặc bằng arr[i]
        }
        if (!st.empty())
            nse[i] = st.top(); // Phần tử nhỏ hơn đầu tiên bên phải
        st.push(arr[i]);
    }
    return nse;
}

void processTestCase()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> nge = nextGreater(arr, n); // Tìm phần tử lớn hơn đầu tiên
    vector<int> result(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (nge[i] != -1)
        {
            vector<int> nse = nextSmaller(arr, n);
            result[i] = nse[i]; // Tìm phần tử nhỏ hơn tiếp theo của next greater
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        processTestCase();
    }
    return 0;
}
