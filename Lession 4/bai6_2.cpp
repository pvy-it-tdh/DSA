#include <iostream>
#include <queue>
#include <set>
using namespace std;

void findSmallestX(int N)
{
    queue<string> q;
    set<int> visited;

    q.push("9");

    while (!q.empty())
    {
        string num = q.front();
        q.pop();

        long long val = stoll(num);
        if (val % N == 0)
        {
            cout << num << endl;
            return;
        }

        if (!visited.count(val % N))
        {
            visited.insert(val % N);
            q.push(num + "0");
            q.push(num + "9");
        }
    }
}

int main()
{
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        findSmallestX(N);
    }
    return 0;
}
