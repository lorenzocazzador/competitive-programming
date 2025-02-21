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

vector<vii> adj;
vector<bool> sw;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(n + 1);
    sw.resize(n + 1, false);
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
    vi dist(n + 1, INT_MAX);
    priority_queue<array<int,3>> q;
    q.push({0, 1, 1});
    if (sw[1]) {
        q.push({0, 1, 0});
    }
    dist[1] = 0;
    while (q.size()) {
        auto a = q.top(); q.pop();
        for (pii & x : adj[a[1]]) {
            if (x.S == a[2] && dist[a[1]] + 1 < dist[x.F]) {
                dist[x.F] = dist[a[1]] + 1;
                q.push({-dist[x.F], x.F, a[1]});
                if (sw[x.F])
                    q.push({-dist[x.F], x.F, (a[2] + 1) % 2});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << "\n";
    cout << dist[n];
}
