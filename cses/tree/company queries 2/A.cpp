#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int parent[MAXN][20];
vector<int> adj[MAXN];
int depth[MAXN];

void dfs (int v, int p) {
    parent[v][0] = p;
    for (int i = 1; i < 20; i++) {
        parent[v][i] = parent[parent[v][i-1]][i-1];
    }
    for (int & x : adj[v]) {
        if (x != p) {
            depth[x] = depth[v] + 1;
            dfs(x, v);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] != depth[b]) {
        if (depth[a] < depth[b]) swap(a, b);
        int d = depth[a] - depth[b];
        for (int i = 0; i < 20; i++) {
            if (d & (1 << i)) {
                a = parent[a][i];
            }
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1, -1);
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}
