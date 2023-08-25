#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int N = 1e3 + 5;
typedef pair<int, int> pii;

vector<pii> adj[N];
vector<int> dist(N, INF);
vector<bool> visited(N);


void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}
void dijkstra(int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({dist[source], source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (pii vpair : adj[u]) {
            int v = vpair.first;
            int w = vpair.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    // Removed init_code() since it's not necessary here
    init_code();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++) {
        cout << "Distance of node " << i << ": ";
        cout << dist[i] << endl;
    }

    return 0;
}
