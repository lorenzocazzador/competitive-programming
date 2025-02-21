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

vector<vii> adj1, adj2;
vll d;
vector<bool> vis;
priority_queue<pair<ll,int>> pq;

void dijkstra(bool first) {
    while (!pq.empty()) {
        int act = pq.top().S; pq.pop();
        if (vis[act]) continue;
        vis[act] = true;
        if (first) {
            for (pii & x : adj1[act]) {
                if (d[x.F] == -1 || d[act] + x.S < d[x.F]) {
                    d[x.F] = d[act] + x.S;
                    pq.push({-d[x.F], x.F});
                }
            }
        } else {
            for (pii & x : adj2[act]) {
                if (d[x.F] == -1 || d[act] + x.S < d[x.F]) {
                    d[x.F] = d[act] + x.S;
                    pq.push({-d[x.F], x.F});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    adj1.resize(n);
    adj2.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        adj1[x].push_back({y,w});
        adj2[y].push_back({x,w});
    }

    d.resize(n, -1);
    vis.resize(n, false);
    d[0] = 0;
    pq.push({0,0});
    dijkstra(true);
    for (int i = 0; i < n; i++) {
        if (d[i] != -1) {
            pq.push({-d[i], i});
            vis[i] = false;
        }
    }
    dijkstra(false);
    for (int i = 1; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";
}
