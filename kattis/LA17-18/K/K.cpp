#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define F first
#define S second
#define maxn 100010
#define ll long long
#define mod 1000000007
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

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
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
        for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
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

vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, id;

int get_id(int i, int j) {
    return i * m + j + 1;
}

int main() {
    cin >> n >> m;
    Dinic din(n * m + 2, 0, n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            id++;
            char c;
            cin >> c;
            int cap = (c == 'o' ? 1 : 2);
            if ((i + j) % 2) {
                din.add_edge(id, n * m + 1, cap);
            } else {
                din.add_edge(0, id, cap);
            }

            for (pii & x : dir) {
                int a = i + x.F, b = j + x.S;
                if (a < 0 || b < 0 || a >= n || b >= m) continue;
                if ((i + j) % 2) {
                    din.add_edge(get_id(a, b), id, 2);
                } else {
                    din.add_edge(id, get_id(a, b), 2);
                }
            }
        }
    }
    din.flow();
    int flow_in = 0, cap_in = 0, flow_out = 0, cap_out = 0;
    for (auto & x : din.edj) {
        if (x.v == 0) {
            flow_in += x.flo;
            cap_in += x.cap;
        } else if (x.u == n * m + 1) {
            flow_out += x.flo;
            cap_out += x.cap;
        }
    }
    // cout << cap_in << " " << cap_out << "\n";
    // cout << flow_in << " " << flow_out << "\n";
    cout << (flow_in == cap_in && flow_out == cap_out ? "Y\n" : "N\n");
}
