#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Hàm kiểm tra ký tự có phải toán tử không
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
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
        return a / b; // Lấy phần nguyên
    }
    return 0;
}

// Hàm tính toán giá trị biểu thức tiền tố
int evaluatePrefix(string exp)
{
    stack<int> stk;

    // Duyệt từ phải sang trái
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        if (isdigit(exp[i]))
        {                           // Nếu là số
            stk.push(exp[i] - '0'); // Chuyển ký tự số thành số nguyên
        }
        else if (isOperator(exp[i]))
        { // Nếu là toán tử
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            int result = applyOperation(a, b, exp[i]);
            stk.push(result);
        }
    }

    return stk.top(); // Kết quả cuối cùng
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
        cout << evaluatePrefix(exp) << endl;
    }

    return 0;
}
