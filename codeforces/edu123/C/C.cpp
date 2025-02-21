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
    ll n, x;
    cin >> n >> x;
    vll a(n);
    for (ll & x : a) cin >> x;
    vll mx(n + 1, LLONG_MIN);
    mx[0] = 0;
    for (int l = 0; l < n; l++) {
        ll sum = 0;
        for (int r = l; r < n; r++) {
            sum += a[r];
            mx[r - l + 1] = max(mx[r - l + 1], sum);
        }
    }
    for (int k = 0; k <= n; k++) {
        ll ans = 0;
        for (int i = 0; i <= n; i++) {
            ans = max(ans, mx[i] + min(k, i) * x);
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}
