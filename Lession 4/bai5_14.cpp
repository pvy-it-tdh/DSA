#include <iostream>
#include <stack>
using namespace std;

void findMinimumNumber(string S)
{
    stack<int> st;
    string result = "";

    for (int i = 0; i <= S.length(); i++)
    {
        st.push(i + 1); // Đẩy số vào stack
        if (i == S.length() || S[i] == 'I')
        {
            // Khi gặp 'I' hoặc kết thúc chuỗi thì lấy số từ stack ra
            while (!st.empty())
            {
                result += to_string(st.top());
                st.pop();
            }
        }
    }
    cout << result << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        findMinimumNumber(S);
    }
    return 0;
}
