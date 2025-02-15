#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void solve(vector<int> &A, int N)
{
    vector<int> B(N);
    stack<int> st; // Lưu chỉ mục các ngày trước đó

    for (int i = 0; i < N; i++)
    {
        // Pop các ngày trước có giá nhỏ hơn hoặc bằng ngày hiện tại
        while (!st.empty() && A[st.top()] <= A[i])
        {
            st.pop();
        }

        // Tính nhịp chứng khoán cho ngày i
        if (st.empty())
        {
            B[i] = i + 1; // Nếu stack rỗng, tất cả ngày trước đều nhỏ hơn hoặc bằng
        }
        else
        {
            B[i] = i - st.top();
        }

        // Đẩy ngày hiện tại vào stack
        st.push(i);
    }

    // In kết quả
    for (int i = 0; i < N; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        solve(A, N);
    }
    return 0;
}
