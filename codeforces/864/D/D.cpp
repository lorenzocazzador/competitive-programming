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

struct SubCmp {
    bool operator()(const pii& a, const pii& b) const {
        return a.F != b.F ? a.F > b.F : a.S < b.S;
    }
};

vector<vi> adj;
vll a, imp;
vi par, siz;
vector<set<pii, SubCmp>> hev;

void dfs(int v, int p = -1) {
    par[v] = p;
    siz[v]++;
    imp[v] += a[v];
    for (int & x : adj[v]) {
        if (x != p) {
            dfs(x, v);
            siz[v] += siz[x];
            imp[v] += imp[x];
            hev[v].insert({siz[x], x});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    imp.resize(n + 1, 0);
    siz.resize(n + 1, 0);
    par.resize(n + 1, 0);
    hev.resize(n + 1);
    dfs(1);

    while (m--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            cout << imp[x] << "\n";
        } else if (!hev[x].empty()) {
            int son = (*hev[x].cbegin()).S;
            int fa = par[x];

            par[son] = fa;
            par[x] = son;

            hev[fa].erase({siz[x], x});
            hev[x].erase({siz[son], son});

            siz[x] -= siz[son];
            siz[son] += siz[x];

            imp[x] -= imp[son];
            imp[son] += imp[x];

            hev[fa].insert({siz[son], son});
            hev[son].insert({siz[x], x});
        }
    }
}
