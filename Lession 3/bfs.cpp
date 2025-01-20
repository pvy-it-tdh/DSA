#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int bfs(int u, vector<vector<int>> &graph, vector<bool> &visited)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int j = 0; j < graph[u].size(); j++)
        {
            int v = graph[u][j];
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(i, graph, visited);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}