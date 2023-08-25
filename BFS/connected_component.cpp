#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

// dfs 
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // vertices and edges

    // adjacency list input
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // connected component count
    int cc = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {  // Check if the node is not already visited
            dfs(i);
            cc++;
        }
    }

    cout << "Result of connected component = " << cc << endl;
    return 0;
}
