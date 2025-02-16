#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <cmath>
using namespace std;

int minOperations(int N)
{
    queue<pair<int, int>> q;    // (giá trị hiện tại, số bước)
    unordered_set<int> visited; // Tránh xét lại số đã gặp

    q.push({N, 0});
    visited.insert(N);

    while (!q.empty())
    {
        int value = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (value == 1)
            return steps; // Đã biến đổi thành 1

        // Thao tác (a): Giảm 1
        if (value - 1 > 0 && visited.find(value - 1) == visited.end())
        {
            q.push({value - 1, steps + 1});
            visited.insert(value - 1);
        }

        // Thao tác (b): Tìm (u, v) sao cho u * v = value và chọn max(u, v)
        for (int i = 2; i <= sqrt(value); i++)
        {
            if (value % i == 0)
            {
                int maxFactor = max(i, value / i);
                if (visited.find(maxFactor) == visited.end())
                {
                    q.push({maxFactor, steps + 1});
                    visited.insert(maxFactor);
                }
            }
        }
    }
    return -1; // Không xảy ra vì luôn tìm được kết quả
}

int main()
{
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << minOperations(N) << endl;
    }
    return 0;
}
