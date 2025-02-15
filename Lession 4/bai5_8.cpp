#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Hàm kiểm tra ký tự có phải toán tử không
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Hàm chuyển đổi tiền tố sang hậu tố
string prefixToPostfix(string exp)
{
    stack<string> stk;

    // Duyệt từ phải sang trái
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char ch = exp[i];

        if (isalnum(ch))
        { // Nếu là toán hạng, đẩy vào stack
            stk.push(string(1, ch));
        }
        else if (isOperator(ch))
        { // Nếu là toán tử
            // Lấy 2 toán hạng trên đỉnh stack
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();

            // Tạo biểu thức hậu tố
            string newExp = op1 + op2 + ch;
            stk.push(newExp);
        }
    }

    return stk.top(); // Biểu thức hậu tố cuối cùng
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(); // Xóa bộ đệm dòng mới

    while (T--)
    {
        string exp;
        getline(cin, exp);
        cout << prefixToPostfix(exp) << endl;
    }

    return 0;
}
