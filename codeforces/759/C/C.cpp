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

ll dist (vll & a, int k) {
    ll f = (sz(a) % k) - 1;
    ll res = f >= 0 ? a[f] * 2 : 0;
    for (int i = f + k; i < sz(a); i += k)
        res += a[i] * 2;
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vll p, ne;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x > 0) p.push_back(x);
        else if (x < 0) ne.push_back(abs(x));
    }
    sort(all(p));
    sort(all(ne));
    ll res = dist(p, k) + dist(ne, k);
    if (sz(p) && sz(ne))
        res -= max(ne[sz(ne)-1], p[sz(p)-1]);
    else if (sz(p))
        res -= p[sz(p)-1];
    else if (sz(ne))
        res -= ne[sz(ne)-1];
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
