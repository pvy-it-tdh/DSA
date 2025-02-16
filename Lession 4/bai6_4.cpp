#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

string findBDN(int N)
{
    queue<string> q;
    unordered_set<int> visited; // Lưu trạng thái số dư để tránh lặp

    q.push("1");

    while (!q.empty())
    {
        string num = q.front();
        q.pop();

        // Chuyển num từ string sang số nguyên dư mod N
        int remainder = 0;
        for (char c : num)
        {
            remainder = (remainder * 10 + (c - '0')) % N;
        }

        if (remainder == 0)
            return num; // Tìm được số chia hết cho N

        // Nếu dư này đã gặp thì bỏ qua (tránh vòng lặp vô hạn)
        if (visited.find(remainder) == visited.end())
        {
            visited.insert(remainder);
            q.push(num + "0");
            q.push(num + "1");
        }
    }
    return "-1"; // Không xảy ra vì luôn có số BDN chia hết cho N
}

int main()
{
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << findBDN(N) << endl;
    }
    return 0;
}
