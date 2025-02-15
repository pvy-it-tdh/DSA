#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

// Hàm kiểm tra độ ưu tiên toán tử
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Hàm thực hiện phép toán
int applyOperation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b; // Phép chia nguyên
    }
    return 0;
}

// Hàm tính giá trị biểu thức trung tố
int evaluateInfix(string s)
{
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            continue; // Bỏ qua khoảng trắng

        if (isdigit(s[i]))
        { // Nếu là số
            int num = 0;
            while (i < s.length() && isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--; // Lùi lại để vòng lặp chính không bỏ qua ký tự tiếp theo
            values.push(num);
        }
        else if (s[i] == '(')
        {
            ops.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOperation(a, b, op));
            }
            ops.pop(); // Loại bỏ dấu '('
        }
        else
        { // Nếu là toán tử
            while (!ops.empty() && precedence(ops.top()) >= precedence(s[i]))
            {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOperation(a, b, op));
            }
            ops.push(s[i]);
        }
    }

    // Thực hiện các phép toán còn lại
    while (!ops.empty())
    {
        int b = values.top();
        values.pop();
        int a = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top(); // Kết quả cuối cùng
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
        cout << evaluateInfix(exp) << endl;
    }

    return 0;
}
