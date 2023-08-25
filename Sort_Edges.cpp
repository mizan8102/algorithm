#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
vector<int> v[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dfs(int s) {
    vis[s] = true;
    for (int i = 0; i < v[s].size(); i++) {
        int child = v[s][i];
        if (vis[child] == false) {
            pq.push(make_pair(s, child));
            dfs(child);
        }
    }
}

int main() {
    int e;
    cin >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    while (!pq.empty()) {
        pair<int, int> edge = pq.top();
        pq.pop();
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}
