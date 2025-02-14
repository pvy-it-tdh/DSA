#include <iostream>
#include <string>
using namespace std;

// Hàm chuẩn hóa biểu thức: chỉ giữ lại dấu '(' và ')'
string normalizeExpression(const string &expr)
{
    string result;
    for (char ch : expr)
    {
        if (ch == '(' || ch == ')')
        {
            result += ch;
        }
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
        string P1, P2;
        getline(cin, P1);
        getline(cin, P2);

        // Chuẩn hóa hai biểu thức
        string normP1 = normalizeExpression(P1);
        string normP2 = normalizeExpression(P2);

        // So sánh hai chuỗi đã chuẩn hóa
        if (normP1 == normP2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
