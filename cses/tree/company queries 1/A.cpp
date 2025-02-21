#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int parent[MAXN][20];
vector<int> adj[MAXN];

void dfs (int v, int p) {
    parent[v][0] = p;
    for (int i = 1; i < 20; i++) {
        parent[v][i] = parent[parent[v][i-1]][i-1];
    }
    for (int & x : adj[v]) {
        if (x != p)
            dfs(x, v);
    }
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
        int x, k; cin >> x >> k;
        for (int i = 0; i < 20; i++) {
            if (k & (1 << i)) {
                x = parent[x][i];
            }
        }
        cout << (x == 0 ? -1 : x) << "\n";
    }
}
