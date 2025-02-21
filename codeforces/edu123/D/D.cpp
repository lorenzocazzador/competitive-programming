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

const int MOD = 998244353;

void solve() {
    ll n, m, k, q;
    cin >> n >> m >> k >> q;
    vi r(n, 0), c(m, 0);
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        r[x] = i;
        c[y] = i;
    }
    set<int> s = {0};
    for (int i = 0; i < n; i++)
        s.insert(r[i]);
    ll ans = 1;
    for (int i = 0; i < sz(s) - 1; i++)
        ans = (ans * k) % MOD;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
