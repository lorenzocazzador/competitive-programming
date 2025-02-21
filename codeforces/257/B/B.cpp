#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define db(x) cout << #x << ": " << x << "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<int, 3>>> adj(n + 1);
    vector<array<int, 3>> edg;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c, -1});
        adj[b].push_back({a, c, -1});
        edg.push_back({a, b, c});
    }
    vector<array<int, 3>> edg2;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        adj[1].push_back({a, b, i});
        adj[a].push_back({1, b, i});
        edg2.push_back({1, a, b});
    }

    vll dist(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while (pq.size()) {
        int x = pq.top().S;
        pq.pop();
        if (vis[x])
            continue;
        vis[x] = true;
        for (auto [y, w, t] : adj[x]) {
            if (dist[x] + w <= dist[y]) {
                dist[y] = dist[x] + w;
                pq.push({dist[y], y});
            }
        }
    }
    vii gr(n + 1, {0,0});
    for (auto [u, v, w] : edg) {
        if (dist[u] + w == dist[v]) {
            gr[v].F++;
        }
        if (dist[v] + w == dist[u]) {
            gr[u].F++;
        }
    }
    int res = 0;
    for (auto [u, v, w] : edg2) {
        if (dist[u] + w == dist[v]) {
            gr[v].S++;
        } else if (dist[v] + w == dist[u]) {
            gr[u].S++;
        } else res++;
    }
    for (auto [a, b] : gr) {
        res += (a > 0 ? b : max(0, b - 1));
    }
    cout << res << "\n";
}
