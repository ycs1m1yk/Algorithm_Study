#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0)
const int MAX_VERTEX_SIZE = 1001;
vector<vector<int> > adj(MAX_VERTEX_SIZE);
vector<bool> visited;
queue<int> q;

int N, M, V;

void dfs(int here)
{
    visited[here] = true;
    cout<< here << " ";

    for(int i=0; i < adj[here].size(); i++){
        int there = adj[here][i];
        if(!visited[there])
            dfs(there);
    }
}

void bfs(int start)
{
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int here = q.front();
        q.pop();
        cout<< here << " ";
        for(int i=0; i<adj[here].size(); i++){
            int there = adj[here][i];
            if(!visited[there]){
                visited[there]=true;
                q.push(there);                
            }
        }
    }    
}

int main()
{
    fastio;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++)
    {
        int here, there;
        cin >> here >> there;
        adj[here].push_back(there);
        adj[there].push_back(here);
    }
    
    for(int i=1; i<=N; i++)
        sort(adj[i].begin(), adj[i].end());

    // dfs
    visited = vector<bool> (adj.size(), false);
    dfs(V);
    cout<< "\n";

    // bfs
    visited = vector<bool> (adj.size(), false);
    bfs(V);
}