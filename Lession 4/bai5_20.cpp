#include <iostream>
#include <stack>
using namespace std;

string decodeString(string s)
{
    stack<string> st;    // Stack lưu các phần xâu đã xử lý
    stack<int> numStack; // Stack lưu số lần lặp
    string currStr = ""; // Xâu hiện tại
    int num = 0;         // Biến lưu số lần lặp

    for (char c : s)
    {
        if (isdigit(c))
        {                               // Nếu là số
            num = num * 10 + (c - '0'); // Xây dựng số đầy đủ
        }
        else if (c == '[')
        {                       // Khi gặp '['
            numStack.push(num); // Lưu số lần lặp vào stack
            st.push(currStr);   // Lưu xâu hiện tại vào stack
            num = 0;            // Reset số
            currStr = "";       // Reset xâu hiện tại
        }
        else if (c == ']')
        { // Khi gặp ']'
            string temp = currStr;
            currStr = st.top();
            st.pop(); // Lấy xâu trước dấu '['
            int repeat = numStack.top();
            numStack.pop(); // Lấy số lần lặp

            // Lặp lại xâu con và nối vào xâu trước đó
            while (repeat--)
            {
                currStr += temp;
            }
        }
        else
        { // Nếu là chữ cái thường
            currStr += c;
        }
    }
    return currStr;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        cout << decodeString(s) << endl;
    }
    return 0;
}
