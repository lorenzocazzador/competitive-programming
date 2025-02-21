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
#define pb push_back

struct FlowEdge {
    int v, u;
    ll cap, flo = 0;
    FlowEdge(int v, int u, ll cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const ll flow_inf = 1e18;
    vector<FlowEdge> edj;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> lvl, ptr;
    queue<int> q;

    Dinic (int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        lvl.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, ll cap) {
        edj.pb({v, u, cap});
        edj.pb({u, v, 0});
        adj[v].pb(m);
        adj[u].pb(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edj[id].cap - edj[id].flo < 1)
                    continue;
                if (lvl[edj[id].u] != -1)
                    continue;
                lvl[edj[id].u] = lvl[v] + 1;
                q.push(edj[id].u);
            }
        }
        return lvl[t] != -1;
    }

    ll dfs(int v, ll pu) {
        if (pu == 0)
            return 0;
        if (v == t)
            return pu;
        for (int& cid = ptr[v]; cid < sz(adj[v]); cid++) {
            int id = adj[v][cid];
            int u = edj[id].u;
            if (lvl[v] + 1 != lvl[u] || edj[id].cap - edj[id].flo < 1)
                continue;
            ll tr = dfs(u, min(pu, edj[id].cap - edj[id].flo));
            if (tr == 0)
                continue;
            edj[id].flo += tr;
            edj[id ^ 1].flo -= tr;
            return tr;
        }
        return 0;
    }

    ll flow() {
        ll f = 0;
        while (true) {
            fill(lvl.begin(), lvl.end(), -1);
            lvl[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pu = dfs(s, flow_inf)) {
                f += pu;
            }
        }
        return f;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<string, int> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]] = i;
    }
    vector<vi> adj(n, vi(n, 1));
    vi vis(n), mx(n);
    int r;
    cin >> r;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < n; j++) vis[j] = false;
        int k, w;
        cin >> k >> w;
        w--;
        while (k--) {
            string x;
            cin >> x;
            int ind = m[x];
            mx[ind] = max(mx[ind], w);
            vis[ind] = true;
        }
        for (int j = 0; j < n; j++) {
            if (!vis[j])
                adj[j][w] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < mx[i])
                adj[i][j] = false;
        }
    }
    Dinic din(n * 2 + 2, n * 2, n * 2 + 1);
    for (int i = 0; i < n; i++) din.add_edge(n * 2, i, 1);
    for (int i = 0; i < n; i++) din.add_edge(n + i, n * 2 + 1, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) {
                din.add_edge(i, n + j, 1);
            }
        }
    }
    din.flow();
    vi pos_to_str(n, -1);
    for (auto & x : din.edj) {
        if (x.v >= 0 && x.v < n && x.flo == 1) {
            pos_to_str[x.u - n] = x.v;
        }
    }
    for (int i = 0; i < n; i++) cout << v[pos_to_str[i]] << " ";
}
