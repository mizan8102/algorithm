#include<bits/stdc++.h>
#include <iostream>
using namespace std;

const int N=1e3+5;
vector<int> adj[N];
bool visited[N];
int level[N];

// dfs 
void dfs(int u){

  visited[u] = true;
  for (int v: adj[u])
  {
    if (visited[v]) continue;
    dfs(v);
  }
}

int main(){
    
    int n,m;
    cin >> n >> m;  // vertex and edges

// adjecency list input
    for (int i = 0; i < m; i++)
    {
      int u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    // bfs(1);


    // connected component count 

    int cc=0;
    for (int i = 1; i <= n; i++)
    {
      if (visited[i]) continue;
      dfs(i);
      cc++;
    }
    cout << "Result of connected component = " << cc << endl;
    return 0;
}