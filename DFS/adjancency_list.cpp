#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 1e5 + 5; 
vector<int> adj[N]; 

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // for direction
        // adj[v].push_back(u); // undirection both
    }

    for (int i = 1; i <= n; i++) {
       cout << i << " : ";
       for(int j: adj[i])
          cout << j << " ";
       cout << endl;
    }
    
    return 0;
}
