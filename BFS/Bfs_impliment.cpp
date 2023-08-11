#include<bits/stdc++.h>
#include <iostream>
using namespace std;

const int N=1e3+5;
vector<int> adj[N];
bool visited[N];
int level[N];
void bfs(int s){
  queue<int> q;
  q.push(s);
  visited[s]=true;
  level[s]=0;
  while (!q.empty())
  {
    int u= q.front();
    q.pop();
    cout << "Visiting node: " << u << endl;
    for (int v: adj[u])
    {
      if(visited[v]==true) continue;
      q.push(v);
      visited[v]=true;
      level[v]=level[u]+1;
      // section 3


    }
    //section 4: same as section 1
    

    
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

  bfs(1);

// print level 
for (int i = 1; i <= n; i++)
{
   cout << "level of node "<< i << ":" << level[i] << endl;
}

    
    return 0;
}