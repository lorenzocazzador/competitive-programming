#include <bits/stdc++.h>
using namespace std;

int n, m, t;
vector<vector<int>> adj_rev;
vector<set<int>> reach;

void dfs(int v, int p) {
    if (reach[v].count(p)) return;
    if (reach[v].size() >= 2) return;
    reach[v].insert(p);
    for (int & x : adj_rev[v]) dfs(x, p);
}

int main() {
    cin >> n >> m >> t;
    adj_rev.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a != t)
            adj_rev[b].push_back(a);
    }
    reach.resize(n);
    for (int & x : adj_rev[t]) dfs(x, x);
    vector<int> v;
    for (int & x : adj_rev[t]) {
        if (reach[x].size() == 1)
            v.push_back(x);
    }
    cout << v.size() << "\n";
    for (int & x : v) cout << x << "\n";
}
