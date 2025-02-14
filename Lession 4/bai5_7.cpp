#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Hàm kiểm tra ký tự có phải toán tử không
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Hàm chuyển đổi tiền tố về trung tố
string prefixToInfix(string exp)
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

            // Tạo biểu thức trung tố
            string newExp = "(" + op1 + ch + op2 + ")";
            stk.push(newExp);
        }
    }

    return stk.top(); // Biểu thức trung tố cuối cùng
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
        cout << prefixToInfix(exp) << endl;
    }

    return 0;
}
