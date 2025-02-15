#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Hàm tìm diện tích lớn nhất của hình chữ nhật trong histogram
long long maxRectangleArea(vector<int> &heights, int n)
{
    stack<int> st;
    long long maxArea = 0;

    for (int i = 0; i <= n; i++)
    {
        // Xử lý cột cuối bằng 0 để đảm bảo tính toán toàn bộ stack
        int h = (i == n) ? 0 : heights[i];

        while (!st.empty() && heights[st.top()] > h)
        {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, (long long)height * width);
        }
        st.push(i);
    }
    return maxArea;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> heights(N);

        for (int i = 0; i < N; i++)
        {
            cin >> heights[i];
        }

        cout << maxRectangleArea(heights, N) << endl;
    }
    return 0;
}
