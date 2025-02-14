#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

// Hàm trả về độ ưu tiên của toán tử
int precedence(char op)
{
    if (op == '^')
        return 3; // Lũy thừa có độ ưu tiên cao nhất
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Hàm chuyển đổi trung tố sang hậu tố
string infixToPostfix(string exp)
{
    stack<char> operators; // Ngăn xếp lưu toán tử
    string result;

    for (char ch : exp)
    {
        if (isalnum(ch))
        { // Nếu là toán hạng (A-Z, a-z, 0-9)
            result += ch;
        }
        else if (ch == '(')
        {
            operators.push(ch);
        }
        else if (ch == ')')
        {
            // Pop cho đến khi gặp '('
            while (!operators.empty() && operators.top() != '(')
            {
                result += operators.top();
                operators.pop();
            }
            operators.pop(); // Bỏ '('
        }
        else
        { // Nếu là toán tử
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch))
            {
                if (ch == '^' && operators.top() == '^')
                    break; // Lũy thừa phải xử lý từ phải sang trái
                result += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    // Lấy các toán tử còn lại trong stack
    while (!operators.empty())
    {
        result += operators.top();
        operators.pop();
    }

    return result;
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
        cout << infixToPostfix(exp) << endl;
    }

    return 0;
}
