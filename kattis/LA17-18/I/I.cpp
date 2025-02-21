#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind {
    vector<ll> p, sz;
    ll numSets;
    UnionFind(ll n) {
        p = vector<ll>(n);
        sz = vector<ll>(n);
        numSets = n;
        for (ll i = 0; i < n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
    }
    ll dsu(ll i) { return (p[i] == i) ? i : (p[i] = dsu(p[i])); }

    void unite(ll i, ll j) {
        i = dsu(i);
        j = dsu(j);
        if (i == j)
            return;
        numSets--;
        if (sz[i] > sz[j])
            swap(i, j);
        sz[j] += sz[i];
        p[i] = j;
    }

    bool isSameSet(ll i, ll j) { return dsu(i) == dsu(j); }
};

struct Edge {
    ll dist, curr, next;
    Edge(ll curr = 0, ll next = 0, ll d = 0)
        : dist(d), curr(curr), next(next) {}
    friend bool operator<(const Edge &lhs, const Edge &rhs) {
        return lhs.dist < rhs.dist;
    }
};

vector<Edge> kruskal(vector<Edge> edges, ll n) {
    vector<Edge> res;
    sort(edges.begin(), edges.end());
    ll count = 0, i = 0;
    UnionFind uf(n);
    while (i < n && count < n - 1) {
        Edge e = edges[i];
        if (uf.isSameSet(e.curr, e.next) == false) {
            count++;
            uf.unite(e.curr, e.next);
            res.push_back(e);
        }
        i++;
    }
    return res;
}

map<pair<ll, ll>, ll> w;
vector<vector<Edge>> adj;
vector<vector<ll>> par, mam;
vector<ll> d;
ll logn;

void dfs(ll v, ll f, ll dd) {
    d[v] = dd;
    ll curr = f;
    par[v][0] = curr;
    mam[v][0] = w[{v, f}];
    for (ll i = 1; (1 << i) <= dd; i++) {
        par[v][i] = par[curr][i - 1];
        mam[v][i] = max(mam[v][i - 1], mam[curr][i - 1]);
        curr = par[curr][i - 1];
    }
    for (Edge next : adj[v]) {
        if (next.next != f)
            dfs(next.next, v, dd + 1);
    }
}

ll lca(ll a, ll b) {
    ll mamma = 0;
    if (d[a] > d[b])
        swap(a, b);
    ll diff = d[b] - d[a];
    for (ll i = 0; i < logn; i++)
        if ((diff >> i) & 1) {
            mamma = max(mamma, mam[b][i]);
            b = par[b][i];
        }
    if (a == b)
        return mamma;
    for (ll i = logn - 1; i >= 0; i--)
        if (par[a][i] != par[b][i]) {
            mamma = max(mamma, mam[a][i]);
            mamma = max(mamma, mam[b][i]);
            a = par[a][i];
            b = par[b][i];
        }
    mamma = max(mamma, mam[a][0]);
    mamma = max(mamma, mam[b][0]);
    return mamma;
}

signed main() {
#ifdef LOCAL_INPUT
    ifstream cin("input.txt");
#else
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#endif

    ll n, r;
    cin >> n >> r;
    vector<Edge> edges;
    for (ll i = 0; i < r; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push_back(Edge(a, b, c));
        w[{a, b}] = c;
        w[{b, a}] = c;
    }
    vector<Edge> mst = kruskal(edges, n);
    ll cost = 0;
    adj.resize(n);
    for (Edge e : mst) {
        adj[e.curr].push_back(Edge(e.curr, e.next, e.dist));
        adj[e.next].push_back(Edge(e.next, e.curr, e.dist));
        cost += e.dist;
    }

    logn = ceill(log2l(n)) + 1;
    par = vector<vector<ll>>(n, vector<ll>(logn));
    mam = vector<vector<ll>>(n, vector<ll>(logn));
    d.resize(n);
    dfs(0, -1, 0);

    ll q;
    cin >> q;
    while (q--) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << cost + w[{u, v}] - lca(u, v) << endl;
    }

#ifdef LOCAL_INPUT
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
