#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

int n, b;
vector<pair<int,int>> v;
vector<vector<array<int, 3>>> adj;
vector<int> c;
vector<vector<long long>> dp;

int dist(pair<int,int> a, pair<int,int> b) {
    return ceil(sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S)));
}

void f(int s, int k) {
    if (s == n + 1) return;
    for (auto & [x, d, m] : adj[s]) {
        if (k + d <= b && dp[x][k + d] > dp[s][k] + m) {
            dp[x][k + d] = dp[s][k] + m;
            f(x, k + d);
        }
    }
}

int main() {
    int xs, ys, xd, yd, c0, t;
    cin >> xs >> ys >> xd >> yd >> b >> c0 >> t;
    c.resize(t + 1);
    c[0] = c0;
    for (int i = 1; i <= t; i++) {
        cin >> c[i];
    }
    cin >> n;
    v.resize(n + 2);
    v[0] = {xs, ys};
    v[n + 1] = {xd, yd};
    adj.resize(n + 2);
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> v[i].F >> v[i].S >> l;
        for (int j = 0; j < l; j++) {
            int x, m;
            cin >> x >> m;
            x++;
            adj[i].push_back({x, 0, m});
            adj[x].push_back({i, 0, m});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto & [x, d, m] : adj[i]) {
            d = dist(v[i], v[x]);
            m = c[m] * d;
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        int d = dist(v[0], v[i]);
        adj[0].push_back({i, d, d * c0});
    }
    for (int i = 1; i <= n; i++) {
        int d = dist(v[i], v[n + 1]);
        adj[i].push_back({n + 1, d, d * c0});
    }
    dp.resize(n + 2, vector<long long>(b + 1, LLONG_MAX));
    dp[0][0] = 0;
    f(0, 0);
    long long res = *min_element(dp[n + 1].begin(), dp[n + 1].end());
    cout << (res == LLONG_MAX ? -1 : res) << "\n";
}
