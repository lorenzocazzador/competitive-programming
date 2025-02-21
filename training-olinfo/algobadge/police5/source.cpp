#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<array<int,3>> adj[n];
    for (int i = 0; i < m; i++) {
        int a, b, c, e;
        cin >> a >> b >> c >> e;
        adj[a].push_back({b,c,e});
    }
    vector<int> dist(n, INT_MAX);
    vector<bool> vis(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (pq.size()) {
        int x = pq.top().S; pq.pop();
        if (vis[x]) {
            continue;
        }
        vis[x] = true;
        for (auto [y, w, e] : adj[x]) {
            if ((dist[x] + w < dist[y] && e && dist[x] + w <= t) || (dist[x] + w < dist[y] && !e)){
                dist[y] = dist[x] + w;
                pq.push({dist[y], y});
            }
        }
    }
    cout << (dist[n-1] == INT_MAX ? -1 : dist[n-1]) << "\n";
}
