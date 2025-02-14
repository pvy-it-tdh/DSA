#include <iostream>
using namespace std;

int minSwapsToBalance(string s)
{
    int balance = 0, swap_count = 0;

    for (char ch : s)
    {
        if (ch == '(')
        {
            balance++;
        }
        else
        { // ch == ')'
            if (balance > 0)
            {
                balance--; // Ghép với '(' trước đó
            }
            else
            {
                swap_count++; // Đổi dấu ')' thành '('
                balance++;
            }
        }
    }

    // Cần đổi balance/2 dấu '(' dư thừa thành ')'
    return swap_count + balance / 2;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string S;
        cin >> S;
        cout << minSwapsToBalance(S) << endl;
    }

    return 0;
}
