#include<bits/stdc++.h>
#include <iostream>
using namespace std;

const int N = 21; 
vector<int> adj[N];
bool visited[N];

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
    cin >> n >> m; 
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }  
    int val;
    cin >> val;
    dfs(val);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            c++;
        }
    }
    cout << c << endl;
    return 0;
}
