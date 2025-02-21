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

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int & x : a) cin >> x;
    vll sum(n + m + 1, 0), in(n + m + 1, 0);
    for (int i = 1; i <= m; i++) {
        int p, v;
        cin >> p >> v;
        p--;
        sum[a[p]] += (i - in[a[p]]);
        a[p] = v;
        in[v] = i;
    }
    for (int i = 0; i < n; i++) {
        sum[a[i]] += (m + 1 - in[a[i]]);
    }
    ll res = 0;
    for (int i = 1; i < n + m + 1; i++) {
        res += m * (m + 1) / 2 - (m - sum[i]) * (m - sum[i] + 1) / 2;
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
