#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeBrackets(string expr)
{
    stack<int> signStack;
    signStack.push(1); // Dấu mặc định bên ngoài là '+'

    string result;
    int currentSign = 1; // Dấu hiện tại (+1 hoặc -1)

    for (size_t i = 0; i < expr.size(); i++)
    {
        char ch = expr[i];

        if (ch == '(')
        {
            if (i > 0 && expr[i - 1] == '-')
            {
                signStack.push(-signStack.top());
            }
            else
            {
                signStack.push(signStack.top());
            }
        }
        else if (ch == ')')
        {
            signStack.pop();
        }
        else if (ch == '+' || ch == '-')
        {
            if (ch == '+')
            {
                currentSign = signStack.top();
            }
            else
            { // ch == '-'
                currentSign = -signStack.top();
            }
            result += (currentSign == 1) ? '+' : '-';
        }
        else
        {
            result += ch;
        }
    }

    // Xóa dấu cộng thừa ở đầu chuỗi
    if (!result.empty() && result[0] == '+')
    {
        result.erase(result.begin());
    }

    return result;
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(); // Xóa bộ đệm

    while (T--)
    {
        string expr;
        getline(cin, expr);
        cout << removeBrackets(expr) << endl;
    }

    return 0;
}
