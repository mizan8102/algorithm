#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 21; 
vector<vector<int>> adj(N);
vector<bool> visited(N, false);

void dfs(int i) {
    visited[i] = true;
    for (int n : adj[i]) {
        if (!visited[n]) {
            dfs(n);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int q;
    cin >> q; 
    dfs(q);

    int r = 0;
    for (bool v : visited) {
        if (v) {
            r++;
        }
    }
    cout << r - 1 << endl; 
    return 0;
}
