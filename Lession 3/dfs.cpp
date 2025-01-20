#include <iostream>
#include <vector>
using namespace std;
int dfs(int u, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (!visited[v])
        {
            dfs(v, graph, visited);
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
            dfs(i, graph, visited);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}