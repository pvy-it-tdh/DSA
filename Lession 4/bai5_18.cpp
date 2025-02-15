#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

void solve(vector<int> &A, int n)
{
    unordered_map<int, int> freq;
    vector<int> result(n, -1);
    stack<int> st;

    // Đếm tần suất xuất hiện của từng phần tử
    for (int i = 0; i < n; i++)
    {
        freq[A[i]]++;
    }

    // Duyệt từ phải sang trái
    for (int i = n - 1; i >= 0; i--)
    {
        // Loại bỏ các phần tử có tần suất nhỏ hơn hoặc bằng hiện tại
        while (!st.empty() && freq[st.top()] <= freq[A[i]])
        {
            st.pop();
        }

        // Nếu stack không rỗng, lấy phần tử gần nhất có tần suất lớn hơn
        if (!st.empty())
        {
            result[i] = st.top();
        }

        // Đẩy phần tử hiện tại vào stack
        st.push(A[i]);
    }

    // In kết quả
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
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        solve(A, n);
    }
    return 0;
}
