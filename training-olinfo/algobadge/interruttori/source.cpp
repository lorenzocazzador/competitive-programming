#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    int x;
    for (int i = 0; i < a; i++) {
        cin >> x;
        dist[x] = 1;
        q.push(x);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < b; i++) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    while (!q.empty()) {
        int t = q.front(); q.pop();
        for (int & y : adj[t]) {
            if (dist[y] > dist[t] + 1) {
                dist[y] = dist[t] + 1;
                q.push(y);
            }
        }
    }
    int mx = 0, ind = -1;
    for (int i = 0; i < n; i++) {
        if (dist[i] > mx) {
            mx = dist[i];
            ind = i;
        }
    }
    cout << ind << " " << mx;
}

int main() {
    int t;
    cin >> t;
    for (int nt = 1; nt <= t; nt++) {
        cout << "Case #" << nt << ": ";
        solve();
        cout << "\n";
    }
}
