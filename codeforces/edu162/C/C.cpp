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
    int n, q;
    cin >> n >> q;
    vll c(n);
    for (ll & x : c) cin >> x;
    vll p(n + 1), u(n + 1);
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + c[i];
        u[i + 1] = u[i] + (c[i] == 1);
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll s = p[r] - p[l - 1];
        ll nu = u[r] - u[l - 1];
        ll k = r - l + 1;
        cout << (k > 1 && s - nu >= k ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
