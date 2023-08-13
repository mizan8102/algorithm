#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 1e5 + 5; 
vector<pair<int, int>> adj[N]; 

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // for direction
        adj[v].push_back({u, w}); // undirection both
    }

    for (int i = 1; i <= n; i++) {
       cout << i << " : ";
       for (auto j : adj[i])
           cout << "(" << j.first << "," << j.second << ") ";
       cout << endl;
    }
    
    return 0;
}
