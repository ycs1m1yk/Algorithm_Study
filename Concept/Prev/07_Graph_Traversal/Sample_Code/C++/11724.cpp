#include <iostream>
#include <vector>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0)

int N, M, u, v;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int start)
{
    visited[start] = true;

    for (int i = 0; i < adj[start].size(); i++)
    {
        int there = adj[start][i];
        if (!visited[there])
            dfs(there);
    }
}

int main()
{
    fastio;
    cin >> N >> M;
    adj = vector<vector<int>>(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    visited = vector<bool>(adj.size(), false);
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout << ans;
}