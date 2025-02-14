#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<string> results;             // Tập hợp để lưu các biểu thức hợp lệ không trùng lặp
vector<pair<int, int>> brackets; // Lưu vị trí các cặp dấu ngoặc

void generateExpressions(string &expr, vector<bool> &removeMask, int idx)
{
    if (idx == brackets.size())
    {
        string newExpr;
        for (size_t i = 0; i < expr.size(); i++)
        {
            if (!removeMask[i])
                newExpr += expr[i];
        }
        results.insert(newExpr);
        return;
    }

    // Không xóa cặp ngoặc tại idx
    generateExpressions(expr, removeMask, idx + 1);

    // Xóa cặp ngoặc tại idx
    removeMask[brackets[idx].first] = true;
    removeMask[brackets[idx].second] = true;
    generateExpressions(expr, removeMask, idx + 1);
    removeMask[brackets[idx].first] = false;
    removeMask[brackets[idx].second] = false;
}

int main()
{
    string expr;
    cin >> expr;

    vector<int> stack;
    for (size_t i = 0; i < expr.size(); i++)
    {
        if (expr[i] == '(')
        {
            stack.push_back(i);
        }
        else if (expr[i] == ')')
        {
            brackets.push_back({stack.back(), i});
            stack.pop_back();
        }
    }

    vector<bool> removeMask(expr.size(), false);
    generateExpressions(expr, removeMask, 0);

    results.erase(expr); // Xóa đi biểu thức ban đầu vì nó không thay đổi

    for (const string &res : results)
    {
        cout << res << endl;
    }

    return 0;
}
