#include <iostream>
#include <queue>
using namespace std;

void printBinaryNumbers(int n)
{
    queue<string> q;
    q.push("1");

    while (n--)
    {
        string s = q.front();
        q.pop();
        cout << s << " ";

        q.push(s + "0");
        q.push(s + "1");
    }
    cout << endl;
}

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        printBinaryNumbers(n);
    }
    return 0;
}
