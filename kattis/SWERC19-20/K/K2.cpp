#include <bits/stdc++.h>
using namespace std;

int n, m, t;
vector<bool> ans, vis, neig;
vector<vector<int>> adj;

void dfs(int v, int p) {
    cout << v << " " << p << "\n";
    if (v != p) {
        ans[v] = false;
    }
    if (vis[v]) return;
    vis[v] = true;
    if (neig[v])
        p = v;
    for (int & x : adj[v])
        dfs(x, p);
}

int main() {
    cin >> n >> m >> t;
    adj.resize(n);
    vector<int> adj_t;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a != t && b != t)
            adj[a].push_back(b);
        if (b == t)
            adj_t.push_back(a);
    }
    vis.resize(n, false);
    ans.resize(n, false);
    neig.resize(n, false);
    for (int & x : adj_t) neig[x] = ans[x] = true;
    vector<int> v;
    for (int & x : adj_t) {
        dfs(x, x);
        v.push_back(x);

    }
    cout << v.size() << "\n";
    for (int & x : v) cout << x << "\n";
}
