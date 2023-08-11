#include<bits/stdc++.h>
#include <iostream>
using namespace std;

const int N=1e3+5;
int adjmat[N][N];
int main(){
    int n,m;
    cin >> n >> m; // here n = nodes and m= edges

    for (int i = 1; i <= m; i++)
    {
      int u, v;
      cin >> u >> v;
      adjmat[u][v] = 1;  // for directed
      adjmat[v][u] = 1;  // for undirected
    }

    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        cout << adjmat[i][j] << " ";
      }
      cout << endl;
      
    }
    
    
    return 0;
}