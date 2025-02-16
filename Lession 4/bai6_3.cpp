#include <iostream>
#include <queue>
using namespace std;

int countBDN(long long N)
{
    queue<long long> q;
    q.push(1);

    int count = 0;
    while (!q.empty())
    {
        long long num = q.front();
        q.pop();

        if (num >= N)
            break; // Dừng nếu số >= N
        count++;

        q.push(num * 10);     // Thêm số có dạng num * 10
        q.push(num * 10 + 1); // Thêm số có dạng num * 10 + 1
    }
    return count;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;
        cout << countBDN(N) << endl;
    }
    return 0;
}
