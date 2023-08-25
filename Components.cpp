#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<vector<int>> adj(N);
vector<bool> visited(N, false);

void dfs(int i, int& c) {
    visited[i] = true;
    c++;
    for (int s : adj[i]) {
        if (!visited[s]) {
            dfs(s, c);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> total;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int c = 0;
            dfs(i, c);
            if (c >= 2) {
                total.push_back(c);
            }
        }
    }
    sort(total.begin(), total.end());
    for (int ch : total) {
        cout << ch << " ";
    }
    return 0;
}
