#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> s;
    while (n > 0)
    {
        s.push(n % 2);
        n /= 2;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}