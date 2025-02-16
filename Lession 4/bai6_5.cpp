#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int minOperations(int S, int T)
{
    if (S >= T)
        return S - T; // Trường hợp chỉ cần giảm (S > T)

    queue<pair<int, int>> q;    // (giá trị hiện tại, số bước)
    unordered_set<int> visited; // Tránh vòng lặp vô hạn

    q.push({S, 0});
    visited.insert(S);

    while (!q.empty())
    {
        int value = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (value == T)
            return steps; // Đã biến đổi thành T

        // Thao tác (a): value - 1
        if (value - 1 > 0 && visited.find(value - 1) == visited.end())
        {
            q.push({value - 1, steps + 1});
            visited.insert(value - 1);
        }

        // Thao tác (b): value * 2
        if (value * 2 <= 20000 && visited.find(value * 2) == visited.end())
        { // Giới hạn 20000 để tránh tràn số
            q.push({value * 2, steps + 1});
            visited.insert(value * 2);
        }
    }
    return -1; // Không xảy ra vì luôn tìm được kết quả
}

int main()
{
    int T, S, Tval;
    cin >> T;
    while (T--)
    {
        cin >> S >> Tval;
        cout << minOperations(S, Tval) << endl;
    }
    return 0;
}
