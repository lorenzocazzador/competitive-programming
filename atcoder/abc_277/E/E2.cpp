#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define db(x) cout << #x << ": " << x << "\n";

const int MAXN = 200010;
vector<pii> adj[MAXN];
bool sw[MAXN], vis[MAXN][2];
int dist[MAXN][2];
priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;

void djkstra(int x, int s) {
    if (vis[x][s]) return;
    vis[x][s] = true;
    for (auto [y, w] : adj[x]) {
        if (s == w && dist[x][s] + 1 < dist[y][s]) {
            dist[y][s] = dist[x][s] + 1;
            pq.push({dist[y][s], y, s});
        }
    }

    if (sw[x] && dist[x][s^1] > dist[x][s]) {
        dist[x][s^1] = dist[x][s];
        pq.push({dist[x][s], x, s^1});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        sw[x] = true;
    }
    for (int i = 0; i <= n; i++) {
        dist[i][0] = dist[i][1] = INT_MAX;
    }
    pq.push({0, 1, 1});
    dist[1][1] = 0;
    while(pq.size()) {
        auto x = pq.top(); pq.pop();
        djkstra(x[1], x[2]);
    }
    int res = min(dist[n][0], dist[n][1]);
    cout << (res == INT_MAX ? -1 : res) << "\n";
}
