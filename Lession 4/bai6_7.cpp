#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// Hàm kiểm tra nếu hai từ chỉ khác nhau đúng 1 ký tự
bool isAdjacent(const string &a, const string &b)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            count++;
        if (count > 1)
            return false;
    }
    return count == 1;
}

// Hàm tìm đường đi ngắn nhất từ s đến t
int shortestTransformation(vector<string> &words, string &s, string &t)
{
    if (s == t)
        return 0; // Nếu s và t giống nhau

    unordered_set<string> wordSet(words.begin(), words.end());
    if (wordSet.find(t) == wordSet.end())
        return -1; // Nếu t không có trong danh sách thì không thể đi đến

    queue<pair<string, int>> q;
    q.push({s, 1}); // Bắt đầu từ s với bước đi đầu tiên
    wordSet.erase(s);

    while (!q.empty())
    {
        auto [current, steps] = q.front();
        q.pop();

        for (auto it = wordSet.begin(); it != wordSet.end();)
        {
            if (isAdjacent(current, *it))
            {
                if (*it == t)
                    return steps + 1;
                q.push({*it, steps + 1});
                it = wordSet.erase(it); // Xóa khỏi tập để tránh lặp lại
            }
            else
            {
                ++it;
            }
        }
    }
    return -1; // Không tìm thấy đường đi
}

int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> n >> s >> t;

        vector<string> words(n);
        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
        }

        int result = shortestTransformation(words, s, t);
        cout << result << endl;
    }
    return 0;
}
