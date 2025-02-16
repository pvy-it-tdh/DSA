#include <iostream>
using namespace std;

// Hàm kiểm tra số K có thỏa mãn điều kiện
bool isValid(int K)
{
    bool used[6] = {false}; // Chỉ cần mảng từ 0-5
    while (K > 0)
    {
        int digit = K % 10;
        if (digit > 5 || used[digit])
            return false;
        used[digit] = true;
        K /= 10;
    }
    return true;
}

int countValidNumbers(int L, int R)
{
    int count = 0;
    for (int i = L; i <= R; i++)
    {
        if (isValid(i))
            count++;
    }
    return count;
}

int main()
{
    int T, L, R;
    cin >> T;
    while (T--)
    {
        cin >> L >> R;
        cout << countValidNumbers(L, R) << endl;
    }
    return 0;
}
