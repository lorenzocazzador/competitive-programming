#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int>& D) {
    vector<vector<pii>> adj(N);
    for (int i = 0; i < M; i++) {
        adj[X[i]].push_back({Y[i], P[i]});
    }
    for (int i = 0; i < N; i++) {
        D[i] = -1;
    }
    priority_queue<pii> pq;
    pq.push({0, 0});
    D[0] = 0;
    while (!pq.empty()) {
        int act = pq.top().S; pq.pop();
        for (pii & x : adj[act]) {
            if (D[x.F] == -1 || D[act] + x.S < D[x.F]) {
                D[x.F] = D[act] + x.S;
                pq.push({-D[x.F], x.F});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m), p(m), d(n);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i] >> p[i];
    }
    mincammino(n, m, x, y, p, d);
    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << "\n";
}
