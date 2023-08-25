#include<bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
int level[N];

vector<int> bfs(int n, int l)
{
    vector<int> ar;
    queue<int> q;
    q.push(0); 
    visited[0] = true;
    level[0] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
                if (level[v] == l)
                    ar.push_back(v);
            }
        }
    }
    return ar;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l;
    cin >> l;
    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
        level[i] = 0;
    }
    vector<int> ar = bfs(n, l);
    if (ar.empty())
    {
        cout << -1 << endl;
    }
    else
    {
      sort(ar.begin(), ar.end());
      for (int a : ar){
        cout << a << " ";
      }
    }
    return 0;
}
