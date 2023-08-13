#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adj[N];
bool visited[N];

void dfs(int u, int &componentSize) {
    visited[u] = true;
    componentSize++;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, componentSize);
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
        adj[v].push_back(u); // Since it's an undirected graph
    }

    vector<int> componentSizes;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int componentSize = 0;
            dfs(i, componentSize);
            if (componentSize > 1) {
                componentSizes.push_back(componentSize);
            }
        }
    }

    sort(componentSizes.begin(), componentSizes.end());

    for (int size : componentSizes) {
        cout << size << " ";
    }

    return 0;
}
