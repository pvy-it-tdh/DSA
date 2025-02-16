#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int x, y, steps;
};

int minSteps(vector<string> &grid, int a, int b, int c, int d)
{
    int N = grid.size();
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<Node> q;
    q.push({a, b, 0});
    visited[a][b] = true;

    int dx[] = {-1, 1, 0, 0}; // Di chuyển lên, xuống, trái, phải
    int dy[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        int x = cur.x, y = cur.y, steps = cur.steps;

        // Nếu đã đến đích, trả về số bước
        if (x == c && y == d)
            return steps;

        // Duyệt theo 4 hướng
        for (int i = 0; i < 4; i++)
        {
            int nx = x, ny = y;

            // Đi đến khi gặp vật cản hoặc ra biên
            while (true)
            {
                nx += dx[i];
                ny += dy[i];

                // Kiểm tra biên và vật cản
                if (nx < 0 || ny < 0 || nx >= N || ny >= N || grid[nx][ny] == 'X')
                    break;

                // Nếu chưa thăm thì thêm vào hàng đợi
                if (!visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, steps + 1});
                }
            }
        }
    }

    return -1; // Không thể đi đến đích
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<string> grid(N);
        for (int i = 0; i < N; i++)
        {
            cin >> grid[i];
        }
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << minSteps(grid, a, b, c, d) << endl;
    }
    return 0;
}
