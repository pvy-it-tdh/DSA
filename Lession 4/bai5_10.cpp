#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Hàm kiểm tra ký tự có phải toán tử không
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Hàm chuyển đổi hậu tố sang trung tố
string postfixToInfix(string exp)
{
    stack<string> stk;

    // Duyệt từ trái sang phải
    for (char ch : exp)
    {
        if (isalnum(ch))
        { // Nếu là toán hạng, đẩy vào stack
            stk.push(string(1, ch));
        }
        else if (isOperator(ch))
        { // Nếu là toán tử
            // Lấy 2 toán hạng trên đỉnh stack
            string op2 = stk.top();
            stk.pop();
            string op1 = stk.top();
            stk.pop();

            // Tạo biểu thức trung tố với dấu ngoặc
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
        cout << postfixToInfix(exp) << endl;
    }

    return 0;
}
