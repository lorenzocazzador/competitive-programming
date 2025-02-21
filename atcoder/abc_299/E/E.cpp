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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vi adj[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vi ans(n, -1);
    int k;
    cin >> k;
    vi nodes[n];
    while (k--) {
        int p, d;
        cin >> p >> d;
        p--;
        vector<bool> vis(n, false);
        queue<pii> q;
        q.push({p, 0});
        while (!q.empty()) {
            pii act = q.front(); q.pop();
            if (vis[act.F]) continue;
            vis[act.F] = true;
            if (act.S == d) {
                nodes[p].push_back(act.F);
            } else {
                ans[act.F] = 0;
                for (int & x : adj[act.F]) {
                    q.push({x, act.S + 1});
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i].size()) {
            bool f = false;
            for (int & x : nodes[i]) {
                if (ans[x] != 0) {
                    f = true;
                    ans[x] = 1;
                }
            }
            if (!f) {
                cout << "No\n";
                return 0;
            }
        }
    }
    bool v = false;
    for (int i = 0; i < n; i++) {
        v |= (ans[i] == -1 || ans[i] == 1);
    }
    if (!v) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << (ans[i] == -1 ? 1 : ans[i]);
    }
    cout << "\n";
}
