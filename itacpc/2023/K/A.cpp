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

vector<vi> adj;
vll n_nod, n_arc, id;

void dfs(int x, int i) {
    if (id[x] != -1) return;
    n_nod[i]++;
    n_arc[i] += (ll)adj[x].size();
    id[x] = i;
    for (int & y : adj[x]) {
        if (id[y] == -1)
            dfs(y, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ll cp, cm;
    cin >> cp >> cm;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    n_nod.resize(n, 0);
    n_arc.resize(n, 0);
    id.resize(n, -1);
    ll ans = 0, cc = 0;
    for (int i = 0; i < n; i++) {
        if (id[i] == -1) {
            dfs(i, i);
            ans += (n_arc[i] / 2 - n_nod[i] + 1) * cm;
            cc++;
        }
    }
    ans += (cc - 1) * cp;
    cout << ans << "\n";
}
