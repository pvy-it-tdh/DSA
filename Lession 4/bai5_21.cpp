#include <iostream>
#include <stack>
#include <string>
using namespace std;

int maxValidLength(string P)
{
    int n = P.length();
    stack<int> st;
    bool valid[n] = {false}; // Đánh dấu các vị trí thuộc biểu thức đúng

    // Tìm các cặp ngoặc đúng và đánh dấu chúng
    for (int i = 0; i < n; i++)
    {
        if (P[i] == '(')
        {
            st.push(i); // Đẩy vị trí '(' vào stack
        }
        else if (!st.empty())
        {                                      // Khi gặp ')'
            valid[i] = valid[st.top()] = true; // Đánh dấu cả cặp là đúng
            st.pop();
        }
    }

    // Tính tổng các đoạn liên tiếp của ngoặc đúng
    int maxLength = 0, currentLength = 0;
    for (int i = 0; i < n; i++)
    {
        if (valid[i])
        {
            currentLength++;
        }
        else
        {
            if (currentLength >= 2)
            {
                maxLength += currentLength; // Cộng vào tổng độ dài
            }
            currentLength = 0; // Reset lại
        }
    }
    if (currentLength >= 2)
        maxLength += currentLength; // Cộng đoạn cuối cùng

    return maxLength;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string P;
        cin >> P;
        cout << maxValidLength(P) << endl;
    }
    return 0;
}
