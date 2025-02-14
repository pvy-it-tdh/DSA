#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool hasRedundantParentheses(const string &expr)
{
    stack<char> st;

    for (char ch : expr)
    {
        if (ch == ')')
        {
            char top = st.top();
            st.pop();

            bool hasOperator = false;

            while (!st.empty() && top != '(')
            {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    hasOperator = true;
                top = st.top();
                st.pop();
            }

            if (!hasOperator)
                return true; // Dấu ngoặc dư thừa
        }
        else
        {
            st.push(ch);
        }
    }

    return false;
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(); // Để loại bỏ ký tự xuống dòng sau khi nhập số T

    while (T--)
    {
        string expr;
        getline(cin, expr);

        cout << (hasRedundantParentheses(expr) ? "Yes" : "No") << endl;
    }

    return 0;
}
