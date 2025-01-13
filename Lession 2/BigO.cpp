#include <iostream>
using namespace std;
void printNumber(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
        
    }
}
int main()
{
    int n;
    cin >> n;
    printNumber(n);
    return 0;
}