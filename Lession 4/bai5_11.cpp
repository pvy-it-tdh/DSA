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

// Hàm tính toán giá trị biểu thức hậu tố
int evaluatePostfix(string exp)
{
    stack<int> stk;

    // Duyệt từng ký tự trong biểu thức
    for (char ch : exp)
    {
        if (isdigit(ch))
        {                       // Nếu là số
            stk.push(ch - '0'); // Chuyển ký tự số thành số nguyên
        }
        else if (isOperator(ch))
        { // Nếu là toán tử
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            int result = applyOperation(a, b, ch);
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
        cout << evaluatePostfix(exp) << endl;
    }

    return 0;
}
